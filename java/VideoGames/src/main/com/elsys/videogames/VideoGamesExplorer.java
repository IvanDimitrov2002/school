package main.com.elsys.videogames;

import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class VideoGamesExplorer {
    private ArrayList<VideoGame> videogames = new ArrayList<>();

    public VideoGamesExplorer(InputStream dataInput) {
        Scanner scanner = new Scanner(dataInput);
        scanner.nextLine();
        while (scanner.hasNextLine()) {
            videogames.add(VideoGame.createVideoGame(scanner.nextLine()));
        }
        scanner.close();
    }

    public Collection<VideoGame> getVideoGames() {
        return videogames;
    }

    public String findNameOfLeastSoldVideoGameInJapan(){
        return videogames.stream().sorted(new Comparator<VideoGame>() {
            @Override
            public int compare(VideoGame videoGame1, VideoGame videoGame2) {
                return Integer.compare(videoGame1.getJpSales(), videoGame2.getJpSales());
            }
        }).collect(Collectors.toList()).get(0).getName();
    }

    public String findNameOfVideoGameWithLargestSaleDifference(){
        return videogames.stream().sorted(new Comparator<VideoGame>() {
            @Override
            public int compare(VideoGame videoGame1, VideoGame videoGame2) {
                int difference1 = Math.abs(videoGame1.getGlobalSales() - (2*videoGame1.getOtherSales()));
                int difference2 = Math.abs(videoGame2.getGlobalSales() - (2*videoGame2.getOtherSales()));
                return Integer.compare(difference1, difference2);
            }
        }.reversed()).collect(Collectors.toList()).get(0).getName();
    }

    public List<String> findNamesOfTopNVideoGamesBySalesInEurope(int n){
        return videogames.stream().sorted(new Comparator<VideoGame>() {
            @Override
            public int compare(VideoGame videoGame1, VideoGame videoGame2) {
                return Integer.compare(videoGame1.getEuSales(), videoGame2.getEuSales());
            }
        }.reversed()).map(VideoGame::getName).limit(n).collect(Collectors.toList());
    }

    public double findAverageSoldCopiesByPublisher(String publisher){
        return videogames.stream()
               .filter(a -> a.getPublisher().equals(publisher))
               .mapToDouble(VideoGame::getGlobalSales).average().orElse(0)/1000000;
    }

    public String findPublisherWithMostVideoGamesInYear(int year){
//        return videogames.stream()
//                .filter(a -> !a.getPublisher().equals("N/A") && !a.getPublisher().equals("Unknown") && a.getReleaseYear() == year)
//                .map(VideoGame::getPublisher)
//                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()))
//                .entrySet()
//                .stream()
//                .max(Map.Entry.comparingByValue());
    }
}
