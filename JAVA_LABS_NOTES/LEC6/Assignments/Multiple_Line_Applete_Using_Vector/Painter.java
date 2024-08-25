import java.applet.Applet;
import java.awt.Graphics;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.util.Vector;

public class Painter extends Applet {
    public int curr_Line = 0;

    Vector<Line> Lines = new Vector<>(3);

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
    }

    public void paint(Graphics g) {
        for (int i = 0; i < Lines.size(); i++) {
            if ((Lines.elementAt(i).states) == 1) {
                g.drawLine((Lines.elementAt(i).pressed_X), Lines.elementAt(i).pressed_Y, Lines.elementAt(i).temp_X,
                        Lines.elementAt(i).temp_Y);
            } else if (Lines.elementAt(i).states == 2) {
                g.drawLine(Lines.elementAt(i).pressed_X, Lines.elementAt(i).pressed_Y, Lines.elementAt(i).released_X,
                        Lines.elementAt(i).released_Y);
            }
        }
    }

    public class Mouse_Listen extends MouseAdapter {

        public void mousePressed(MouseEvent e) {
            Lines.add(new Line());

            Lines.elementAt(curr_Line).pressed_X = e.getX();
            Lines.elementAt(curr_Line).pressed_Y = e.getY();

            repaint();
        }

        public void mouseDragged(MouseEvent e) {
            Lines.elementAt(curr_Line).temp_X = e.getX();
            Lines.elementAt(curr_Line).temp_Y = e.getY();
            Lines.elementAt(curr_Line).states = 1;
            repaint();
        }

        public void mouseReleased(MouseEvent e) {
            Lines.elementAt(curr_Line).released_X = e.getX();
            Lines.elementAt(curr_Line).released_Y = e.getY();
            Lines.elementAt(curr_Line).states = 2;
            curr_Line++;
            repaint();
        }
    }
}
