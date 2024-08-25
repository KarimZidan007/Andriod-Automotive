import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.lang.Thread;
import java.lang.InterruptedException;
import java.awt.Color;
import java.awt.Button;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Thready extends Applet implements Runnable
{
private boolean Direction_x=true;
private boolean Direction_y=true;
private int x_Pos =0;
private int y_Pos=0;
private boolean start_resume_flag=false;
private Button StartButton;
private Button StopButton;
private  Thread threadOne;
    public void init()
    {
        StartButton = new Button("Start");
        StopButton = new Button("Stop");
        add(StartButton);
        add(StopButton);

        threadOne = new Thread(this);
        Thread ThreadTwo = new Thread(new Runnable() {
            public void run() {
                StartButton.addActionListener(new ActionsStart());
                StopButton.addActionListener(new ActionsStop());
            }
        });
      
          ThreadTwo.start();

    }
     public void paint(Graphics g) {

        g.setColor(Color.RED);
        g.fillOval(x_Pos,y_Pos,25,25);

        if((Direction_x==true)&&(x_Pos>=getWidth()))
          {
                    Direction_x=false;

          }
          else if((Direction_x==false)&&(x_Pos<=0))
            {

                    Direction_x=true;

            }
           if(Direction_x==true)
            {
                x_Pos++;

            }
            else
            {
                x_Pos--;

            }



        if((Direction_y==true)&&(y_Pos>=getHeight()))
          {
                    Direction_y=false;

          }
          else if((Direction_y==false)&&(y_Pos<=0))
            {

                    Direction_y=true;

            }
           if(Direction_y==true)
            {
                y_Pos++;

            }
            else
            {
                y_Pos--;

            }
     }

    public void run()
    {
        while(true)
        {
            try{
            Thread.sleep(2);   
            repaint();
            }
            catch(InterruptedException ie)
            {
                ie.printStackTrace();
            }

        }
    }

    class ActionsStart implements ActionListener {
        public void actionPerformed(ActionEvent e) {

            if(false==start_resume_flag)
            {
                threadOne.start();
                start_resume_flag=true;
            }
            else
            {
            threadOne.resume();

            }
            repaint();

        }
    }

    class ActionsStop implements ActionListener {
        public void actionPerformed(ActionEvent e) {

            threadOne.suspend();
            repaint();

        }
    }




}

