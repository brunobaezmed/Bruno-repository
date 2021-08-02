import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.InputStreamReader;
import java.security.SecureRandom;

public class tmain1{
    static final SecureRandom rng=new SecureRandom();
    static PrintStream cout=new PrintStream(System.out);
    static BufferedReader cin=new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String []args){
        
        LinkedList list=new LinkedList();
    

        int a=0;
        
        for(int r=0;r<5;r++){
            a=rng.nextInt(22);
            list.addFirst(a, list);
        }   
        list.printList(list);
        
        cout.println();

        list.addEnd(561,list);
        list.printList(list);
        
        cout.println();
        list.removeItem(561, list);
        list.printList(list);

    }






}
