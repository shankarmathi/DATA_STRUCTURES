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

    void spiral_order(node* p){
        stack<node*> s1,s2;
        if(p == NULL){
            return;
        }
        s1.push(p);
        while (!s1.empty() || !s2.empty())
        {
            while (!s1.empty())
            {
                node* t = s1.top();
                cout<<t->data<<" ";
                s1.pop();
                if(t->left){
                    s2.push(t->left);
                }
                if(t->right){
                    s2.push(t->right);
                }
            }
            cout<<endl;
            while (!s2.empty())
            {
                node* t = s2.top();
                cout<<t->data<<" ";
                s2.pop();
                if(t->right){
                    s1.push(t->right);
                }
                if(t->left){
                    s1.push(t->left);
                }
            }
            cout<<endl;
        }
        
    }
};

int main(){
    bt obj;
    obj.create();
    obj.spiral_order(obj.root);
}