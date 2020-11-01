#include <iostream>

using namespace std;

int main(){
    int row,col,i,j;
    cin>>row>>col;
    int cost[101][101];
    for(i = 0;i < row;i++){
        for(j = 0;j < col;j++){
            cin>>cost[i][j];
       }
    }
    int dp[101][101];
    for(i = 0;i < row;i++){
        for(j=0;j < col;j++){
            if(!i && !j){
                dp[i][j] = cost[i][j];
            }
            else if(!i && j){
                dp[i][j] = dp[i][j-1] + cost[i][j];
            }
            else if(i && !j){
                dp[i][j] = dp[i-1][j] + cost[i][j];
            }
            else{
                dp[i][j] =  min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + cost[i][j];
            }
       }
    }

    cout<<dp[row-1][col-1]<<'\n';

    //to print the path
    i = row-1,j = col-1;
    while(i  && j ){
        cout<<dp[i][j]<<"<-";
        int mini = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        if(mini == dp[i-1][j-1]){
            i--;
            j--;
        }
        else if(mini == dp[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }
    while(i){ 
        cout<<dp[i][j]<<"<-";
        i--;
    }
    while(j){
        cout<<dp[i][j]<<"<-";
        j--;
    }
    cout<<dp[i][j];
}