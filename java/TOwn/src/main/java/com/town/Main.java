package main.java.com.town;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
	    List<City> cities = new ArrayList<City>();
        List<Road> roads = new ArrayList<Road>();
        cities.add(new City(0, "Sofia"));
        cities.add(new City(1, "Varna"));
        cities.add(new City(2, "Plovdiv"));

        roads.add((new Road(0, "Trakia", 150, 0, 1)));
        roads.add((new Road(1, "Hemus", 210, 1, 2)));

        System.out.println(findShortestRoad(0, 1, roads));
        System.out.println(findShortestRoad(0, 2, roads));

    }

    private static Integer findShortestRoad(Integer cityOneId, Integer cityTwoId, List<Road> roads){
        if(cityOneId == cityTwoId){
            return 0;
        }
        Integer shortestRoad = 0;
        for(Road road : roads){
            if((road.getCityOneId() == cityOneId && road.getCityTwoId() == cityTwoId) || (road.getCityOneId() == cityTwoId && road.getCityTwoId() == cityOneId)) {
                shortestRoad = road.getRoadLength();
                if(shortestRoad == 0 || shortestRoad > road.getRoadLength()){
                    shortestRoad = road.getRoadLength();
                }
            }
            if(road.getCityOneId() == cityOneId){
                Integer currRoad = findShortestRoad(road.getCityTwoId(), cityTwoId, roads);
                if(currRoad < shortestRoad && currRoad != 0){
                    shortestRoad += currRoad;
                    road.setChecked(true);
                }
            }
        }
        return shortestRoad;
    }
}
