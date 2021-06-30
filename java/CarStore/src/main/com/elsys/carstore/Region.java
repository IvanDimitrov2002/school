package main.com.elsys.carstore;

public enum Region {
    SOFIA, BURGAS, VARNA, PLOVDIV, RUSE, GABROVO, VIDIN, VRATSA;

    public static String getPrefix(Region region){
        switch(region){
            case SOFIA:
                return "CB";

            case BURGAS:
                return "A";

            case VARNA:
                return "B";

            case PLOVDIV:
                return "PB";

            case RUSE:
                return "P";

            case GABROVO:
                return "EB";

            case VIDIN:
                return "BH";

            case VRATSA:
                return "BP";
        }
        return null;
    }
}
