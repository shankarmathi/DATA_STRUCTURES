/*
Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n,rsum = 0;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        rsum += v[i];
	    }
	    int lsum = 0,f = 0;
	    for(int i=0;i<n;i++){
	        rsum -= v[i];
	        if(rsum == lsum){
	            cout<<i+1<<'\n';
	            f = 1;
	            break;
	        }
	        lsum += v[i];
	    }
	    if(f == 0){
	        cout<<-1<<'\n';
	    }
	}
	return 0;
}