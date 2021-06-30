package main.com.elsys.Angryman;

import javax.imageio.ImageIO;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedImage image  = ImageIO.read(new File("img/input.png"));
        Tracing trace = new Tracing();
        trace.GetBoundary(image);
        AffineTransform tx = new AffineTransform();
        tx.rotate(Math.PI, image.getWidth()/2, image.getHeight()/2);
        AffineTransformOp op = new AffineTransformOp(tx, AffineTransformOp.TYPE_BILINEAR);
        image = op.filter(image, null);
        trace.GetBoundary(image);
        image = op.filter(image, null);
        File file = new File("img/output.png");
        ImageIO.write(image, "png", file);
    }
}
