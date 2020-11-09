#include <iostream>
#include <queue>

using namespace std;

int sum = 0;

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

    int sum_leaf_nodes(node* p){
        if(p == NULL){
            return 0;
        }
    
        if(p->left == NULL && p->right == NULL){
            return p->data;
        }
    
        return sum_leaf_nodes(p->left) + sum_leaf_nodes(p->right);
    }
};

int main(){
    bt obj;
    obj.create();
    cout<<obj.sum_leaf_nodes(obj.root);
}