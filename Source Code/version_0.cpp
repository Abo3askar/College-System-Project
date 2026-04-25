#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
// defining the max inputs for our system
#define Students_max_users 500
#define Doctors_max_users 100
#define Administrators_max_users 5
#define Courses_limit 35
using namespace std;

struct grades {
  string course_name;
  float final, practical, year_work, quiz, grade_sum;
};
struct students {
  int Student_ID, academic_year;
  string name, department, mobile_number, password;
  grades student_grade[10];
  int student_grades_count = 1;
};
struct ASMs {
  int staff_member_ID, academic_year;
  string name, mobile_number, department, position, password,
      teaching_courses[5];
};
struct Admins {
  int ID;
  string mobile_number, name, position, password;
};
struct courses {
  float grade;
  string name, academic_member_name;
};
struct appointments {
  int student_id;
  int staff_id;
  string date;
  string time;
};
struct exams_schedule {
  string exam_name;
  string date;
  string time;
};
struct courses_schedule {
  string course_name;
  string week_day;
  string time;
};

// Preparing ram data
students student[Students_max_users];
int studentcount(1);
ASMs academic_member[Doctors_max_users];
int staffcount(0);
Admins admin_member[Administrators_max_users];
int adminscount(0);
courses course[Courses_limit];
int coursescount(0);
exams_schedule exam_schedule[Courses_limit];
int examscount(0);
courses_schedule courses_table[Courses_limit];
int schedules_count(0);
appointments appointment[200];
int appointment_count(0);

// Function declarations
bool logincheck(string username, string password, int usertype);
bool signupcheck(string username, string password, int usertype);
void studentmenu();
void staffmenu();
void adminsmenu();
void save();
void load();

int main() {
  load();
  char choice;
  cout << "=================================\n";
  cout << "Welcome to the college management system\n";
  cout << "=================================\n";
  cout << "press 1: if you are a student\n";
  cout << "press 2: if you are a staff member\n";
  cout << "press 3: if you are an admin\n";
  cout << "press 4: Save & Exit\n";
  cin >> choice;
  switch (choice) {
  case '1':
    studentmenu();
    break;
  case '2':
    staffmenu();
    break;
  case '3':
    adminsmenu();
    break;
  case '4':
    break;
  default:
    cout << "Sorry Invalid Option! " << endl;
  }
  save();
  return 0;
}

void save() {
  ofstream savefile("data.txt");
  if (savefile.is_open()) {
    savefile << "CMS_DATABASE_V1" << endl;
    savefile << studentcount << " " << staffcount << " " << adminscount << " "
             << coursescount << " " << examscount << " " << schedules_count
             << " " << appointment_count << " " << endl;
    for (int i = 0; i < studentcount; i++) {
      savefile << student[i].name << endl;
      savefile << student[i].department << endl;
      savefile << student[i].mobile_number << endl;
      savefile << student[i].password << endl;
      savefile << student[i].Student_ID << endl;
      savefile << student[i].academic_year << endl;
      for (int j = 0; j < student[i].student_grades_count; j++) {
        savefile << student[i].student_grade[j].course_name << endl;
        savefile << student[i].student_grade[j].final << endl;
        savefile << student[i].student_grade[j].practical << endl;
        savefile << student[i].student_grade[j].year_work << endl;
        savefile << student[i].student_grade[j].quiz << endl;
        savefile << student[i].student_grade[j].grade_sum << endl;
      }
    }
    for (int i = 0; i < staffcount; i++) {
      for (int j = 0; j < 5; j++) {
        savefile << academic_member[i].teaching_courses[j] << endl;
      }
      savefile << academic_member[i].name << endl;
      savefile << academic_member[i].password << endl;
      savefile << academic_member[i].mobile_number << endl;
      savefile << academic_member[i].department << endl;
      savefile << academic_member[i].position << endl;
      savefile << academic_member[i].staff_member_ID << endl;
    }
    for (int i = 0; i < adminscount; i++) {
      savefile << admin_member[i].name << endl;
      savefile << admin_member[i].password << endl;
      savefile << admin_member[i].mobile_number << endl;
      savefile << admin_member[i].position << endl;
      savefile << admin_member[i].ID << endl;
    }
    for (int i = 0; i < coursescount; i++) {
      savefile << course[i].name << endl;
      savefile << course[i].academic_member_name << endl;
      savefile << course[i].grade << endl;
    }
    for (int i = 0; i < appointment_count; i++) {
      savefile << appointment[i].date << endl;
      savefile << appointment[i].time << endl;
      savefile << appointment[i].student_id << endl;
      savefile << appointment[i].staff_id << endl;
    }
    for (int i = 0; i < examscount; i++) {
      savefile << exam_schedule[i].exam_name << endl;
      savefile << exam_schedule[i].date << endl;
      savefile << exam_schedule[i].time << endl;
    }
    for (int i = 0; i < schedules_count; i++) {
      savefile << courses_table[i].course_name << endl;
      savefile << courses_table[i].week_day << endl;
      savefile << courses_table[i].time << endl;
    }
  }
  savefile.close();
}

void load() {
  ifstream loadfile("data.txt");
  if (loadfile.is_open()) {
    string header;
    getline(loadfile, header);
    if (header != "CMS_DATABASE_V1") {
      cout << "Error: File corrupted or incompatible!" << endl;
      return;
    }
    loadfile >> studentcount >> staffcount >> adminscount >> coursescount >>
        examscount >> schedules_count >> appointment_count;
    for (int i = 0; i < studentcount; i++) {
      getline(loadfile >> ws, student[i].name);
      getline(loadfile >> ws, student[i].department);
      getline(loadfile >> ws, student[i].mobile_number);
      getline(loadfile >> ws, student[i].password);
      loadfile >> student[i].Student_ID;
      loadfile >> student[i].academic_year;
      for (int j = 0; j < 10; j++) {
        getline(loadfile >> ws, student[i].student_grade[j].course_name);
        loadfile >> student[i].student_grade[j].final;
        loadfile >> student[i].student_grade[j].practical;
        loadfile >> student[i].student_grade[j].quiz;
        loadfile >> student[i].student_grade[j].year_work;
        loadfile >> student[i].student_grade[j].grade_sum;
      }
    }
    for (int i = 0; i < staffcount; i++) {
      for (int j = 0; j < 5; j++) {
        getline(loadfile >> ws, academic_member[i].teaching_courses[j]);
      }
      getline(loadfile >> ws, academic_member[i].name);
      getline(loadfile >> ws, academic_member[i].password);
      getline(loadfile >> ws, academic_member[i].mobile_number);
      getline(loadfile >> ws, academic_member[i].department);
      getline(loadfile >> ws, academic_member[i].position);
      loadfile >> academic_member[i].staff_member_ID;
    }
    for (int i = 0; i < adminscount; i++) {
      getline(loadfile >> ws, admin_member[i].name);
      getline(loadfile >> ws, admin_member[i].password);
      getline(loadfile >> ws, admin_member[i].mobile_number);
      getline(loadfile >> ws, admin_member[i].position);
      loadfile >> admin_member[i].ID;
    }
    for (int i = 0; i < coursescount; i++) {
      getline(loadfile >> ws, course[i].name);
      getline(loadfile >> ws, course[i].academic_member_name);
      loadfile >> course[i].grade;
    }
    for (int i = 0; i < appointment_count; i++) {
      getline(loadfile >> ws, appointment[i].date);
      getline(loadfile >> ws, appointment[i].time);
      loadfile >> appointment[i].student_id;
      loadfile >> appointment[i].staff_id;
    }
    for (int i = 0; i < examscount; i++) {
      getline(loadfile >> ws, exam_schedule[i].exam_name);
      getline(loadfile >> ws, exam_schedule[i].date);
      getline(loadfile >> ws, exam_schedule[i].time);
    }
    for (int i = 0; i < schedules_count; i++) {
      getline(loadfile >> ws, courses_table[i].course_name);
      getline(loadfile >> ws, courses_table[i].week_day);
      getline(loadfile >> ws, courses_table[i].time);
    }
  }
  loadfile.close();
}

bool logincheck(string username, string password, int usertype) {
  if (usertype == 1) {
    for (int i = 0; i < studentcount; i++) {
      if (username == student[i].name && password == student[i].password)
        return true;
    }
  }
  if (usertype == 2) {
    for (int i = 0; i < staffcount; i++) {
      if (username == academic_member[i].name &&
          password == academic_member[i].password)
        return true;
    }
  }
  if (usertype == 3) {
    for (int i = 0; i < adminscount; i++) {
      if (username == admin_member[i].name &&
          password == admin_member[i].password)
        return true;
    }
  }
  return false;
}

bool signupcheck(string username, string password, int usertype) {
  return false;
}

void AddExamSchedule() {
  if (examscount < Courses_limit) {
    cout << "\n--- Add New Exam ---\n";
    cin.ignore();
    cout << "Course Name: ";
    getline(cin, exam_schedule[examscount].exam_name);
    cout << "Date (DD/MM/YYYY): ";
    getline(cin, exam_schedule[examscount].date);
    cout << "Time (HH:MM): ";
    getline(cin, exam_schedule[examscount].time);
    examscount++;
    cout << "Exam added successfully!\n";
  } else {
    cout << "Error: Exam schedule limit reached!\n";
  }
}

void add_course_table() {
  if (schedules_count < Courses_limit) {
    cout << "\n--- Add Course to Schedule ---\n";
    cin.ignore();
    cout << "Course Name: ";
    getline(cin, courses_table[schedules_count].course_name);
    cout << "Week Day: ";
    getline(cin, courses_table[schedules_count].week_day);
    cout << "Time: ";
    getline(cin, courses_table[schedules_count].time);
    schedules_count++;
    cout << "Course schedule updated successfully!\n";
  } else {
    cout << "Error: Course schedule limit reached!\n";
  }
}

void adminsmenu() {
  int adminChoice;
  cout << "\n--- Admin Menu ---\n";
  cout << "1. Add Exam Schedule\n";
  cout << "2. Add Course Schedule\n";
  cout << "3. Go Back\n";
  cout << "Selection: ";
  cin >> adminChoice;

  if (adminChoice == 1)
    AddExamSchedule();
  else if (adminChoice == 2)
    add_course_table();
}

void studentmenu() { cout << "\nStudent Menu logic goes here...\n"; }

void staffmenu() { cout << "\nStaff Menu logic goes here...\n"; }
