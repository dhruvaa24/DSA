#include<iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(int nums[]) {
        while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]]);
       }
       return nums[0];
    }
};

int main() {
    Solution solution;

    int n;
    std::cout << "Enter the number of digits: " << std::endl;
    std::cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        std::cout << "Enter the " << i+1 << " digit : ";
        std::cin >> a[i];
    }
    std::cout << endl;
    int ans = solution.findDuplicate(a);
    std::cout << "The duplicate element is : "<< ans << std::endl;
    return 0;
}