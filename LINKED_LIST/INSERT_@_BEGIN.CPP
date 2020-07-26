#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
class linkedlist{
    public:
    node *head,*tail;
    linkedlist(){
        head = tail = NULL;
    }
    void insertatbegin(int num){
        node* temp = new node();
        temp->data = num;
        temp->next = NULL;
        if(head == NULL){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
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
    linkedlist* ll = new linkedlist();
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        ll->insertatbegin(num);
    }
    ll->print();
}