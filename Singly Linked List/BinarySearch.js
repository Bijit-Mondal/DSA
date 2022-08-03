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
    print(){
     let current = this.head;
        while(current){
            console.log(current.data+"  ");
            current = current.next;
        }
        console.log("-----------------------");
    }
    LinearSearch(data){
        let current = this.head;
        let found = false;
        let i = 1;
        while(current.next){
            if(current.data == data) {
                found = true;
                break;
            }else{
                current = current.next;
                i++;
            }
        }
        if(found){
            console.log('Data was found at '+i+' position');
        }else{
            console.log("Data Wasn't Found ");
        }
    }
}
let list = new LinkedList();
list.createAtEnd(10);
list.createAtEnd(20);
list.createAtEnd(25);
list.createAtEnd(30);
list.createAtEnd(32);
list.createAtEnd(45);

list.print();

list.LinearSearch(30);

