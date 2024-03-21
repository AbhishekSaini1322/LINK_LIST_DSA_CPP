#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

  // default constructure
    Node(){
        this->data = data;
        // this->next = NULL;
    }

    // parametrise ctor
    Node(int data){
     this->data = data;
     this->next = NULL;
    }
};

void printLL(Node *head) {
    // good practic
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

int printLen(Node *head) {
    Node*  temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    return count;
}


int main(){
    // static allocation
    // Node a;

    // dynamic allocation 
    // Node*head = new Node();

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first-> next = second;
    second-> next = third;
    third-> next = fourth;
    fourth-> next = fifth;
    fifth-> next = NULL;//fifth is the last node so next should be null
    
    Node* head = first;
    // printLL(head);
    cout<<printLen(head);

    return 0;

}