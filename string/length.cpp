#include <bits/stdc++.h>
using namespace std;

void reverse(char name[], int x){
    int start=0;
    int end=x-1;
    while(start!=end){
        swap(name[start], name[end]);
        start++;
        end--;
    }
    cout << "Reverse : " << name << endl;
}

int getLength(char name[]){
    int count = 0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char name[20];
    cout << "Enter your name : " << endl;
    cin >> name;

    int x = getLength(name);
    //int x =strlen(name);
    cout << "Length : " << x << endl;
    reverse(name, x);

    return 0;
}