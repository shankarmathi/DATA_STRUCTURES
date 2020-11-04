/*
You are given an array A (distinct elements) of size N. Find out the maximum difference between any two elements such that larger element appears after the smaller number in A.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line of each test case is N,N is the size of array. The second line of each test case contains N elements separated by spaces.

Output:
For each testcase, print the maximum difference between two element. Otherwise print -1

Constraints:
1 <= T <= 100
2 <= N <= 107
0 <= Ai <= 107

Example:
Input:
2
7
2 3 10 6 4 8 1
6
7 9 5 6 3 2

Output:
8
2
*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int max_diff = v[1] - v[0],min_ele = v[0];
	    for(int i=1;i<n;i++){
	       if(v[i] - min_ele > max_diff){
	           max_diff = v[i] - min_ele;
	       } 
	       if(v[i]<min_ele){
	           min_ele = v[i];
	       }
	    }
	    cout<<max_diff<<'\n';
	}
	return 0;
}