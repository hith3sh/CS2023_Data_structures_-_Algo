#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Define the structure of each node in the linked list
struct Node {
    int data;
    Node* next;
};

// Define the stack class using a linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack
public:
    Stack() {
        top = NULL; // Initialize the top pointer to NULL
    }

    // Push a new element onto the top of the stack
    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;
        newNode->next = top; // Set the next pointer to the current top
        top = newNode; // Update the top pointer to the new node
    }

    // Pop the top element from the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top; // Store the current top pointer
        top = top->next; // Update the top pointer to the next node
        delete temp; // Delete the previous top node
    }

    // Display all the elements in the stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top; // Start from the top node
        cout<< "values in stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Driver code to test the implementation
int main() {
   auto start_time = high_resolution_clock::now();
    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    s.display();
   auto end_time = high_resolution_clock::now();
   auto execution_time = duration_cast<microseconds>(end_time - start_time);
   cout << "Execution time: " << execution_time.count() << " us" << endl;
    return 0;
}
