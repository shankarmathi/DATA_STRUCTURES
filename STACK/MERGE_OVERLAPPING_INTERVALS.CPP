#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
	    vector<pair<int,int>> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i].first;
	        cin>>v[i].second;
	    }
	    sort(v.begin(),v.end());
	    pair<int,int> p = v[0];
	    vector<pair<int,int>> ans;
	    for(int i=0;i<n;i++){
	        if(v[i].first <= p.second){
	            p.second = max(v[i].second,p.second);
	        }
	        else{
	            ans.push_back(p);
	            p = v[i];
	        }
	    }
	    ans.push_back(p);
	    for(auto i:ans){
	        cout<<i.first<<" "<<i.second<<" ";
	    }
	    cout<<'\n';
    }
	return 0;
}