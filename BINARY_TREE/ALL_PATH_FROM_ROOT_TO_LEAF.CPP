#include <iostream>
#include <queue>
#include <vector>

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

    void print_all_path(node* p,vector<int> arr){
        if(p == NULL){
            return;
        }

        arr.push_back(p->data);

        if(p->left == NULL && p->right == NULL){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<'\n';
        }

        print_all_path(p->left,arr);
        print_all_path(p->right,arr);
    }
};

int main(){
    bt obj;
    vector<int> arr;
    obj.create();
    obj.print_all_path(obj.root,arr);
}