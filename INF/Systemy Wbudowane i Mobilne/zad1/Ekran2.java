import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.TextBox;

public class Ekran2 extends TextBox implements CommandListener {
	private Display wyswietlacz;
	private Command powrot;
	Displayable ekranP;
	
	public Ekran2(Displayable ekranPowrotny) {
		super("Okno 2","Witaj w oknie 2!",256,0);
		wyswietlacz = MojMidlet1.mojDisplay();
		ekranP = ekranPowrotny;
		// polecenie powrotu
		powrot = new Command("Powrót",Command.BACK,1);
		// dodanie komendy powrót do TextBox 
		this.addCommand(powrot);
		// ustawienie s³uchacza
		this.setCommandListener(this);
	}

	public void commandAction(Command komenda, Displayable elemEkranu) {
		if (komenda == powrot)
			wyswietlacz.setCurrent(ekranP);
	}
}