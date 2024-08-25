import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;

public class DRAGBALL extends Applet {

    private int oval_X, oval_Y;

    public void init() {
        this.addMouseMotionListener(new MouseAdapter() {
            public void mouseDragged(MouseEvent e) {
                oval_X = e.getX();
                oval_Y = e.getY();
                repaint();
            }
        });
    }

    public void paint(Graphics g) {
        g.setColor(Color.MAGENTA);
        g.fillOval(oval_X, oval_Y, 100, 100);
    }

}