/*
You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow Each test case consists of two lines. First line of each test case contains an integer N denoting the range of numbers to be inserted in array of size N+2. Second line of each test case contains the N+2 space separated integers denoting the array elements.

Output:
Print the two elements occuring twice in the array. Order of the two elements must be preserved as in the original list, i.e., print the element which arrives first(2nd time).

Constraints:
1 ≤ T ≤ 30
1 ≤ N ≤ 105

Example:
Input:
2
4
1 2 1 3 4 3
5
2 4 3 1 2 7 4

Output:
1 3
2 4
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    n += 2;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i = 0; i < n; i++)  
        {  
            if(arr[abs(arr[i])] > 0){  
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            }
            else{
                cout<< abs(arr[i]) <<" ";
            }
        } 
	    cout<<'\n';
	}
	return 0;
}
