#include <iostream>
using namespace std;

const int NUMS_SIZE = 100;

// Display main menu
void display_menu(){
     cout << "--------Options--------\n";
     cout << "[1] Add to stack\n";
     cout << "[2] Remove from stack\n";
     cout << "[3] Show Stack Pointer\n";
     cout << "[4] Exit\n> ";
};

class Stack{
    public:
        int numbers[NUMS_SIZE];
        int top_of_stack = 0;

        void push_to_stack(int number){
            if(top_of_stack < NUMS_SIZE){
                numbers[top_of_stack] = number;
                top_of_stack++;
            }else{
                cout << "[-] Stack is full.\n";
            }
        };

        void pop_from_stack(){
            if(top_of_stack > 0){
                top_of_stack --;
                cout << "[+] " << numbers[top_of_stack] << " out of stack!\n";
            }else{
                cout << "[-] Stack is empty.\n";
            }
        }

        void show_stack(){
            int disp_top_of_stack = top_of_stack > 0 ? top_of_stack - 1 : top_of_stack;
            cout << "\n[+] Stack pointer: " << disp_top_of_stack << endl;
        }
};

int main(){
    Stack myStack;
    int option_choice, num_input;

    while(1){
        display_menu();
        cin >> option_choice;

        switch(option_choice){
            case 1: 
                cout << "Enter number: ";
                cin >> num_input;
                myStack.push_to_stack(num_input);
                break;
                case 2: myStack.pop_from_stack(); break;
                case 3: myStack.show_stack(); break;
                case 4: cout << "\nBye!\n"; exit(1);
                default: cout << "Invalid!\n";
        }
    }
    return 0;
}