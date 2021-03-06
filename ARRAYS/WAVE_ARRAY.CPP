/*
Given a sorted array arr[] of non-repeating integers without duplicates. Sort the array into a wave-like array and return it. In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).

Input:
The first line contains an integer T, depicting total number of test cases. T testcases follow. The first line of each testcase contains an integer N depicting the size of the array. The second line contains N space separated elements of the array.

Output:
For each testcase, in a new line, print the array into wave-like array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
0 ≤ A[i] ≤107

Example:
Input:
1
5
1 2 3 4 5
Output:
2 1 4 3 5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long tc;
	cin>>tc;
	while(tc--){
	    long n;
	    cin>>n;
	    vector<long> v(n);
	    for(long i=0;i<n;i++){
	        cin>>v[i];
	    }
	    sort(v.begin(),v.end());
	    for(int i=0;i<n-1;i+=2){
	        swap(v[i],v[i+1]);
	    }
	    for(auto i:v){
	        cout<<i<<" ";
	    }
	    cout<<'\n';
	}
	return 0;
}