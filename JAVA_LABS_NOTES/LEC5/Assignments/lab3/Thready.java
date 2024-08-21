import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.lang.Thread;
import java.lang.InterruptedException;
import java.awt.Color;


public class Thready extends Applet implements Runnable
{
private boolean Direction_x=true;
private boolean Direction_y=false;
private int x_Pos =0;
private int y_Pos=0;

    public void init()
    {

        Thread threadOne = new Thread(this);
        threadOne.start();

    }
     public void paint(Graphics g) {

        g.setColor(Color.RED);
        g.fillOval(x_Pos,y_Pos,25,25);

        if(false==Direction_x)
          {
              if(x_Pos<(getWidth())-25)
                {
                    x_Pos+=20;     
                }
                else
                {
                    y_Pos-=20;
                    Direction=true;
                }

           }
            else if(Direction_x==true)
            {
              if((x_Pos>25))
                {
                    x_Pos-=20;
                }
                else
                {
                    y_Pos+=20;
                    Direction=false;
                }
            }
              if(y_Pos>25)
                {
                y_Pos-=20;
                }
                else
                {
                    x_Pos+=20;
                    Direction=0;
                }

              }
              if(y_Pos<(getHeight()-25))
                {
                y_Pos+=20;
                }
                else
                {
                    x_Pos+=20;
                    Direction=1;
                }



}
    public void run()
    {
        while(true)
        {
            try{
            Thread.sleep(250);   
            repaint();
            }
            catch(InterruptedException ie)
            {
                ie.printStackTrace();
            }

        }
    }

}

