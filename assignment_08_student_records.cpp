// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Student
{
    string name;
    int id;
    vector<double> scores;
};

void displayMenu()
{
    cout << "===============================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "===============================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

double calculateAverage(const vector<double>& scores)
{
    if (scores.empty())
    {
        return 0.0;
    }

    double sum = 0.0;
    for (double score : scores)
    {
        sum += score;
    }
    return sum / scores.size();
}

void addStudent(vector<Student>& students)
{
    Student student;
    cout << "Student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    int scoreCount;
    cout << "How many scores? ";
    cin >> scoreCount;

    if (scoreCount < 0)
    {
        cout << "Error: Number of scores cannot be negative." << endl;
        return;
    }

    student.scores.clear();
    for (int i = 1; i <= scoreCount; ++i)
    {
        double score;
        cout << "Enter score " << i << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(12) << "ID" << setw(30) << "Scores" << "Average" << endl;
    cout << string(75, '=') << endl;

    for (const Student& student : students)
    {
        cout << left << setw(20) << student.name << setw(12) << student.id;

        string scoresText;
        for (size_t i = 0; i < student.scores.size(); ++i)
        {
            scoresText += to_string(student.scores[i]);
            if (i + 1 < student.scores.size())
            {
                scoresText += " ";
            }
        }

        cout << setw(30) << scoresText;
        cout << fixed << setprecision(2) << calculateAverage(student.scores) << endl;
    }
}

void calculateStudentAverage(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "Enter student ID: ";
    int searchId;
    cin >> searchId;

    for (const Student& student : students)
    {
        if (student.id == searchId)
        {
            double average = calculateAverage(student.scores);
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << average << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

int main()
{
    vector<Student> students;
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
            cout << "Error: Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Please enter a number between 1 and 4." << endl;
                break;
        }

        if (running)
        {
            cout << endl;
        }
    }

    return 0;
}

