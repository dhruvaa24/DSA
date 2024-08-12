#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            for (int num : nums) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            return;
        }
        if(n==2){
            reverse(nums.begin(), nums.end());    
        }
        else{
            int x=-1;
            for(int i=n-2;i>=0;i--){
                if(nums[i]<nums[i+1]){
                    x=i;
                    break;
                }
            }
            if(x==-1){
                reverse(nums.begin(), nums.end());
            }
            else{
                for(int i=n-1;i>x;i--){
                    if(nums[i]>nums[x]){
                        swap(nums[i],nums[x]);
                        break;
                    }
                }
                reverse(nums.begin()+x+1,nums.end());
            }
        }
        for(int i=0;i<n;i++){
            std::cout << nums[i];
        }
    }
};

int main(){
    Solution solution;
    int n;
    std::cout << "Enter the number of elements you want : ";
    std::cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        std::cout << "Enter the value at position " << i+1 << " : ";
        std::cin >> vect[i];
    }
    std::cout << "The next permutation is : " << std::endl;
    solution.nextPermutation(vect);
    return 0;
}