#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cctype>
#include<limits>

#define Students_max_users 500
#define Doctors_max_users 100
#define Administrators_max_users 15
#define Courses_limit 35
using namespace std;

struct grades {
    string course_name, gpa_alphabet;
    float final, practical, year_work, quiz, gpa;
};
struct appointments {
    int student_id;
    int staff_id;
    string date;
    string time;
};
struct students {
    int Student_ID, academic_year;
    string name, department, mobile_number, password;
    grades student_grade[7];
    int student_grades_count = 0;
    appointments student_side[5];
    int student_appointment_side_count = 0;
};
struct ASMs {
    int staff_member_ID, academic_year;
    string name, mobile_number, department, position, password, teaching_courses[25];
    int teaching_courses_count = 0;
    appointments staff_side[25];
    int staff_appointment_side_count = 0;
};
struct Admins {
    int ID;
    string  mobile_number, name, position, password;
};
struct courses {
    float grade;
    string name, academic_member_name;
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
int studentcount(0);
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
grades grade[Courses_limit];

bool logincheck(int id, string password, int usertype);
bool signupcheck(string name, string password, char usertype);
void studentmenu(int id); 
void staffmenu(int id);
void adminsmenu(int id);
void save();
void load();

int safeInputInt() {
    int value;
    cin >> value; 

    while (cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input! Please enter a valid number: ";
        cin >> value; 
    }

    return value;
}

float safeInputFloat() {
    float value;
    cin >> value;
        while (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a valid number: ";
            cin >> value;
    }
    return value;
}


int main() {
    load();
    char choice;
    do {
        system("cls");
        cout << "=================================\n";
        cout << "Welcome to the college management system\n";
        cout << "=================================\n";
        cout << "press 1: To Sign Up\n";
        cout << "press 2: To Login As a Student\n";
        cout << "press 3: To Login As a Staff member\n";
        cout << "press 4: To Login As an Admin\n";
        cout << "press 5: Save & Exit\n";
        cin >> choice;

        switch (choice) {
        case '1': {
            string signup_name, signup_pass;
            char type;
            cout << "Sign up as (1: Student, 2: Staff, 3: Admin): ";
            cin >> type;
            cout << "Enter your Full Name: ";
            getline(cin >> ws, signup_name); 
            cout << "Enter new password: ";
            cin >> signup_pass;

            if (signupcheck(signup_name, signup_pass, type)) {
                if (type == '1') {
                    cout << "Enter Your Mobile Number Please: ";
                    cin >> student[studentcount - 1].mobile_number;
                    cout << "Enter Academic Year Please: ";
                    student[studentcount - 1].academic_year = safeInputInt();
                    cout << "Enter Your Department Please: ";
                    cin >> student[studentcount - 1].department;
                    cout << "Registration Done!\n";
                    save();
                    system("pause");
                }
                if (type == '2') {
                    cout << "Enter Your Mobile Number Please: ";
                    cin >> academic_member[staffcount - 1].mobile_number;
                    cout << "Enter Academic Year Please: ";
                    academic_member[staffcount - 1].academic_year = safeInputInt();
                    cout << "Enter Your Department Please: ";
                    cin >> academic_member[staffcount - 1].department;
                    cout << "Enter Your Position Please: ";
                    cin >> academic_member[staffcount - 1].position;
                    cout << "Registration Done!\n";
                    save();
                    system("pause");
                }
                if (type == '3') {
                    cout << "Enter Your Mobile Number Please: ";
                    cin >> admin_member[adminscount - 1].mobile_number;
                    cout << "Enter Your Position Please: ";
                    cin >> admin_member[adminscount - 1].position;
                    cout << "Registration Done!\n";
                    save();
                    system("pause");
                }
            }
            break;
        }
        case '2': {
            int login_id; string pass;
            cout << "\n--- Student Login ---\n";
            cout << "Enter Your ID (or type 0 to go back): ";
            login_id = safeInputInt();
            if (login_id == 0) break;
            cout << "Enter Password: ";
            cin >> pass;
            if (logincheck(login_id, pass, 1)) {
                studentmenu(login_id);
            }
            else { cout << "Invalid ID or Password!\n"; system("pause"); }
            break;
        }
        case '3': {
            int login_id; string pass;
            cout << "\n--- Staff Login ---\n";
            cout << "Enter Your ID (or type 0 to go back): ";
            login_id = safeInputInt();
            if (login_id == 0) break;
            cout << "Enter Password: ";
            cin >> pass;
            if (logincheck(login_id, pass, 2)) {
                staffmenu(login_id);
            }
            else { cout << "Invalid ID or Password!\n"; system("pause"); }
            break;
        }
        case '4': {
            int login_id; string pass;
            cout << "\n--- Admins Login ---\n";
            cout << "Enter Your ID (or type 0 to go back): ";
            login_id = safeInputInt();
            if (login_id == 0) break;
            cout << "Enter Password: ";
            cin >> pass;
            if (logincheck(login_id, pass, 3)) {
                adminsmenu(login_id);
            }
            else { cout << "Invalid ID or Password!\n"; system("pause"); }
            break;
        }
        case '5':
            cout << "Saving data and exiting...\n";
            break;
        default:
            cout << "Sorry Invalid Option! " << endl;
            break;
        }
    } while (choice != '5');
    save();
    return 0;
}

void save() {
    ofstream savefile("data.txt");
    if (savefile.is_open()) {
        savefile << studentcount << " " << staffcount << " " << adminscount << " " << coursescount << " " << examscount << " " << schedules_count << " " << appointment_count << " " << endl;
        for (int i = 0; i < studentcount; i++) {
            savefile << student[i].name << endl;
            savefile << student[i].department << endl;
            savefile << student[i].mobile_number << endl;
            savefile << student[i].password << endl;
            savefile << student[i].Student_ID << endl;
            savefile << student[i].academic_year << endl;
            savefile << student[i].student_grades_count << endl;
            for (int j = 0; j < student[i].student_grades_count; j++) {
                savefile << student[i].student_grade[j].course_name << endl;
                savefile << student[i].student_grade[j].gpa_alphabet << endl;
                savefile << student[i].student_grade[j].final << endl;
                savefile << student[i].student_grade[j].practical << endl;
                savefile << student[i].student_grade[j].year_work << endl;
                savefile << student[i].student_grade[j].quiz << endl;
                savefile << student[i].student_grade[j].gpa << endl;
            }
        }

        for (int i = 0; i < staffcount; i++) {
            savefile << academic_member[i].teaching_courses_count << endl;
            for (int j = 0; j < academic_member[i].teaching_courses_count; j++) {
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
        loadfile >> studentcount >> staffcount >> adminscount >> coursescount >> examscount >> schedules_count >> appointment_count;
        for (int i = 0; i < studentcount; i++) {
            getline(loadfile >> ws, student[i].name);
            getline(loadfile >> ws, student[i].department);
            getline(loadfile >> ws, student[i].mobile_number);
            getline(loadfile >> ws, student[i].password);
            loadfile >> student[i].Student_ID;
            loadfile >> student[i].academic_year;
            loadfile >> student[i].student_grades_count;
            for (int j = 0; j < student[i].student_grades_count; j++) {
                getline(loadfile >> ws, student[i].student_grade[j].course_name);
                getline(loadfile >> ws, student[i].student_grade[j].gpa_alphabet);
                loadfile >> student[i].student_grade[j].final;
                loadfile >> student[i].student_grade[j].practical;
                loadfile >> student[i].student_grade[j].quiz;
                loadfile >> student[i].student_grade[j].year_work;
                loadfile >> student[i].student_grade[j].gpa;
            }
        }

        for (int i = 0; i < staffcount; i++) {
            loadfile >> academic_member[i].teaching_courses_count;
            for (int j = 0; j < academic_member[i].teaching_courses_count; j++) {
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

bool logincheck(int id, string password, int usertype) {
    if (usertype == 1) {
        for (int i = 0; i < studentcount; i++) {
            if (id == student[i].Student_ID && password == student[i].password) return true;
        }
    }
    if (usertype == 2) {
        for (int i = 0; i < staffcount; i++) {
            if (id == academic_member[i].staff_member_ID && password == academic_member[i].password) return true;
        }
    }
    if (usertype == 3) {
        for (int i = 0; i < adminscount; i++) {
            if (id == admin_member[i].ID && password == admin_member[i].password) return true;
        }
    }
    return false;
}

bool signupcheck(string name, string password, char usertype) {
    if (usertype == '1') {
        studentcount++;
        student[studentcount - 1].name = name;
        student[studentcount - 1].password = password;
        student[studentcount - 1].Student_ID = 20260000 + studentcount; 
        cout << "\n=========== Account Created! ===========\n";
        cout << "IMPORTANT: Your Student ID is: " << student[studentcount - 1].Student_ID << endl;
        cout << "Please save this ID, you will use it to LOGIN.\n";
        cout << "========================================\n";
        return true;
    }
    if (usertype == '2') {
        staffcount++;
        academic_member[staffcount - 1].name = name;
        academic_member[staffcount - 1].password = password;
        academic_member[staffcount - 1].staff_member_ID = 30360000 + staffcount;
        cout << "\n=========== Account Created! ===========\n";
        cout << "IMPORTANT: Your Staff ID is: " << academic_member[staffcount - 1].staff_member_ID << endl;
        cout << "Please save this ID, you will use it to LOGIN.\n";
        cout << "========================================\n";
        return true;
    }
    if (usertype == '3') {
        adminscount++;
        admin_member[adminscount - 1].name = name;
        admin_member[adminscount - 1].password = password;
        admin_member[adminscount - 1].ID = 40460000 + adminscount;
        cout << "\n=========== Account Created! ===========\n";
        cout << "IMPORTANT: Your Admin ID is: " << admin_member[adminscount - 1].ID << endl;
        cout << "Please save this ID, you will use it to LOGIN.\n";
        cout << "========================================\n";
        return true;
    }
    return false;
}

void studentmenu(int id) {
    int studentIndex = -1;
    for (int i = 0; i < studentcount; i++) {
        if (student[i].Student_ID == id) {
            studentIndex = i;
            break;
        }
    }
    string username = student[studentIndex].name;
    char student_choice;
    do {
        cout << "\n=================================\n";
        cout << "       Welcome " << username << "!\n";
        cout << "       Student Dashboard\n";
        cout << "=================================\n";
        cout << "Press 1 To Register Courses\n";
        cout << "Press 2 To See Your Grades\n";
        cout << "Press 3 To Request An Appointment With An Academic Staff\n";
        cout << "Press 4 To Logout (Return to Main Menu)\n";
        cout << "Enter your choice: ";
        cin >> student_choice;
        switch (student_choice) {
        case '1': {
            cout << "====Available Courses====\n";
            for (int i = 0; i < coursescount; i++) {
                cout << i + 1 << ". " << course[i].name << " (Staff: " << course[i].academic_member_name << ")\n";
            }
            int course_choice;
            cout << "Select course number to register: ";
            course_choice = safeInputInt();
            if (course_choice > 0 && course_choice <= coursescount) {
                int current_course = student[studentIndex].student_grades_count;
                if (current_course < 7) {
                    student[studentIndex].student_grade[current_course].course_name = course[course_choice - 1].name;
                    student[studentIndex].student_grade[current_course].quiz = 0.0;
                    student[studentIndex].student_grade[current_course].year_work = 0.0;
                    student[studentIndex].student_grade[current_course].practical = 0.0;
                    student[studentIndex].student_grade[current_course].final = 0.0;
                    student[studentIndex].student_grade[current_course].gpa = 0.0;
                    student[studentIndex].student_grade[current_course].gpa_alphabet = "N/A";
                    student[studentIndex].student_grades_count++;
                    cout << "Successfully registered in " << course[course_choice - 1].name << endl;
                }
                else
                {
                    cout << "You reached the maximum limit of courses!\n";
                }
            }
            system("pause");
            break;
        }
        case '2': {
            for (int i = 0; i < student[studentIndex].student_grades_count; i++) {
                cout << "=====================================\n";
                cout << student[studentIndex].student_grade[i].course_name << ": \n";
                cout << "quiz: " << student[studentIndex].student_grade[i].quiz << endl;
                cout << "Year work: " << student[studentIndex].student_grade[i].year_work << endl;
                cout << "Final: " << student[studentIndex].student_grade[i].final << endl;
                cout << "GPA: " << student[studentIndex].student_grade[i].gpa << endl;
                cout << "gpa_alphabet: " << student[studentIndex].student_grade[i].gpa_alphabet << endl;
                cout << "=====================================\n";
            }
            system("pause");
            break;
        }
        case '3': {
            cout << "1 To show your appointments: \n";
            cout << "2 To register an appointment: \n";
            char app_choice;
            cin >> app_choice;
            switch (app_choice) {
            case '1': {
                for (int i = 0; i < student[studentIndex].student_appointment_side_count; i++) {
                    cout << student[studentIndex].student_side[i].staff_id << endl;
                    cout << student[studentIndex].student_side[i].date << endl;
                    cout << student[studentIndex].student_side[i].time << endl;
                }
                break;
            }
            case '2': {
                cout << "Please choose the staff member to meet with (*Type the name*): ";
                for (int i = 0; i < staffcount; i++) {
                    cout << academic_member[i].name << endl;
                }
                string member_to_meet;
                int app_date_year, app_date_month, app_date_day, app_time;
                cin >> member_to_meet;

                for (int i = 0; i < staffcount; i++) {
                    if (member_to_meet == academic_member[i].name) {
                        cout << "Choose the date please: \n";
                        cout << "Year: "; app_date_year = safeInputInt();
                        cout << "Month: "; app_date_month = safeInputInt();
                        cout << "Day: "; app_date_day = safeInputInt();

                        cout << "Choose the time please (from 8 to 16): ";
                        app_time = safeInputInt();

                        int st_app_count = student[studentIndex].student_appointment_side_count;
                        int doc_app_count = academic_member[i].staff_appointment_side_count;

                        student[studentIndex].student_side[st_app_count].date = to_string(app_date_year) + "-" + to_string(app_date_month) + "-" + to_string(app_date_day);
                        student[studentIndex].student_side[st_app_count].time = to_string(app_time);
                        student[studentIndex].student_side[st_app_count].staff_id = academic_member[i].staff_member_ID;

                        academic_member[i].staff_side[doc_app_count].date = to_string(app_date_year) + "-" + to_string(app_date_month) + "-" + to_string(app_date_day);
                        academic_member[i].staff_side[doc_app_count].time = to_string(app_time);
                        academic_member[i].staff_side[doc_app_count].student_id = student[studentIndex].Student_ID;

                        appointment[appointment_count].student_id = student[studentIndex].Student_ID;
                        appointment[appointment_count].staff_id = academic_member[i].staff_member_ID;
                        appointment[appointment_count].date = to_string(app_date_year) + "-" + to_string(app_date_month) + "-" + to_string(app_date_day);
                        appointment[appointment_count].time = to_string(app_time);

                        student[studentIndex].student_appointment_side_count++;
                        academic_member[i].staff_appointment_side_count++;
                        appointment_count++;

                        cout << "The appointment registered successfully \n";
                        system("pause");
                        break;
                    }
                }
                break;
            }
            }
        }
        }
    } while (student_choice != '4');
}

void staffmenu(int id) {
    char staff_choice;
    int stafff_logged_index = -1;
    for (int i = 0; i < staffcount; i++) {
        if (academic_member[i].staff_member_ID == id) {
            stafff_logged_index = i;
            break;
        }
    }
    string username = academic_member[stafff_logged_index].name;
    do {
        cout << "\n=================================\n";
        cout << "       Welcome " << username << "!\n";
        cout << "       Academic members' Dashboard\n";
        cout << "=================================\n";
        cout << "Press 1 To select the academic courses to teach\n";
        cout << "Press 2 To set grades\n";
        cout << "Press 3 To View Appointments\n";
        cout << "Press 4 To Logout (Return to Main Menu)\n";
        cout << "Enter your choice: ";
        cin >> staff_choice;
        switch (staff_choice) {
        case '1': {
            int show_option, selected_index;
            cout << "What Course(s) Do You Want To Teach? \n";
            cout << "Press 1 To See All Available Courses: ";
            show_option = safeInputInt();
            if (show_option == 1) {
                for (int i = 0; i < coursescount; i++) {
                    cout << i + 1 << ": " << course[i].name << " | ";
                    if ((i + 1) % 4 == 0) {
                        cout << endl;
                    }
                }
                cout << "\nEnter the course number: ";
                selected_index = safeInputInt();
                int course_index = selected_index - 1;

                if (course_index >= 0 && course_index < coursescount) {
                    int current_count = academic_member[stafff_logged_index].teaching_courses_count;
                    if (current_count < 25) {
                        academic_member[stafff_logged_index].teaching_courses[current_count] = course[course_index].name;
                        academic_member[stafff_logged_index].teaching_courses_count++;
                        cout << "Course added to your teaching list successfully!\n";
                    }
                    else {
                        cout << "You reached the maximum limit of teaching courses!\n";
                    }
                }
                else {
                    cout << "Invalid course selection!\n";
                }
            }
            break;
        }
        case '2': {
            int course_number_choice;
            cout << "Choose which course you want to set grades in it\n";
            for (int i = 0; i < coursescount; i++) {
                cout << i + 1 << ": " << course[i].name << " | ";
                if ((i + 1) % 4 == 0) {
                    cout << endl;
                }
            }
            cout << "\nEnter course number: ";
            course_number_choice = safeInputInt();

            if (course_number_choice > 0 && course_number_choice <= coursescount) {
                string selected_course_name = course[course_number_choice - 1].name;
                bool student_found = false;

                cout << "\n--- Entering grades for " << selected_course_name << " ---\n";

                for (int i = 0; i < studentcount; i++) {
                    for (int j = 0; j < student[i].student_grades_count; j++) {
                        if (student[i].student_grade[j].course_name == selected_course_name) {
                            student_found = true;
                            cout << "\nStudent ID: " << student[i].Student_ID << " (Name: " << student[i].name << ")\n";

                            cout << "Quiz (out of 10): ";
                            student[i].student_grade[j].quiz = safeInputFloat();
                            cout << "Practical (out of 20): ";
                            student[i].student_grade[j].practical = safeInputFloat();
                            cout << "Year work (out of 10): ";
                            student[i].student_grade[j].year_work = safeInputFloat();
                            cout << "Final (out of 60): ";
                            student[i].student_grade[j].final = safeInputFloat();
                            float total = student[i].student_grade[j].quiz + student[i].student_grade[j].practical +
                                student[i].student_grade[j].year_work + student[i].student_grade[j].final;
                            if (total >= 90) { student[i].student_grade[j].gpa_alphabet = "A"; student[i].student_grade[j].gpa = 4.0; }
                            else if (total >= 85) { student[i].student_grade[j].gpa_alphabet = "A-"; student[i].student_grade[j].gpa = 3.7; }
                            else if (total >= 80) { student[i].student_grade[j].gpa_alphabet = "B+"; student[i].student_grade[j].gpa = 3.3; }
                            else if (total >= 75) { student[i].student_grade[j].gpa_alphabet = "B"; student[i].student_grade[j].gpa = 3.0; }
                            else if (total >= 70) { student[i].student_grade[j].gpa_alphabet = "C+"; student[i].student_grade[j].gpa = 2.7; }
                            else if (total >= 65) { student[i].student_grade[j].gpa_alphabet = "C"; student[i].student_grade[j].gpa = 2.4; }
                            else if (total >= 60) { student[i].student_grade[j].gpa_alphabet = "D+"; student[i].student_grade[j].gpa = 2.2; }
                            else if (total >= 50) { student[i].student_grade[j].gpa_alphabet = "D"; student[i].student_grade[j].gpa = 2.0; }
                            else { student[i].student_grade[j].gpa_alphabet = "F"; student[i].student_grade[j].gpa = 0.0; }

                            cout << "=> System Auto-Calculated => Total: " << total
                                << " | GPA: " << student[i].student_grade[j].gpa
                                << " (" << student[i].student_grade[j].gpa_alphabet << ")\n";

                            break;
                        }
                    }
                }

                if (!student_found) {
                    cout << "No students are currently registered for this course.\n";
                }
            }
            else {
                cout << "Invalid course selection!\n";
            }
            break;
        }
        case '3': {
            cout << "=== Your Appointments ===\n";
            int current_doc_apps = academic_member[stafff_logged_index].staff_appointment_side_count;
            if (current_doc_apps == 0) {
                cout << "You have no appointments currently.\n";
            }
            else {
                for (int i = 0; i < current_doc_apps; i++) {
                    cout << "Appointment " << i + 1 << ":\n";
                    cout << "Student ID: " << academic_member[stafff_logged_index].staff_side[i].student_id << endl;
                    cout << "Date: " << academic_member[stafff_logged_index].staff_side[i].date << endl;
                    cout << "Time: " << academic_member[stafff_logged_index].staff_side[i].time << ":00" << endl;
                    cout << "-------------------------\n";
                }
            }
            system("pause");
            break;
        }
        }

    } while (staff_choice != '4');
}

void adminsmenu(int id) {
    int Admin_index = -1;
    char Admin_choice;
    for (int i = 0; i < adminscount; i++) {
        if (admin_member[i].ID == id) {
            Admin_index = i;
            break;
        }
    }
    string username = admin_member[Admin_index].name;

    do {
        cout << "\n=================================\n";
        cout << "       Welcome " << username << "!\n";
        cout << "       Admins' Dashboard\n";
        cout << "=================================\n";
        cout << "Press 1 To Add Courses\n";
        cout << "Press 2 To Put Schedule Of Courses\n";
        cout << "Press 3 To Put Schedule Of Exams\n";
        cout << "Press 4 To See The Available Courses\n";
        cout << "Press 5 To See The Schedules Of Courses\n";
        cout << "Press 6 To See The Schedules Of Exams\n";
        cout << "Press 7 To Logout (Return to Main Menu)\n";

        cout << "Enter your choice: ";
        cin >> Admin_choice;

        switch (Admin_choice) {
        case '1': {
            string add_choice;
            do {
                string temp_name;
                float temp_grade;

                cout << "Course name: ";
                getline(cin >> ws, temp_name);
                cout << "Course grade: ";
                temp_grade = safeInputFloat();

                bool exists = false;
                for (int i = 0; i < coursescount; i++) {
                    string existing_course = course[i].name;
                    string new_course = temp_name;
                    transform(existing_course.begin(), existing_course.end(), existing_course.begin(), ::tolower);
                    transform(new_course.begin(), new_course.end(), new_course.begin(), ::tolower);

                    if (new_course == existing_course) {
                        cout << "*****Sorry this course is already existed*****\n";
                        exists = true;
                        break; 
                    }
                }
                if (!exists) {
                    course[coursescount].name = temp_name;
                    course[coursescount].grade = temp_grade;
                    transform(course[coursescount].name.begin(), course[coursescount].name.end(), course[coursescount].name.begin(), ::tolower);
                    courses_table[schedules_count].course_name = course[coursescount].name;

                    coursescount++;
                    schedules_count++;
                    cout << "Course added successfully!\n";
                }

                cout << "Do you want to add another course? (\"yes\" | \"no\") ";
                cin >> add_choice;
                transform(add_choice.begin(), add_choice.end(), add_choice.begin(), ::tolower);
            } while (add_choice != "no");

            break;
        }
        case '2': {
            string set_choice;
            do {
                int course_number_choice;
                int course_index;
                for (int i = 0; i < coursescount; i++) {
                    cout << i + 1 << ": " << course[i].name << " | ";
                    if ((i + 1) % 4 == 0) {
                        cout << endl;
                    }
                }
                cout << "\nChoose the course number: ";
                course_number_choice = safeInputInt();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << endl;

                course_index = course_number_choice - 1;
                cout << "Course week day: ";
                getline(cin, courses_table[course_index].week_day);
                cout << "Course time: ";
                getline(cin, courses_table[course_index].time);
                cout << "Do you want to set another course schedule? (\"yes\" | \"no\") ";
                cin >> set_choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                transform(set_choice.begin(), set_choice.end(), set_choice.begin(), ::tolower);
            } while (set_choice != "no");
            break;
        }
        case '3': {
            string set_exams_choice;

            do {
                int exam_number_choice;
                int exam_set_index;
                int course_number_choice;
                for (int i = 0; i < coursescount; i++) {
                    cout << i + 1 << ": " << course[i].name << " | ";
                    if ((i + 1) % 4 == 0) {
                        cout << endl;
                    }
                }
                cout << "\nChoose the course number to set the exam: ";
                course_number_choice = safeInputInt();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << endl;

                exam_set_index = course_number_choice - 1;
                cout << "Exam date: ";
                getline(cin, exam_schedule[exam_set_index].date);
                cout << "Exam time: ";
                getline(cin, courses_table[exam_set_index].time);
                examscount++;
                cout << "Do you want to set another course schedule? (\"yes\" | \"no\") ";
                cin >> set_exams_choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                transform(set_exams_choice.begin(), set_exams_choice.end(), set_exams_choice.begin(), ::tolower);
            } while (set_exams_choice != "no");

            break;
        }
        case '4': {
            for (int i = 0; i < coursescount; i++) {
                cout << i + 1 << ": " << course[i].name << " | ";
                if ((i + 1) % 4 == 0) {
                    cout << endl;
                }
            }
            cout << endl;
            break;
        }
        case '5': {
            cout << "Course name\t" << "\t" << "Day\t" << "\t" << "Time\n";
            for (int i = 0; i < coursescount; i++) {
                cout << course[i].name << "\t" << "\t" << "\t" << courses_table[i].week_day << "\t" << courses_table[i].time << "\n";
            }
            break;
        }
        case '6': {
            cout << "Course name\t" << "\t" << "Day\t" << "\t" << "Time\n";
            for (int i = 0; i < examscount; i++) {
                cout << course[i].name << "\t" << "\t" << "\t" << exam_schedule[i].date << "\t" << "\t" << exam_schedule[i].time << "\n";
            }
            break;
        }
        }
    } while (Admin_choice != '7');
}