function LinkedList(){
    function Node(data){
        this.data = data;
        this.next = null;
    }
    let length = 0;
    let head = null;
    this.createAtEnd = function(data){
        let node = new Node(data), current;
        if(head === null){
            head = node;
        }else{
            current = head;
            while(current.next){
                current = current.next;
            }
            current.next = node;
        }
        length++;
    };
    this.insert = function(position,elem){
        if(position>=0 && position<=length){
            let node = new Node(elem),current = head, previous,index = 0;

            if(position == 0){
                node.next = current;
                head = node;
            }
            else{
                while(index++<position){
                    previous = current;
                    current = current.next;
                }
                node.next = current;
                previous.next = node;
            }
            length++;
        }
    };
    this.print = function(){
        let current = head;
        while(current){
            console.log(current.data+"  ");
            current = current.next;
        }
        console.log("-------------------------------");
    };
}

let list = new LinkedList();
list.createAtEnd(20);
list.print();
list.createAtEnd(21);
list.print();

list.insert(1,22);
list.print();
