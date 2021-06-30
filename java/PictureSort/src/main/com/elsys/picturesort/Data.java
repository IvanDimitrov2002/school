package main.com.elsys.picturesort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Data {
    private ArrayList<ArrayList<Integer>> imagePixels = new ArrayList<>();
    private ArrayList<ArrayList<Integer>> mask = new ArrayList<>();

    public Data(List data) {
        for(int i = 0; i < data.size(); i += 4){
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            for(int j = 0; j < 4; j++){
                tmp.add(Integer.parseInt(data.get(i+j).toString()));
            }
            imagePixels.add(tmp);
        }
        mask.add(new ArrayList<Integer>(Arrays.asList(0, -1,  0)));
        mask.add(new ArrayList<Integer>(Arrays.asList(-1,  4, -1)));
        mask.add(new ArrayList<Integer>(Arrays.asList(0, -1,  0)));
    }

    public ArrayList<ArrayList<Integer>> getImagePixels() {
        return imagePixels;
    }

    public void setImagePixels(ArrayList<ArrayList<Integer>> imagePixels) {
        this.imagePixels = imagePixels;
    }

    public ArrayList<ArrayList<Integer>> getMask() {
        return mask;
    }

    public void setMask(ArrayList<ArrayList<Integer>> mask) {
        this.mask = mask;
    }
}
