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

    int curr_level = 0;
    void right_view(int level,node* p){
        if(p == NULL){
            return;
        }

        if(level >= curr_level){
            cout<<p->data<<" ";
            curr_level++;
        }

        right_view(level+1,p->right);
        right_view(level+1,p->left);
    }
};

int main(){
    bt obj;
    obj.create();
    obj.right_view(0,obj.root);
}