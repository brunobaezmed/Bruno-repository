package searching;

import java.io.PrintStream;
import java.util.Arrays;
import java.io.*;


public class TestBinarySearch {
	
  static PrintStream cout=new PrintStream(System.out);
   
  public static void main(String []args) throws IOException {
	  
	  int n=0;	
	 
      
	  Binarysearch B=new Binarysearch();
	  FileReader Read=B.filereader(new File("/home/bruno/Documents/java/eclipse/Searching/src/searching/FileSymbol"));  
	  BufferedReader BRead=new BufferedReader(Read);	
	  
	  n=B.NLinesread(BRead);
	  String []e=B.Fread(BRead, n);
	  String []v=Arrays.copyOf(e, e.length);
	  long time=System.nanoTime();
	  
	  Arrays.sort(v);

	  
	  B.binarySearch(v,"chip",0,v.length,0);
	  time=System.nanoTime()-time;
	  cout.print(" "+time);
  }

	
			
}
