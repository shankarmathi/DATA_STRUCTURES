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

    int height(node* p){
        if(p == NULL){
            return 0; 
        }
        int left = height(p->left);
        int right = height(p->right);
        return max(left,right) + 1;
    }

    int diameter(node *p){
        if(p == NULL){
            return 0;
        }

        int left_height = height(p->left);
        int right_height = height(p->right);

        int left_diameter = diameter(p->left);
        int right_diameter = diameter(p->right);

        return max(left_height+right_height+1,max(left_diameter,right_diameter));
    }
};

int main(){
    bt obj;
    obj.create();
    cout<<obj.diameter(obj.root);
}