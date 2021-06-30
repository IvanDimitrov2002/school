package main.java.com.collections;

import java.util.*;

public class Main {
    static void printList(Iterable list) {
        Iterator iter = list.iterator();
        while(iter.hasNext()) {
            System.out.println(iter.next());
        }
    }

    public static void main(String[] args) {
        List<Temple> arrayTemples = new ArrayList<Temple>();
        List<Temple> listTemples = new LinkedList<Temple>();
        Set<Temple> hashSetTemples = new HashSet<Temple>();
        Set<Temple> treeSetTemples = new TreeSet<Temple>();
        Map<String, Temple> hashMapTemples = new HashMap<String, Temple>();
        Map<String, Temple> treeMapTemples = new TreeMap<String, Temple>();

        arrayTemples.add(new Temple("Test", "Christian", 5, true));
        listTemples.add(new Temple("Test", "Christian", 5, true));

    }
}
