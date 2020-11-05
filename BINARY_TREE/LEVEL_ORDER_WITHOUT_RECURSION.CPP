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
        left = NULL;
        right = NULL;
    }
};

class bt{
    public:
    node* root;

    bt(){
        root = NULL;
    }

    void create(){
        queue<node*> q;
        node *p,*t;
        int x;
        cout<<"ENTER ROOT VALUE\n";
        cin>>x;
        root = new node(x);
        q.push(root);
        while(!q.empty()){
            p = q.front();
            q.pop();
            cout<<"ENTER VALUE OF LEFT\n";
            cin>>x;
            if(x != -1){
                t = new node(x);
                p->left = t;
                q.push(t);
            }
            cout<<"ENTER VALUE OF RIGHT\n";
            cin>>x;
            if(x != -1){
                t = new node(x);
                p->right = t;
                q.push(t);
            }
        }
    }

    int find_height(node* p){
        if(p == NULL){
            return 0;
        }
        int left = find_height(p->left);
        int right = find_height(p->right);
        return max(left,right)+1;
    }

    void print_at_level(node* p,int level){
        if(p == NULL){
            return;
        }
        if(level == 1){
            cout<<p->data<<" ";
            return;
        }
        print_at_level(p->left,level-1);
        print_at_level(p->right,level-1);
    }

    void level_order(node* p){
        int h = find_height(p);
        for(int i=0;i<=h;i++){
            print_at_level(p,i);
            cout<<'\n';
        }
    }
};

int main(){
    bt obj;
    obj.create();
    obj.level_order(obj.root);
    return 0;
}