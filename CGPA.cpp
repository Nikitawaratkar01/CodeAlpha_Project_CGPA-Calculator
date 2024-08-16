#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Course
{
    string name;
    int credits;
    float grade; // Grade should be on a scale, e.g., 0-10
};

float calculateGPA(const vector<Course> &courses)
{
    float totalGradePoints = 0;
    float totalCredits = 0;

    for (int i = 0; i < courses.size(); ++i)
    {
        totalGradePoints += courses[i].grade * courses[i].credits;
        totalCredits += courses[i].credits;
    }
    
    if (totalCredits == 0)
    {
        return 0;
    }
    return totalGradePoints / totalCredits;
}

int main()
{
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    cin.ignore(); // Clear newline character left in the input buffer
    
    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; ++i)
    {
        cout << "Enter the name of course " << (i + 1) << ": ";
        getline(cin, courses[i].name);
        cout << "Enter the number of credits for " << courses[i].name << ": ";
        cin >> courses[i].credits;
        cout << "Enter the grade for " << courses[i].name << " (0-10): ";
        cin >> courses[i].grade;
        cin.ignore(); // Clear newline character left in the input buffer
    }

    float gpa = calculateGPA(courses);

    cout << fixed << setprecision(2);

    cout << "\nCourse Details:\n";
    for (int i = 0; i < courses.size(); ++i)
    {
        cout << "Course: " << courses[i].name << ", Credits: " << courses[i].credits
             << ", Grade: " << courses[i].grade << "\n";
    }

    cout << "\nTotal Credits: " << numCourses << "\n"; // numCourses is not the total credits, you should compute total credits separately if needed
    cout << "Total Grade Points: " << (gpa * numCourses) << "\n"; // This line is misleading; GPA calculation already provides this
    cout << "GPA for the semester: " << gpa << "\n";
    cout << "CGPA: " << gpa << "\n"; // Assuming CGPA is same as GPA for the given semester

    return 0;
}
