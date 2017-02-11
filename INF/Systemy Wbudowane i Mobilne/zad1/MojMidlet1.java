import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.TextBox;
import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;

public class MojMidlet1 extends MIDlet implements CommandListener {
	// deklaracja zmiennej midletu typu Display
	private static Display wyswietlacz;
	// deklaracja zmiennej TextBox
	TextBox tb, okno2;
	// deklaracja zmiennej dla komendy zakoñczenia
	private Command koniec, o2;
	
	public static Display mojDisplay() {
		return wyswietlacz;
	}
	
	public void commandAction(Command komenda, Displayable elemEkranu) {
		if (komenda == koniec) {
			// usuñ aplikacjê - wywo³aj destroyApp(...)
			try {
				destroyApp(false);
			} catch (MIDletStateChangeException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			// zawiadom platformê, ¿e midlet zakoñczy³ siê
			notifyDestroyed();
		}
		else if (komenda == o2)
			wyswietlacz.setCurrent(okno2);
	}
	
	public MojMidlet1() {
		// pobranie referencji do ekranu ze statycznego
		// obiektu reprezentuj¹cego ekran
		wyswietlacz = Display.getDisplay(this);
		// TextBox z tekstem "Witaj mój u¿ytkowniku!"
		tb = new TextBox("Mój Midlet1","Witaj mój u¿ytkowniku!",256,0);
		// inicjalizacja komendy koniec typu wyjœcie (EXIT)
		koniec = new Command("Koniec",Command.EXIT,1);
		// dodanie komendy koniec do TextBox
		tb.addCommand(koniec);
		// inicjalizacja komendy wyboru drugiego ekranu 
		o2 = new Command("Okno 2",Command.SCREEN,1);
		// dodanie komendy wyboru drugiego ekranu
		tb.addCommand(o2);
		// utworzenie obiektu dla drugiego ekranu
		okno2 = new Ekran2(tb);
	}

	protected void destroyApp(boolean arg0) throws MIDletStateChangeException {
	}

	protected void pauseApp() {
	}

	protected void startApp() throws MIDletStateChangeException {
		// ustawienie aktualnego ekranu midletu na TextBox
		wyswietlacz.setCurrent(tb);
		// dodanie s³uchacza w midlecie do TextBox
		tb.setCommandListener( (CommandListener) this);
	}
}