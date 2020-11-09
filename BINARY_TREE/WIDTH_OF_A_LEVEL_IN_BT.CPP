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

    int get_width_at_given_level(node*p ,int level){
        if(p == NULL){
            return 0;
        }
        if(level == 1){
            return 1;
        }
        return get_width_at_given_level(p->left,level-1) + get_width_at_given_level(p->right,level-1);
    }
};

int main(){
    bt obj;
    obj.create();
    int level;
    cin>>level;
    obj.get_width_at_given_level(obj.root,level);
}