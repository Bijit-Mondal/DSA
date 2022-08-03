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
    }
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
    getLen(hot,cold){
        let len = 1;
        while(hot.next!=cold){
            hot = hot.next;
            ++len;
        }
        return len;
    }
    getMiddlePosition(hot,cold){
        if(hot == null){
            return null;
        }else{
            let myIndex = 1;
            let current = hot;
            let midPos = (this.getLen(hot,cold)/2)+1;
            while(myIndex < midPos){
                current = current.next;
                myIndex++;
            }
            return current;
        }
    }
    BinarySearch(data){
        let hot = this.head;
        let cold = null;
        let found = false;
        do {
            let LukeWarm = this.getMiddlePosition(hot,cold);
            if(LukeWarm == null){
                console.log("Search Not Possible");
                return null;
            }
            if(LukeWarm.data === data){
                console.log("Data Was Found");
                found = true;
                return found;
            }else if(LukeWarm.data<data){
                hot = LukeWarm.next;
            }else{
                cold = LukeWarm;
            }
        }while(cold == null || cold!=hot);
        if(!fou
        )
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

list.BinarySearch(24);

