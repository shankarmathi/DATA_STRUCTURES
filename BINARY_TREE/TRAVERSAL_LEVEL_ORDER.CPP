#include <iostream>
#include <queue>

using namespace std;

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

    void levelorder(node* p){
        queue<node*> q;
        if(p){
            cout<<p->data<<" ";
            q.push(p);
        }
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p->left){
                cout<<p->left->data<<" ";
                q.push(p->left);
            }
            if(p->right){
                cout<<p->right->data<<" ";
                q.push(p->right);
            }
        }
    }
};

int main(){
    bt obj;
    obj.create();
    obj.levelorder(obj.root);
}