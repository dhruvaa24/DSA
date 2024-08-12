#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            // int i=0,j=0;
            // while(i<n){
            //     if(arr2[j]<arr1[i]){
            //         std::swap(arr1[i],arr2[j]);
            //         std::sort(arr2,arr2+m);
            //         i++;
            //     }
            // }
            int i=n-1,j=0;
            while(i>=0&&j<m){
                if(arr1[i]>arr2[j]){
                    std::swap(arr1[i],arr2[j]);
                }
                i--;
                j++;
            }
            std::sort(arr1,arr1+n);
            std::sort(arr2,arr2+m);
        }

        void printArrays(long long arr1[], int n, long long arr2[], int m) 
        {
            for (int i = 0; i < n; i++) {
                std::cout << arr1[i] << " ";
            }
            std::cout << "\n";
            for (int i = 0; i < m; i++) {
                std::cout << arr2[i] << " ";
            }
            std::cout << "\n";
        }
};

int main(){
    Solution solution;

    int N;
    std :: cout << "Enter number of digits of 1st array: ";
    std :: cin >> N;
    long long A[N];

    for (int i=0;i<N;i++){
        std :: cout << "Enter the " << i+1 << " value: ";
        std :: cin >> A[i];
    }

    int M;
    std :: cout << "Enter number of digits of 2nd array: ";
    std :: cin >> M;
    long long B[M];

    for (int i=0;i<M;i++){
        std :: cout << "Enter the " << i+1 << " value: ";
        std :: cin >> B[i];
    }

    solution.merge(A,B,N,M);
    solution.printArrays(A,N,B,M);
    return 0;
}