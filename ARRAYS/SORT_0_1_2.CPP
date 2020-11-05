/*
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n,num;
	    cin>>n;
	    vector<int> v;
	    while(n--){
	        cin>>num;
	        v.push_back(num);
	    }
	    int l=0,m=0,h=v.size()-1;
	    while(m<=h){
	        if(v[m] == 0){
	            swap(v[l++],v[m++]);
	        }
	        else if(v[m] == 1){
	            m++;
	        }
	        else{
	            swap(v[m],v[h--]);
	        }
	    }
	    for(auto i:v){
	        cout<<i<<" ";
	    }
	    cout<<'\n';
	}
	return 0;
}