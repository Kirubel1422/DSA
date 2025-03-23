#include <iostream>
using namespace std;

const int SIZE = 3;

class Stack{
    public:
        Stack();
        bool is_full();
        bool is_empty();
        char stack_top();
        void push(char item);
        void pop();
    
    private:
        int top;
        char items[SIZE];
};

Stack::Stack(){
    top=-1;
}

bool Stack::is_full(){
    return bool(top == SIZE-1);
}

bool Stack::is_empty(){
    return bool(top == -1);
}

void Stack::push(char item){
    if(is_full()){
        cout << "Sorry! Stack is Full." << endl;
    }else{
        top ++;
        items[top] = item;
    }
}

void Stack::pop(){
    if(is_empty()){
        cout << "Sorry! Stack is Empty." << endl;
    }else{
        top --;
    }
}

char Stack::stack_top(){
    if(is_empty()){
        cout << "Sorry! Stack is Empty." << endl;
    }else{
        return items[top];
    }
}

int main(){
    Stack my_stack = Stack();

    return 0;
};