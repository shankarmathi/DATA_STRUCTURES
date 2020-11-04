/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1
*/

//METHOD - 1

#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        
        // Select 1st element as majority element
        int majority_index=0;
        int count=1;
        
        for(int i=1;i<n;i++){
            
            // If same then increment it's count
            if(v[i]==v[majority_index]){
                count++;
            }
            // If different cancel it's count
            else{
                count--;
            }
            
            // If count reduces to zero select current element as majority element and set count to 1
            if(count==0){
                majority_index=i;
                count=1;
            }
            
        }
        
        // It returns majority element candidate so check if it's count>n/2
        count=0;
        for(int i=0;i<n;i++){
            if(v[i]==v[majority_index]){
                count++;
            }
        }
        if(count>n/2){
            cout<<v[majority_index]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
    }
}

//METHOD - 2

#include <iostream>
#include <unordered_map>
#include <limits.h>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n,ans;
	    cin>>n;
	    int arr[n];
	    unordered_map<int,int> m;
	    int max = INT_MIN;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        m[arr[i]] += 1;
	        if(m[arr[i]] > max){
	            max = m[arr[i]];
	            ans = arr[i];
	        }
	    }
	    if(max > n/2){
	        cout<<ans<<'\n';
	    }
	    else{
	        cout<<-1<<'\n';
	    }
	}
	return 0;
}