import java.applet.Applet;
import java.awt.Graphics;

import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;

import java.awt.event.MouseAdapter;

public class Line extends Applet {
    private int pressed_X = 0;
    private int pressed_Y = 0;

    private int released_X = 0;
    private int released_Y = 0;

    private int temp_X = 0;
    private int temp_Y = 0;

    private boolean states = false;

    public void init() {
        Mouse_Listen mouse_one = new Mouse_Listen();
        this.addMouseMotionListener(mouse_one);
        this.addMouseListener(mouse_one);
    }

    public void paint(Graphics g) {
        if (states == false) {
            g.drawLine(pressed_X, pressed_Y, temp_X, temp_Y);
        } else if (states == true) {
            g.drawLine(pressed_X, pressed_Y, released_X, released_Y);
        }
    }

    public class Mouse_Listen extends MouseAdapter {

        public void mousePressed(MouseEvent e) {
            pressed_X = e.getX();
            pressed_Y = e.getY();
            states = false;
            repaint();
        }

        public void mouseDragged(MouseEvent e) {
            temp_X = e.getX();
            temp_Y = e.getY();
            repaint();
        }

        public void mouseReleased(MouseEvent e) {
            released_X = e.getX();
            released_Y = e.getY();
            states = true;
            repaint();
        }
    }
}
