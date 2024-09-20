#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this->next!=NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory cleared for the data " << value << endl;
    }
};

void print(Node* & head){
    Node* itr = head;
    while(itr!=NULL){
        cout << itr -> data <<endl;
        itr = itr -> next;
    }
    cout << endl;
}

void insertAtStart(Node* & head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtEnd(Node* & tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtMiddle(Node* & head, Node* & tail, int pos, int data){
    if(pos==1){
        insertAtStart(head, data);
        return;
    }
    else{
        Node* temp = new Node(data);
        Node* itr = head;
        for(int i=1;i<pos-1;i++){
            itr = itr -> next;
        }
        if(itr->next == NULL){
            insertAtEnd(tail, data);
            return;
        }
        else{
            temp -> next = itr->next;
            itr -> next = temp;
        }
    }
}

void deleteNode(Node* & head, int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* prev = head;
        Node* curr = head->next;
        for(int i=1;i<pos-1;i++){
            prev = prev->next;
            curr = curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void deleteByVal(Node* & head, int val){
    if(head->data==val){
        Node* temp=head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* prev = head;
        Node* curr = head->next;
        while(curr->data!=val){
            prev = prev->next;
            curr = curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtStart(head, 71);
    insertAtEnd(tail, 14);
    insertAtMiddle(head, tail, 2, 62);
    insertAtMiddle(head, tail, 5, 89);
    insertAtMiddle(head, tail, 1, 8);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    deleteNode(head, 1);
    deleteNode(head, 5);
    print(head);
    deleteByVal(head, 62);
    print(head);
}
