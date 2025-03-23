#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
    public:
        Stack();
        bool is_empty();
        void push(int item);
        void pop();
        int stack_top();
    private:
        Node *head;
};

Stack::Stack(){
    head = NULL;
}

bool Stack::is_empty(){
    return head == NULL;
}

int Stack::stack_top(){
    if (is_empty()) {
        cout << "Stack is empty. No top element." << endl;
        return -1;
    }
    return head->data;
}

void Stack::push(int item){
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void Stack::pop(){
    if (is_empty()){
        cout << "Sorry! Stack is already empty." << endl;
        return;
    }

    Node* delNode = head;
    head = head->next;
    delete delNode;
}

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top of stack: " << s.stack_top() << endl;

    s.pop();
    cout << "After popping, top of stack: " << s.stack_top() << endl;

    s.pop();
    s.pop();
    s.pop();  // Attempting to pop from an empty stack

    return 0;
}
