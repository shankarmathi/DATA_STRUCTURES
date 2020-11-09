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

    bool sum_path_exist(node* p,int total){
        if(p == NULL){
            return 0;
        }

        if(p->left == NULL && p->right == NULL && p->data == total){
            return 1;
        }

        return sum_path_exist(p->left,total-p->data) || sum_path_exist(p->right,total-p->data);
    }
};

int main(){
    bt obj;
    obj.create();
    int sum;
    cin>>sum;
    int x = obj.sum_path_exist(obj.root,sum);
}