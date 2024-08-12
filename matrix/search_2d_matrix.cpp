#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0;i<r;i++){
            if(target<=matrix[i][c-1]){
                if(target==matrix[i][c-1]){
                    return true;
                }
                for(int j=0;j<c;j++){
                    if(target==matrix[i][j]){
                        return true;
                    }
                }return false;
            }
        }return false;
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
    int tar;
    std::cout << "Enter the target value :";
    std::cin >> tar;

    bool ans = sol.searchMatrix(matrix, tar);
    if(ans){
        std::cout<< "The target value is present in the matrix.";
    }
    else{
        std::cout << "The traget value is not present in the matrix.";
    }
}