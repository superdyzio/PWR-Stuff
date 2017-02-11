package kolejki;

public class FIFO {
		private final int INITIAL_CAPACITY = 15000;
		public Proces _tab[];
		private int _size = 0;
	 
		public FIFO() {
			_tab = new Proces[INITIAL_CAPACITY];
		}
	 
		public void enqueue(Proces ob){
			if(_tab.length == _size){
				Proces temp[] = new Proces[_size + _size/2];
				System.arraycopy(_tab, 0, temp, 0, _size);
				_tab = temp;
			}
			_tab[_size]=ob;
			_size++;
		}
	 
		public Proces dequeue() {
			if(_size==0) 
				return null;
			Proces temp = _tab[0];
			System.arraycopy(_tab, 1, _tab, 0, _tab.length-1);
			_size--;
			return temp;
		}
	 
		public void clear(){
			_tab = new Proces[INITIAL_CAPACITY];
			_size=0;
		}
	 
		public int size(){
			return _size;
		}
	 
		public boolean isEmpty(){
			return _size==0;
		}
		
		public void druk() {
			for (int i = 0; i < _size; i++) {
				System.out.printf("%d, %d, %d, %d\n",_tab[i].index,_tab[i].czasZgloszenia,_tab[i].getCzasP(),_tab[i].getCzasO());
			}
		}
}
