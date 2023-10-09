#include <iostream>
#include <cmath>

#include "History.h"

using namespace std;
History history;   // Declare and instantiate an object of the History class

// Function to display the calculator UI
void show_calculator()
{
	cout<<"----------------------------------------"<< endl;
	cout<<"---                                  ---"<< endl;
	cout<<"-             SCIENTIFIC               -"<< endl;
	cout<<"-             CALCULATOR               -"<< endl;
	cout<<"---                                  ---"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     +      |      -      |     *     -"<< endl;
	cout<<"-    Add     |  Substract  |  Multiply -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     /      |      l      |     L     -"<< endl;
	cout<<"-   Divide   |      ln     |    log    -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     S      |      e      |     r     -"<< endl;
	cout<<"-   Square   |   Exponent  |    sqrt   -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     s      |      c      |     t     -"<< endl;
	cout<<"-    sin     |     cos     |    tan    -"<< endl;
	cout<<"----------------------------------------"<< endl;
   cout <<"-     h      |      d      |     .     -" << endl;
   cout <<"-  display   |    clear    |   close   -" << endl; 
   cout <<"----------------------------------------" << endl;
}
    
// Function to display the current answer and the calculator UI
void display_output(double answer)
{
	cout<<"----------------------------------------"<< endl;
	cout<<"---                ---------------------"<< endl;
	cout<<"-     CURRENT      |                    "<< endl;
	cout<<"-     OUTPUT       |  "<<answer          << endl;
	cout<<"---                ---------------------"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     +      |      -      |     *     -"<< endl;
	cout<<"-    Add     |  Substract  |  Multiply -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     /      |      l      |     L     -"<< endl;
	cout<<"-   Divide   |      ln     |    log    -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     S      |      e      |     r     -"<< endl;
	cout<<"-   Square   |   Exponent  |    sqrt   -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     s      |      c      |     t     -"<< endl;
	cout<<"-    sin     |     cos     |    tan    -"<< endl;
	cout<<"----------------------------------------"<< endl;
	cout<<"-     h      |      k      |     .     -"<< endl;
	cout<<"-  history   |    clear    |   close   -"<< endl;
	cout<<"----------------------------------------"<< endl;
}

int main()
{
    // Variable declarations
	double num1 = 0.0;
	double num2 = 0.0;
	double newInput = 0.0;
    double previousAnswer = 0.0;


	double answer = 0.0;
	char input = '\n';
	bool converter = 0;
	
	// Main loop for calculator operations
	while(input != '.')
	{
        // If the calculator is in converter mode, display previous answer and calculator UI
		if(converter == 1)
		{
			display_output(answer);
			cout<<"Enter: ";
			cin>>input;
			
			if(input == '+' || input == '-' || input == '*'|| input == '/' || input == 'e')
			{
				num1 = answer;
				
				cout<<"Enter num: ";
				cin>>num2;
			}
			else if(input == 'k' || input == '.')
			{
				
			}
			else
			{
				num1 = answer;
			}
		}
        //Shows the standard calculator UI
		else 
		{
			show_calculator();
			cout<<"Enter: ";
			cin>>input;
			
			if(input == '+' || input == '-' || input == '*'|| input == '/' || input == 'l' || input == 'e')
			{
				cout<<"Enter num 1: ";
				cin>>num1;
				
				cout<<"Enter num 2: ";
				cin>>num2;
			}
			else if(input == 'k' || input == '.')
			{
				
			}
			else
			{
				cout<<"Enter num: ";
				cin>> num1;
			}
			converter = 1;
		}
		// Switch case for handling user inputs for mathematical operations
		switch(input)
		{
        // For each case:
        // 1. Compute the required operation
        // 2. Save the operation to the history
			case '+': // Addition operation
                answer = num1 + num2;
             history.addToHistory(num1, input, num2, answer);  
                break;

            case '-': // Substraction operation
                answer = num1 - num2;
                 history.addToHistory(num1, input, num2, answer); 
                break;
			case '*': // Multiplication operation
				answer = num1 * num2;
                history.addToHistory(num1, input, num2, answer); 
				break;
			case '/': // Division operation
				answer = num1 / num2;
                history.addToHistory(num1, input, num2, answer); 
				break;
			case 'l': // Log operation
				answer = log1p(num1);
                history.addToHistory(num1, input, num2, answer); 
				break;
			case 'L': // Substraction operation
				answer = log(num1);
                history.addToHistory(num1, input, num2, answer); 
				break;	
			case 'S': //Square the answer
				answer = num1*num1;
                history.addToHistory(num1, input, num2, answer); 
				break;
			case 'e': //exponents operation
				answer = pow(num1,num2);
                history.addToHistory(num1, input, num2, answer); 
				break;
            case 's':  // sin operation
                cout << "Enter value for sin (answer * sin(value)): ";
                cin >> newInput;
                previousAnswer = answer;  // Store the original value
                answer = answer * sin(newInput);  // Modify the answer
                history.addToHistory(previousAnswer, 's', newInput, answer);
                break;

            case 'c':  // cos operation
                cout << "Enter value for cos (answer * cos(value)): ";
                cin >> newInput;
                previousAnswer = answer;  // Store the original value
                answer = answer * cos(newInput);  // Modify the answer
                history.addToHistory(previousAnswer, 'c', newInput, answer);
                break;

            case 't':  // tan operation
                cout << "Enter value for tan (answer * tan(value)): ";
                cin >> newInput;
                previousAnswer = answer;  // Store the original value
                answer = answer * tan(newInput);  // Modify the answer
                history.addToHistory(previousAnswer, 't', newInput, answer);
                break;

			case 'r': // Square root operation
				answer = sqrt(num1);
                history.addToHistory(num1, input, num2, answer); 
				break;
			case 'k':
				converter = 0;
				break;
			case 'h':  // Display history
                system("clear");  // Or use system("cls"); if on Windows
                history.displayHistory();

                // Ask user if they want to delete an entry
                cout << "\nEnter the number of the entry you want to delete, or 0 to skip: ";
                int entryToDelete;
                cin >> entryToDelete;

            if (entryToDelete != 0) {
                history.deleteEntry(entryToDelete);
                cout << "Entry " << entryToDelete << " deleted!" << endl;
                cin.ignore();  // Clear newline from buffer
                cin.get();  // Pause
            }
            break;

            case 'd':  // Delete history
                history.clearHistory();
                cout << "History cleared!" << endl;
                cin.get();  // Wait for the user to press a key before continuing
                break;

			case '.': // Exit the program
				break;
			default: // Display an error message for invalid input
				cout<<"Invalid"<<endl;
		}
		// Clear the screen for the next operation
		system("clear");
		
	}
    // Display the history at the end
   history.displayHistory();


	return 0;
}
