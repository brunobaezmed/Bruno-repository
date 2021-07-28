import java.security.SecureRandom;
import java.io.*;
import java.util.Arrays;

public class sorting {
	
	
	private double timer;
	static PrintStream stdout=new PrintStream(System.out);
	static SecureRandom rng=new SecureRandom() ;
	public sorting() {
		super();
		
	}
	public int [] sortBubble(int m[],int size)  
	{
		int flag=0;
		long t=System.currentTimeMillis();
		for(int i=0;i<size;i++) {

			for(int j=0;j<size-1;j++) {
			if(m[j]>m[j+1]) {
				
				flag=m[j+1];
				m[j+1]=m[j];
				m[j]=flag;
				
			}
			
				
			}
			
		}
		t=System.currentTimeMillis()-t;
		setTimer((double)t);
	   return m;
	}
	public int[]sortSelection(int m[],int size){
		int flag=0,curr=0;
		long t=System.currentTimeMillis();
			for(int i=0;i<size;i++) {
				
				
				curr=i;
				for(int j=i+1;j<size;j++) {
					
					if(m[j]<m[curr]) {
	
						curr=j;
						}
					
					}
				flag=m[i];
				m[i]=m[curr];
				m[curr]=flag;		
					}
			t=System.currentTimeMillis()-t;
			setTimer((double)t);
			return m;
	}


	public int[]sortInsertion(int m[],int size){
		
		long t=System.currentTimeMillis();	
		int max=0,j=0,i=0;
		for(i=1;i<size;i++) {
			max=m[i];
		for(j=i-1;j>=0&&m[j]>max;j--) {
				m[j+1]=m[j];
						}
					m[j+1]=max;
			
			}
		
		t=System.currentTimeMillis()-t;
		setTimer((double)t);
		return m;
	}
	public int[]sortMergeSort(int m[],int size){

		int v[]=new int [size];
		long t=System.currentTimeMillis();
		MergeSort(m,0,size-1,v);
		t=System.currentTimeMillis()-t;
		setTimer((double)t);
		return m;
	}
	public void MergeSort(int m[],int left,int right,int v[]){
		if(left>=right)  return ;
        int md=left+(right-left)/2;
		MergeSort(m, left,md,v);
		MergeSort(m,md+1,right,v);
		Merge(m,left,right,md,v);
		
	}
	public void Merge(int m[],int left,int right,int md,int v[]){// 1 4 5 7   0 2 3
		
	
		int i=left;
		int j=md+1;

		for(i=left;i<=right;i++){
			v[i]=m[i];
		}
		
		for(i=left;i<=right;i++)
			if(left>md){
				m[i]=v[j];
				j++;
			}
			else if(j>right){
				m[i]=v[left];
				left++;
			}
			else if(v[left]>v[j]){
				m[i]=v[j];
				j++;
			}
			else{
				m[i]=v[left];
				left++;
		}

		
	}

	public int[] sortQuickSort(int m[],int size){

		long t=System.currentTimeMillis();
		QuickSort(m,0,size-1);
		t=System.currentTimeMillis()-t;
		setTimer((double)t);
		return m;
	}
	public void QuickSort(int m[],int low,int high){
		if(low>=high)return;
		int q=Partition(m,low,high);
		QuickSort(m,low,q-1);
		QuickSort(m,q+1,high);
	}
	public int Partition(int m[],int low,int high){
		int q=m[high];
		int i=low;
		int flag=0;
		for(int j=low;j<high;j++){

			if(m[j]<q){
				flag=m[j];
				m[j]=m[i];
				m[i]=flag;
				i++;
				}
				
			}
			flag=m[i];
			m[i]=m[high];
			m[high]=flag;
			return i;
		}

		

	
	public void PrintVector(int m[],int size) {
		
		stdout.printf("\n");
		for(int b=0;b<size;b++) {
			
			stdout.printf("%d ",m[b]);
		}
		stdout.printf("\n");
		
	}
	public double getTimer() {
		
		return this.timer;
	}
	public void setTimer(double timer) {
		
		this.timer=timer;
			}
	public static void main(String []args)throws IOException {
		
		sorting sort=new sorting();
	
		int n=0;
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		stdout.println("n:");
		String s= new String (in.readLine());
		n=Integer.parseInt(s);


		
		int v[]=new int[n];
		int c[]=new int[n];
		
		for(int m=0;m<n;m++)
		v[m]=rng.nextInt(10000);



		System.arraycopy(v, 0, c, 0, v.length);
		c=sort.sortInsertion(c,n);
		stdout.printf("Insertion=%f ",sort.getTimer()/Math.pow(10, 3));

	

		System.arraycopy(v, 0, c, 0, v.length);
		c=sort.sortSelection(c,n);
		stdout.printf("Selection=%f ",sort.getTimer()/Math.pow(10, 3));


		System.arraycopy(v, 0, c, 0, v.length);
		c=sort.sortBubble(c,n);
		stdout.printf("Bubble=%f ",sort.getTimer()/Math.pow(10, 3));
		
		System.arraycopy(v,0,c,0,v.length);
		sort.sortMergeSort(c,n);
		stdout.printf("MergeSort=%f ",sort.getTimer()/Math.pow(10,3));

		System.arraycopy(v, 0, c, 0, v.length);
		sort.sortQuickSort(c,n);
		stdout.printf("QuickSort=%f ",sort.getTimer()/Math.pow(10,3));
	
		System.arraycopy(v,0,c,0,v.length);
		long t=System.currentTimeMillis();
		Arrays.sort(c);
	    t=System.currentTimeMillis()-t;
		sort.setTimer((double)t);
		stdout.printf("util.ArraysSort=%f ",sort.getTimer()/Math.pow(10,3));
	}
}
