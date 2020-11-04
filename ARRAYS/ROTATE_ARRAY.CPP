/*
Given an unsorted array arr[] of size N, rotate it by D elements (clockwise). 

Input:
The first line of the input contains T denoting the number of testcases. First line of each test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105

Example:
Input:
2
5 2
1 2 3 4 5 
10 3
2 4 6 8 10 12 14 16 18 20

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6
*/

//METHOD 1

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>n>>k;
	    k = k%n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    for(int i=k;i<n+k;i++){
	        cout<<v[i%n]<<" ";
	    }
	    cout<<'\n';
	}
	return 0;
}

//METHOD 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leftrotatebyone(vector<int>&arr,int n){
    int temp = arr[0];
    for(int i=0;i<n;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void display(vector<int> &arr,int n){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<'\n';
}

void leftrotate(vector<int>& arr,int n,int k){
    for(int i=0;i<k;i++){
        leftrotatebyone(arr,n);
    }
    display(arr,n);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>n>>k;
	    k = k%n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    leftrotate(v,n,k);
	}
	return 0;
}

//METHOD 3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>n>>k;
	    k = k%n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    reverse(v.begin(),v.begin()+k);
	    reverse(v.begin()+k,v.end());
	    reverse(v.begin(),v.end());
	    for(auto i:v){
	        cout<<i<<" ";
	    }
	    cout<<'\n';
	}
	return 0;
}