class Node{
    constructor(data,next=null,prev=null){
        this.data = data;
        this.next = next;
        this.prev = prev;
    }
}
class DCircularLL{
    constructor(){
        this.length = 0;
        this.head = null;
        this.tail = null;
    }
    CreateAtEnd(data){
        let node = new Node(data);
        if(this.head == null){
            this.head = node;
            this.tail = node;
            node.next = node;
            node.prev = node;
        }else{
            node.next = this.head;
            node.prev = this.tail;
            this.tail.next = node;
            this.head.prev = node;
            this.tail = node;
        }
        this.length++;
    }
    InsertAtBeg(data){
        let node = new Node(data);
        if(this.head == null){
            CreateAtEnd(data);
        }else{
            node.next = this.head;
            node.prev = this.tail;
            this.head.prev = node;
            this.tail.next = node;
            this.head = node;
            this.length++;
        }
    }
    InsertAt(position,data){
        if(position>=0 && position<=this.length){
            let node = new Node(data),current = this.head,index = 1;
            if(position == 0){
                this.InsertAtBeg(data);
            }else{
                while(index++<position){
                    current = current.next;
                }
                node.next = current;
                node.prev = current.prev;
                current.prev.next = node;
                current.prev = node;
                this.length++;
            }
        }
    }
    Display(){
        let current = this.head;
        do{
            console.log(current.data+" ");
            current = current.next;
        }while(current!=this.head);
        console.log("-----------------------");
    }
    DeleteAtLast(){
        let RIPnode = this.tail;
        this.tail = tail.prev;
        this.tail.next = this.head;
        this.head.prev = this.tail;
        delete RIPnode;
    }
    DeleteAtBeg(){
        let RIPnode = this.head;
        this.head = head.next;
        this.head.prev = this.tail;
        this.tail.next = this.head;
        delete RIPnode;
    }
}
let flag = true;
let list = new DCircularLL();
while(flag){
    console.log("1 for InsertAtLast");
    console.log("2 for InsertAtBeginning");
    console.log("3 for InsertAt Any Position");
    console.log("4 for Display");
    console.log("5 for DeleteAtLast");
    console.log("6 for DeleteAtBeg");
    console.log("-1 for Exit");
    let option = prompt("Enter ");
    option = Number(option);
    switch(option){
        case 1:
            var data = prompt("Enter the data ");
            list.CreateAtEnd(data);
            break;
        case 2:
            var data = prompt("Enter the data ");
            list.InsertAtBeg(data);
            break;
        case 3:
            var data = prompt("Enter the data ");
            let position = prompt("Enter the position ");
            list.InsertAt(position,data);
            break;
        case 4:
            list.Display();
            break;
        case 5:
            list.DeleteAtLast();
            break;
        case 6:
            list.DeleteAtBeg();
            break;
        case -1:
            flag = false;
            break;
        default:
            console.log("Hey!");
    }
}