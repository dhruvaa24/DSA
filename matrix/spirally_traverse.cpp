#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> traversed;
        
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0 , bottom = r-1 , left = 0 , right = c-1;
        while(top<=bottom && left<=right){
            
            for(int i=left;i<=right;i++){
                traversed.push_back(matrix[top][i]);
            }top++;
            
            for(int i=top;i<=bottom;i++){
                traversed.push_back(matrix[i][right]);
            }right--;
            
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    traversed.push_back(matrix[bottom][i]);
                }bottom--;
            }
            
            
            if(left<=right){
                for(int i=bottom;i>=top;i++){
                    traversed.push_back(matrix[i][left]);
                }left++;
            }
        }
        return traversed;
    }
};

int main(){
    Solution sol;
    int r,c;
    std::cout << "Enter the number of rows : ";
    std::cin >> r;
    std::cout << "Enter the number of columns : ";
    std::cin >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    std::cout << "enter the value at positions " << std::endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cout << "row "<< i+1 << " and column " << j+1 << " : ";
            std::cin >> matrix[i][j];
        }
    }

    vector<int> ans = sol.spirallyTraverse(matrix);
    std::cout << ans.size();
    std::cout << "Spiral Traversal: ";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i];
        if (i < ans.size() - 1) {
            std::cout << " ";  // Add space between elements
        }
    }
    std::cout << endl;

    return 0;
}