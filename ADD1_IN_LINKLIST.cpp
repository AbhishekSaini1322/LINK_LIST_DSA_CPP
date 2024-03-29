class Solution
{
    public:
    
    Node* reverseLL(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
       head = reverseLL(head);
    //   add 1
       int carry = 1;
       Node *temp = head;
       while(temp->next != NULL){
           int totalSum = temp->data + carry;
           int digit = totalSum % 10;
           carry = totalSum / 10;
           
           temp->data = digit;
           temp = temp->next;
       }
    //   process last node
        if(carry != 0){
           int totalSum = temp->data + carry;
           int digit = totalSum % 10;
           carry = totalSum / 10;
           
           temp->data = digit;
           if(carry != 0){
               Node *newNode = new Node(carry);
               temp->next = newNode;
           }
        }
        // reverse 
        head = reverseLL(head);
        return head;
    }
};
