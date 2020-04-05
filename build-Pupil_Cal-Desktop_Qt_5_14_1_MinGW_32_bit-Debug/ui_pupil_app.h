/********************************************************************************
** Form generated from reading UI file 'pupil_app.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUPIL_APP_H
#define UI_PUPIL_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuPil_APP
{
public:
    QWidget *centralwidget;
    QLabel *Ques_Index_Label;
    QTextBrowser *Ques_Out_Browser;
    QPushButton *Ques_Start_Button;
    QLabel *label;
    QPushButton *Ques_NextOne_Button;
    QLineEdit *Ques_Total_Text;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PuPil_APP)
    {
        if (PuPil_APP->objectName().isEmpty())
            PuPil_APP->setObjectName(QString::fromUtf8("PuPil_APP"));
        PuPil_APP->resize(800, 600);
        centralwidget = new QWidget(PuPil_APP);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Ques_Index_Label = new QLabel(centralwidget);
        Ques_Index_Label->setObjectName(QString::fromUtf8("Ques_Index_Label"));
        Ques_Index_Label->setGeometry(QRect(100, 110, 201, 41));
        Ques_Out_Browser = new QTextBrowser(centralwidget);
        Ques_Out_Browser->setObjectName(QString::fromUtf8("Ques_Out_Browser"));
        Ques_Out_Browser->setGeometry(QRect(100, 150, 291, 61));
        Ques_Start_Button = new QPushButton(centralwidget);
        Ques_Start_Button->setObjectName(QString::fromUtf8("Ques_Start_Button"));
        Ques_Start_Button->setGeometry(QRect(520, 270, 112, 34));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(500, 110, 181, 31));
        Ques_NextOne_Button = new QPushButton(centralwidget);
        Ques_NextOne_Button->setObjectName(QString::fromUtf8("Ques_NextOne_Button"));
        Ques_NextOne_Button->setGeometry(QRect(100, 270, 112, 34));
        Ques_Total_Text = new QLineEdit(centralwidget);
        Ques_Total_Text->setObjectName(QString::fromUtf8("Ques_Total_Text"));
        Ques_Total_Text->setGeometry(QRect(500, 150, 171, 51));
        PuPil_APP->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PuPil_APP);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        PuPil_APP->setMenuBar(menubar);
        statusbar = new QStatusBar(PuPil_APP);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PuPil_APP->setStatusBar(statusbar);

        retranslateUi(PuPil_APP);

        QMetaObject::connectSlotsByName(PuPil_APP);
    } // setupUi

    void retranslateUi(QMainWindow *PuPil_APP)
    {
        PuPil_APP->setWindowTitle(QCoreApplication::translate("PuPil_APP", "PuPil_APP", nullptr));
        Ques_Index_Label->setText(QCoreApplication::translate("PuPil_APP", "\351\242\230\347\233\256\357\274\232", nullptr));
        Ques_Start_Button->setText(QCoreApplication::translate("PuPil_APP", "\345\274\200\345\247\213", nullptr));
        label->setText(QCoreApplication::translate("PuPil_APP", "\350\276\223\345\205\2451-10000\357\274\232", nullptr));
        Ques_NextOne_Button->setText(QCoreApplication::translate("PuPil_APP", "\344\270\213\344\270\200\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuPil_APP: public Ui_PuPil_APP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUPIL_APP_H
