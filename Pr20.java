import java.awt.*;
import java.applet.*;
import java.awt.event.*;

//<applet code="Pr20" width=300 height=200></applet>

public class Pr20 extends Applet implements ActionListener
{
	String S = "";
	
	public void init()
	{
		setBackground(Color.RED);
		setForeground(Color.YELLOW);
		Button yes = new Button("yes");
		Button no = new Button("no");
		Button hello = new Button("hello");
		
		add(yes);
		add(no);
		add(hello);
		
		yes.addActionListener(this);
		no.addActionListener(this);
		hello.addActionListener(this);
	}
	
	public void actionPerformed (ActionEvent E)
	{
		String s = E.getActionCommand();
		
		if (s.equals("yes"))
			S = "You pressed yes";
		
		else if (s.equals"no")
			S = "You pressed no";
		
		else
			S = "You pressed hello";
			
		repaint();
	}
	
	public void paint(Graphics G)
	{
		G.drawString(S, 10, 100);
	}
}
