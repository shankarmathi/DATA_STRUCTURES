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
};

int check_identical(node* x,node* y){
    if(x == NULL && y == NULL){
        return 1;
    }
    if(x == NULL || y == NULL){
        return 0;
    }

    return x->data == y->data && check_identical(x->left,y->left) && check_identical(x->right,y->right);
}

int main(){
    bt obj1,obj2;
    cout<<"ENTER VALUES OF FIRST TREE\n";
    obj1.create();
    cout<<"ENTER VALUES OF SECOND TREE\n";
    obj2.create();
    int x = check_identical(obj1.root,obj2.root);
    if(x == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
