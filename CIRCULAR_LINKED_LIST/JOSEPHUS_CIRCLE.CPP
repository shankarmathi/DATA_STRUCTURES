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

    node(int x){
        data = x;
        next = NULL;
    }
};

class cll{
    public:
    node* head;

    cll(){
        head = NULL;
    }

    void get_josephus_circle(int m,int n){
        int i=1;
        head = new node(i);
        node* prev = head;
        for(i=2;i<=n;i++){
            prev->next = new node(i);
            prev = prev -> next;
        } 
        prev->next = head;

        node* ptr1 = head,*ptr2 = head;
        while(ptr1->next != ptr1){
            int count = 1;
            while(count != m){
                ptr2 = ptr1;
                ptr1 = ptr1->next;
                count++;
            }
            ptr2->next = ptr1->next;
            delete ptr1;
            ptr1 = ptr2->next;
        }
        cout<<ptr1->data<<'\n';
    }
};

int main(){
    cll obj;
    obj.get_josephus_circle(15,4);
}