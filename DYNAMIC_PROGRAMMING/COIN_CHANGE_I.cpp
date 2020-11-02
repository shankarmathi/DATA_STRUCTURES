//NO OF WAYS
#include <iostream>

using namespace std;

int main(){
    int i,j,n,amount;
    cin>>n>>amount;
    int coins[n];
    for(i=0;i<n;i++){
        cin>>coins[i];
    }
    //using 2d array
    int dp[n+1][amount+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=amount;j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else{
                if(j >= coins[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                    //without including + with including
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][amount]<<'\n';
    //using 1d array
    int dpmat[amount+1] = {1};
    for(i=0;i<n;i++){
        for(j=coins[i];j<=amount;j++){
            dpmat[j] += dpmat[j-coins[i]];
        }
    }
    cout<<dpmat[amount];
}