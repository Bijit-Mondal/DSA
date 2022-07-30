class Node{
    constructor(data, next = null){
        this.data = data;
        this.next = next;
    }
}
class LinkedList{
    constructor(){
        this.length = 0;
        this.head = null;
    }
    createAtEnd(data){
        let node = new Node(data), current;
        if(this.head === null){
            this.head = node;
        }else{
            current = this.head;
            while(current.next){
                current = current.next;
            }
            current.next = node;
        }
        this.length++;
    };
    insert(position,elem){
        if(position>=0 && position<=this.length){
            let node = new Node(elem),current = this.head, previous,index = 0;

            if(position == 0){
                node.next = current;
                this.head = node;
            }
            else{
                while(index++<position){
                    previous = current;
                    current = current.next;
                }
                node.next = current;
                previous.next = node;
            }
            this.length++;
        }
    };
    /*delete(value){
        if(this.head.next){
        let current = this.head, prevCur;
        while(value!=current.data){
            prevCur = current;
            current = current.next;
        }
        prevCur.next = current.next;
        }
    };*/
    print(){
     let current = this.head;
        while(current){
            console.log(current.data+"  ");
            current = current.next;
        }
        console.log("-----------------------");
    }
}

let list = new LinkedList();
list.createAtEnd(20);
list.print();
list.createAtEnd(21);
list.print();

list.insert(1,22);
list.print();


list.insert(4,2);
list.print();

//list.delete(20);
list.print();
