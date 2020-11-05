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

    node* mirror(node* p){
        if(p == NULL){
            return NULL;
        }
        node* temp = p->left;
        p->left = p->right;
        p->right = temp;

        mirror(p->left);
        mirror(p->right);

        return p;
    }

    void inorder(node* p){
        if(p){
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }
};

int main(){
    bt obj;
    obj.create();
    obj.inorder(obj.root);
    cout<<endl;
    node* mirror_node = obj.mirror(obj.root);
    obj.inorder(mirror_node);
}