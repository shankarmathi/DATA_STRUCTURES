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
        head = NULL;
        tail = NULL;
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
    void reverselist(){
        node *prev = NULL,*curr = head,*next = NULL;
        if(head == NULL){
            head = NULL;
        }
        else{
            next = curr->next;
            while(curr){
                curr -> next = prev;
                prev = curr;
                curr = next;
                if(curr){
                    next = curr->next;
                }
            }
            head = prev;
        }
    }
    node* recursive_reverse(node *t){
        if(t == NULL || t->next == NULL){
            return t;
        }
        node* temp = recursive_reverse(t->next);
        t->next->next = t;
        t->next = NULL;
        return temp;
    }
    void print(){
        node* t = head;
        while(t != NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<'\n';
    }
};
int main(){
    int n,num;
    cin>>n;
    linkedlist ll;
    for(int i=0;i<n;i++){
        cin>>num;
        ll.insertatend(num);
    }
    ll.print();
    ll.reverselist();
    ll.print();
    ll.head = ll.recursive_reverse(ll.head);
    ll.print();
}