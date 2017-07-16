import msrcpsp.evaluation.BaseEvaluator;
import msrcpsp.evaluation.DurationEvaluator;
import msrcpsp.evaluation.Statistics;
import msrcpsp.io.MSRCPSPIO;
import msrcpsp.io.Saver;
import msrcpsp.scheduling.Resource;
import msrcpsp.scheduling.Schedule;
import msrcpsp.scheduling.Task;
import msrcpsp.scheduling.greedy.Greedy;
import msrcpsp.validation.BaseValidator;
import msrcpsp.validation.CompleteValidator;
import msrcpsp.validation.ValidationResult;

import java.io.IOException;
import java.util.List;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Runner class to help with understanding of the library.
 */
public class Runner {

    private static final String fileName = "200_20_55_9";
    private static final Logger LOGGER = Logger.getLogger(Runner.class.getName());
    private static final String definitionFile = "assets/def_small/" + fileName + ".def";
    private static final String writeFile = "assets/solutions_small/" + fileName + ".sol";

    private static int pop_size = 100;
    private static int gen = 100;
    private static double Pm = 0.01;
    private static double Px = 0.1;
    private static int Tn = 100;
    private static Schedule[] population = new Schedule[pop_size];
    private static int generation = 1;
    private static int iterations = 10;

    private static double[] minValues = new double[gen];
    private static double[] maxValues = new double[gen];
    private static double[] avgValues = new double[gen];

    private static final Saver saver = new Saver(fileName);

    public static void main(String[] args) {
        MSRCPSPIO reader = new MSRCPSPIO();
        Schedule loadedSchedule = reader.readDefinition(definitionFile);
        BaseValidator validator = new CompleteValidator();
        if (null == loadedSchedule) {
            LOGGER.log(Level.WARNING, "Could not read the Definition " + definitionFile);
        }

        long start, stop;
        long time = 0;

        for (int iter = 0; iter < iterations; iter++) {
            start = System.currentTimeMillis();

            for (int i = 0; i < pop_size; i++) {
                Schedule schedule = new Schedule(loadedSchedule);

                int[] upperBounds = schedule.getUpperBounds(schedule.getTasks().length);
                BaseEvaluator evaluator = new DurationEvaluator(schedule);
                Task[] tasks = schedule.getTasks();

                Random random = new Random(System.currentTimeMillis());
                List<Resource> capableResources;
                for (int j = 0; j < tasks.length; ++j) {
                    capableResources = schedule.getCapableResources(tasks[j]);
                    schedule.assign(tasks[j], capableResources.get((int) (random.nextDouble() * upperBounds[j])));
                }

                Greedy greedy = new Greedy(schedule.getSuccesors());
                greedy.buildTimestamps(schedule);

                population[i] = new Schedule(schedule);
                population[i].setEvaluator(evaluator.getCopy(population[i]));
            }

            while (generation <= gen) {
                double[] timeDurations = Statistics.timeDurations(population);
                minValues[generation - 1] += Statistics.getMin(timeDurations);
                maxValues[generation - 1] += Statistics.getMax(timeDurations);
                avgValues[generation - 1] += Statistics.getAvg(timeDurations);

                population = generateNewPopulation(population);

                generation++;
            }

            stop = System.currentTimeMillis();

            generation = 1;

            time += stop - start;

            System.out.println(iter);
        }

        for (int i = 0; i < gen; i++) {
            minValues[i] /= iterations;
            maxValues[i] /= iterations;
            avgValues[i] /= iterations;
            saver.saveResults(i, minValues[i] + ";" + maxValues[i] + ";" + avgValues[i]);
        }

        saver.close();

        System.out.println("Avg time: " + time / iterations);

        try {
            reader.write(getBestSchedule(population), writeFile);
        } catch (IOException e) {
            System.out.print("Writing to a file failed");
        }
    }

    private static Schedule[] generateNewPopulation(Schedule[] population) {
        int numer = 0;
        Random random = new Random(System.currentTimeMillis());
        Schedule[] newPopulation = new Schedule[pop_size];

        while (numer < pop_size) {
            Schedule[] selected = new Schedule[Tn];
            double[] values = new double[Tn];
            for (int i = 0; i < Tn; i++) {
                selected[i] = population[random.nextInt(pop_size)];
                values[i] = selected[i].evaluate();
            }

            double min = 99999999;
            int minIndex1 = -1;
            for (int i = 0; i < Tn; i++) {
                if (values[i] < min) {
                    min = values[i];
                    minIndex1 = i;
                }
            }
            Schedule s1 = new Schedule(selected[minIndex1]);

            min = 99999999;
            int minIndex2 = -1;
            for (int i = 0; i < Tn; i++) {
                if (i != minIndex1 && values[i] <= min) {
                    min = values[i];
                    minIndex2 = i;
                }
            }
            Schedule s2 = new Schedule(selected[minIndex2]);

            int tasksToCrossover = s1.getTasks().length / 3;
            random = new Random(System.currentTimeMillis());
            if (random.nextDouble() < Px) {
                for (int j = 0; j < tasksToCrossover; j++) {
                    int temp = s1.getTask(j+1).getResourceId();
                    s1.getTask(j+1).setResourceId(s2.getTask(j+1).getResourceId());
                    s2.getTask(j+1).setResourceId(temp);
                }
            }

            int tasksCount = s1.getTasks().length;
            for (int i = 0; i < tasksCount; i++) {
                if (random.nextDouble() < Pm) {
                    int[] upperBounds = s1.getUpperBounds(s1.getTasks().length);
                    Task task = s1.getTask(i + 1);
                    List<Resource> capableResources = s1.getCapableResources(task);
                    s1.assign(task, capableResources.get((int) (random.nextDouble() * upperBounds[i])));
                }
                if (random.nextDouble() < Pm) {
                    int[] upperBounds = s2.getUpperBounds(s2.getTasks().length);
                    Task task = s2.getTask(i + 1);
                    List<Resource> capableResources = s2.getCapableResources(task);
                    s2.assign(task, capableResources.get((int) (random.nextDouble() * upperBounds[i])));
                }
            }

            Greedy greedy = new Greedy(s1.getSuccesors());
            greedy.buildTimestamps(s1);
            greedy = new Greedy(s2.getSuccesors());
            greedy.buildTimestamps(s2);

            newPopulation[numer] = s1;
            numer++;
            newPopulation[numer] = s2;
            numer++;
        }

        return newPopulation;
    }

    private static Schedule getBestSchedule(Schedule[] pop) {
        Schedule best = pop[0];
        for (int i = 1; i < pop.length - 1; i++) {
            if (best.evaluate() > pop[i].evaluate()) {
                best = pop[i];
            }
        }
        return best;
    }
}
