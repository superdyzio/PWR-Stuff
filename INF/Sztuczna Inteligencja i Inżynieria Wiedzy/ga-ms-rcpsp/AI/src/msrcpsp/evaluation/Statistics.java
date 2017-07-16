package msrcpsp.evaluation;

import msrcpsp.scheduling.Schedule;
import java.util.Arrays;

/**
 * Created by Dyzio on 27.03.2017.
 */
public class Statistics {

    public static double[] timeDurations(Schedule[] population) {
        return Arrays.stream(population).parallel().mapToDouble(individual -> individual.evaluate()).toArray();
    }

    public static double getMax(double[] timeDurations) {
        return Arrays.stream(timeDurations).parallel().max().getAsDouble();
    }

    public static double getMin(double[] timeDurations) {
        return Arrays.stream(timeDurations).parallel().min().getAsDouble();
    }

    public static double getAvg(double[] timeDurations) {
        return Arrays.stream(timeDurations).parallel().average().getAsDouble();
    }

    public static String getStats(Schedule[] population) {
        double[] timeDurations = timeDurations(population);
        return getMin(timeDurations) + ";" + getMax(timeDurations) + ";" + getAvg(timeDurations);
    }
}