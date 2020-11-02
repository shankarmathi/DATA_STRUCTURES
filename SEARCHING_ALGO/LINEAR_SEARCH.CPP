//ALSO KNOWN AS SEQUENTIAL SEARCH

#include <iostream>

using namespace std;

void linear_search(int arr[],int num,int n){
    int temp = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == num){
            cout<<"element found @ index "<<i<<'\n';
            temp = 0;
            break;
        }
    }
    if(temp == -1){
        cout<<"element not found";
    }
}

int main(){
    int n,find;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>find;
    linear_search(arr,find,n);
}