#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

// Structure to store course information
struct Course {
    string name;
    string grade;
    int creditHours;
    int gradePoints;
};

// Function to convert grade to points
int getGradePoints(string grade) {
    map<string, int> gradeMap = {
        {"A+", 10}, {"A", 9}, {"B+", 8},
        {"B", 7}, {"C+", 6}, {"C", 5},
        {"D", 4}, {"F", 0}
    };

    if (gradeMap.find(grade) != gradeMap.end()) {
        return gradeMap[grade];
    } else {
        return -1; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses;
    int totalCredits = 0;
    int totalGradePoints = 0;

    for (int i = 0; i < numCourses; i++) {
        Course course;
        course.name = "Course " + to_string(i + 1);

        cout << "\n" << course.name << ":\n";
        cout << "Enter grade (A+, A, B+, etc.): ";
        cin >> course.grade;
        cout << "Enter credit hours: ";
        cin >> course.creditHours;

        int gradePoint = getGradePoints(course.grade);

        if (gradePoint == -1) {
            cout << "Invalid grade entered. Try again.\n";
            i--;
            continue;
        }

        course.gradePoints = gradePoint * course.creditHours;
        totalCredits += course.creditHours;
        totalGradePoints += course.gradePoints;

        courses.push_back(course);
    }

    // Calculate CGPA
    double cgpa = 0.0;
    if (totalCredits != 0)
        cgpa = static_cast<double>(totalGradePoints) / totalCredits;

    // Display course-wise details
    cout << "\n--- Individual Course Grades ---\n";
    for (const auto &course : courses) {
        cout << course.name << ": Grade = " << course.grade
             << ", Credit Hours = " << course.creditHours
             << ", Grade Points = " << course.gradePoints << "\n";
    }

    // Final output
    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
    