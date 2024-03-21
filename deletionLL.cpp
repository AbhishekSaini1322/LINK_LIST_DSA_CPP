#include<iostream>
using  namespace std;

class Node{
 public:
    int data;
    Node* next;

    Node(){
        // this->data = data;
        this->next = NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

int getLen(Node *head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void printLL(Node *head) {
    // good practice
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

int insertatHead(Node* &head,Node* &tail, int data) {
    if(head == NULL) {
        // create new node
        Node* newNode = new Node(data);
        // update head
        head = newNode;
    }
    else{
        // create a new node
        Node *newNode = new Node(data);
        // attach node
        newNode->next = head;
        // update head
        head = newNode;
    }
}

int insertatTail(Node* &head,Node* &tail,int data ){

    if(head == NULL){
        // empty link list
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // non empty LL
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
} 

void insertatPosition(Node* &head,Node* &tail,int data,int pos ) {

if(head == NULL){
    cout<<"link list is empty"<<endl;
    return;
}

if(pos < 1){
    cout<<"enter valid position"<<endl;
    return ;
}

int len = getLen(head);

if(pos > len){
    insertatTail(head,tail,data);
    return ;
}

// if(pos > len){
//     cout<<"position does not exist"<<endl;
// }

if(pos == 1){
    insertatHead(head,tail,data);
}
else{
    // create node
    Node *newNode= new Node(data);
    // travese prev and curr position
    Node* prev = NULL;
    Node* curr = head;

    while(pos != 1){
        prev = curr;
        curr = curr->next;
        pos--;
    }

    // attcth prev to newnode
    prev->next = newNode;
    newNode->next = curr;
}
}

void deletionAtPos(Node* &head, Node* &tail,int pos) {
    if(head == NULL){
        cout<<"cannot delete bcz LL is empty"<<endl;
    }

    if(head == tail){
        // single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int len = getLen(head);

    // delete from head
    if(pos == 1){
        // first node delete
        Node* temp = head;
        head = temp->next;
        // isolate kr do node ko
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len){
        // last node delete
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        // prev node ko null karo
        prev->next = NULL;
        // node delete karo
        delete tail;
        // update tail
        tail = prev;

    }
    // middle node delete-----------------
    else{
        Node* prev = NULL;
        Node* curr = head;

        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertatHead(head,tail,10);
    insertatHead(head,tail,20);
    insertatHead(head,tail,30);
    insertatHead(head,tail,40);
    insertatHead(head,tail,50);
    // insertatTail(head,tail,40);
    // insertatTail(head,tail,50);

    printLL(head);
    cout<<endl;
    // insertatPosition(head,tail,122,51);
     deletionAtPos(head,tail,5);
    cout<<endl;
    printLL(head);


    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    // first-> next = second;
    // second-> next = third;
    // third-> next = fourth;
    // fourth-> next = fifth;
    // fifth-> next = NULL;//fifth is the last node so next should be null
    
    // Node* head = first;
    // Node* tail = fifth;

    //  insertatHead(head,tail,100);
    // // insertatTail(head,tail,60);
    // // insertatMid()
     
   
}