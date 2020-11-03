#include <iostream>
#include <stack>

using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    stack<int> s; 
	    int i = 0,maxarea = 0,area;
	    while(i < n){
	        if(s.empty() || arr[s.top()] <= arr[i]){
	            s.push(i++);
	        }
	        else{
	            int x = s.top();
	            s.pop();
	            if(s.empty()){
	                area = arr[x]*i;
	            }
	            else{
	                area = arr[x]*(i-s.top()-1);
	            }
	            if(area > maxarea){
	                maxarea = area;
	            }
	        }
	    }
	    while(!s.empty()){
	        int x = s.top();
	            s.pop();
	            if(s.empty()){
	                area = arr[x]*i;
	            }
	            else{
	                area = arr[x]*(i-s.top()-1);
	            }
	            if(area > maxarea){
	                maxarea = area;
	            }
	    }
	    cout<<maxarea<<'\n';
	}
	return 0;
}