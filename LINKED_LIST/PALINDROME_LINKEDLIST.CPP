#include <iostream>
#include <stack>
using namespace std;
class node{
    public:
    int data;
    node* next;
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
        temp -> next = NULL;
        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    int palindrom_using_stack(){
        stack<int> s;
        node* temp1 = head;
        while (temp1)
        {
            s.push(temp1->data);
            temp1 = temp1->next;
        }
        node* temp2 = head;
        while(temp2){
            int t = s.top();
            if(temp2 -> data != t){
                return 0;
            }
            s.pop();
            temp2 = temp2 -> next;
        }
        return 1;
    }
    int ispalindrome(){
        node* slow = head;
        node* fast = head;
        node* prev = NULL;
        while (slow && fast && fast->next)
        {
            fast = fast->next->next;
            node* temp = slow;
            slow = slow -> next;
            temp->next = prev;
            prev = temp;
        }
        if(fast){
            slow = slow -> next;
        }
        while (prev && slow)
        {
            if(prev->data != slow->data){
                return 0;
            }
            prev = prev -> next;
            slow = slow -> next;
        }
        return prev == NULL && slow == NULL;
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
    cout<<ll.palindrom_using_stack()<<'\n';
    cout<<ll.ispalindrome();
}