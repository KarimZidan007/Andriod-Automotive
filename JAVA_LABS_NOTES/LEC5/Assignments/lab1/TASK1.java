import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.lang.Thread;
import java.lang.InterruptedException;

public class TASK1 extends Applet
{

     public void paint(Graphics g) {
        Date date_obj = new Date();
        g.drawString(date_obj.toString(),100,175);
        
    }
}

public class Thready extends Thread implements Runnable
{

    public void init()
    {

    Thread threadOne = new Thread(this);
        threadOne.start();

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

