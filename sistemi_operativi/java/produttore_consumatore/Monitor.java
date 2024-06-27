package produttore_consumatore;

public class Monitor {
	//ATTRIBUTI
	public int N;
	private int buffer[];
	private int count;	//numero di elementi disponibili nel buffer
	private int lo;		//indice per insert
	private int hi;		//indice per remove
	
	//COSTRUTTORE
	public Monitor(int n) {
		this.N = n;
		this.buffer = new int[this.N];
		this.count = this.N;
		this.lo = 0;
		this.hi = 0;
		
		//inizializzo il buffer
		for(int index = 0; index < this.N; index++) {
			this.buffer[index] = index;
		}
	}
	
	//METODI
	public synchronized void insert(int val) {
		while(this.count == N) { //se il buffer è pieno il produttore dorme
			goSleep();
		}
		
		System.out.println("Produco item: " + val);
		this.buffer[this.hi] = val;			//	|
		this.count++;					//	| --> inserisco un elemento (e aggiorno l'indice)
		this.hi = (this.hi + 1) % this.N;		//	|
		
		if(this.count == 1) { //se counter = 1 il consumatore sta dormendo
			notify();	//dunque lo sveglio
		}
	}
	
	public synchronized int remove() {
		while(this.count == 0) {	//se il buffer è vuoto il consumatore dorme
			goSleep();
		}
		
		int val = this.buffer[this.lo];			//	|
		this.lo = (this.lo + 1) % this.N;		//	| --> prelevo un elemento (e aggiorno l'indice)
		this.count--;					//	|
		System.out.println("Consumo item: " + val);

		if(this.count == this.N - 1) { //se elementi nel buffer = N-1 il produttore sta dormendo
			notify();	//dunque lo sveglio
		}
		
		return val; //ritorno l'elemento prelevato
	}
	
	private void goSleep() {
		try {
			wait();
		}catch(Exception e) {
			System.out.println("Errore --> " + e);
		}
	}
}
