#include<iostream>
#include<algorithm>

void rotate(int arr[], int n)
{
    std::swap(arr[0], arr[n-1]);
    for(int i=n-1;i>1;i--){
        std::swap(arr[i], arr[i-1]);
    }
}

int main() {
    int n;
    std::cout << "Enter number of digits: ";
    std::cin >> n;
    int a[n];

    std::cout << "Enter the values: " << std::endl;
    for (int i=0;i<n;i++){
       std::cin >> a[i];
    }

    rotate(a,n);

    std::cout << "After rotating: ";
    for (int i=0;i<n;i++){
       std::cout << a[i] <<std::endl;
    }   
    return 0;
}
