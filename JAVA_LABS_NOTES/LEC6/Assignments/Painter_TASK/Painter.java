import java.applet.Applet;
import java.awt.Graphics;
import java.util.ArrayList;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseListener;
import java.awt.event.ActionListener;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import java.awt.event.ActionEvent;
import java.awt.Button; 
import java.awt.Color;
import java.awt.Checkbox;
import java.awt.GridLayout;
import java.awt.Graphics2D;
import java.awt.BasicStroke;

enum Shapes_state {
    OVAL,
    RECTANGLE,
    LINE,
};

enum DrawingModes {
    DRAW,
    PENCIL,
    ERASEALL,
    ERASEOBJ,
    PENCILERASE,

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
        Button buttonFive = new Button("Oval"); // STATE
        Button buttonSix = new Button("Rectangle");
        Button buttonSeven = new Button("Line");
        Button buttonEight = new Button("Pencil");
        Button buttonNine = new Button("Clear");
        Button buttonTen = new Button("Erase Object");
        Button buttonEleven = new Button("Undo");
        Button buttonTwelve = new Button("Eraser");
        Button buttonThirteen = new Button("+");
        Button buttonFourteen = new Button("-");
        // check boxes
        Checkbox ObjectFour = new Checkbox("Solid");
        Checkbox ObjectFive = new Checkbox("Dotted");
        // add them into UI
        setBackground(Color.WHITE);
        buttonOne.setBackground(Color.RED);
        add(buttonOne);
        buttonOne.setForeground(Color.WHITE);

        buttonTwo.setBackground(Color.GREEN);
        add(buttonTwo);
        buttonTwo.setForeground(Color.WHITE);

        buttonThree.setBackground(Color.BLUE);
        add(buttonThree);
        buttonThree.setForeground(Color.WHITE);

        buttonFour.setBackground(Color.BLACK);
        add(buttonFour);
        buttonFour.setForeground(Color.WHITE);

        add(buttonFive);
        add(buttonSix);
        add(buttonSeven);
        add(buttonEight);
        add(buttonNine);
        add(buttonTen);
        add(buttonEleven);
        add(buttonTwelve);
        add(buttonThirteen);
        add(buttonFourteen);
        add(ObjectFour);
        add(ObjectFive);

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

        ObjectFour.addItemListener(new ItemListener() { // solid
            public void itemStateChanged(ItemEvent e) {
                StateObj.SOLID = true;

                repaint();
            }
        });
        ObjectFive.addItemListener(new ItemListener() { // dotted
            public void itemStateChanged(ItemEvent e) {
                StateObj.SOLID = false;

                repaint();
            }
        });
        buttonFive.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.DRAW;
                StateObj.SHAPE_TYPE = Shapes_state.OVAL;
                Painter.StateObj.color = Color.BLACK;

                repaint();
            }
        });
        buttonSix.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.DRAW;
                StateObj.SHAPE_TYPE = Shapes_state.RECTANGLE;
                Painter.StateObj.color = Color.BLACK;

                repaint();
            }
        });
        buttonSeven.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.Current_Mode = DrawingModes.DRAW;
                StateObj.SHAPE_TYPE = Shapes_state.LINE;
                Painter.StateObj.color = Color.BLACK;

                repaint();
            }
        });
        buttonEight.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.fillState = true;
                Painter.StateObj.color = Color.BLACK;
                StateObj.Current_Mode = DrawingModes.PENCIL;

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
        buttonTwelve.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                StateObj.fillState = true;
                StateObj.Current_Mode = DrawingModes.PENCILERASE;
                StateObj.color = Color.WHITE;

            }
        });
        buttonThirteen.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (StateObj.PENCILSIZE < 27)
                    StateObj.PENCILSIZE += 3;
            }
        });
        buttonThirteen.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (StateObj.PENCILSIZE < 27)
                    StateObj.PENCILSIZE += 3;
            }
        });

        buttonFourteen.addActionListener(e -> {
            if (StateObj.PENCILSIZE > 3)
                StateObj.PENCILSIZE -= 3;
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

                case PENCIL:
                    if (StateObj.SOLID == true) {
                        Shapes.add(new Oval(StateObj, e.getX(), e.getY(), StateObj.PENCILSIZE, StateObj.PENCILSIZE));
                    } else if (StateObj.SOLID == false) {
                        Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX() + 1, e.getY() + 1));
                    }
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
                    break;
                case PENCILERASE:
                    Shapes.add(new Rectangle(StateObj, e.getX(), e.getY(), StateObj.PENCILSIZE, StateObj.PENCILSIZE));
                    StateObj.shapesNumber++;
                    repaint();
                    break;
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

                case PENCIL:
                    if (StateObj.SOLID == true) {
                        Shapes.add(new Oval(StateObj, e.getX(), e.getY(), StateObj.PENCILSIZE, StateObj.PENCILSIZE));
                    } else if (StateObj.SOLID == false) {
                        Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX() + 1, e.getY() + 1));
                    }
                    StateObj.shapesNumber++;
                    repaint();
                    break;

                case PENCILERASE:
                    Shapes.add(new Rectangle(StateObj, e.getX(), e.getY(), StateObj.PENCILSIZE, StateObj.PENCILSIZE));
                    StateObj.shapesNumber++;
                    repaint();
                    break;
                default:
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

                case PENCIL:
                    if (StateObj.SOLID == true) {
                        Shapes.add(new Oval(StateObj, e.getX(), e.getY(), StateObj.PENCILSIZE, StateObj.PENCILSIZE));

                    } else if (StateObj.SOLID == false) {
                        Shapes.add(new Line(StateObj, e.getX(), e.getY(), e.getX() + 1, e.getY() + 1));

                    }
                    StateObj.shapesNumber++;
                    repaint();
                    break;
                case PENCILERASE:
                    Shapes.add(new Rectangle(StateObj, e.getX(), e.getY(), StateObj.PENCILSIZE, StateObj.PENCILSIZE));
                    StateObj.shapesNumber++;
                    repaint();
                    break;
                default:
                    break;
            }
        }
    }
}

class Current_State {
    DrawingModes Current_Mode = DrawingModes.DRAW;
    Color color = Color.BLACK;
    boolean fillState = false;
    Shapes_state SHAPE_TYPE = Shapes_state.LINE;
    int shapesNumber = 0;
    boolean SOLID = true;
    int PENCILSIZE = 5;
}

abstract class Shape {

    protected int x = 0;
    protected int y = 0;
    public Current_State ShapeState;

    public abstract void draw(Graphics g);

    public abstract void setSize(int x2, int y2);

    public abstract boolean checkSelection(int x, int y);

}

class Oval extends Shape {

    private int width = 0;
    private int height = 0;
    private int minX = x;
    private int minY = y;

    Oval(Current_State state, int x, int y, int width, int height) {
        ShapeState = new Current_State();
        ShapeState.color = state.color;
        ShapeState.fillState = state.fillState;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        ShapeState.SOLID = state.SOLID;
        minX = x;
        minY = y;
    }

    public void setSize(int x2, int y2) {
        minX = Math.min(x2, x);
        minY = Math.min(y2, y);

        this.width = Math.abs(x2 - x);

        this.height = Math.abs(y2 - y);

    }

    public boolean checkSelection(int x, int y) {

        if ((this.x <= x && x <= (this.x + this.width)) && (this.y <= y && y <= (this.y + this.height))) {
            return true;
        } else {
            return false;
        }

    }

    public void draw(Graphics g) {

        if (ShapeState.SOLID == true) {
            if (ShapeState.fillState == true) {
                g.setColor(ShapeState.color);
                g.fillOval(minX, minY, width, height);
            } else {
                g.drawOval(minX, minY, width, height);
            }
        } else if (ShapeState.SOLID == false) {
            Graphics2D g2d = (Graphics2D) g;
            g2d.setColor(ShapeState.color);
            g2d.setStroke(new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[] { 5, 5 }, 0));
            g2d.drawOval(minX, minY, width, height);
            g2d.setStroke(new BasicStroke(1));
        } else {
        }

    }
}

class Line extends Shape {

    private int x2 = 0;
    private int y2 = 0;

    Line(Current_State state, int x, int y, int x2, int y2) {
        ShapeState = new Current_State();
        ShapeState.color = state.color;
        ShapeState.fillState = state.fillState;
        ShapeState.SOLID = state.SOLID;

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
        if (ShapeState.SOLID == true) {
            g.setColor(ShapeState.color);
            g.drawLine(x, y, x2, y2);
        } else if (ShapeState.SOLID == false) {
            Graphics2D g2d = (Graphics2D) g;
            g2d.setColor(ShapeState.color);
            g2d.setStroke(
                    new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[] { 5, 5 }, 0));
            g2d.drawLine(x, y, x2, y2);
            g2d.setStroke(new BasicStroke(1));
        }

    }
}

class Rectangle extends Shape {

    private int width = 0;
    private int height = 0;
    private int minX;
    private int minY;

    Rectangle(Current_State state, int x, int y, int width, int height) {
        ShapeState = new Current_State();
        ShapeState.color = state.color;
        ShapeState.fillState = state.fillState;
        ShapeState.SOLID = state.SOLID;

        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        minX = x;
        minY = y;
    }

    public void setSize(int x2, int y2) {

        minX = Math.min(x2, x);
        minY = Math.min(y2, y);

        this.width = Math.abs(x2 - x);

        this.height = Math.abs(y2 - y);

    }

    public boolean checkSelection(int x, int y) {

        if ((this.x <= x && x <= (this.x + this.width)) && (this.y <= y && y <= (this.y + this.height))) {
            return true;
        } else {
            return false;
        }

    }

    public void draw(Graphics g) {
        if (ShapeState.SOLID == true) {
            if (ShapeState.fillState == true) {
                g.setColor(ShapeState.color);
                g.fillRect(minX, minY, width, height);
            } else {
                g.drawRect(minX, minY, width, height);
            }
        } else if (ShapeState.SOLID == false) {
            Graphics2D g2d = (Graphics2D) g;
            g2d.setColor(ShapeState.color);
            g2d.setStroke(new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[] { 5, 5 }, 0));
            g2d.drawRect(minX, minY, width, height);

            g2d.setStroke(new BasicStroke(1));
        } else {
        }

    }
}
