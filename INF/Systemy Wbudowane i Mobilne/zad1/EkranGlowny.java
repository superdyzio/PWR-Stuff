package slownik;

import javax.microedition.lcdui.Alert;
import javax.microedition.lcdui.AlertType;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Form;
import javax.microedition.lcdui.List;
import javax.microedition.lcdui.TextBox;
import javax.microedition.lcdui.TextField;
import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;
import javax.microedition.rms.RecordEnumeration;
import javax.microedition.rms.RecordStore;
import javax.microedition.rms.RecordStoreException;
import javax.microedition.rms.RecordStoreFullException;
import javax.microedition.rms.RecordStoreNotFoundException;
import javax.microedition.rms.RecordStoreNotOpenException;

public class EkranGlowny extends MIDlet implements CommandListener {
	protected Display wyswietlacz;
	TextBox glowny;
	private TextField polskiwyraz, angielskiwyraz, dousuniecia, dosprawdzeniapl, dosprawdzeniaang;
	private Command koniec, dodaj, powrot, dodajrekord, wyczysc, usun, 
						usunrekord, sprawdz, sprawdzrekord;
	static RecordStore pol;
	Form dodawanie, usuwanie, sprawdzanie;
	List slowa;
	
	public EkranGlowny() {
		wyswietlacz = Display.getDisplay(this);
		glowny = new TextBox("S³ownik",null,256,0);
		koniec = new Command("Koniec",Command.EXIT,1);
		dodaj = new Command("Dodaj",Command.SCREEN,1);
		powrot = new Command("Powrót",Command.BACK,1);
		usun = new Command("Usuñ",Command.SCREEN,1);
		wyczysc = new Command("Wyczyœæ s³ownik",Command.SCREEN,1);
		sprawdz = new Command("SprawdŸ s³owo",Command.SCREEN,1);
		dodajrekord = new Command("Dodaj rekord",Command.SCREEN,1);
		usunrekord = new Command("Usuñ rekord",Command.SCREEN,1);
		sprawdzrekord = new Command("Szukaj",Command.SCREEN,1);
//		glowny.addCommand(koniec);
//		glowny.addCommand(dodaj);
//		glowny.addCommand(usun);
//		glowny.addCommand(sprawdz);
//		glowny.addCommand(wyczysc);
//		glowny.setCommandListener(this);
		dodawanie = new Form("Dodawanie rekordu");
		polskiwyraz = new TextField("Polski wyraz",null,32,TextField.ANY);
		dodawanie.append(polskiwyraz);
		angielskiwyraz = new TextField("Angielski wyraz",null,32,TextField.ANY);
		dodawanie.append(angielskiwyraz);
		dodawanie.addCommand(powrot);
		dodawanie.addCommand(dodajrekord);
		usuwanie = new Form("Usuwanie rekordu");
		dousuniecia = new TextField("Wyraz do usuniêcia",null,32,TextField.ANY);
		usuwanie.append(dousuniecia);
		usuwanie.addCommand(powrot);
		usuwanie.addCommand(usunrekord);
		sprawdzanie = new Form("Sprawdzanie s³owa");
		dosprawdzeniapl = new TextField("Polski wyraz do sprawdzenia",null,32,TextField.ANY);
		dosprawdzeniaang = new TextField("Angielski wyraz do sprawdzenia",null,32,TextField.ANY);
		sprawdzanie.append(dosprawdzeniapl);
		sprawdzanie.append(dosprawdzeniaang);
		sprawdzanie.addCommand(powrot);
		sprawdzanie.addCommand(sprawdzrekord);
		slowa = new List("S³ownik:",List.IMPLICIT);
		slowa.addCommand(koniec);
		slowa.addCommand(dodaj);
		slowa.addCommand(usun);
		slowa.addCommand(sprawdz);
		slowa.addCommand(wyczysc);
		slowa.setCommandListener(this);
	}
	
	public void commandAction(Command komenda, Displayable elemEkranu) {
		if (komenda == koniec) {
			try {
				destroyApp(false);
			} catch (MIDletStateChangeException e) {
				System.out.println(e);
			}
			notifyDestroyed();
		}
		else if (komenda == dodaj) {
			wyswietlacz.setCurrent(dodawanie);
			dodawanie.setCommandListener(this);
		}
		else if (komenda == dodajrekord) {
			dodawanieRekordu();
		}
		else if (komenda == powrot) {
//			wyswietlacz.setCurrent(glowny);
//			glowny.setCommandListener(this);
//			wyswietlRekordy();
			wyswietlacz.setCurrent(slowa);
			slowa.setCommandListener(this);
			listaSlow();
		}
		else if (komenda == wyczysc) { 
			usunRekordy();
//			wyswietlacz.setCurrent(glowny);
//			glowny.setCommandListener(this);
//			wyswietlRekordy();
			wyswietlacz.setCurrent(slowa);
			slowa.setCommandListener(this);
			listaSlow();
		}
		else if (komenda == usun) {
//			wyswietlacz.setCurrent(usuwanie);
//			usuwanie.setCommandListener(this);
			usunZaznaczone();
			wyswietlacz.setCurrent(slowa);
			slowa.setCommandListener(this);
			listaSlow();
		}
		else if (komenda == usunrekord) {
			usuwanieRekordu();
		}
		else if (komenda == sprawdz) {
			wyswietlacz.setCurrent(sprawdzanie);
			sprawdzanie.setCommandListener(this);
		}
		else if (komenda == sprawdzrekord) {
			sprawdzenieRekordu();
		}
	}

	protected void destroyApp(boolean unconditional) throws MIDletStateChangeException {
		notifyDestroyed();
	}

	protected void pauseApp() {}

	protected void startApp() throws MIDletStateChangeException {
//		wyswietlacz.setCurrent(glowny);
//		wyswietlRekordy();
		wyswietlacz.setCurrent(slowa);
		listaSlow();
	}
	
	public void wyswietlRekordy() {
		glowny.setString("");
		try {
			pol = RecordStore.openRecordStore("S³ownik",true);
			RecordEnumeration it = pol.enumerateRecords(null,null,false);
			byte[] rekord;
			while (it.hasNextElement()) {
				rekord = it.nextRecord();
				String s = new String(rekord);
				glowny.insert(s+"\n",glowny.getCaretPosition());
			}
			pol.closeRecordStore();
		} catch (RecordStoreNotOpenException e) {
			System.out.println(e);
		} catch (RecordStoreException e) {
			System.out.println(e);
		}
	}
	
	public void usunRekordy() {
		int liczba = 0;
		try {
			pol = RecordStore.openRecordStore("S³ownik",true);
			RecordEnumeration it = pol.enumerateRecords(null,null,false);
			liczba = pol.getNumRecords();
			for (int i = 0; i < liczba; i++) {
				int j = it.nextRecordId();
				pol.deleteRecord(j);
			}
			pol.closeRecordStore();
		} catch (RecordStoreNotOpenException e) {
			System.out.println(e);
		} catch (RecordStoreException e) {
			System.out.println(e);
		}
	}
	
	public void dodawanieRekordu() {
		if (!polskiwyraz.getString().equals("") && !angielskiwyraz.getString().equals("")) {
			String napis = polskiwyraz.getString() + " - " + angielskiwyraz.getString();
			byte[] b = napis.getBytes();
			try {
				pol = RecordStore.openRecordStore("S³ownik",true);
				pol.addRecord(b,0,b.length);
				pol.closeRecordStore();
			} catch (RecordStoreException e) {
				System.out.println(e);
			}
			Alert komunikat = new Alert("Sukces!","Rekord zosta³ dodany.",null,AlertType.INFO);
			komunikat.setTimeout(3000);
			wyswietlacz.setCurrent(komunikat,dodawanie);	
		}
		else {
			Alert komunikat = new Alert("B³¹d!","Oba pola musz¹ byæ wype³nione.",null,AlertType.INFO);
			komunikat.setTimeout(3000);
			wyswietlacz.setCurrent(komunikat,dodawanie);
		}
	}
	
	public void usuwanieRekordu() {
		String wyraz = dousuniecia.getString();
		int liczba = 0;
		boolean znalezione = false;
		try {
			pol = RecordStore.openRecordStore("S³ownik",true);
			RecordEnumeration it = pol.enumerateRecords(null,null,false);
			liczba = pol.getNumRecords();
			for (int i = 0; i < liczba; i++) {
				int j = it.nextRecordId();
				byte[] b = pol.getRecord(j);
				String s = new String(b);
				int indeks = s.indexOf(' ');
				String polskie = s.substring(0,indeks);
				indeks = s.lastIndexOf(' ')+1;
				String angielskie = s.substring(indeks);
				if (polskie.equals(wyraz) || angielskie.equals(wyraz)) {
					znalezione = true;
					pol.deleteRecord(j);
				}
			}
			if (znalezione) {
				Alert komunikat = new Alert("Sukces!","Rekord zosta³ usuniêty.",null,AlertType.INFO);
				komunikat.setTimeout(3000);
				wyswietlacz.setCurrent(komunikat,usuwanie);
			}
			else {
				Alert komunikat = new Alert("B³¹d!","Szukany rekord nie istnieje.",null,AlertType.INFO);
				komunikat.setTimeout(3000);
				wyswietlacz.setCurrent(komunikat,usuwanie);
			}
			pol.closeRecordStore();
		} catch (RecordStoreNotOpenException e) {
			System.out.println(e);
		} catch (RecordStoreException e) {
			System.out.println(e);
		}
	}
	
	public void sprawdzenieRekordu() {
		String wyrazpl = dosprawdzeniapl.getString();
		String wyrazang = dosprawdzeniaang.getString();
		if (!wyrazpl.equals("") && !wyrazang.equals("")) {
			Alert komunikat = new Alert("B³¹d!","Wype³nij tylko jedno pole.",null,AlertType.INFO);
			komunikat.setTimeout(3000);
			wyswietlacz.setCurrent(komunikat,sprawdzanie);
		}
		else {
			int liczba = 0;
			String pl = "";
			String eng = "";
			boolean znalezione = false;
			try {
				pol = RecordStore.openRecordStore("S³ownik",true);
				RecordEnumeration it = pol.enumerateRecords(null,null,false);
				liczba = pol.getNumRecords();
				for (int i = 0; i < liczba; i++) {
					int j = it.nextRecordId();
					byte[] b = pol.getRecord(j);
					String s = new String(b);
					int indeks = s.indexOf(' ');
					String polskie = s.substring(0,indeks);
					indeks = s.lastIndexOf(' ')+1;
					String angielskie = s.substring(indeks);
					if (polskie.equals(wyrazpl) || angielskie.equals(wyrazang)) {
						znalezione = true;
						pl = polskie;
						eng = angielskie;
					}
				}
				if (znalezione) {
					Alert komunikat = new Alert("Sukces!",pl+" - "+eng,null,AlertType.INFO);
					komunikat.setTimeout(3000);
					wyswietlacz.setCurrent(komunikat,sprawdzanie);
				}
				else {
					Alert komunikat = new Alert("B³¹d!","Wyrazu nie ma w s³owniku.",null,AlertType.INFO);
					komunikat.setTimeout(3000);
					wyswietlacz.setCurrent(komunikat,sprawdzanie);
				}
				pol.closeRecordStore();
			} catch (RecordStoreNotOpenException e) {
				System.out.println(e);
			} catch (RecordStoreException e) {
				System.out.println(e);
			}			
		}
	}
	
	public void listaSlow() {
		int liczba = 0;
		slowa.deleteAll();
		try {
			pol = RecordStore.openRecordStore("S³ownik",true);
			RecordEnumeration it = pol.enumerateRecords(null,null,false);
			liczba = pol.getNumRecords();
			for (int i = 0; i < liczba; i++) {
				int j = it.nextRecordId();
				byte[] b = pol.getRecord(j);
				String s = new String(b);
				slowa.append(s,null);
			}
			pol.closeRecordStore();
		} catch (RecordStoreNotOpenException e) {
			System.out.println(e);
		} catch (RecordStoreException e) {
			System.out.println(e);
		}
	}
	
	public void usunZaznaczone() {
		String napis = slowa.getString(slowa.getSelectedIndex());
		int index = napis.indexOf(' ');
		String pl = napis.substring(0,index);
		index = napis.lastIndexOf(' ')+1;
		String ang = napis.substring(index);
		int liczba = 0;
		boolean znalezione = false;
		try {
			pol = RecordStore.openRecordStore("S³ownik",true);
			RecordEnumeration it = pol.enumerateRecords(null,null,false);
			liczba = pol.getNumRecords();
			for (int i = 0; i < liczba; i++) {
				int j = it.nextRecordId();
				byte[] b = pol.getRecord(j);
				String s = new String(b);
				int indeks = s.indexOf(' ');
				String polskie = s.substring(0,indeks);
				indeks = s.lastIndexOf(' ')+1;
				String angielskie = s.substring(indeks);
				if (polskie.equals(pl) || angielskie.equals(ang)) {
					znalezione = true;
					pol.deleteRecord(j);
				}
			}
			if (znalezione) {
				Alert komunikat = new Alert("Sukces!","Rekord zosta³ usuniêty.",null,AlertType.INFO);
				komunikat.setTimeout(3000);
				wyswietlacz.setCurrent(komunikat,slowa);
			}
			else {
				Alert komunikat = new Alert("B³¹d!","Szukany rekord nie istnieje.",null,AlertType.INFO);
				komunikat.setTimeout(3000);
				wyswietlacz.setCurrent(komunikat,slowa);
			}
			pol.closeRecordStore();
		} catch (RecordStoreNotOpenException e) {
			System.out.println(e);
		} catch (RecordStoreException e) {
			System.out.println(e);
		}
	}
}
