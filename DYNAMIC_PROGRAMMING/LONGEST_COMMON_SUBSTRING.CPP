#include <iostream>

using namespace std;

int main(){
    string arr,brr;
    cin>>arr>>brr;
    int i,j,l1 = arr.length(),l2 = brr.length(),max_len = 0;
    int dp[l1+1][l2+1];
    for(i=0;i<=l1;i++){
        for(j=0;j<=l2;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                if(arr[i-1] == brr[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    max_len = max(max_len,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    cout<<max_len;
}