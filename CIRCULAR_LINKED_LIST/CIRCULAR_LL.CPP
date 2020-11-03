#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(){
        data = 0;
        next = NULL;
    }
};

class cll{
    public:
    node* head;

    cll(){
        head = NULL;
    }
// position starts from zero
    void insert(int pos,node* n){
        if(pos == 0){
            if(head == NULL){
                head = n;
                head -> next = head;
            }
            else{
                node* t = head;
                while(t -> next != head){
                    t = t -> next;
                }
                t -> next = n;
                n -> next = head;
                head = n;
            }
        }
        else{
            node* p =head;
            for(int i=0;p && i<pos-1;i++){
                p = p -> next;
            }
            if(p){
                n -> next = p->next;
                p->next = n;
            }
        }
    }

    void del(int pos){
        node *p,*q;
        if(pos == 0){
            p = head;
            while(p->next != head){
                p = p->next;
            }
            //cll with only one node
            if(p == head){
                delete head;
                head = NULL;
            }
            else{
                p -> next = head -> next;
                delete head;
                head = p -> next;
            }
        }
        else{
            p = head;
            for(int i=0;i<pos-1;i++){
                p = p->next;
            }
            q = p->next;
            delete q;
            p->next = p->next->next;
        }
    }

    void print(){
        if(head){
            node* temp = head;
            do{
                cout<<temp -> data<<"-->";
                temp = temp -> next;
            }
            while (temp != head);
        }
    }
};

int main(int argc, const char** argv) {
    cll obj;
    int x;
    do{
        cout<<"your choice:\n 0. exit\n 1. insert\n 2. del\n 3.print\n";
        int val,pos;
        cin>>x;
        node* temp = new node();
        switch (x)
        {
            case 0:
            break;
            case 1:
            cin>>pos;
            cin>>val;
            temp -> data = val;
            obj.insert(pos,temp);
            break;
            case 2:
            cin>>pos;
            obj.del(pos);
            break;
            case 3:
            obj.print();
            break;
        }
        cout<<endl;
    }
    while(x != 0);
    return 0;
}