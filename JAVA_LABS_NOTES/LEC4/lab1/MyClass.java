
import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.Toolkit;

public class MyClass extends Applet {

public String[] s;
    public void init(){

         Toolkit t_1 = Toolkit.getDefaultToolkit();
        s = t_1.getFontList();
    } 

    public void paint(Graphics g) {

        for (int i = 0; i < s.length; i++) {
            Font myFont = new Font(s[i], Font.BOLD, 24);
            g.setFont(myFont);
            g.drawString(s[i], 50, 50 + (i * 50));
        }

    }

}
