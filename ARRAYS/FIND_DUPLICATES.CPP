/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3 
Explanation: 2 and 3 occur more than once
in the given array.
*/

//METHOD 1
vector<int> duplicates(int a[], int n) {
    vector<int> b;
    for(int i=0;i<n;i++){
        if(a[abs(a[i])] >= 0){
            a[abs(a[i])] = -a[abs(a[i])];
        }
    }
    for(auto i:a){
        if(i < 0){
            b.push_back(i);
        }
    }
    if(b.size() == 0){
        b.push_back(-1);
    }
    sort(b.begin(),b.end());
    return b;
}

//METHOD 2
#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}


vector<int> duplicates(int a[], int n) {
    vector<int> b;
    for(int i=0;i<n;i++){
        a[a[i]%n] += n;
    }
    for(int i=0;i<n;i++){
        if(a[i]/n > 1){
            b.push_back(i);
        }
    }
    if(b.size() == 0){
        b.push_back(-1);
    }
    return b;
}
