#include <bits/stdc++.h>
using namespace std;

int checkPal(char str[], int x){
    int start=0;
    int end=x-1;
    while(start<end){
        if(str[start]!=str[end]){
            cout << "Not a palindrome. "<<endl;
            return 0;
        }
        start++;
        end--;
    }
    cout << "The given string is a palindrome. "<< endl;
    return 0;
}

int main(){
    char str[20];
    cout << "Enter the string : " << endl;
    cin >> str;

    int x = strlen(str);
    checkPal(str , x);
    return 0;
}