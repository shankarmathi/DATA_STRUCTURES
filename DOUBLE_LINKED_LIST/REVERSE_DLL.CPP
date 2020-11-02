#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(){
        prev = NULL;
        next = NULL;
    }
};
class dll{
    public:
    node* head;

    dll(){
        head = NULL;
    }

    void append(node* n){
        if(head == NULL){
            head = n;
        }
        else{
            node* ptr = head;
            while(ptr -> next != NULL){
                ptr = ptr->next;
            }
            ptr -> next = n;
            n->prev = ptr;
        }
    }

    void printlist(){
        if(head){
            node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp -> next;
            }
        }
    }

    void reverse(){
        node* curr = head,*temp;
        while(curr){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if(temp != NULL){
            head = temp->prev; //to avoid error when size of dll is 1 -- care
        }
    }
};

int main(){
    dll obj;
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        node* n1 = new node();
        n1->data = num;
        obj.append(n1);
    }
    obj.printlist();
    obj.reverse();
    cout<<'\n';
    obj.printlist();
}