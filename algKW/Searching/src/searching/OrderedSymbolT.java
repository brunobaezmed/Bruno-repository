package searching;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Iterator;
public class OrderedSymbolT <Key extends Comparable<Key>,Value> implements SymbolTable<Key,Value>{
	
	final PrintStream  cout=new PrintStream(System.out);
	private Key[] key;
	private Value[] value;
	private int size;
	private int curr;
	private int n;
	
	public OrderedSymbolT(Key[] b,Value[] v){
		
		key=b;
		value=v;
		this.size=key.length;
		this.curr=0;
		this.n=this.size;
			}
	public void put(Key key,Value value) {
			
			if(value==null) {
				delete(key);
				}
			
			else {
				for (int q = 0; q < this.size;q++) 
					
					if (key.compareTo(this.key[q]) == 0) {
						this.value[q] = value;
						return;

						
					}

				this.size++;
				this.key[this.size - 1] = key;
				this.value[this.size - 1] = value;
				this.n=this.size;
					}

			
		
		}
	public Value get(Key key) {
		
		int h=0;
		while(h<this.size) {
			
			if(key.compareTo(this.key[h])==0)
			return this.value[h];
			h++;
			}
			return null;
		}
	public void delete(Key key) {
		int r=0;
		while(r<this.size) {
			if(key.compareTo(this.key[r])==0) {
				this.value[r]=null;
			}
			r++;
			
			}
		this.n--;
		}
	
	public boolean contains(Key key) {
			
			return get(key)==null;
		
		}
	
	public boolean isEmpty() {
		return this.n==0&&key==null;
		
		}
	
	public int size() {
		return this.n;
		}
	
	public Key min() {
		Key min;
		int y=0;
		Key []i=this.key;
		
		Arrays.sort(key);
		
		while(this.value[y]==null)
			y++;
			
		min=this.key[y];
		this.key=i;
		
		return min;
		}
	public Key max() {
		Key max;
		Key []i=this.key;
		int y=this.size-1;
		
		Arrays.sort(key);
		while(this.value[y]==null)
			y--;
		max=this.key[y];
		
		this.key=i;
		return max;
		}
	public Key floor(Key key) {
		Key f=this.key[0];
		
		for(int u=0;u<this.size;u++) {
			
			if(key.compareTo(this.key[u])>=0)
					f=this.key[u];
			}
			return f;
		}
	public Key ceiling(Key key) {
		
		Key f=this.key[0];
		for(int t=0;t<this.size;t++) {
			
			if(key.compareTo(this.key[t])<=0)
				f=this.key[t];
			}
			return f;
		}
	public int rank(Key key) {
		int c=0,e=0;
		
		while(e<this.size) {
			
			if(key.compareTo(this.key[e])>=0)
				c++;
			
			
			e++;
				}
		return c;
		
		}

	public Key select(int k) {
		
			
		return this.key[k];
		}
	public void deleteMin() {
		
		delete(min());
		
		}
	public void deleteMax() {
		
		delete(max());
		
		}
	public int size(Key low,Key high) { //[ 4 99 100 null 571 1555 9111]
		
		if(low.compareTo(high)>0)
			return 0;
		else {
			return rank(high)-rank(low);
			}
		
		
		
		
		}
		
	public Iterable<Key>keys(){
	
	return	keys(min(),max());
		}
	public Iterable<Key>keys(Key low,Key high){
		
		Key []i=this.key;
		int z=this.size;
		Arrays.sort(key);
		
		this.curr=rank(low)-1;
		this.size=rank(high);
		
		while(iterator().hasNext()) {
			
			if((value[this.curr]==null))curr++;
			cout.print(iterator().next()+"\n");
			
			}	
		this.size=z;
		this.key=i;
		return null;
	}
	public Iterator<Key> iterator(){
		
		Iterator<Key> I=new Iterator<Key>() {	

		public boolean hasNext() {
			
			if(curr<size)
				return true;
				return false;
				}
		
		public Key next(){	
			
			return key[curr++];
				}
					
			};
		return I;
	}
	
}
