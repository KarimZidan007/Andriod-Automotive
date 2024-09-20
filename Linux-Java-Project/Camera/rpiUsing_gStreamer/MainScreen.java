/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gstreamer;

import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author karim
 */
 class MainScreen {
    public static JFrame frame;
    
    public static JPanel panel_video;

    static {
        frame = new JFrame("Main Screen");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        frame.setLayout(new BorderLayout());
        
        panel_video = new JPanel();
        panel_video.setLayout(new BorderLayout()); 
        
        frame.add(panel_video, BorderLayout.CENTER);
        
        frame.setVisible(true);
    }
 }