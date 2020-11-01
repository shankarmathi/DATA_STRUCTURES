#include <iostream>

using namespace std;

int main(){
    int n,i,j,max_e=1,max_i=0;
    cin>>n;
    int arr[n],dp[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = 1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[j] <= arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
                if(dp[i] > max_e){
                    max_e = dp[i];
                    max_i = i;
                }
            }
        }
    }
    cout<<max_e<<" "<<max_i<<'\n';
    while(max_e > 0){
        if(dp[max_i] == max_e){
            cout<<arr[max_i]<<"<--";
            max_e--;
        }
        max_i--;
    }
}