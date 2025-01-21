//#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

int solve(){
    int x,y;
    cin >>x>>y;
    vector<int> arr(x);
    for(int i=0;i<x;i++){
        cin >>arr[i];
    }
    int count=0,steal=0;
    for(int i=0;i<x;i++){
        if(arr[i]>=y){
            steal+=arr[i];
            arr[i]=0;
            continue;
        }
        if(arr[i]==0&&steal!=0){
            arr[i]=1;
            steal--;
            count++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}