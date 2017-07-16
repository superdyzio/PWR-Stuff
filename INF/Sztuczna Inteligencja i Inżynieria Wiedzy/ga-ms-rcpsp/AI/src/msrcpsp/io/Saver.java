package msrcpsp.io;

import msrcpsp.evaluation.Statistics;
import msrcpsp.scheduling.Schedule;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.*;
import java.util.Arrays;

public class Saver {

    private File file;
    private int buforSize = 10000;
    private String[] bufor;
    private int index;

    public Saver(String fileName) {
        this.file = new File(fileName + ".csv");
        try {
            this.file.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.bufor = new String[this.buforSize];
        this.index = 0;

        deleteFile(fileName);
    }


    private void deleteFile(String fileName) {
        Path path = FileSystems.getDefault().getPath(fileName+".csv");

        try {
            Files.delete(path);
        } catch (NoSuchFileException x) {
            System.err.format("%s: no such" + " file or directory%n", path);
        } catch (DirectoryNotEmptyException x) {
            System.err.format("%s not empty%n", path);
        } catch (IOException x) {
            // File permission problems are caught here.
            System.err.println(x);
        }
    }


    public void saveResults(int generation, Schedule[] population) {
        bufor[index++ % bufor.length] = generation + ";" + Statistics.getStats(population);
        if (index % bufor.length == 0) {
            saveToFile(bufor);
        }
    }

    public void saveResults(int generation, String row) {
        bufor[index++ % bufor.length] = generation + ";" + row;
        if (index % bufor.length == 0) {
            saveToFile(bufor);
        }
    }

    public void close() {
        saveToFile(Arrays.copyOfRange(bufor, 0, index % bufor.length));
    }

    private void saveToFile(String[] data) {
        try {
            FileWriter fileWriter = new FileWriter(file, true);
            write(data, fileWriter);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void write(String[] data, FileWriter fileWriter) {
        try {
            for (int i = 0, length = data.length; i < length; i++) {
                fileWriter.write(data[i].replace(".", ","));
                fileWriter.write(System.getProperty("line.separator"));
                fileWriter.flush();
            }
            fileWriter.flush();
            fileWriter.close();
        } catch (Exception e) {
            System.out.print("blad zapisu");
        }
    }
}
