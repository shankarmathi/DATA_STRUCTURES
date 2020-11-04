/*
Given a string S as input. You have to reverse the given string.

Input: First line of input contains a single integer T which denotes the number of test cases. T test cases follows, first line of each test case contains a string S.

Output: Corresponding to each test case, print the string S in reverse order.

Constraints:
1 <= T <= 100
3 <= length(S) <= 1000

Example:
Input:
3
Geeks
GeeksforGeeks
GeeksQuiz

Output:
skeeG
skeeGrofskeeG
ziuQskeeG
*/

//METHOD 1

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    string arr;
	    cin>>arr;
	    int s = 0,e = arr.length()-1;
	    while (s < e){
	        swap(arr[s++],arr[e--]);
	    }
	    cout<<arr<<'\n';
	}
	return 0;
}

//METHOD 2

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    string arr;
	    cin>>arr;
	    reverse(arr.begin(),arr.end());
	    cout<<arr<<'\n';
	}
	return 0;
}