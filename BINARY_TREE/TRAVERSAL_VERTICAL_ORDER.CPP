#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    int height;

    node(int x){
        data = x;
        left = right = NULL;
        height = 0;
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

    void vertical_order(node* p){
        map<int,vector<int>> m;
        queue<node*> q;
        if(p == NULL){
            return;
        }
        q.push(p);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            int hd = temp->height;
            m[hd].push_back(temp->data);

            if(temp->left){
                temp->left->height = hd-1;
                q.push(temp->left);
            }

            if(temp->right){
                temp->right->height = hd+1;
                q.push(temp->right);
            }
        }

        for(auto i:m){
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<'\n';
        }
    }
};

int main(){
    bt obj;
    obj.create();
    obj.vertical_order(obj.root);
}