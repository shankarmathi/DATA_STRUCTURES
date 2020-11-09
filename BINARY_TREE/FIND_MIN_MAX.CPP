#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int mini = INT_MAX,maxi = INT_MIN;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

class bt{
    public:
    node* root;

    bt(){
        root = NULL;
    }

    void create(){
        node *p,*t;
        int x;
        queue<node*> q;
        cout<<"ENTER ROOT VALUE\n";
        cin>>x;
        root = new node(x);
        q.push(root);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout<<"ENTER LEFT CHILD\n";
            cin>>x;
            if(x != -1){
            t = new node(x);
            p->left = t;
            q.push(t);
            }
            cout<<"ENTER RIGHT CHILD\n";
            cin>>x;
            if(x != -1){
                t = new node(x);
                p->right = t;
                q.push(t);
            }
        }
    }

    void find_minmax(node* p){
        if(p == NULL){
            return;
        }
        mini = min(p->data,mini);
        maxi = max(p->data,maxi);
        find_minmax(p->left);
        find_minmax(p->right);
    }
};

int main(){
    bt obj;
    obj.create();
    obj.find_minmax(obj.root);
    cout<<mini<<" "<<maxi;
}