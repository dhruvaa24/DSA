#include <iostream>
#include <algorithm>

class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {

        std::sort(a, a + n);
        std::sort(b, b + m);
        
        // Use two pointers to merge the arrays while counting unique elements
        int i = 0, j = 0, count = 0;
        int lastElement = -1; 
        
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                if (a[i] != lastElement) {
                    count++;
                    lastElement = a[i];
                }
                i++;
            } 
            else if (a[i] > b[j]) {
                if (b[j] != lastElement) {
                    count++;
                    lastElement = b[j];
                }
                j++;
            } 
            else {
                if (a[i] != lastElement) {
                    count++;
                    lastElement = a[i];
                }
                i++;
                j++;
            }
        }
        
        while (i < n) {
            if (a[i] != lastElement) {
                count++;
                lastElement = a[i];
            }
            i++;
        }
        
        while (j < m) {
            if (b[j] != lastElement) {
                count++;
                lastElement = b[j];
            }
            j++;
        }
        
        return count;
    }
};

int main(){
    Solution sol;

    int n;
    std::cout << "Enter the number of elements for 1st array: ";
    std::cin >> n;
    int a[n];
    std::cout << "Enter the elements of 1st array: ";
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }

    int m;
    std::cout << "Enter the number of elements for 2nd array: ";
    std::cin >> m;
    int b[m];
    std::cout << "Enter the elements of 2nd array: ";
    for(int i=0;i<m;i++){
        std::cin >> b[i];
    }

    int count = sol.doUnion(a,n,b,m);
    std::cout << "The number of elements after doing union are : " << count << std::endl;

    return 0;
}