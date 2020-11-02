#include <iostream>

using namespace std;

int main(){
    string arr,brr;
    cin>>arr>>brr;
    int i,j,l1 = arr.length(),l2 = brr.length();
    int dp[l1+1][l2+1];
    for(i=0;i<=l1;i++){
        for(j=0;j<=l2;j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else{
                if(arr[i-1] == brr[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
    }
    for(i=0;i<=l1;i++){
        for(j=0;j<=l2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<dp[l1][l2];
}