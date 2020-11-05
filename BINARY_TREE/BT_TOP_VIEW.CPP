#include <iostream>
#include <queue>
#include <map>

using namespace std;

//this program is a combination of level order + vertical order

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

    void topview(node* p){
        queue<node*> q;
        map<int,int> m;
        if(p == NULL){
            return;
        }

        q.push(p);

        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            int hd = temp->height; 
            //hd horizontal distance
            if(m[hd] == 0){
                m[hd] = temp->data;
            }
            if(temp->left != NULL){
                temp->left->height = hd-1;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                temp->right->height = hd+1;
                q.push(temp->right);
            }
        }

        for(auto i:m){
            cout<<i.second<<" ";
        }
    }
};

int main(){
    bt obj;
    obj.create();
    obj.topview(obj.root);
}