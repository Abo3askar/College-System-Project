#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cctype>
//#include<algorithm>
// defining the max inputs for our system
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
    // for the easy access!
    grades student_grade[7];
    int student_grades_count = 0;
    appointments student_side[5];
    int student_appointment_side_count = 0;
};
// (ASM) for Academic_ Staff_member
struct ASMs {
    int staff_member_ID, academic_year;
    string name, mobile_number, department, position, password, teaching_courses[25];
    appointments staff_side[25];
    int staff_appointment_side_count = 0;
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
// Please declare the functions here

bool logincheck(string username, string password, int usertype);
bool signupcheck(string username, string password, char usertype);
void studentmenu(string username, string password);
void staffmenu(string username, string password);
void adminsmenu(string username, string password);


// Save & Load functions (type them down)
void save();
void load();
// Save & Load functions
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
            string signup_username, signup_pass;
            char type;
            cout << "Sign up as (1: Student, 2: Staff, 3: Admin): ";
            cin >> type;
            cout << "Enter new username: ";
            cin >> signup_username;
            cout << "Enter new password: ";
            cin >> signup_pass;

            if (signupcheck(signup_username, signup_pass, type)) {
                if (type == '1') {
                    cout << "Enter Your Mobile Number Please: ";
                    cin >> student[studentcount - 1].mobile_number;
                    cout << "Enter Academic Year Please: ";
                    cin >> student[studentcount - 1].academic_year;
                    cout << "Enter Your Department Please: ";
                    cin >> student[studentcount - 1].department;
                    cout << "Account created successfully! You can now login.\n";
                    system("pause");
                }
                if (type == '2') {
                    cout << "Enter Your Mobile Number Please: ";
                    cin >> academic_member[staffcount - 1].mobile_number;
                    cout << "Enter Academic Year Please: ";
                    cin >> academic_member[staffcount - 1].academic_year;
                    cout << "Enter Your Department Please: ";
                    cin >> academic_member[staffcount - 1].department;
                    cout << "Enter Your Position Please: ";
                    cin >> academic_member[staffcount - 1].position;
                    cout << "Account created successfully! You can now login.\n";
                    system("pause");
                }
                if (type == '3') {
                    cout << "Enter Your Mobile Number Please: ";
                    cin >> admin_member[adminscount - 1].mobile_number;
                    cout << "Enter Your Position Please: ";
                    cin >> admin_member[adminscount - 1].position;
                    cout << "Account created successfully! You can now login.\n";
                    system("pause");
                }
            }
        }
                break;
        case '2': {
            string user, pass;
            cout << "\n--- Student Login ---\n";
            cout << "Enter Username (or type '0' to go back): ";
            cin >> user;
            if (user == "0")
                break;
            cout << "Enter Password: ";
            cin >> pass;
            if (logincheck(user, pass, 1)) {
                studentmenu(user, pass);
            }
        }
                break;
        case '3': {
            string user, pass;
            cout << "\n--- staff' Login ---\n";
            cout << "Enter Username (or type '0' to go back): ";
            cin >> user;
            if (user == "0")
                break;
            cout << "Enter Password: ";
            cin >> pass;
            if (logincheck(user, pass, 2)) {
                staffmenu(user, pass);
            }
        }
                break;
        case '4': {
            string user, pass;
            cout << "\n--- Admins' Login ---\n";
            cout << "Enter Username (or type '0' to go back): ";
            cout << "Enter Username: ";
            cin >> user;
            if (user == "0")
                break;
            cout << "Enter Password: ";
            cin >> pass;
            if (logincheck(user, pass, 3)) {
                adminsmenu(user, pass);
            }
        }
                break;
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
bool logincheck(string username, string password, int usertype) {

    if (usertype == 1) {
        for (int i = 0; i < studentcount; i++) {
            if (username == student[i].name && password == student[i].password) {
                return true;
            }
        }
    }
    if (usertype == 2) {
        for (int i = 0; i < staffcount; i++) {
            if (username == academic_member[i].name && password == academic_member[i].password) {
                return true;
            }
        }
    }
    if (usertype == 3) {
        for (int i = 0; i < adminscount; i++) {
            if (username == admin_member[i].name && password == admin_member[i].password) {
                return true;
            }
        }
    }
    return false;
}
bool signupcheck(string username, string password, char usertype) {
    if (usertype == '1') {
        for (int i = 0; i < studentcount; i++) {
            if (username == student[i].name) {
                cout << "*********Sorry this username is already used!*********";
                system("pause");
                return false;
            }
        }
        studentcount++;
        student[studentcount - 1].name = username;
        student[studentcount - 1].password = password;
        student[studentcount - 1].Student_ID = 1882202611 + studentcount;
        cout << "===========Almost Done!===========\n";
        cout << "Your student ID is: " << student[studentcount - 1].Student_ID << endl;
        save();
        system("pause");
        return true;
    }
    if (usertype == '2') {
        for (int i = 0; i < studentcount; i++) {
            if (username == student[i].name) {
                cout << "*********Sorry this username is already used!*********";
                break;
            }
        }
        staffcount++;
        academic_member[staffcount - 1].name = username;
        academic_member[staffcount - 1].password = password;
        academic_member[staffcount - 1].staff_member_ID = 1882202622 + staffcount;
        cout << "===========Almost Done!===========\n";
        cout << "Your academic_member ID is: " << academic_member[staffcount - 1].staff_member_ID << endl;
        save();
        return true;
        system("pause");
    }
    if (usertype == '3') {
        for (int i = 0; i < adminscount; i++) {
            if (username == admin_member[i].name) {
                cout << "*********Sorry this username is already used!*********";
                break;
            }
        }
        adminscount++;
        admin_member[adminscount - 1].name = username;
        admin_member[adminscount - 1].password = password;
        admin_member[adminscount - 1].ID = 1882202611 + adminscount;
        cout << "===========Almost Done!===========\n";
        cout << "Your student ID is: " << admin_member[adminscount - 1].ID << endl;
        save();
        return true;
        system("pause");
    }
    return false;
}
void studentmenu(string username, string passwword) {
    int studentIndex = -1;
    for (int i = 0; i < studentcount; i++) {
        if (student[i].name == username) {
            studentIndex = i;
            break;
        }
    }
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
            cin >> course_choice;
            if (course_choice > 0 && course_choice <= coursescount) {
                int current_course = student[studentIndex].student_grades_count;
                if (current_course < 7) {
                    student[studentIndex].student_grade[current_course].course_name = course[course_choice - 1].name;
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
            // appointment
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
                int staff_index;
                for (int i = 0; i < staffcount; i++) {
                    if (member_to_meet == academic_member[i].name) {
                        staff_index = i;
                    }
                }
                for (int i = 0; i < staffcount; i++) {
                    if (member_to_meet == academic_member[i].name) {
                        cout << "Choose the date please: ";
                        cout << "Year: ";
                        cin >> app_date_year;
                        cout << "month: ";
                        cin >> app_date_month;
                        cout << "day: ";
                        cin >> app_date_day;
                        student[studentIndex].student_side[student[studentIndex].student_appointment_side_count - 1].date =
                            to_string(app_date_year) + "-" + to_string(app_date_month) + "-" + to_string(app_date_day);
                        academic_member[staff_index].staff_side[academic_member[staff_index].staff_appointment_side_count - 1].date =
                            to_string(app_date_year) + "-" + to_string(app_date_month) + "-" + to_string(app_date_day);
                        cout << "Choose the time please (from 8 to 16): ";
                        cin >> app_time;
                        student[studentIndex].student_side[student[studentIndex].student_appointment_side_count - 1].time = to_string(app_time);
                        academic_member[staff_index].staff_side[academic_member[staff_index].staff_appointment_side_count - 1].time = to_string(app_time);
                        appointment[appointment_count - 1].student_id = student[studentIndex].Student_ID;
                        appointment[appointment_count - 1].staff_id = academic_member[staff_index].staff_member_ID;
                        appointment_count++;
                        cout << "The appointment registered successfully \n";
                        system("pause");
                    }
                }
                break;
            }
            }
        }
        }


    } while (student_choice != '4');
}
void staffmenu(string username, string passwword) {
    char staff_choice;
    int stafff_logged_index;
    for (int i = 0; i < staffcount; i++) {
        if (academic_member[i].name == username) {
            stafff_logged_index = i;
            break;
        }
    }
    do {
        cout << "\n=================================\n";
        cout << "       Welcome " << username << "!\n";
        cout << "       Academic members' Dashboard\n";
        cout << "=================================\n";
        cout << "Press 1 To select the academic courses to teach\n";
        cout << "Press 2 To set grades\n";
        cout << "Press 3 To Logout (Return to Main Menu)\n";
        cout << "Enter your choice: ";
        cin >> staff_choice;
        switch (staff_choice) {
        case '1': {
            int show_option, selected_index;
            cout << "What Course(s) Do You Want To Teach? ";
            cout << "Press: " << "1 To See All Available Courses ";
            cin >> show_option;
            if (show_option == 1) {
                for (int i = 0; i < coursescount; i++) {
                    // طباعة رقم الكورس واسمه
                    cout << i + 1 << ": " << course[i].name << " | ";

                    // لو ترتيب الكورس الحالي بيقبل القسمة على 4 (يعني العمود الرابع)
                    // ننزل سطر جديد عشان نبدأ صف جديد
                    if ((i + 1) % 4 == 0) {
                        cout << endl;
                    }
                }
                cout << "Enter the course number:";
                cin >> selected_index;
                int course_index = selected_index - 1;
                if (course_index >= 0 && course_index < coursescount) {
                    academic_member[stafff_logged_index].teaching_courses[course_index] = course[course_index].name;

                }
            }

            break;
        }
        case '2': {
            int course_index, course_number_choice;
            cout << "Choose which course you want to set grades in it\n";
            for (int i = 0; i < coursescount; i++) {
                // طباعة رقم الكورس واسمه
                cout << i + 1 << ": " << course[i].name << " | ";

                // لو ترتيب الكورس الحالي بيقبل القسمة على 4 (يعني العمود الرابع)
                // ننزل سطر جديد عشان نبدأ صف جديد
                if ((i + 1) % 4 == 0) {
                    cout << endl;
                }
            }
            cin >> course_number_choice;
            for (int i = 0; i < studentcount; i++) {


                course_index = course_number_choice - 1;
                cout << student[i].Student_ID << endl;
                cout << "Quiz:";
                cin >> grade[course_index].quiz;
                cout << "Final:";
                cin >> grade[course_index].final;
                cout << "year work:";
                cin >> grade[course_index].year_work;
                cout << "practical:";
                cin >> grade[course_index].practical;
                cout << "gpa alphabet:";
                cin >> grade[course_index].gpa_alphabet;
                cout << "gpa:";
                cin >> grade[course_index].gpa;
            }
            break;
        }
        }

    } while (staff_choice != '3');
}

void adminsmenu(string username, string password) {
    int Admin_index;
    char Admin_choice;
    for (int i = 0; i < adminscount; i++) {
        if (admin_member[i].name == username) {
            Admin_index = i;
            break;
        }
    }

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
                cout << "Course name: ";
                getline(cin >> ws, course[coursescount].name);
                cout << "Course grade: ";
                cin >> course[coursescount].grade;
                for (int i = 0; i < coursescount; i++) {
                    if (course[coursescount].name == course[i].name) {
                        cout << "*****Sorry this course is already existed*****";
                        break;
                    }
                }
                transform(course[coursescount].name.begin(), course[coursescount].name.end(), course[coursescount].name.begin(), ::tolower);
                courses_table[schedules_count].course_name = course[coursescount].name;
                coursescount++;
                schedules_count++;
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
                    // طباعة رقم الكورس واسمه
                    cout << i + 1 << ": " << course[i].name << " | ";

                    // لو ترتيب الكورس الحالي بيقبل القسمة على 4 (يعني العمود الرابع)
                    // ننزل سطر جديد عشان نبدأ صف جديد
                    if ((i + 1) % 4 == 0) {
                        cout << endl;
                    }
                }
                cout << "Choose the course number: ";
                cin >> course_number_choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // سطر جديد في النهاية عشان لو عدد الكورسات الكلي مش من مضاعفات الـ 4 
                // الشكل ميبوظش مع أي نصوص هتنطبع بعد الجدول
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
                int course_index;
                for (int i = 0; i < coursescount; i++) {
                    // طباعة رقم الكورس واسمه
                    cout << i + 1 << ": " << course[i].name << " | ";

                    // لو ترتيب الكورس الحالي بيقبل القسمة على 4 (يعني العمود الرابع)
                    // ننزل سطر جديد عشان نبدأ صف جديد
                    if ((i + 1) % 4 == 0) {
                        cout << endl;
                    }
                }
                cout << "Choose the course number to set the exam: ";
                cin >> course_number_choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // سطر جديد في النهاية عشان لو عدد الكورسات الكلي مش من مضاعفات الـ 4 
                // الشكل ميبوظش مع أي نصوص هتنطبع بعد الجدول
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
            char choice;
            for (int i = 0; i < coursescount; i++) {
                // طباعة رقم الكورس واسمه
                cout << i + 1 << ": " << course[i].name << " | ";

                // لو ترتيب الكورس الحالي بيقبل القسمة على 4 (يعني العمود الرابع)
                // ننزل سطر جديد عشان نبدأ صف جديد
                if ((i + 1) % 4 == 0) {
                    cout << endl;
                }
            }
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
