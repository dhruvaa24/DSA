#include<iostream>
using namespace std;

class Stack{
    public:
        int top;
        int *arr;
        int size;

        Stack(int size){
            this->size=size;
            arr = new int[size];
            top=-1;
        }

        void push(int x){
            if(top<size-1){
                top++;
                arr[top]=x;
            }
            else{
                cout << "stack overloaded " << endl;
            }
        }

        void pop(){
            if(top!=-1){
                int y = arr[top];
                top--;
                cout << y << " popped" << endl;
            }
            else{
                cout << "stack underloaded " <<endl;
            }
        }

        void peek(){
            if(top>=0){
                cout<< "The top elemenet is " << arr[top] << endl;
            }
            else{
                cout << "Stack underloaded " << endl;
            }
        }

        void s(){
            cout << "The size of the stack is " << top+1 << endl;
        }
};

class Queue{
    public:
        int size;
        int curr_size;
        int *q;
        int start;
        int end;

        Queue(int size){
            this->size = size;
            q = new int[size];
            curr_size = 0;
            start =-1;
            end = -1;
        }

        void push(int x){
            if(curr_size == size){
                cout << "Queue is full " <<endl;
                return;
            }
            else if(curr_size == 0){
                start=0, end=0;
            }
            else{
                end = (end+1)%size;
            }
            q[end] = x;
            curr_size++;
        }

        void pop(){
            if(curr_size == 0){
                cout << "There is no element in queue to pop." <<endl;
                return;
            }
            int popped = q[start];
            if(curr_size == 1){
                start = end = -1;
            }
            else{
                start = (start+1)%size;
            }
            curr_size--;
            cout << popped << " popped." << endl;
        }

        void top(){
            if(curr_size == 0){
                cout << "Stack underflow" <<endl;
            }
            else{
                cout << "Top element is : " << q[start] << endl;
            }
        }

        void s(){
            cout << "The size of the queue is : " << curr_size << endl;
        }

};

int main(){
    // Stack st(4);
    // st.push(2);
    // st.push(6);
    // st.push(9);
    // st.push(4);
    // st.peek();
    // st.pop();
    // st.peek();
    // st.s();

    Queue q(5);
    q.push(5);
    q.push(4);
    q.push(3);
    q.pop();
    q.top();
    q.s();
    return 0;
}