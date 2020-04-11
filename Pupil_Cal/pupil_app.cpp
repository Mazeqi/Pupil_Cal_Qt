#include "pupil_app.h"
#include "ui_pupil_app.h"
#include <QMessageBox>
#include<fstream>
PuPil_APP::PuPil_APP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PuPil_APP)
{
    ui->setupUi(this);

    ui->Ques_NextOne_Button->setDisabled(true);

    ui->Ques_Ans_Submit_Button->setDisabled(true);

    ui->Ques_Cal_Max_Num_Button->setDisabled(true);

    //开始按钮
    connect(ui->Ques_Start_Button,SIGNAL(clicked()),this,SLOT(Ques_Start()));

    //下一题按钮
    connect(ui->Ques_NextOne_Button,SIGNAL(clicked()),this,SLOT(Ques_NextOne()));

    //提交按钮
    connect(ui->Ques_Ans_Submit_Button,SIGNAL(clicked()),this,SLOT(Ques_Ans_Checked()));

    //设置参与计算最大数值按钮
    connect(ui->Ques_Cal_Max_Num_Button,SIGNAL(clicked()),this,SLOT(Ques_Cal_Max_Num_Set()));

    Is_Sumbit = false;


}

PuPil_APP::~PuPil_APP()
{
    delete ui;
}


void PuPil_APP::Ques_Start()
{

       //获取题目数量
       int Total = ui->Ques_Total_Text->text().toInt();

       //题目数量限制
       if(Total < 1 || Total > 10000){
              QMessageBox::information(this, "数量错误","请输入1- 10000的数量",QMessageBox::Yes);
              ui->Ques_Start_Button->setEnabled(true);
              return;
       }

       //将设置题目数量的按钮设成可按
       ui->Ques_Cal_Max_Num_Button->setEnabled(true);

       //第一次点击之后将开始按钮设成不可按下
       ui->Ques_Start_Button->setDisabled(true);

       //去掉上次的题目
       Ques_G.Set_Ques_Total_Zeros();

       //设置题目的数量
       Ques_G.Set_Ques_Num(Total);

       //保存目前的数量
       Ques_Total = Total;

       //第几个题
       Ques_Index = 0;

       Current_Socre   = 0;


}
void PuPil_APP::Ques_Cal_Max_Num_Set(){

    //获取题目数量
    int Num = ui->Ques_Cal_Max_Num_Text->text().toInt();

    //题目数量限制
    if(Num < 10){
           QMessageBox::information(this, "数量错误","请输入大于等于10的数",QMessageBox::Yes);
           return;
    }

    Ques_G.Set_Cal_Max_Num(Num);

    //将设置最大值按钮设成不可按
    ui->Ques_Cal_Max_Num_Button->setDisabled(true);

    //将下一题按钮设成可按
    ui->Ques_NextOne_Button->setEnabled(true);

    //设置提交按钮为可按
    ui->Ques_Ans_Submit_Button->setEnabled(true);

    //保存这次的题目
    Ques_G.Question_Gen_Many_Save(Ques_G.Get_Ques_Num());


    //设置题目位置
    ui->Ques_Index_Label->setText("题目：" + QString::number(Ques_Index + 1) + "/" + QString::number(Ques_Total));

    //输出题目
    ui->Ques_Out_Browser->setText(QString::fromStdString(Ques_G.Get_Index_Ex(Ques_Index)));


}
void PuPil_APP::Ques_NextOne()
{
    //设置上一次的回答正确与否标志为空
    ui->Ques_Ans_RorN_Label->setText("");

    //设置回答问题的Text为空
    ui->Ques_YAans_Text->setText("");

    //设置提交按钮可按下
    ui->Ques_Ans_Submit_Button->setEnabled(true);

    //结束
    if(Is_Sumbit == false){
        Ques_NoAns.push_back(Ques_Index + 1);
    }
    else{
        Is_Sumbit = false;
    }
    //当问题到末尾，需要设置提交、下一题为不可按，开始按钮为可按
    if(Ques_Index == Ques_Total - 1 ){

        ui->Ques_NextOne_Button->setDisabled(true);

        ui->Ques_Ans_Submit_Button->setDisabled(true);

        ui->Ques_Start_Button->setEnabled(true);

        Save_History();
    }else{

        Ques_Index++;

        ui->Ques_Index_Label->setText("题目：" + QString::number(Ques_Index + 1) + "/" + QString::number(Ques_Total));

        ui->Ques_Out_Browser->setText(QString::fromStdString(Ques_G.Get_Index_Ex(Ques_Index)));

        ui->Ques_Scores_Label->setText("得分：" + QString::number(Current_Socre));

    }


}

//检查答案，按下提交按钮时的反应
void PuPil_APP::Ques_Ans_Checked(){
    string Y_Ans = ui->Ques_YAans_Text->text().toStdString();

    string R_Ans = Ques_G.Get_Index_Ans(Ques_Index);

    ui->Ques_Ans_Submit_Button->setDisabled(true);

    if(Y_Ans != R_Ans){

         ui->Ques_Ans_RorN_Label->setText("X");

         ui->Ques_YAans_Text->setText("");

         Ques_Err.push_back(Ques_Index + 1);


    }else{

        Current_Socre++;

        ui->Ques_Ans_RorN_Label->setText("√");

        ui->Ques_Scores_Label->setText("得分：" + QString::number(Current_Socre));

        Ques_Rig.push_back(Ques_Index + 1);

    }
    Is_Sumbit = true;
}

bool PuPil_APP::Save_History(){

    ofstream OutFile_Score("PCal_Files/Grade.txt",ios::app);
    if (!OutFile_Score){

        return false;
    }
    string Line  = "-----------------------------------------\n\n";

    string Right = "";
    string Wrong = "";
    string NoAns = "";

    if(Ques_Rig.size() > 0){

         Right = "Correct:" + to_string(Ques_Rig.size()) + "(";

        for (int i = 0; i < Ques_Rig.size(); i++){
                Right += to_string(Ques_Rig[i]) + " ";
        }

        Right += ")\n";

    }

    if(Ques_Err.size() > 0){

         Wrong = "Wrong:" + to_string(Ques_Err.size()) + "(";

        for (int i = 0; i < Ques_Err.size(); i++){
                Wrong += to_string(Ques_Err[i]) + " ";
        }

        Wrong += ")\n";

    }

    if(Ques_NoAns.size() > 0){

         NoAns = "NO_Ansowers:" + to_string(Ques_NoAns.size()) + "(";

        for (int i = 0; i < Ques_NoAns.size(); i++){
                NoAns += to_string(Ques_NoAns[i]) + " ";
        }

        NoAns += ")\n";
    }

    OutFile_Score << Line;

    if(NoAns != ""){
        OutFile_Score << NoAns;
    }

    if(Right != ""){
        OutFile_Score << Right;
    }

    if(Wrong != ""){
        OutFile_Score << Wrong;
    }
    OutFile_Score.close();
}
