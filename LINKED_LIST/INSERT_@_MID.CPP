#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
class linkedlist{
    private:
    node *head,*tail;
    public:
    linkedlist(){
        head = tail = NULL;
    }
    void insertatend(int num){
        node* temp = new node();
        temp -> data = num;
        temp -> next = NULL;
        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    void insertatpos(int pos,int val){
        node* temp = new node();
        temp -> data = val;
        temp -> next = NULL;
        if(pos == 0){
            temp->next = head;
            head = temp;
        }
        else{
            node* t = head;
            for(int i=0;i<pos-1 && t;i++){
                t = t->next;
            }
            if(t){
                temp->next = t->next;
                t->next = temp;
            }
        }
    }
    void print(){
        node* t = head;
        while(t != NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
    }
};
int main(){
    linkedlist ll;
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        ll.insertatend(num);
    }
    int pos,val;
    cin>>pos,val;
    ll.insertatpos(pos,val);
    ll.print();
}