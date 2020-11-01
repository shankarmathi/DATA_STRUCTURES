#include <iostream>
#include <vector> 

using namespace std;

int main(){
    int n,capacity,i,j;
    cin>>n;
    int value[101],weight[101];
    //value[n],weight[n]
    for(i = 0; i < n; i++){
        cin>>value[i]>>weight[i];
    }
    cin>>capacity;
    int dp[101][101];
    //dp[n+1][capacity+1]
    for(i=0;i<=n;i++){
        for(j=0;j<=capacity;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(weight[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-weight[i-1]] + value[i-1] ,dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    cout<<dp[n][capacity]<<'\n';

    //to print selected items

    i = n,j = capacity;
    while(i && j){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            printf("weight: %d , value: %d\n",weight[i-1],value[i-1]);
            j = j - weight[i-1];
            i--;
        }
    }

}