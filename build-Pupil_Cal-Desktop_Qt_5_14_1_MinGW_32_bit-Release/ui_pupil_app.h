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
    QLabel *Ques_Max_Nums_Label;
    QPushButton *Ques_NextOne_Button;
    QLineEdit *Ques_Total_Text;
    QLabel *Ques_YAns_LLabel;
    QLabel *Ques_Ans_RorN_Label;
    QPushButton *Ques_Ans_Submit_Button;
    QLineEdit *Ques_YAans_Text;
    QLabel *Ques_Scores_Label;
    QLineEdit *Ques_Cal_Max_Num_Text;
    QLabel *Ques_Set_Cal_Max_Num_Label;
    QPushButton *Ques_Cal_Max_Num_Button;
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
        Ques_Out_Browser->setGeometry(QRect(100, 150, 291, 51));
        Ques_Start_Button = new QPushButton(centralwidget);
        Ques_Start_Button->setObjectName(QString::fromUtf8("Ques_Start_Button"));
        Ques_Start_Button->setGeometry(QRect(460, 210, 112, 34));
        Ques_Max_Nums_Label = new QLabel(centralwidget);
        Ques_Max_Nums_Label->setObjectName(QString::fromUtf8("Ques_Max_Nums_Label"));
        Ques_Max_Nums_Label->setGeometry(QRect(470, 120, 181, 21));
        Ques_NextOne_Button = new QPushButton(centralwidget);
        Ques_NextOne_Button->setObjectName(QString::fromUtf8("Ques_NextOne_Button"));
        Ques_NextOne_Button->setGeometry(QRect(270, 330, 121, 31));
        Ques_Total_Text = new QLineEdit(centralwidget);
        Ques_Total_Text->setObjectName(QString::fromUtf8("Ques_Total_Text"));
        Ques_Total_Text->setGeometry(QRect(460, 150, 171, 41));
        Ques_YAns_LLabel = new QLabel(centralwidget);
        Ques_YAns_LLabel->setObjectName(QString::fromUtf8("Ques_YAns_LLabel"));
        Ques_YAns_LLabel->setGeometry(QRect(100, 230, 81, 18));
        Ques_Ans_RorN_Label = new QLabel(centralwidget);
        Ques_Ans_RorN_Label->setObjectName(QString::fromUtf8("Ques_Ans_RorN_Label"));
        Ques_Ans_RorN_Label->setGeometry(QRect(400, 270, 81, 18));
        Ques_Ans_Submit_Button = new QPushButton(centralwidget);
        Ques_Ans_Submit_Button->setObjectName(QString::fromUtf8("Ques_Ans_Submit_Button"));
        Ques_Ans_Submit_Button->setGeometry(QRect(100, 330, 112, 34));
        Ques_YAans_Text = new QLineEdit(centralwidget);
        Ques_YAans_Text->setObjectName(QString::fromUtf8("Ques_YAans_Text"));
        Ques_YAans_Text->setGeometry(QRect(100, 260, 291, 51));
        Ques_Scores_Label = new QLabel(centralwidget);
        Ques_Scores_Label->setObjectName(QString::fromUtf8("Ques_Scores_Label"));
        Ques_Scores_Label->setGeometry(QRect(100, 90, 81, 21));
        Ques_Cal_Max_Num_Text = new QLineEdit(centralwidget);
        Ques_Cal_Max_Num_Text->setObjectName(QString::fromUtf8("Ques_Cal_Max_Num_Text"));
        Ques_Cal_Max_Num_Text->setGeometry(QRect(460, 290, 171, 41));
        Ques_Set_Cal_Max_Num_Label = new QLabel(centralwidget);
        Ques_Set_Cal_Max_Num_Label->setObjectName(QString::fromUtf8("Ques_Set_Cal_Max_Num_Label"));
        Ques_Set_Cal_Max_Num_Label->setGeometry(QRect(460, 261, 301, 20));
        Ques_Cal_Max_Num_Button = new QPushButton(centralwidget);
        Ques_Cal_Max_Num_Button->setObjectName(QString::fromUtf8("Ques_Cal_Max_Num_Button"));
        Ques_Cal_Max_Num_Button->setGeometry(QRect(460, 350, 112, 34));
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
        Ques_Max_Nums_Label->setText(QCoreApplication::translate("PuPil_APP", "\350\276\223\345\205\2451-10000\357\274\232", nullptr));
        Ques_NextOne_Button->setText(QCoreApplication::translate("PuPil_APP", "\344\270\213\344\270\200\351\242\230", nullptr));
        Ques_YAns_LLabel->setText(QCoreApplication::translate("PuPil_APP", "\344\275\240\347\232\204\347\255\224\346\241\210\357\274\232", nullptr));
        Ques_Ans_RorN_Label->setText(QString());
        Ques_Ans_Submit_Button->setText(QCoreApplication::translate("PuPil_APP", "\346\217\220\344\272\244", nullptr));
        Ques_Scores_Label->setText(QCoreApplication::translate("PuPil_APP", "\345\276\227\345\210\206\357\274\232", nullptr));
        Ques_Set_Cal_Max_Num_Label->setText(QCoreApplication::translate("PuPil_APP", "\350\276\223\345\205\245\345\217\202\344\270\216\350\256\241\347\256\227\347\232\204\346\234\200\345\244\247\345\200\274(\345\244\247\344\272\216\347\255\211\344\272\21610):", nullptr));
        Ques_Cal_Max_Num_Button->setText(QCoreApplication::translate("PuPil_APP", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuPil_APP: public Ui_PuPil_APP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUPIL_APP_H
