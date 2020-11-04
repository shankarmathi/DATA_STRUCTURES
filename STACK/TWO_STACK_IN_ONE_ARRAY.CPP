#include <iostream>

using namespace std;

class twostack{
    public:
    int *arr;
    int size;
    int top1,top2;

    twostack(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top1+1 != top2){
            arr[++top1] = x;
        }
    }

    void push2(int x){
        if(top2-1 != top1){
            arr[--top2] = x;
        }
    }

    int pop1(){
        if(top1 >= 0){
            return arr[top1--];
        }
        return -1;
    }

    int pop2(){
        if(top2 < size){
            return arr[top2++];
        }
        return -1;
    }

};

int main(){
    int n;
    cin>>n;
    twostack obj(n);
}