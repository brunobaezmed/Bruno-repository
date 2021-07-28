/*
 1.1.19  Run the following program on your computer:
public class    Fibonacci 
{
   public static long F(int N)
   {
      if (N == 0) return 0;
      if (N == 1) return 1;
      return F(N-1) + F(N-2);
   }
   public static void main(String[] args)
   {
      for (int N = 0; N < 100; N++)
         StdOut.println(N + " " + F(N));
   } 
}
571.1  Basic Programming Model
What is the largest value of N for which this program takes less 1 hour to compute the 
value of F(N)? Develop a better implementation of F(N) that saves computed values in 
an array.
 
 */
import java.math.BigInteger;
public class Fibonacci {
	 public static BigInteger F(int N,BigInteger v[])
	   {
		 
	      if (N == 0) return BigInteger.ZERO;
	      if (N == 1) return BigInteger.ONE;
	      
	      
	    	  v[N]=v[N-1].add(v[N-2]);
	    	  return v[N];

	      }
	      
	      
	   
	   public static void main(String[] args)
	   {
		  BigInteger v[]=new BigInteger [100];
		 
		  int N=0;
	      for (N = 0; N <100; N++) {
	    	 v[N]=F(N,v);
	    
	    	 System.out.printf("%d %d\n",N,v[N] );
	      	} 
	      
	   	}
}