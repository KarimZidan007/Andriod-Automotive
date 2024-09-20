package gstreamer;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import org.freedesktop.gstreamer.Gst;
import org.freedesktop.gstreamer.Pipeline;
import org.freedesktop.gstreamer.Version;
import org.freedesktop.gstreamer.elements.AppSink;
import org.freedesktop.gstreamer.swing.GstVideoComponent;
import javafx.scene.Camera;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;

public class GStreamer extends Application {
    private Pipeline pipeline;
    private ImageView imageView;

    @Override
    public void start(Stage primaryStage) {

        Gst.init(Version.BASELINE, "BasicPipeline");


        pipeline = (Pipeline) Gst.parseLaunch("v4l2src device=/dev/video0 ! videoconvert ! appsink name=sink");

        AppSink sink = (AppSink) pipeline.getElementByName("sink");

        GstVideoComponent vc = new GstVideoComponent(sink);
        vc.setSize(600, 560);
        vc.setVisible(true);

        MainScreen.panel_video.add(vc);

        pipeline.play();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
