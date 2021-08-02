//linked list

final class LinkedList{
    
    private LinkedList first;
    private LinkedList next;
    private int Item;
    public  LinkedList(){
        
        this.Item=0;
        this.first=null;            
    
    }
    public void addFirst(int item,LinkedList list){

        LinkedList n=new LinkedList();
        n.next=list.next;
        n.Item=item;
        list.next=n;
       
    }
    public void printList(LinkedList list){
        LinkedList node=list.next;
        while(node!=null){
            System.out.print(" "+node.Item);
            node=node.next;
        }
    }
    public void removeFirst(LinkedList list){

        LinkedList node;
        node=list.next;
        list.next=node.next;
        node=null;

        }
    public void addEnd(int item,LinkedList list){

        LinkedList node;
        node=list.next;
        while(node.next!=null){
            node=node.next;
            }
        
        LinkedList n=new LinkedList();
        n.Item=item;
        n.next=null;
        node.next=n;

        }
     public void removeItem(int value,LinkedList list){

            LinkedList node=list.next;
            LinkedList nr=null;
            if(node.Item==(value)){
                list.next=node.next;

            }
            else{
            while(node!=null){

                if(node.Item==(value)){
                    nr.next=node.next;
                    
                        }
                nr=node;
                node=node.next;

                    }
            }

     }

    }

