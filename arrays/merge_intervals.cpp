#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(merged.back()[1] >= intervals[i][0]){
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> vect = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = solution.merge(vect);
    int size = ans.size();
    for(int i=0 ; i<size ; i++){
        std::cout << "["<<ans[i][0]<<","<<ans[i][1]<<"]";
    }
}