#include <iostream>
#include <fstream>
#include <stack>
#include "Header.h"

using namespace std;

void printMenu() {
    cout << "1. Push a value onto the stack" << endl;
    cout << "2. Pop the top value from the stack" << endl;
    cout << "3. Print the top value of the stack" << endl;
    cout << "4. Check if stack is empty" << endl;
    cout << "5. Clear the stack" << endl;
    cout << "6. Print the stack" << endl;
    cout << "7. Check if stack has equal next values" << endl;
    cout << "8. Save the stack to a file" << endl;
    cout << "9. Load the stack from a file" << endl;
    cout << "0. Exit" << endl;
}

void saveToFile(Stack& stack, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    Node* current = stack.head;
    while (current != NULL) {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
    cout << "Stack saved to " << filename << endl;
}


void loadFromFile(Stack& stack, string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    stack.clear();
    int value;
    while (file >> value) {
        stack.push(value);
    }
    file.close();
    cout << "Stack loaded from " << filename << endl;
}

int main() {
    Stack stack;
    int choice, value;
    string filename;
    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter a value to push onto the stack: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Top value: " << stack.top() << endl;
            break;
        case 4:
            if (stack.empty()) {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 5:
            stack.clear();
            break;
        case 6:
            stack.print();
            break;
        case 7:
            if (stack.hasEqualNext()) {
                cout << "Stack has equal next values" << endl;
            }
            else {
                cout << "Stack does not have equal next values" << endl;
            }
            break;
        case 8:
            cout << "Enter a filename to save the stack to: ";
            cin >> filename;
            saveToFile(stack, filename);
            break;
        case 9:
            cout << "Enter a filename to load the stack from: ";
            cin >> filename;
            loadFromFile(stack, filename);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
    return 0;
}