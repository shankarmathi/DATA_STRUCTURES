/*
Given an array A[] of N numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains n and x. Next line contains array elements.

Output:
Print 1 if there exist three elements in A whose sum is exactly x, else 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n,sum;
	    cin>>n>>sum;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int f = 0;
	    for(int i=0;i<n;i++){
	        int currsum = sum - v[i];
	        for(int j=i+1;j<n;j++){
	            if(find(v.begin()+j+1,v.end(),currsum - v[j]) != v.end()){
	                f = 1;
	                break;
	            }
	        }
	        if(f == 1){
	            break;
	        }
	    }
	    cout<<f<<'\n';
	}
	return 0;
}