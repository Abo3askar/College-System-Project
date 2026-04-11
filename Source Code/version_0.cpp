#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
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
    // for the easy access!
    grades student_grade[10];
};
// (ASM) for Academic_ Staff_member
struct ASMs {
    int staff_member_ID, academic_year;
    string name, mobile_number, department, position, password, teaching_courses[5];
};
// (Admin) for administration_member
struct Admins {
    int ID;
    string  mobile_number, name, position, password;
};
struct courses {
    float grade;
    string name, academic_member_name;
};
// if the student want to meet a staff member
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
ASMs  academic_member[Doctors_max_users];
int  staffcount(0);
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
// Please define the functions here
bool login(int type, string username, string password);
bool signup(int type, string username, string password);


// Save & Load functions (type them down)
void save();
void load();
// Save & Load functions
int main() {
    load();
    student[0].name = "Omar Gamal";
    student[0].department = "Computer science";
    student[0].mobile_number = "0123123213";
    student[0].password = "aswerwa";
    student[0].Student_ID = 31321;
    student[0].academic_year = 1;
    student[0].student_grade[0].course_name = "discrete math";
    student[0].student_grade[0].final = 45;
    student[0].student_grade[0].practical = 17;
    student[0].student_grade[0].year_work = 10;
    student[0].student_grade[0].quiz = 5;
    student[0].student_grade[0].grade_sum = 77;
    cout << "Hi iam testing (:\n";

    save();
    return 0;
}
// don't forget to declare them (:
void save() {
    // we want to save the data from structs for every type we have
    // students, staff members, admins, student_grades, courses, appointment, exam schedules, course_schedule
    // students and their grades
    ofstream savefile("data.txt");
    if (savefile.is_open()) {
        savefile << "CMS_DATABASE_V1" << endl;
        savefile << studentcount << " " << staffcount << " " << adminscount << " " << coursescount << " " << examscount << " " << schedules_count << " " << appointment_count << " " << endl;
        for (int i = 0; i < studentcount; i++) {
            savefile << student[i].name << endl;
            savefile << student[i].department << endl;
            savefile << student[i].mobile_number << endl;
            savefile << student[i].password << endl;
            savefile << student[i].Student_ID << endl;
            savefile << student[i].academic_year << endl;
            for (int j = 0; j < 10; j++) {
                savefile << student[i].student_grade[j].course_name << endl;
                savefile << student[i].student_grade[j].final << endl;
                savefile << student[i].student_grade[j].practical << endl;
                savefile << student[i].student_grade[j].year_work << endl;
                savefile << student[i].student_grade[j].quiz << endl;
                savefile << student[i].student_grade[j].grade_sum << endl;
            }
        }
        // staff members
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
        // staff members
       // admins
        for (int i = 0; i < adminscount; i++) {
            savefile << admin_member[i].name << endl;
            savefile << admin_member[i].password << endl;
            savefile << admin_member[i].mobile_number << endl;
            savefile << admin_member[i].position << endl;
            savefile << admin_member[i].ID << endl;
        }

        // admins
        // courses
        for (int i = 0; i < coursescount; i++) {
            savefile << course[i].name << endl;
            savefile << course[i].academic_member_name << endl;
            savefile << course[i].grade << endl;
        }

        //courses
        // appointments
        for (int i = 0; i < appointment_count; i++) {
            savefile << appointment[i].date << endl;
            savefile << appointment[i].time << endl;
            savefile << appointment[i].student_id << endl;
            savefile << appointment[i].staff_id << endl;
        }


        // appointments
        // exam schedules
        for (int i = 0; i < examscount; i++) {
            savefile << exam_schedule[i].exam_name << endl;
            savefile << exam_schedule[i].date << endl;
            savefile << exam_schedule[i].time << endl;
        }
        // exam schedules
        // courses_schedule
        for (int i = 0; i < schedules_count; i++) {
            savefile << courses_table[i].course_name << endl;
            savefile << courses_table[i].week_day << endl;
            savefile << courses_table[i].time << endl;
        }

        //courses_schedule
    }
    savefile.close();
}
// load function declaration
void load() {
    ifstream loadfile("data.txt");
    if (loadfile.is_open()) {
        string header;
        getline(loadfile, header);
        if (header != "CMS_DATABASE_V1") {
            cout << "Error: File corrupted or incompatible!" << endl;
            return;
            }

        loadfile >> studentcount >> staffcount >> adminscount >> coursescount >> examscount >> schedules_count >> appointment_count;
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
        // staff members
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
        // staff members
       // admins
        for (int i = 0; i < adminscount; i++) {
            getline(loadfile >> ws, admin_member[i].name);
            getline(loadfile >> ws, admin_member[i].password);
            getline(loadfile >> ws, admin_member[i].mobile_number);
            getline(loadfile >> ws, admin_member[i].position);
            loadfile >> admin_member[i].ID;
        }

        // admins
        // courses
        for (int i = 0; i < coursescount; i++) {
            getline(loadfile >> ws, course[i].name);
            getline(loadfile >> ws, course[i].academic_member_name);
            loadfile >> course[i].grade;
        }

        //courses
        // appointments
        for (int i = 0; i < appointment_count; i++) {
            getline(loadfile >> ws, appointment[i].date);
            getline(loadfile >> ws, appointment[i].time);
            loadfile >> appointment[i].student_id;
            loadfile >> appointment[i].staff_id;
        }


        // appointments
        // exam schedules
        for (int i = 0; i < examscount; i++) {
            getline(loadfile >> ws, exam_schedule[i].exam_name);
            getline(loadfile >> ws, exam_schedule[i].date);
            getline(loadfile >> ws, exam_schedule[i].time);
        }
        // exam schedules
        // courses_schedule
        for (int i = 0; i < schedules_count; i++) {
            getline(loadfile >> ws, courses_table[i].course_name);
            getline(loadfile >> ws, courses_table[i].week_day);
            getline(loadfile >> ws, courses_table[i].time);
        }

        //courses_schedule
    }
    loadfile.close();
}