/*
Write a program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x. 
Examples: 

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3, 1
If we calculate the sum of the output,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
No valid pair exists.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int  tc;
	cin>>tc;
	while(tc--){
	    int n,sum;
	    cin>>n>>sum;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int flag = 0;
	    for(int i=0;i<n;i++){
	        if(v[i] < sum){
	            if(find(v.begin()+i+1,v.end(),sum - v[i]) != v.end()){
	                //cout<<v[i]<<" "<<sum - v[i];
	                flag = 1;
	                break;
	            }
	        }
	    }
	    if(flag == 1){
	        cout<<"Yes"<<'\n';
	    }
	    else{
	        cout<<"No"<<'\n';
	    }
	}
	return 0;
}