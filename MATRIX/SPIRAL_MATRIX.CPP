vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> ans;
    int top = 0,bottom = A.size()-1,left = 0,right = A[0].size()-1;
    while(1){
        if(left > right){
            break;
        }
        for(int i=left;i<=right;i++){
            ans.push_back(A[top][i]);
        }
        top += 1;
        if(top > bottom ){
            break;
        }
        for(int i=top;i<=bottom;i++){
            ans.push_back(A[i][right]);
        }
        right -= 1;
        if(right < left){
            break;
        }
        for(int i=right;i>=left;i--){
            ans.push_back(A[bottom][i]);
        }
        bottom -= 1;
        if(bottom < top){
            break;
        }
        for(int i=bottom;i>=top;i--){
            ans.push_back(A[i][left]);
        }
        left += 1;
    }
    return ans;
}