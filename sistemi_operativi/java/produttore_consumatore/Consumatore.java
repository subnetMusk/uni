package produttore_consumatore;

public class Consumatore extends Thread{
	//ATTRIBUTI
	private Monitor mon;

	//COSTRUTTORE
	public Consumatore(Monitor m) {
		this.mon = m;
	}
	
	//METODI
	public void run() {
		while(true) {
			int item = this.mon.remove();
			consume_item(item);
		}
	}
	
	private void consume_item(int i) { //"consumo" l'elemento
		return;
	}
}
