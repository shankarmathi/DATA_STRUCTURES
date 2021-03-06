#include <iostream>
#include <queue>
#include <stack>

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

    void preorder(node* p){
        if(p){
            cout<<p->data<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void preorder_using_stack(node* p){
        stack<node*> s;
        while (p || !s.empty())
        {
            if(p){
                cout<<p->data<<" ";
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

};

int main(){
    bt obj;
    obj.create();
    obj.preorder(obj.root);
    cout<<'\n';
    obj.preorder_using_stack(obj.root);
}