#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        std::sort(arr , arr + (r+1));
        return arr[k-1];
    }
};

int main() {
    Solution solution;

    int n;
    std::cout << "Enter the number of digits: ";
    std::cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        std::cout << "Enter the " << i+1 << " digit : ";
        std::cin >> a[i];
    }
    int k;
    std::cout << "Enter the value of k : ";
    std::cin >> k;
    int ans = solution.kthSmallest(a,0,n-1,k);
    std::cout << "The kth smallest element is : "<< ans << std::endl;
    return 0;
}