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

    void split(node* n){
        node *slow_ptr = head;  
        node *fast_ptr = head;  
      
        if(head == NULL)  
            return;
        while(fast_ptr->next != head &&  
              fast_ptr->next->next != head)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
      
        if(fast_ptr->next->next == head)  
            fast_ptr = fast_ptr->next;  
        
        *head1_ref = head;  
          
        if(head->next != head)  
            *head2_ref = slow_ptr->next;  
          
        /* Make second half circular */
        fast_ptr->next = slow_ptr->next;  
          
        /* Make first half circular */
        slow_ptr->next = head;  
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

int main(){
    cll obj;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        node* newnode = new node();
        cin>>newnode->data;
        obj.insert(i,newnode);
    }
    cout<<"BEFORE SPLITING : ";
    obj.print();
    cout<<endl;
    cout<<"AFTER SPLITING :";
    obj.split(newnode);
    return 0;
}