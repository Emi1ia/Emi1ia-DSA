#include "History.h"
#include <iostream>
#include <sstream>

using namespace std;

// This function adds a new calculation to the history.
void History::addToHistory(double prevResult, char operation, double newInput, double result) {
    stringstream ss;
    
    // Check if the operation is one of the trigonometric functions: sin, cos, or tan
    if (operation == 's' || operation == 'c' || operation == 't') {
        string funcName;
        // Determine the trigonometric function's name based on the operation character
        if (operation == 's') funcName = "sin";
        else if (operation == 'c') funcName = "cos";
        else funcName = "tan";

        // Format the calculation string for trigonometric operations
        ss << prevResult << " * " << funcName << "(" << newInput << ") = " << result;
    } else {
        // Format the calculation string for standard operations
        ss << prevResult << " " << operation << " " << newInput << " = " << result;
    }

    // Add the formatted calculation string to the history queue
    calculations.push(ss.str());
    // Display a message indicating the addition to history
    cout << "Added to history: " << ss.str() << endl;
}

// This function displays all the calculations stored in the history.
void History::displayHistory() {
    cout << "Calculation History (Size: " << calculations.size() << "):" << endl;
    // Use a temporary queue to display the history so that the original history is not modified
    queue<string> temp = calculations;

    // Display each entry in the temporary queue
    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }
}

// This function deletes a specific entry in the history based on its index.
void History::deleteEntry(int index) {
    // Check if the provided index is out of bounds
    if (index < 1 || index > calculations.size()) {
        cout << "Invalid index!" << endl;
        return;
    }

    // Create a new queue to store all entries except the one to be deleted
    queue<string> newQueue;
    // Traverse the original history and copy entries to the new queue, skipping the entry to be deleted
    for (int i = 1; !calculations.empty(); i++) {
        if (i != index) {
            newQueue.push(calculations.front());
        }
        calculations.pop();
    }

    // Update the history with the new queue
    calculations = newQueue;
}

// This function clears all entries in the history.
void History::clearHistory() {
    // Pop all entries from the history queue
    while (!calculations.empty()) {
        calculations.pop();
    }
}
