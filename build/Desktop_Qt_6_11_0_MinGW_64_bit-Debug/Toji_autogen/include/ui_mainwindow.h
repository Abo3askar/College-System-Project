/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page_login;
    QGridLayout *gridLayout;
    QLabel *header;
    QComboBox *userTypeCombo;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginBtn;
    QPushButton *resetpasswordbutton;
    QLabel *donthave;
    QPushButton *signupBtn;
    QWidget *signup_page;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *reg_typeCombo;
    QLineEdit *reg_nameInput;
    QLineEdit *reg_passInput;
    QLineEdit *reg_mobileInput;
    QLineEdit *reg_deptInput;
    QLineEdit *reg_yearInput;
    QLineEdit *reg_posInput;
    QPushButton *btn_doSignup;
    QPushButton *btn_back;
    QWidget *student_page;
    QLabel *name_lbl;
    QLabel *id_lbl;
    QLabel *dpt_lbl;
    QLabel *ay_lbl;
    QPushButton *btn_logout;
    QPushButton *btn_bookApp;
    QPushButton *btn_regCourses;
    QPushButton *btn_viewGrades;
    QLabel *name_val_lbl;
    QLabel *id_val_lbl;
    QLabel *dept_val_lbl;
    QLabel *year_val_lbl;
    QListWidget *listWidget;
    QWidget *staff_page;
    QLabel *label_2;
    QComboBox *combo_doctors;
    QDateTimeEdit *dateEdit_app;
    QPushButton *btn_confirm_app;
    QPushButton *btn_back_to_profile;
    QWidget *admin_page;
    QTableWidget *tableWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_login = new QWidget();
        page_login->setObjectName("page_login");
        gridLayout = new QGridLayout(page_login);
        gridLayout->setObjectName("gridLayout");
        header = new QLabel(page_login);
        header->setObjectName("header");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font.setPointSize(28);
        font.setBold(false);
        font.setItalic(false);
        font.setStrikeOut(false);
        header->setFont(font);
        header->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(header, 0, 0, 1, 1);

        userTypeCombo = new QComboBox(page_login);
        userTypeCombo->addItem(QString());
        userTypeCombo->addItem(QString());
        userTypeCombo->addItem(QString());
        userTypeCombo->setObjectName("userTypeCombo");
        userTypeCombo->setMinimumSize(QSize(300, 0));
        userTypeCombo->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        userTypeCombo->setFont(font1);

        gridLayout->addWidget(userTypeCombo, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        usernameInput = new QLineEdit(page_login);
        usernameInput->setObjectName("usernameInput");
        usernameInput->setMinimumSize(QSize(300, 0));
        usernameInput->setMaximumSize(QSize(300, 16777215));
        usernameInput->setPlaceholderText(QString::fromUtf8("username"));

        gridLayout->addWidget(usernameInput, 2, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        passwordInput = new QLineEdit(page_login);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setMinimumSize(QSize(300, 0));
        passwordInput->setMaximumSize(QSize(300, 16777215));
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(passwordInput, 3, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        loginBtn = new QPushButton(page_login);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setMinimumSize(QSize(300, 0));
        loginBtn->setMaximumSize(QSize(300, 16777215));
        loginBtn->setStyleSheet(QString::fromUtf8("background-color: #2ecc71; \n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-weight: bold;"));

        gridLayout->addWidget(loginBtn, 4, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        resetpasswordbutton = new QPushButton(page_login);
        resetpasswordbutton->setObjectName("resetpasswordbutton");
        resetpasswordbutton->setMinimumSize(QSize(300, 0));
        resetpasswordbutton->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(resetpasswordbutton, 5, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        donthave = new QLabel(page_login);
        donthave->setObjectName("donthave");
        donthave->setMaximumSize(QSize(300, 16777215));
        donthave->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(donthave, 6, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        signupBtn = new QPushButton(page_login);
        signupBtn->setObjectName("signupBtn");
        signupBtn->setMinimumSize(QSize(300, 0));
        signupBtn->setMaximumSize(QSize(300, 16777215));
        signupBtn->setStyleSheet(QString::fromUtf8("background-color: #2ecc71; \n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 5px;\n"
"font-weight: bold;"));

        gridLayout->addWidget(signupBtn, 7, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        stackedWidget->addWidget(page_login);
        signup_page = new QWidget();
        signup_page->setObjectName("signup_page");
        verticalLayout = new QVBoxLayout(signup_page);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(signup_page);
        label->setObjectName("label");
        label->setMaximumSize(QSize(500, 200));
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setItalic(true);
        label->setFont(font2);
        label->setMouseTracking(false);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        reg_typeCombo = new QComboBox(signup_page);
        reg_typeCombo->addItem(QString());
        reg_typeCombo->addItem(QString());
        reg_typeCombo->addItem(QString());
        reg_typeCombo->setObjectName("reg_typeCombo");

        verticalLayout->addWidget(reg_typeCombo);

        reg_nameInput = new QLineEdit(signup_page);
        reg_nameInput->setObjectName("reg_nameInput");

        verticalLayout->addWidget(reg_nameInput);

        reg_passInput = new QLineEdit(signup_page);
        reg_passInput->setObjectName("reg_passInput");
        reg_passInput->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(reg_passInput);

        reg_mobileInput = new QLineEdit(signup_page);
        reg_mobileInput->setObjectName("reg_mobileInput");

        verticalLayout->addWidget(reg_mobileInput);

        reg_deptInput = new QLineEdit(signup_page);
        reg_deptInput->setObjectName("reg_deptInput");

        verticalLayout->addWidget(reg_deptInput);

        reg_yearInput = new QLineEdit(signup_page);
        reg_yearInput->setObjectName("reg_yearInput");

        verticalLayout->addWidget(reg_yearInput);

        reg_posInput = new QLineEdit(signup_page);
        reg_posInput->setObjectName("reg_posInput");

        verticalLayout->addWidget(reg_posInput);

        btn_doSignup = new QPushButton(signup_page);
        btn_doSignup->setObjectName("btn_doSignup");

        verticalLayout->addWidget(btn_doSignup);

        btn_back = new QPushButton(signup_page);
        btn_back->setObjectName("btn_back");

        verticalLayout->addWidget(btn_back);

        stackedWidget->addWidget(signup_page);
        student_page = new QWidget();
        student_page->setObjectName("student_page");
        name_lbl = new QLabel(student_page);
        name_lbl->setObjectName("name_lbl");
        name_lbl->setGeometry(QRect(90, 100, 71, 31));
        id_lbl = new QLabel(student_page);
        id_lbl->setObjectName("id_lbl");
        id_lbl->setGeometry(QRect(90, 140, 71, 21));
        dpt_lbl = new QLabel(student_page);
        dpt_lbl->setObjectName("dpt_lbl");
        dpt_lbl->setGeometry(QRect(90, 180, 81, 21));
        ay_lbl = new QLabel(student_page);
        ay_lbl->setObjectName("ay_lbl");
        ay_lbl->setGeometry(QRect(90, 210, 111, 21));
        btn_logout = new QPushButton(student_page);
        btn_logout->setObjectName("btn_logout");
        btn_logout->setGeometry(QRect(380, 410, 121, 41));
        btn_bookApp = new QPushButton(student_page);
        btn_bookApp->setObjectName("btn_bookApp");
        btn_bookApp->setGeometry(QRect(540, 410, 121, 41));
        btn_regCourses = new QPushButton(student_page);
        btn_regCourses->setObjectName("btn_regCourses");
        btn_regCourses->setGeometry(QRect(220, 410, 121, 41));
        btn_viewGrades = new QPushButton(student_page);
        btn_viewGrades->setObjectName("btn_viewGrades");
        btn_viewGrades->setGeometry(QRect(70, 410, 121, 41));
        name_val_lbl = new QLabel(student_page);
        name_val_lbl->setObjectName("name_val_lbl");
        name_val_lbl->setGeometry(QRect(160, 110, 49, 16));
        id_val_lbl = new QLabel(student_page);
        id_val_lbl->setObjectName("id_val_lbl");
        id_val_lbl->setGeometry(QRect(160, 140, 49, 16));
        dept_val_lbl = new QLabel(student_page);
        dept_val_lbl->setObjectName("dept_val_lbl");
        dept_val_lbl->setGeometry(QRect(170, 180, 49, 16));
        year_val_lbl = new QLabel(student_page);
        year_val_lbl->setObjectName("year_val_lbl");
        year_val_lbl->setGeometry(QRect(180, 220, 49, 16));
        listWidget = new QListWidget(student_page);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(-20, 500, 811, 91));
        stackedWidget->addWidget(student_page);
        staff_page = new QWidget();
        staff_page->setObjectName("staff_page");
        label_2 = new QLabel(staff_page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 60, 301, 61));
        combo_doctors = new QComboBox(staff_page);
        combo_doctors->setObjectName("combo_doctors");
        combo_doctors->setGeometry(QRect(300, 80, 65, 24));
        dateEdit_app = new QDateTimeEdit(staff_page);
        dateEdit_app->setObjectName("dateEdit_app");
        dateEdit_app->setGeometry(QRect(400, 80, 194, 25));
        btn_confirm_app = new QPushButton(staff_page);
        btn_confirm_app->setObjectName("btn_confirm_app");
        btn_confirm_app->setGeometry(QRect(170, 440, 131, 41));
        btn_back_to_profile = new QPushButton(staff_page);
        btn_back_to_profile->setObjectName("btn_back_to_profile");
        btn_back_to_profile->setGeometry(QRect(360, 440, 131, 41));
        stackedWidget->addWidget(staff_page);
        admin_page = new QWidget();
        admin_page->setObjectName("admin_page");
        tableWidget = new QTableWidget(admin_page);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 20, 751, 551));
        stackedWidget->addWidget(admin_page);
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);

        verticalLayout_4->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        header->setText(QCoreApplication::translate("MainWindow", "College Management System", nullptr));
        userTypeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Student", nullptr));
        userTypeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Staf Member", nullptr));
        userTypeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Admin", nullptr));

        passwordInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "password", nullptr));
        loginBtn->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        resetpasswordbutton->setText(QCoreApplication::translate("MainWindow", "forgot your password?", nullptr));
        donthave->setText(QCoreApplication::translate("MainWindow", "dont have account?", nullptr));
        signupBtn->setText(QCoreApplication::translate("MainWindow", "signup", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Create New Account", nullptr));
        reg_typeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Student", nullptr));
        reg_typeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Staff", nullptr));
        reg_typeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Admin", nullptr));

        reg_nameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        reg_passInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Paswword", nullptr));
        reg_mobileInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Mobile_Number", nullptr));
        reg_deptInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Department", nullptr));
        reg_yearInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        reg_posInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        btn_doSignup->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        btn_back->setText(QCoreApplication::translate("MainWindow", "Back to Login", nullptr));
        name_lbl->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        id_lbl->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        dpt_lbl->setText(QCoreApplication::translate("MainWindow", "Department", nullptr));
        ay_lbl->setText(QCoreApplication::translate("MainWindow", "Academic Year", nullptr));
        btn_logout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        btn_bookApp->setText(QCoreApplication::translate("MainWindow", "Book Appointment", nullptr));
        btn_regCourses->setText(QCoreApplication::translate("MainWindow", "Register Courses", nullptr));
        btn_viewGrades->setText(QCoreApplication::translate("MainWindow", "View Grades", nullptr));
        name_val_lbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        id_val_lbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        dept_val_lbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        year_val_lbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Book an Appointment with a Doctor:", nullptr));
        btn_confirm_app->setText(QCoreApplication::translate("MainWindow", "Confiirm Booking", nullptr));
        btn_back_to_profile->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Course Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "GPA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
