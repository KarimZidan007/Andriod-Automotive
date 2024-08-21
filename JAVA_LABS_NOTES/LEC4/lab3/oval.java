
import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.Color;

//	drawArc(int x, int y, int width, int height, int startAngle, int arcAngle)

//	drawLine(int x1, int y1, int x2, int y2)

//drawOval(int x, int y, int width, int height)

//fillOval(int x, int y, int width, int height)
public class oval extends Applet {

    public void paint(Graphics g) {

        // Draw the arc

        g.drawLine(120, 250, 160, 150);
        g.drawLine(280, 250, 240, 150);
        g.drawArc(120, 200, 160, 100, -180, 180);
        g.drawRect(140, 350, 120, 20);
        g.drawLine(240, 350, 210, 300);
        g.drawLine(160, 350, 190, 300);
        g.setColor(Color.YELLOW);
        g.fillOval(160, 137, 80, 20);
        g.fillOval(180, 170, 40, 80);
        g.fillOval(150, 190, 20, 40);
        g.fillOval(235, 190, 20, 40);
    }

}
