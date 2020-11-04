#include <iostream>

using namespace std;

int main(){
    int i,j,k,r,c;
    cin>>r>>c;
    int mat[r][c],rotated_mat[c][r];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

    for(i=0;i<c;i++){
        for(j=0,k=r-1;j<r;j++,k--){
            rotated_mat[i][j] = mat[k][i];
        }
    }

    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            cout<<rotated_mat[i][j]<<" ";
        }
        cout<<'\n';
    }
}