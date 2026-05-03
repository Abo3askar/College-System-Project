#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
using namespace std;
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
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    int loggedInIndex = -1;

private slots:
    void on_loginBtn_clicked();

    void on_btn_back_clicked();

    void on_signupBtn_clicked();

    void on_btn_doSignup_clicked();

    void on_btn_logout_clicked();

    void on_btn_viewGrades_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
