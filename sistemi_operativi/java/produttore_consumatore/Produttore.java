package produttore_consumatore;

public class Produttore extends Thread{
	//ATTRIBUTI
	private int counter; //solo per avere il valore degli item in sequenza
	public Monitor mon;

	//COSTRUTTORE
	public Produttore(Monitor m) {
		this.mon = m;
		this.counter = 0;
	}
	
	//METODI
	public void run() {
		while(true) {
			int item = produce_item();
			mon.insert(item);
		}
	}
	
	private int produce_item() { //creo l'elemento (intero)
		this.counter++;
		int i = this.counter % this.mon.N;
		
		return i;
	}
}