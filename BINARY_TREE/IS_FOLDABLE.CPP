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

    bool is_mirror(node* p,node* q){
        if(p == NULL && q == NULL){
            return 1;
        }
        if(p == NULL || q == NULL){
            return 0;
        }

        return is_mirror(p->left,q->right) && is_mirror(p->right,q->left);
    }

    bool is_foldable(node* p){
        if(p == NULL){
            return 1;
        }
        return is_mirror(p->left,p->right);
    }
};

int main(){
    bt obj;
    obj.create();
    int x = obj.is_foldable(obj.root);
    if(x){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}