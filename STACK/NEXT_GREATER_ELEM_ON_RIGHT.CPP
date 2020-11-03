#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	long tc;
	cin>>tc;
	while(tc--){
	    long n;
	    cin>>n;
	    vector<long> v(n);
	    stack<long> s;
	    for(long i=0;i<n;i++){
	        cin>>v[i];
	    }
	    for(long i=n-1;i>=0;i--){
	        if(s.empty()){
	            s.push(v[i]);
	            v[i] = -1;
	        }
	        else{
	            if(v[i] < s.top()){
	                long t = v[i];
	                v[i] = s.top();
	                s.push(t);
	            }
	            else{
	                while(!s.empty() && s.top() <= v[i]){
	                    s.pop();
	                }
	                if(s.empty()){
	                    s.push(v[i]);
	                    v[i] = -1;
	                }
	                else{
	                   long t = v[i];
	                    v[i] = s.top();
	                    s.push(t); 
	                }
	            }
	        }
	    }
	    for(auto i:v){
	        cout<<i<<" ";
	    }
	    cout<<'\n';
	}
	return 0;
}