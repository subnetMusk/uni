package produttore_consumatore;

public class Main {

	public static void main(String[] args) {
		final int N = 1000; //numero elementi totali possibili nel buffer

		final Monitor m = new Monitor(N);
		final Produttore p = new Produttore(m);
		final Consumatore c = new Consumatore(m);
		
		p.start();	//faccio partire produttore	
		c.start();	//faccio partire consumatore
	}
}
