#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
class linkedlist{
    public:
    node *head,* tail;
    linkedlist(){
        this -> head = NULL;
        this -> tail = NULL;
    }
    void insertatend(int num){
        node* temp = new node();
        temp -> data = num;
        temp -> next = NULL;
        if(head == NULL){
            this -> head = this -> tail = temp;
        }
        else{
            this -> tail -> next = temp;
            this -> tail = temp;
        }
    }
    void print(){
        node* t = head;
        while(t != NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
    }
    ~linkedlist();
};
int main(){
    int n,num;
    cin>>n;
    linkedlist* ll = new linkedlist();
    for(int i=0;i<n;i++){
        cin>>num;
        ll->insertatend(num);
    }
    ll->print();
}