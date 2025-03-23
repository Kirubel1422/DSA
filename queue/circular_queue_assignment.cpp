#include <iostream>
using namespace std;

const int MAX_QUEUE = 10; // Length of the queue

// create queue class
class Queue{
    // public members
    public:
        Queue();
        ~Queue();
        double get_front();
        double get_rear();
        bool is_empty();
        bool is_full();
        void enQueue(double);
        void deQueue();
        void print();
    
    // Private members
    private:
        int front, back, count;
        double items[MAX_QUEUE];
};

// class member implementations
Queue::Queue(){ // Constructor
    front=0;
    back=-1;
    count=0;
}; // endof contructor

Queue::~Queue(){ // Destructor
    front=0;
    back=MAX_QUEUE-1;
    count=0;
}; // endof Destructor

bool Queue::is_full(){ // check if queue is full
    return (count == MAX_QUEUE);    
}; // endof is_full()

bool Queue::is_empty(){ // check if queue is empty
    return (count == 0);    
}; // endof is_empty()

double Queue::get_front(){ // get the front element
    if(is_empty()){
        cout << "Sorry! Queue is Empty." << endl;
        return -1;
    }else{
        return items[front];
    }
} // endif get_front()

double Queue::get_rear(){ // get the rear element
    if(is_empty()){
        cout << "Sorry! Queue is Empty." << endl;
        return -1;
    }else{
        return items[back];
    } 
} // endof get_rear()

void Queue::enQueue(double newItem){ // add new element
    // Check if it is full before adding element
    if(is_full()){
        cout << "Sorry! Queue is already full." << endl;
    }else{
        back = (back + 1) % MAX_QUEUE;
        count ++; // Keep track of the number of elements
        items[back] = newItem;
    }
}; // endof enQueue(double newItem);

void Queue::deQueue(){ // remove an item
    // Check if it is empty before removing an element
    if(is_empty()){
        cout << "Sorry! Queue is Empty." << endl;
    }else{
        // Show the item before it is removed
        // cout << "Number removed: " << items[front] << endl;
        count --;
        front = (front + 1) % MAX_QUEUE;
    }
} // endof deQueue

void Queue::print(){  // List all elements in the queue
    cout << "========>\tQueue\t<========" << endl;
    for(int i = 0; i < MAX_QUEUE; i++){
        cout << "Index:\t" << i << "\t\tItem:\t" << items[i] << endl; // Show index and the item
    };
}

int main(){
    Queue q; // Create instance
    
    /*  Setup a queue where front is index 9 and 
        back is index 0; front = 9, back = 0.125
    
        Use for loop to enqueue demo vaules and to 
        dequeue
    */
    
    for(int i=1; i <= 9; i++){ // Fill zeroes upto index 8
        q.enQueue(0); 
    } // at the end of this back is at index 8
    
    for(int i=1; i <= 9; i++){ // Remove all zeroes
        q.deQueue(); 
    } // at the end of this front is at index 9 
    
    q.enQueue(9.9); // Back will be at index 9 same as front
    q.enQueue(0.125); // Back will be at index 0 passing front
    
    q.print();
    
    cout << endl << endl << "----------------------" << endl;
    cout << "Front element: " << q.get_front() << endl;
    cout << "Back  element: " << q.get_rear() << endl;
}