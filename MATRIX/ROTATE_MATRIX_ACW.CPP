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

    for(i=0,k=c-1;i<c;i++,k--){
        for(j=0;j<r;j++){
            rotated_mat[i][j] = mat[j][k];
        }
    }

    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            cout<<rotated_mat[i][j]<<" ";
        }
        cout<<'\n';
    }
}