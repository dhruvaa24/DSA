#include<iostream>
#include <climits>
using namespace std;

class Solution {
  public:

    long long maxSubarraySum(int arr[], int n) {
        long long max_so_far = INT_MIN;
        long long max_here = 0;
        
        for(int i=0;i<n;i++){
            max_here = max_here + arr[i];
            if(max_so_far < max_here)
                max_so_far = max_here;
                
            if(max_here < 0)
                max_here = 0;
        }
        return max_so_far;
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

    int result = solution.maxSubarraySum(A, N);
    std :: cout << "The maximun sum of the subarray is : " << result << std :: endl;   
    return 0;
}
