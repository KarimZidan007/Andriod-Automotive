import java.applet.Applet;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyAdapter;

public class MVTEXT extends Applet {

    private int x = 100;
    private int y = 100;

    public void init() {
        KEYS_ONE key_UP = new KEYS_ONE();

        this.addKeyListener(key_UP);

    }

    public void paint(Graphics g) {

        g.drawString("ZIDAN", x, y);
    }

    class KEYS_ONE extends KeyAdapter {

        public void keyPressed(KeyEvent var1) {

            int keyCode_temp = var1.getKeyCode();

            if ((keyCode_temp == var1.VK_UP) || ((keyCode_temp == var1.VK_W))) {
                y -= 20;
                repaint();
            } else if ((keyCode_temp == var1.VK_DOWN) || ((keyCode_temp == var1.VK_S))) {
                y += 20;
                repaint();
            } else if ((keyCode_temp == var1.VK_LEFT) || ((keyCode_temp == var1.VK_A))) {
                x -= 20;
                repaint();
            } else if ((keyCode_temp == var1.VK_RIGHT) || ((keyCode_temp == var1.VK_D))) {
                x += 20;
                repaint();
            }

        }

    }

}
