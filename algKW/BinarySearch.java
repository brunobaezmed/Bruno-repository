/*1.1.22  Write a version of  BinarySearch that uses the recursive rank() given on page 
25 and traces the method calls. Each time the recursive method is called, print the argu-
ment values lo and hi, indented by the depth of the recursion. Hint: Add an argument 
to the recursive method that keeps track of the depth.*/

import java.util.Arrays;
import java.io.*;


public class BinarySearch {
	

  
  
  public BinarySearch() {
	  
	  super();
  }
  
  public int binarySearch(int v[],int number,int low,int high,int calls) {// 1 5 9 11 15 22 33 55 57 98
		
	  	if(v[(low+high)/2]==number||calls>v.length) {System.out.printf("low=%d high=%d calls %d \n",low,high,calls);
	  	
	  	if(calls>v.length) {System.out.printf("number not found");}else{System.out.printf("number founded");};
	  	return -1;
	  	}
		
	  	else {
	  		if(v[(low+high)/2]<number) {
	  			System.out.printf("low=%d high=%d calls %d \n",low,high,calls);
	  			return binarySearch(v,number,(high+low)/2,high,calls+1);
	  			
	  		}
	  		if(v[(low+high)/2]>number) {
	  			
	  			System.out.printf("low=%d high=%d calls %d \n",low,high,calls);
	  			return binarySearch(v,number,low,(high+low)/2,calls+1);
	  			
	  		}			
	  	}
	  	
	  	return -1;
	}
  public int[] IntFread(BufferedReader f,int n)throws IOException{
	  String a="";
	  
	  int i=0;
	  	  
	  int v[]=new int [n];
	  try {
	  a=f.readLine();
	  while(a!=null) {
		v[i]=Integer.parseInt(a);
		a=f.readLine();
	  	i=i+1;
	  		}
	  f.close();
	  return v;
	  }catch(IOException e) {
		  e.printStackTrace();
	  }
	  throw new IOException();
	  	
	
  }
  public int NLinesread(BufferedReader f) throws IOException{
	  int n=0;
	  try {
	  f.mark(100);
	  String a=f.readLine();
	  
	  
	  while(a!=null) {
		  a=f.readLine();
		  n++;
	  		}
	  f.reset();
	  return n;
	  }catch(IOException e) {
		  e.printStackTrace();
	  }
	  throw new IOException();
  }
   public FileReader filereader(File file) throws FileNotFoundException{
	  
	   try {
		  FileReader Freader=new FileReader(file);
		  return Freader;
	   }catch(FileNotFoundException e) {
		   e.printStackTrace();
	   }
	  throw new FileNotFoundException();
  }
   
  public static void main(String []args) throws IOException {
	  
	  int n=0;	
	  int b=0;

	  		BinarySearch B=new BinarySearch();
		  	FileReader Read=B.filereader(new File("C:\\Users\\bruno\\Documents\\java\\algKW\\textW.txt"));  
		  	BufferedReader BRead=new BufferedReader(Read);	
		  	
		  	n=B.NLinesread(BRead);
		    System.out.print("keys="+n+"\n");
		     int v[]=new int [n];
		     v=B.IntFread(BRead,n);
             
		  	 byte bits[]=new byte[10];
		  	 b=System.in.read(bits);
		     String number=new String(bits);
		     number=number.trim();
		  	 System.out.printf("key=%s\n",number);
		  	 b=Integer.valueOf(number);
		  	 Arrays.sort(v);
		  	 B.binarySearch(v,b,0,v.length,0) ;
		  		  
  }

	
			
}

