#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1||n==0){
            return 0;
        }
        int max_profit = 0;
        int min_price = prices[0];
        
        for(int i=1;i<n;i++){
            min_price = std::min(min_price, prices[i]);
            int profit = prices[i]-min_price;
            max_profit = std::max(profit,max_profit);
        }
        return max_profit;
    }
};

int main(){
    Solution sol;
    int n;
    std::cout << "Enter the number of days you want : ";
    std::cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        std::cout << "Enter the price of stock at day " << i+1 << " : ";
        std::cin >> vect[i];
    }
    int ans = sol.maxProfit(vect);
    std::cout << "The maximum profit is : "<< ans << std::endl;

}