import java.applet.Applet;
import java.awt.Graphics;
import java.util.ArrayList;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseListener;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Button;
import java.awt.Color;

enum Shapes_state {
    OVAL,
    RECTANGLE,
    LINE,
};

enum DrawingModes {
    DRAW,
    FREEHAND,
    ERASEALL,
    ERASEOBJ,

}

public class Painter extends Applet {

    public ArrayList<Shape> Shapes = new ArrayList<>(5); // array list initially hold 5 references to obj from type
                                                         // shapes

    public static Current_State StateObj; // obj hold the current user choices

    public void paint(Graphics g) {

        for (int i = 0; i < Shapes.size(); i++) {
            Shapes.get(i).draw(g);

        }

    }

    public void init() {
        StateObj = new Current_State();
        Button buttonOne = new Button("Red Color");
        Button buttonTwo = new Button("Green Color");
        Button buttonThree = new Button("Blue Color");
        Button buttonFour = new Button("Fill Mode");
        Button buttonFive = new Button("Draw Oval"); // STATE
        Button buttonSix = new Button("Draw Rectangle");
        Button buttonSeven = new Button("Draw Line");
        Button buttonEight = new Button("Free Hand Mode");
        Button buttonNine = new Button("Erase All");
        Button buttonTen = new Button("Free Hand Erase ");
        Button buttonEleven = new Button("Undo");
        add(buttonOne);
        add(buttonTwo);
        add(buttonThree);
        add(buttonFour);
        add(buttonFive);
        add(buttonSix);
        add(buttonSeven);
        add(buttonEight);
        add(buttonNine);
        add(buttonTen);
        add(buttonEleven);
        // at the end i will listen on another thread
        buttonOne.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Painter.StateObj.color = Color.RED;
                repaint();
            }
        });
        buttonTwo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Painter.StateObj.color = Color.GREEN;
                repaint();
            }
        });

        buttonThree.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Painter.StateObj.color = Color.BLUE;
                repaint();
            }
        });
        buttonFour.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Painter.StateObj.fillState = !Painter.StateObj.fillState;
                repaint();
            }
        });
        buttonFive.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.DRAW;
                StateObj.SHAPE_TYPE = Shapes_state.OVAL;
                repaint();
            }
        });
        buttonSix.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.DRAW;
                StateObj.SHAPE_TYPE = Shapes_state.RECTANGLE;
                repaint();
            }
        });
        buttonSeven.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.DRAW;
                StateObj.SHAPE_TYPE = Shapes_state.LINE;
                repaint();
            }
        });
        buttonEight.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.FREEHAND;
            }
        });
        buttonNine.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.ERASEALL;
                Shapes.clear();
                StateObj.shapesNumber = 0;
                StateObj.Current_Mode = DrawingModes.DRAW;
                repaint();
            }
        });
        buttonTen.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.ERASEOBJ;

            }
        });
        buttonEleven.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Shapes.remove(StateObj.shapesNumber - 1);
                StateObj.shapesNumber--;
                repaint();
            }
        });

        Mouse_Listen MouseEve = new Mouse_Listen();
        Painter.this.addMouseListener(MouseEve);
        Painter.this.addMouseMotionListener(MouseEve);

    }

    class Mouse_Listen extends MouseAdapter {

        public void mousePressed(MouseEvent e) {

            switch (StateObj.Current_Mode) {

                case DRAW:
                    switch (StateObj.SHAPE_TYPE) {

                        case RECTANGLE:
                            Shapes.add(new Rectangle(StateObj, e.getX(), e.getY(), 0, 0));
                            repaint();
                            break;
                        case LINE:
                            Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX(), e.getY()));
                            repaint();
                            break;
                        case OVAL:
                            Shapes.add(new Oval(StateObj, e.getX(), e.getY(), 0, 0));
                            repaint();
                            break;
                        default:
                            break;

                    }
                    break;

                case FREEHAND:
                    Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX(), e.getY()));
                    StateObj.shapesNumber++;
                    repaint();
                    break;

                case ERASEOBJ:

                    for (int i = 0; i < Shapes.size(); i++) {
                        boolean state = false;
                        state = Shapes.get(i).checkSelection(e.getX(), e.getY());
                        if (state == true) {
                            Shapes.remove(i);
                            StateObj.shapesNumber--;
                            repaint();
                            break;

                        } else {

                        }
                    }

            }

        }

        public void mouseReleased(MouseEvent e) {

            switch (StateObj.Current_Mode) {

                case DRAW:
                    switch (StateObj.SHAPE_TYPE) {

                        case RECTANGLE:
                            Shapes.get(StateObj.shapesNumber).setSize(e.getX(), e.getY());
                            StateObj.shapesNumber++;
                            repaint();
                            break;
                        case LINE:
                            Shapes.get(StateObj.shapesNumber).setSize(e.getX(), e.getY());
                            StateObj.shapesNumber++;
                            repaint();
                            break;
                        case OVAL:
                            Shapes.get(StateObj.shapesNumber).setSize(e.getX(), e.getY());
                            StateObj.shapesNumber++;
                            repaint();
                            break;
                        default:
                            break;
                    }
                    break;

                case FREEHAND:
                    Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX(), e.getY()));
                    StateObj.shapesNumber++;
                    repaint();
                    break;

            }
        }

        public void mouseDragged(MouseEvent e) {
            switch (StateObj.Current_Mode) {

                case DRAW:
                    switch (StateObj.SHAPE_TYPE) {
                        case RECTANGLE:
                            Shapes.get(StateObj.shapesNumber).setSize(e.getX(), e.getY());
                            repaint();
                            break;
                        case LINE:
                            Shapes.get(StateObj.shapesNumber).setSize(e.getX(), e.getY());
                            repaint();
                            break;
                        case OVAL:
                            Shapes.get(StateObj.shapesNumber).setSize(e.getX(), e.getY());
                            repaint();
                            break;
                        default:
                            break;
                    }
                    break;

                case FREEHAND:
                    Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX(), e.getY()));
                    StateObj.shapesNumber++;
                    repaint();
                    break;
            }
        }
    }
}

class Current_State {
    DrawingModes Current_Mode = DrawingModes.DRAW;
    Color color = Color.BLACK;
    boolean fillState = true;
    Shapes_state SHAPE_TYPE = Shapes_state.LINE;
    int shapesNumber = 0;
}

abstract class Shape {

    public Current_State ShapeState;

    public abstract void draw(Graphics g);

    public abstract void setSize(int x2, int y2);

    public abstract boolean checkSelection(int x, int y);

}

class Oval extends Shape {

    private int width = 0;
    private int height = 0;
    private int x = 0;
    private int y = 0;

    Oval(Current_State state, int x, int y, int width, int height) {
        ShapeState = new Current_State();
        ShapeState.color = state.color;
        ShapeState.fillState = state.fillState;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public void setSize(int x2, int y2) {
        this.width = x2 - this.x;
        this.height = y2 - this.y;
    }

    public boolean checkSelection(int x, int y) {

        if ((this.x <= x && x <= (this.x + this.width)) && (this.y <= y && y <= (this.y + this.height))) {
            return true;
        } else {
            return false;
        }

    }

    public void draw(Graphics g) {
        if (ShapeState.fillState == true) {
            g.setColor(ShapeState.color);
            g.fillOval(x, y, width, height);
        } else {
            g.drawOval(x, y, width, height);
        }
    }
}

class Line extends Shape {

    private int x = 0;
    private int y = 0;
    private int x2 = 0;
    private int y2 = 0;

    Line(Current_State state, int x, int y, int x2, int y2) {
        ShapeState = new Current_State();
        ShapeState.color = state.color;
        ShapeState.fillState = state.fillState;
        this.x = x;
        this.y = y;
        this.y2 = y2;
        this.x2 = x2;

    }

    public boolean checkSelection(int x, int y) {

        if ((this.x <= x && x <= x2) && (this.y <= y && y <= this.y2)) {
            return true;
        } else {
            return false;
        }

    }

    public void setSize(int x2, int y2) {
        this.x2 = x2;
        this.y2 = y2;
    }

    public void draw(Graphics g) {
        g.setColor(ShapeState.color);
        g.drawLine(x, y, x2, y2);

    }
}

class Rectangle extends Shape {

    private int x = 0;
    private int y = 0;
    private int width = 0;
    private int height = 0;

    Rectangle(Current_State state, int x, int y, int width, int height) {
        ShapeState = new Current_State();
        ShapeState.color = state.color;
        ShapeState.fillState = state.fillState;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public void setSize(int x2, int y2) {

        this.width = x2 - this.x;
        this.height = y2 - this.y;
    }

    public boolean checkSelection(int x, int y) {

        if ((this.x <= x && x <= (this.x + this.width)) && (this.y <= y && y <= (this.y + this.height))) {
            return true;
        } else {
            return false;
        }

    }

    public void draw(Graphics g) {
        if (ShapeState.fillState == true) {
            g.setColor(ShapeState.color);
            g.fillRect(x, y, width, height);
        } else {
            g.drawRect(x, y, width, height);
        }
    }
}
