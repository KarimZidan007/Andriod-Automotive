import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.lang.Thread;
import java.lang.InterruptedException;


public class Thready extends Applet implements Runnable
{

    public void init()
    {

        Thread threadOne = new Thread(this);
        threadOne.start();

    }
     public void paint(Graphics g) {
        Date date_obj = new Date();
        g.drawString(date_obj.toString(),getWidth()/3,getWidth()/3); 
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

