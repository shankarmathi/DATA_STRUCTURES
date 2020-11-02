//also known as INTERVAL SEARCH
//designed for sorted data structures
//efficient than linear search

#include <iostream>

using namespace std;
int binarysearch(int arr[],int start,int end,int val){
    if(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == val){
            return mid;
        }
        else if(arr[mid] < val){
            return binarysearch(arr,start,mid-1,val);
        }
        else{
            return binarysearch(arr,mid+1,end,val);
        }
    }
    return -1;
}

int binary_search_using_loop(int arr[],int left,int right,int x){
    while (left <= right)
    {
        int mid = (left + right)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int n,val;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>val;
    int x = binarysearch(arr,0,n-1,val);
    if(x == -1){
        cout<<"ELEMENT NOT FOUND";
    }
    else
    {
        cout<<"ELEMENT FOUND @ INDEX "<<x;
    }
}