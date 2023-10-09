#ifndef HISTORY_H
#define HISTORY_H

#include <queue>      // We use the queue library to use a queue data structure
#include <string>

using namespace std;

class History {
private:
 // Use a queue to store calculations. 
    // This data structure is appropriate for sequential access (like a history).
    queue<string> calculations;

public:
    // Method to add a new calculation to the history.
    void addToHistory(double num1, char operation, double num2, double result);
    
    // Method to display all the calculations stored in the history.
    void displayHistory();
    
    // Method to clear or reset the history.
    void clearHistory();

    // Method to delete a specific entry in the history based on its index.
    void deleteEntry(int index);
};
#endif
