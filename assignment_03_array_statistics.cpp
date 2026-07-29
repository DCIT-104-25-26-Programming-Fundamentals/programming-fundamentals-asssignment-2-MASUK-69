// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

#include <iostream>
using namespace std;

int calculateSum(const int numbers[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += numbers[i];
    }
    return sum;
}

double calculateAverage(const int numbers[], int count)
{
    int sum = calculateSum(numbers, count);
    return static_cast<double>(sum) / count;
}

int findMaximum(const int numbers[], int count)
{
    int maximum = numbers[0];
    for (int i = 1; i < count; ++i)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }
    return maximum;
}

int findMinimum(const int numbers[], int count)
{
    int minimum = numbers[0];
    for (int i = 1; i < count; ++i)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }
    return minimum;
}

int main()
{
    int count;
    cout << "How many numbers? ";
    cin >> count;

    if (count <= 0)
    {
        cout << "Error: Number of elements must be positive." << endl;
        return 0;
    }

    int* numbers = new int[count];
    for (int i = 0; i < count; ++i)
    {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int sum = calculateSum(numbers, count);
    double average = calculateAverage(numbers, count);
    int maximum = findMaximum(numbers, count);
    int minimum = findMinimum(numbers, count);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    delete[] numbers;
    return 0;
}

