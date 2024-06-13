#include<iostream>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int count = 0;
        int after_jump = 0;
        int current = 0;
        for(int i=0;i<n;i++){
            after_jump = max(after_jump , i+arr[i]);
            if(i==current){
                current = after_jump;
                count++;
                if(after_jump >= n-1){
                    return count;
                }
            }
        }
        return -1;
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
    int ans = solution.minJumps(a,n);
    std::cout << "The minimum number of jumps to reach ata last is : "<< ans << std::endl;
    return 0;
}

