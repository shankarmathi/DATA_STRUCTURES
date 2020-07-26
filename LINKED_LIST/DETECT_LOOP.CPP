#include <iostream>
#include <set>
using namespace std;
class node{
    public:
    int data;
    node* next;
    int flag;
};
class linkedlist{
    private:
    node *head,* tail;
    public:
    linkedlist(){
        head = NULL;
        tail = NULL;
    }
    void insertatend(int num){
        node* temp = new node();
        temp -> data = num;
        temp -> flag = 0;
        temp -> next = NULL;
        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    void make_loop(){
        head -> next -> next -> next -> next = head;
    }
    int find_loop_ptr(){
        node* ptr = head;
        while(ptr){
            if(ptr->flag == 1){
                return 1;
            }
            ptr->flag = 1;
            ptr = ptr->next;
        }
        return 0;
    }
    int find_loop_flag(){
        node* slw_ptr = head;
        node* fast_ptr = head;
        while(slw_ptr && fast_ptr && fast_ptr->next){
            slw_ptr = slw_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if(slw_ptr == fast_ptr){
                return 1;
            }
        }
        return 0;
    }
    int find_loop_set(){
        node* ptr = head;
        set<node*> s;
        while(ptr){
            if(s.find(ptr)!=s.end()){
                return 1;
            }
            s.insert(ptr);
            ptr = ptr->next;
        }
        return 0;
    }
};
int main(){
    linkedlist ll;
    ll.insertatend(10);
    ll.insertatend(20);
    ll.insertatend(30);
    ll.insertatend(40);
    ll.make_loop();
    cout<<ll.find_loop_flag()<<'\n';
    cout<<ll.find_loop_ptr()<<'\n';
    cout<<ll.find_loop_set()<<'\n';
}