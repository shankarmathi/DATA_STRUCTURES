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

    void postorder(node* p){
        if(p){
            postorder(p->left);
            postorder(p->right);
            cout<<p->data<<" ";
        }
    }

    void postorder_stack(node* p){
        if(p == NULL){
            return;
        }
        stack<node*> s1,s2;
        s1.push(p);
        node* t;
        while (!s1.empty())
        {
            t = s1.top();
            s1.pop();
            s2.push(t);
            if(t->left){
                s1.push(t->left);
            }
            if(t->right){
                s1.push(t->right);
            }
        }

        while (!s2.empty())
        {
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
    }
};

int main(){
    bt obj;
    obj.create();
    obj.postorder(obj.root);
    cout<<"\n";
    obj.postorder_stack(obj.root);
}