// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

void displayMenu()
{
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

double add(double a, double b)
{
    return a + b;
}

double subtractNumbers(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

bool divide(double a, double b, double& result)
{
    if (b == 0)
    {
        return false;
    }
    result = a / b;
    return true;
}

bool modulus(int a, int b, int& result)
{
    if (b == 0)
    {
        return false;
    }
    result = a % b;
    return true;
}

double exponentiate(double a, double b)
{
    return pow(a, b);
}

int main()
{
    bool running = true;

    while (running)
    {
        displayMenu();
        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a number between 1 and 7." << endl;
            cout << endl;
            continue;
        }

        if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        double x, y;
        cout << "Enter first number : ";
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid number." << endl;
            cout << endl;
            continue;
        }

        cout << "Enter second number: ";
        cin >> y;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid number." << endl;
            cout << endl;
            continue;
        }

        cout << fixed << setprecision(2);
        switch (choice)
        {
            case 1:
                cout << "Result: " << x << " + " << y << " = " << add(x, y) << endl;
                break;
            case 2:
                cout << "Result: " << x << " - " << y << " = " << subtractNumbers(x, y) << endl;
                break;
            case 3:
                cout << "Result: " << x << " * " << y << " = " << multiply(x, y) << endl;
                break;
            case 4: {
                double result;
                if (!divide(x, y, result))
                {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                else
                {
                    cout << "Result: " << x << " / " << y << " = " << result << endl;
                }
                break;
            }
            case 5: {
                int a = static_cast<int>(x);
                int b = static_cast<int>(y);
                int result;
                if (!modulus(a, b, result))
                {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                else
                {
                    cout << "Result: " << a << " % " << b << " = " << result << endl;
                }
                break;
            }
            case 6:
                cout << "Result: " << x << " ^ " << y << " = " << exponentiate(x, y) << endl;
                break;
            default:
                cout << "Error: Please enter a number between 1 and 7." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}

