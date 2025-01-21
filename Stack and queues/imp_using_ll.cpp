#include<iostream>
using namespace std;

class stackNode {
    public:
        int data;
        stackNode * next;
        int size;

        stackNode(int d){
            data = d;
            next = NULL;
        }
};

class Stack{
    public:
        stackNode *top;
        int size;
        Stack(){
            top = NULL;
            size = 0;
        }

        void push(int x){
            stackNode * temp = new stackNode(x);
            temp->next = top;
            top = temp;
            size++;
        }

        void pop(){
            if(size == 0){
                cout << "Stack underflow" <<endl;
            }
            else{
                int x = top->data;
                stackNode * temp = top;
                top =top->next;
                temp->next = NULL;
                size -- ;
                delete temp;
                cout << x << " popped" << endl;
            }
        }

        void s(){
            cout << "The size of stack is " << size << endl;
        }

        void peek(){
            int x = top->data;
            cout << "The data at the top is " << x << endl;
        }
};

class queueNode {
    public: 
        int data;
        queueNode *next;

        queueNode(int x){
            data = x;
            next = NULL;
        }
};

class Queue {
    public:
        queueNode* start ;
        queueNode* end;
        int size;

        Queue(){
            size = 0;
            start = end = NULL;
        }

        void push(int data){
            queueNode * temp = new queueNode(data);
            if(size == 0){
                start = end = temp;
            }
            else{
                end->next = temp;
                end = temp;
            }
            size++;
        }

        void pop(){
            if(size == 0){
                cout << "The queue is empty " <<endl;
                exit(1);
            } 
            else{
                int x = start->data;
                queueNode* temp = start;
                start = start->next;
                temp->next = NULL;
                delete temp;
                size--;
                cout << x << " popped" << endl;
            }
        }

        void top(){
            cout << "The value at top is : " << start->data << endl;
        }

        void s(){
            cout << "The size of queue is " << size << endl;
        }

};

int main(){
    // Stack st;
    // st.push(2);
    // st.push(6);
    // st.push(9);
    // st.push(4);
    // st.peek();
    // st.pop();
    // st.peek();
    // st.s();

    Queue q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.pop();
    q.top();
    q.s();
    return 0;
}