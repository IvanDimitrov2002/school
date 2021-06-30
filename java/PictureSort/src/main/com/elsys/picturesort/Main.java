package main.com.elsys.picturesort;

import org.json.simple.parser.ParseException;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws ParseException, InterruptedException, IOException {
        ImageClient cl = new ImageClient("http://3.126.121.194:3000/api/image");
        ImageData id = cl.requestImage();
        Data processedData = new Data(id.data);
        System.out.println(processedData.getImagePixels().get(0));
        cl.sendImage(id);
    }
}
