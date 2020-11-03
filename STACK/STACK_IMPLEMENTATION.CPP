#include <iostream>

using namespace std;

struct stack{
    int *arr;
    int size;
    int top;
};

int isempty(stack s){
    if(s.top == -1){
        return 1;
    }
    return 0;
}

int isfull(stack s){
    if(s.top == s.size-1){
        return 1;
    }
    return 0;
}

int stacktop(stack s){
    if(s.top == -1){
        return -1;
    }
    return s.arr[s.top];
}

void push(stack* s,int val){
    if(s->top == s->size-1){
        cout<<"stack over flow";
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(stack* s){
    if(s->top == -1){
        cout<<"stack underflow";
        return -1;
    }
    else{
        int x = s->arr[s->top];
        s->top--;
        return x;
    }
}

int main(){
    stack s;
    cout<<"enter size of stack";
    cin>>s.size;
    s.arr = new int[s.size];
    s.top = -1;
}