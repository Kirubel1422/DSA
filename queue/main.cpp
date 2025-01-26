#include <iostream>
using namespace std;

const short NUMS_SIZE = 100;

void displayOptions(){
        cout << "---------Options---------\n";
        cout << "[1] Add Number to the Queue.\n";
        cout << "[2] Remove First Item from Queue.\n";
        cout << "[3] Display Queue Indexes\n";
        cout << "[4] Exit\n> ";
};
    
class Queue{
    public:
    // Last index is the indicator of where to add the last element to the queue
    // Not the index of the last element itself
    int firstIndex, lastIndex = 0;
    int numbers[NUMS_SIZE];

    void addItem(int newNumber){
        if(lastIndex < NUMS_SIZE){
            numbers[lastIndex]=newNumber;
            lastIndex++;
            cout << "[+] " << newNumber << " in queue!\n";
        }else{
            cout << "Queue is full.";
        }
    }

    void removeItem(){
        if(firstIndex < lastIndex - 1){
            cout << "[+] " <<  numbers[firstIndex] << " out of queue!\n";
            firstIndex ++;
        }else if(firstIndex == 0 && lastIndex == 0){
            cout << "[-] Queue is empty.\n";
        }else{
            cout << "[-] Queue has only one element.\n";
        }
    }

    void displayIndexes(){
        cout << "First Item: " << "(" << firstIndex << ", " << numbers[firstIndex] << ")"  << endl;
        cout << "Last Item: " << "(" << lastIndex - 1 << ", " << numbers[lastIndex - 1] << ")"  << endl;
    }
};

int main(){
    Queue myQueue;
    int optionChoice, numberInput;

    while(1){
        displayOptions();
        cin >> optionChoice;

        switch(optionChoice){
            case 1: 
                cout << "Enter the number: ";
                cin >> numberInput;
                myQueue.addItem(numberInput);
                break;
                case 2:
                    myQueue.removeItem();
                    break;
                    case 3:
                        myQueue.displayIndexes();
                        break;
                        case 4:
                            cout << "\nBye!\n";
                            exit(1);
                            default:
                                cout << "Invalid!\n";

        }
    }

    return 0;
}