#pragma once
#ifndef PUPIL_APP_H
#define PUPIL_APP_H

#include <QMainWindow>
#include <vector>
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
    void Ques_Start();

    void Ques_NextOne();

    void Ques_Ans_Checked();

    void Ques_Cal_Max_Num_Set();

private:

    Ui::PuPil_APP *ui;

    Question_Gen Ques_G;

    int Ques_Total;

    int Ques_Index;

    int Current_Socre;

    vector<int> Ques_Err;

    vector<int> Ques_Rig;

    vector<int> Ques_NoAns;

    bool Save_History();

    bool Is_Save;

    bool Is_Sumbit;
};
#endif // PUPIL_APP_H
