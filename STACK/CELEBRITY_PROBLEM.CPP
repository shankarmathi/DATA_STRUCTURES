#include <iostream>

using namespace std;

#define MAX 501


int getId(int M[MAX][MAX], int n)
{
    int s = 0,e = n-1;
    while(s < e){
        if(M[s][e]){
            s++;
        }
        else{
            e--;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=s && (M[s][i] || !M[i][s])){
            return -1;
        }
    }
    return s;
}

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

