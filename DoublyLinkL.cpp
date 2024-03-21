#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int findlength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertathead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        // create a node
        Node *newnode = new Node(data);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertattail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {

        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);

        tail->next = newnode;

        newnode->prev = tail;

        tail = newnode;
    }
}

void insertatposition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;

        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        curr->prev = newnode;
        newnode->next = curr;
        prev->next = newnode;
        newnode->prev = prev;
    }
}

void deleteatHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "cannot delete bcz link list is empty\n";
        return;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
}

void deleteatTail(Node *&head, Node *&tail)
{
    if (tail == NULL)
    {
        cout << "Bcz link list is empty" << endl;
        return;
    }
    else
    {
        Node *prevNode = head;
        while (prevNode->next != tail)
        {
            prevNode = prevNode->next;
        }
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
}

void deleteatPosition(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "Bcz link list is empty" << endl;
        return;
    }
    // single node
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    int len = findlength(head);
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if (pos == len)
    {
        deleteatTail(head, tail);
    }
    else
    {
        Node *nextNode = NULL;
        Node *prevNode = NULL;
        Node *currNode = head;
        while (pos != 1)
        {
            prevNode = currNode;
            currNode = currNode->next;
            pos--;
        }
        nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertathead(head, tail, 40);
    insertathead(head, tail, 30);
    insertathead(head, tail, 20);
    insertathead(head, tail, 10);
    insertathead(head, tail, 5);

    // deleteatHead(head,tail);
    // deleteatTail(head,tail);
    print(head);
    cout << endl;

    deleteatPosition(head, tail, 5);
    // insertatposition(head,tail,50,5);

    print(head);
    cout << endl;
}