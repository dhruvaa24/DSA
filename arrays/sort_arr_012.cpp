#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int p=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                swap(a,i,p);
                p++;
            }
        }
        for(int i=p;i<n;i++){
            if(a[i]==1){
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

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of digits: " << endl;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cout << "Enter the " << i+1 << " digit : ";
        cin >> a[i];
    }
    cout << endl;
    solution.sort012(a,n);
    cout << "The sorted array is : ";
    for(int i=0;i<n;i++){
        cout << a[i];
    }

    return 0;
}
