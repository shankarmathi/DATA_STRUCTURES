#include <iostream>

using namespace std;

int main(){
    string arr,brr;
    cin>>arr;
    cin>>brr;
    int l1 = arr.length(),l2 = brr.length(),i,j;
    int dp[l1+1][l2+1];
    for(i=0;i<=l1;i++){
        for(j=0;j<=l2;j++){
            if(i == 0 || j == 0 ){
                dp[i][j] = 0;
            }
            else if(arr[i-1] == brr[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[l1][l2];
}