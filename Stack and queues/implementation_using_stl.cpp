#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int top;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int e){
        if(size>top){
            top++;
            arr[top]=e;
        }
        else{
            cout << "stack overflow" << endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout << "Stack underflow" << endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout << "stack is empty " << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){
    Stack st(5);
    st.push(90);
    st.push(7);
    st.push(83);
    cout << st.peek() <<endl;
    st.pop();
    st.pop();
    cout << st.peek() <<endl;
    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }
    return 0;
}