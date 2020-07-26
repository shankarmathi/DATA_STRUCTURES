#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
class linkedlist{
    private:
    node* head,*tail;
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
    void del(int pos){
        node* ptr1 = head;
        if(pos == 0){
            head = head -> next;
            delete ptr1;
        }
        else{
            node* ptr2 = NULL;
            for(int i=0;i<pos && ptr1;i++){
                ptr2 = ptr1;
                ptr1 = ptr1 -> next;
            }
            if(ptr1){
                ptr2->next = ptr1->next;
                delete ptr1;
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
    ll.print();
    ll.del(1);
    cout<<'\n';
    ll.print();
}