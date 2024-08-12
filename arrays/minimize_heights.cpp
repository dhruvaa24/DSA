#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        std::sort(arr,arr+n);
        int min_diff = arr[n-1]-arr[0];
        int mini,maxi;
        for(int i=0;i<n;i++){
            if(arr[i+1]-k<0)
                continue;
            
            mini = min(arr[0]+k,arr[i+1]-k);
            maxi = max(arr[n-1]-k,arr[i]+k);
            min_diff = min(min_diff,maxi-mini);
        }
        
        return min_diff;
    }
};

int main(){
    Solution solution;

    int N;
    std :: cout << "Enter number of digits: ";
    std :: cin >> N;
    int A[N];

    for (int i=0;i<N;i++){
        std :: cout << "Enter the " << i+1 << " value: ";
        std :: cin >> A[i];
    }

    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    int result = solution.getMinDiff(A, N, k);
    std :: cout << "The maximun sum of the subarray is : " << result << std :: endl;   
    return 0;
}