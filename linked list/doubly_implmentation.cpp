#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }

        ~Node(){
            int value = this -> data;
            if(this->next!=NULL){
                delete next;
                this -> next = NULL;
            }
            cout << "Memory cleared with data : " << value << endl;
        }
};

void print(Node* & head){
    Node* temp = head;
    cout << endl;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtBegin(Node* & head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head=temp;
}

void insertAtEnd(Node* & tail, int data){
    Node* temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node* & head, Node* & tail, int pos, int data){
    if(pos==1){
        insertAtBegin(head, data);
        return;
    }
    else{
        Node* temp = new Node(data);
        Node* itr = head;
        Node* curr = head->next;
        for(int i=1;i<pos-1;i++){
            itr = itr->next;
            curr = curr->next;
        }
        if(itr->next == NULL||curr==NULL){
            insertAtEnd(tail, data);
            return;
        }
        else{
            temp->next = curr;
            curr->prev = temp;
            temp->prev = itr;
            itr->next = temp;
        }
    }
}

void deleteNode(Node* & head, Node* & tail, int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    else{
        Node* itr = head;
        Node* curr = head->next;
        for(int i=1;i<pos-1;i++){
            itr = itr->next;
            curr = curr->next;
        }
        if(curr->next == NULL){
            tail = tail->prev;
            curr->prev = NULL;
            itr->next = NULL;
            delete curr;
            return; 
        }
        else{
            itr->next = curr->next;
            curr->next->prev = itr;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtBegin(head, 12);
    insertAtBegin(head, 89);
    insertAtEnd(tail, 23);
    insertAtEnd(tail, 67);
    insertAtPos(head, tail, 3, 15);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    deleteNode(head, tail, 6);
    deleteNode(head, tail, 1);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
}