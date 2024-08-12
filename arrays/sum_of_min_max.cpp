#include <iostream>
using namespace std;

class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int min = A[0];
        int max = A[0];
        
        for (int i = 1; i < N; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
            }
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        
        int sum = max + min;       
        return sum;
    }
};

int main() {
    Solution solution;

    int N;
    cout << "Enter number of digits: ";
    cin >> N;
    int A[N];

    for (int i=0;i<N;i++){
        cout << "Enter the " << i+1 << " value: ";
        cin >> A[i];
    }

    int result = solution.findSum(A, N);
    cout << "The sum of the minimum and maximum elements is: " << result << endl;   
    return 0;
}
