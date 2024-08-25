import java.applet.Applet;
import java.awt.Button;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Graphics;

//	addActionListener(ActionListener l)
public class Buttons extends Applet {
    private int counter;
    private Button IncButton;
    private Button DecButton;

    public void init() {
        counter = 0;
        IncButton = new Button("+");
        DecButton = new Button("-");
        add(IncButton);
        add(DecButton);

        Thread Thread_one = new Thread(new Runnable() {
            public void run() {
                DecButton.addActionListener(new ActionsDec());
                IncButton.addActionListener(new ActionsInc());
            }
        });



        Thread_one.start();


    }

    public void paint(Graphics g) {
        g.drawString("" + counter, getWidth() / 2, getHeight() / 2);

    }

    class ActionsInc implements ActionListener {
        public void actionPerformed(ActionEvent e) {

            counter++;
            repaint();

        }
    }

    class ActionsDec implements ActionListener {
        public void actionPerformed(ActionEvent e) {

            counter--;
            repaint();

        }
    }

}
