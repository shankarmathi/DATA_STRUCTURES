#include <iostream>

using namespace std;

int main(){
    int n,i,j,sum;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;
    bool dp[n+1][sum+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=sum;j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else{
                if(arr[i-1] <= j){
                     dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][sum]<<endl;
    i = n,j = sum;
    while(i && j){
        if(dp[i-1][j]){
            i--;
        }
        else{
            cout<<arr[i-1]<<"+";
            j = j - arr[i-1];
            i--;
        }
    }
}