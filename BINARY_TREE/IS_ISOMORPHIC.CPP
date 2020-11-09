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

    bool is_isomorphic(node* p,node* q){
        if(p == NULL && q == NULL){
            return 1;
        }
        if(p == NULL || q == NULL){
            return 0;  
        }
        if(p->data != q->data){
            return 0;
        }

        return (is_isomorphic(p->left,q->left) && is_isomorphic(p->right,q->right)) || (is_isomorphic(p->left,q->right) && is_isomorphic(p->right,q->left));
    }
};

int main(){
    bt obj1,obj2;
    obj1.create();
    obj2.create();
}