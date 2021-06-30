package main.com.elsys.videogames;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        VideoGamesExplorer videoGamesExplorer = new VideoGamesExplorer(new FileInputStream(new File("vgsales.csv")));
        System.out.println(videoGamesExplorer.findNameOfLeastSoldVideoGameInJapan());
        System.out.println(videoGamesExplorer.findNameOfVideoGameWithLargestSaleDifference());
        System.out.println(videoGamesExplorer.findNamesOfTopNVideoGamesBySalesInEurope(5));
        System.out.println(videoGamesExplorer.findAverageSoldCopiesByPublisher("Nintendo"));
    }
}
