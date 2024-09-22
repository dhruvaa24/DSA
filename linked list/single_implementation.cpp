#include<iostream>
using namespace std;


//Node for the linked list
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data: "<< value << endl;
    }
};

//inserting at head
void insertAtHead(Node* & head, int d){
    // create a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head=temp;
}

//inserting at tail
void insertAtTail(Node* &tail, int d){
    //create a new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

//inserting at middle
void insertAtMid(Node* & tail, Node* & head, int pos, int d){
    //if index is 0
    if(pos==1){
        insertAtHead(head,d);
        return;
    }

    else{
        //create a new node
        Node* temp = new Node(d);
        Node* itr = head;
        for(int i=1;i<pos-1;i++){
            itr=itr -> next;
        }
        if(itr->next==NULL){
            insertAtTail(tail , d);
            return;
        }
        else{
            temp -> next=itr->next;
            itr -> next=temp;
        }
    }
}

void deleteNode(Node* & head, Node* & tail, int pos){
    //deleting first node
    if(pos==1){
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    //deleting last or any middle node
    else{
        Node* itr = head;
        Node* curr = head->next;
        for(int i=1;i<pos-1;i++){
            itr = itr->next;
            curr = curr->next;
        }
        if(curr->next == NULL){
            tail = itr;
            itr->next = NULL;
            delete curr;
            return;
        }
        else{
            itr->next = curr->next;
            curr->next=NULL;
            delete curr;
        }
    }
}

//traversing a linked list
void print(Node* & head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp -> data << endl;
        temp=temp->next;
    }
}

int main(){
    Node* node1=new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    insertAtTail(tail, 18);
    insertAtMid(tail, head, 2, 24);
    insertAtMid(tail, head, 1, 40);
    insertAtMid(tail, head, 6, 30);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    deleteNode(head, tail, 7);
    cout << "tail : " << tail->data << endl;
    print(head);
}