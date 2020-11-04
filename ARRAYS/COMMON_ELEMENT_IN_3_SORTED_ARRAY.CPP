/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long tc;
	cin>>tc;
	while(tc--){
	    long long n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    vector<long long> v1(n1),v2(n2),v3(n3);
	    for(long long i=0;i<n1;i++){
	        cin>>v1[i];
	    }
	    for(long long i=0;i<n2;i++){
	        cin>>v2[i];
	    }
	    for(long long i=0;i<n3;i++){
	        cin>>v3[i];
	    }
	    long long i=0,j=0,k=0,f=0;
	    while(i < n1 && j < n2 && k < n3){
	        if(v1[i] == v2[j] and v2[j] == v3[k]){
	            cout<<v1[i]<<" ";
	            f = 1;
	            i++;
	            j++;
	            k++;
	        }
	        else if(v1[i] < v2[j]){
	            i++;
	        }
	        else if(v2[j] < v3[k]){
	            j++;
	        }
	        else{
	            k++;
	        }
	    }
	    if(f == 0){
	        cout<<-1;
	    }
	    cout<<'\n';
	}
	
	return 0;
}