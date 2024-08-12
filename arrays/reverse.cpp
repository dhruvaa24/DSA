#include<iostream>
using namespace std;

class Solution{
    public:
    void reverse(int A[],int n){
        int start = 0;
        int end = n-1;
        while(start<end){
            int temp=A[start];
            A[start]=A[end];
            A[end]=temp;

            start++;
            end--;
        }
    }
};

int main(){
    Solution solution;

    int n;
    cout << "Enter the number of digit: ";
    cin >> n;

    int A[n];
    for(int i=0;i<n;i++){
        cout << "Enter the " << i+1 << " digit: ";
        cin >> A[i];
    }

    solution.reverse(A,n);
    cout << "The reversed array is: ";
    for(int i=0;i<n;i++){
        cout << "\n" << A[i];
    }
    cout << endl;

    return 0;
}