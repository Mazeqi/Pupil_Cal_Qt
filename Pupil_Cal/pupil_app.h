#pragma once
#ifndef PUPIL_APP_H
#define PUPIL_APP_H

#include <QMainWindow>
#include "./PCal_Head/Question.h"
QT_BEGIN_NAMESPACE
namespace Ui { class PuPil_APP; }
QT_END_NAMESPACE

class PuPil_APP : public QMainWindow
{
    Q_OBJECT

public:
    PuPil_APP(QWidget *parent = nullptr);
    ~PuPil_APP();

private slots:
    void on_Ques_Start_Button_clicked();

    void on_Ques_NextOne_Button_clicked();

private:
    Ui::PuPil_APP *ui;
    Question_Gen *Ques_G;
    int Ques_Total;
    int Ques_Index;
    int Current_Socre;
};
#endif // PUPIL_APP_H
