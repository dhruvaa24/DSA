#include<iostream>
using namespace std;

class Solution{
   public:
   void negaside(int a[],int n){
        int p=0;
        for(int i=0;i<n;i++){
            if(a[i]<0 && i!=p){
                swap(a,i,p);
                p++;
            }
        }
   } 
   void swap(int a[],int i,int p){
        int temp=a[i];
        a[i]=a[p];
        a[p]=temp;
   }
};

int main(){
    Solution solution;
    int n;
    cout << "Enter the number of values: ";
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cout <<"\nEnter the "<<i+1<<" value: ";
        cin >> a[i];
    }

    solution.negaside(a,n);
    cout << "The solution with negative numbers at starting of array is: "<<endl;
    for(int i=0;i<n;i++){
        cout << a[i] <<endl;
    }
}