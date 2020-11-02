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

    void append(node* newnode){
        if(head == NULL){
            head = newnode;
            newnode -> next = head;
        }
        else{
            node* ptr = head;
            while (ptr -> next != head)
            {
                ptr = ptr->next;
            }
            ptr -> next = newnode;
            newnode -> next = head;
        }
    }
    
    void prepend(node* newnode){
        if(head == NULL){
            head = newnode;
            newnode -> next = head;
        }
        else{
            node* ptr = head;
            while(ptr -> next != head){
                ptr = ptr -> next;
            }
            ptr -> next = newnode;
            newnode -> next = head;
            head = newnode;
        }
    }

    void insertnodeafter(int pos,node* newnode){
        node* ptr = head;
        for(int i=1;ptr && i<pos-1;i++){
            ptr = ptr -> next;
        }
        if(ptr){
            if(ptr -> next == head){
                newnode->next = head;
                ptr->next = newnode;
            }
            else{
                newnode -> next = ptr -> next;
                ptr->next = newnode;
            }
        }
    }

    void print(){
        if(head){
            node* temp = head;
            do{
                cout<<temp -> data;
                temp = temp -> next;
            }
            while (temp != head);
        }
    }
};

int main(int argc, const char** argv) {
    cll obj;
    int x;
    do{
        cout<<"your choice:\n 1. append\n 2. prepend\n 3. insert_inbetween\n 4.print\n";
        int val,pos;
        cin>>x;
        node* temp = new node();
        switch (x)
        {
            case 1:
            cin>>val;
            temp -> data = val;
            obj.append(temp);
            break;
            case 2:
            cin>>val;
            temp -> data = val;
            obj.prepend(temp);
            break;
            case 3:
            cin>>pos;
            cin>>val;
            temp -> data = val;
            obj.insertnodeafter(pos,temp);
            break;
            case 4:
            obj.print();
            break;
        }
        cout<<endl;
    }
    while(x != 0);
    return 0;
}