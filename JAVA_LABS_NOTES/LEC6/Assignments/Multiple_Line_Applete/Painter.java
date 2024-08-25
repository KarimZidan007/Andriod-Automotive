import java.applet.Applet;
import java.awt.Graphics;

import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;

import java.awt.event.MouseAdapter;

public class Painter extends Applet {
    public int curr_Line = 0;
    Line[] Lines;

    class Line {
        int pressed_X = 0;
        int pressed_Y = 0;

        int released_X = 0;
        int released_Y = 0;

        int temp_X = 0;
        int temp_Y = 0;

        boolean mouseDragged = false;

        int states = 0;

        void reset() {
            pressed_X = 0;
            pressed_Y = 0;
            temp_X = 0;
            temp_Y = 0;
            released_X = 0;
            released_Y = 0;
            states = 0;
        }
    }

    public void init() {
        Mouse_Listen mouse_one = new Mouse_Listen();
        this.addMouseMotionListener(mouse_one);
        this.addMouseListener(mouse_one);
        Lines = new Line[3];
        for (int i = 0; i < 3; i++) {
            Lines[i] = new Line();
        }
    }

    public void paint(Graphics g) {
        for (int i = 0; i <= curr_Line; i++) {
            if (Lines[i].states == 1) {
                g.drawLine(Lines[i].pressed_X, Lines[i].pressed_Y, Lines[i].temp_X, Lines[i].temp_Y);
            } else if (Lines[i].states == 2) {
                g.drawLine(Lines[i].pressed_X, Lines[i].pressed_Y, Lines[i].released_X, Lines[i].released_Y);
            }
        }
    }

    public class Mouse_Listen extends MouseAdapter {

        public void mousePressed(MouseEvent e) {
            Lines[curr_Line].pressed_X = e.getX();
            Lines[curr_Line].pressed_Y = e.getY();
            repaint();
        }

        public void mouseDragged(MouseEvent e) {
            Lines[curr_Line].temp_X = e.getX();
            Lines[curr_Line].temp_Y = e.getY();
            Lines[curr_Line].states = 1;
            repaint();
        }

        public void mouseReleased(MouseEvent e) {
            Lines[curr_Line].released_X = e.getX();
            Lines[curr_Line].released_Y = e.getY();
            Lines[curr_Line].states = 2;
            if (curr_Line < 2) {
                curr_Line++;
                Lines[curr_Line].reset();
            } else {
                curr_Line = 0;
                Lines[curr_Line].reset();
            }
            repaint();
        }
    }
}
