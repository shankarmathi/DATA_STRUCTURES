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

    int search(node* p,int key){
        if(p == NULL){
            return 0;
        }
        if(p->data == key){
            return 1;
        }
        return search(p->left,key) || search(p->right,key);
    }
};

int main(){
    bt obj;
    obj.create();
    int num;
    cin>>num;
    int x = obj.search(obj.root,num);
    if(x == 1){
        cout<<"ELEMENT EXISTS";
    }
    else
    {
        cout<<"ELEMENT DOES NOT EXISTS";
    }
    
}