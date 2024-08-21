import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.lang.Thread;
import java.lang.InterruptedException;


public class Thready extends Applet implements Runnable
{
    private int x_Pos=0;

    public void init()
    {

        Thread threadOne = new Thread(this);
        threadOne.start();

    }
     public void paint(Graphics g) {

        g.drawString("HELLO JAVA",x_Pos,getWidth()/3); 
        if(x_Pos<getWidth())
        {
            x_Pos+=20;

        }
        else
        {
            x_Pos=0;
        }
    }

    public void run()
    {
        while(true)
        {
            try{
            Thread.sleep(1000);   
            repaint();
            }
            catch(InterruptedException ie)
            {
                ie.printStackTrace();
            }

        }
    }

}

