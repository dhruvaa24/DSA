#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
    node(int x){
        this->data=x;
        this->next=NULL;
    }
};

void print(node *& head){
    node * temp = head;
    while(temp!=NULL){
        cout << temp->data <<endl;
        temp = temp->next;
    }
}

void insertAtHead(node *& head, int x){
    node * newnode1 = new node(x);
    newnode1->next = head;
    head = newnode1;
}

void insertAtEnd(node *& tail, int x){
    node * newnode = new node(x);
    tail->next = newnode;
    tail = newnode;
}

void insertAtMid(node *& head, node *& tail, int x,int pos){
    if(pos==1){
        insertAtHead(head, x);
        return;
    }
    else{
        node * temp = new node(x);
        node * itr = head;
        for(int i=1;i<pos-1;i++){
            itr = itr->next;
        }
        if(itr->next == NULL){
            insertAtEnd(tail, x);
            return;
        }
        else{
            temp->next = itr->next;
            itr->next = temp;
        }
    }
}

void deleteNode(node *& head, int pos){
    node * temp = head;
    node * prev = NULL;
    node * curr = head;
    if(pos == 1){
        head = head->next;
        temp->next = NULL;
        delete(temp);
        return;
    }
    else{
        for(int i=1;i<pos;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete(curr);
    }
}

int main(){
    node * node1 = new node(2);
    node * head = node1;
    node * tail = node1;
    // cout << node1->data <<endl;
    // cout << node1->next <<endl;
    insertAtHead(head, 3);
    insertAtEnd(tail, 6);
    insertAtMid(head, tail, 8, 2);
    print(head);
}