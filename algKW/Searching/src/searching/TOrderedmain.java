package searching;
import java.io.PrintStream;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class TOrderedmain {
	
	
    
	static Scanner cin = new Scanner(System.in);

	static PrintStream cout = new PrintStream(System.out);

	public static void main(String[] args)throws FileNotFoundException {
	    File f =new File("/home/bruno/Documents/java/eclipse/Searching/src/searching/FileSymbol");
	    Scanner file=new Scanner(f);
	    int p=0;
	    while(file.hasNextLine()) {
	    	p++;
	    	file.nextLine();
	    	
	    }
	    file.close();
	    Scanner file1=new Scanner(f);
		Integer[] k = new Integer[p];
		String[] v = new String[k.length];
		OrderedSymbolT<Integer, String> Table = new OrderedSymbolT<Integer, String>(k, v);

		
		for (int y = 0; y < k.length; y++) {
			
			cout.print("key:");
			k[y] = cin.nextInt();
			//cout.print("Value:");
			Table.put(k[y],file1.nextLine());
			
		}
		
		cout.print("size:"+Table.size()+"\n");
		Table.keys();
		//cout.print(Table.get(Table.max()));
		cin.close();
		file1.close();
	}

	
	
	
	
	
	
	
	
}
