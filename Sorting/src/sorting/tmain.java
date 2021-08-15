package sorting;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class tmain {

	static PrintStream cout = new PrintStream(System.out);
	static BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String args[]) throws IOException {

		int m = 0;
		String q = "";
		boolean k = false;

		/*
		 * Bag <Double>bag=new Bag<Double>(); if(bag.isEmpty()){
		 * m=Integer.parseInt(cin.readLine()); } double dat[]=new double [m];
		 * while(bag.size()<m){
		 * 
		 * dat[bag.size()]=Double.parseDouble(cin.readLine()); bag.add(dat[bag.size()]);
		 * } m=0; cout.print("sizebag ="+bag.size()+"Bag="); do{
		 * 
		 * cout.print(dat[m]+" "); m++;
		 * 
		 * }while(m<bag.size()); cout.println();
		 */

		Queue<String> queue = new Queue<String>();// {()})

		if (queue.isEmpty()) {
			q = cin.readLine();
			m = q.length();
		}
		char h[] = q.toCharArray();
		String[] f = new String[m];

		while (queue.size() < m) {

			f[queue.size()] = String.valueOf(h[queue.size()]);
			queue.push(f[queue.size()]);
		}

		queue.pop();
		cout.print("queue= ");
		while (!queue.isEmpty()) {

			q = f[m - 1];

			// cout.print(q+" \n");

			queue.pop();
			if (!queue.isEmpty()) {
				if (f[queue.size()].equals("{") && q.equals("}")) {
					k = true;
				}
				if (f[queue.size()].equals("[") && q.equals("]")) {
					k = true;
				}
				if (f[queue.size()].equals("(") && q.equals(")")) {
					k = true;
				}
			}

			// cout.print(f[queue.size()]+" \n");
			m = m--;
		}
		// {()}
		if (k)
			cout.print("true");

	}

}