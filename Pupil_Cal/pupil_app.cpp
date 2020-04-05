#include "pupil_app.h"
#include "ui_pupil_app.h"
#include <QMessageBox>
PuPil_APP::PuPil_APP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PuPil_APP)
{
    ui->setupUi(this);
    ui->Ques_NextOne_Button->setDisabled(true);
}

PuPil_APP::~PuPil_APP()
{
    delete ui;
}


void PuPil_APP::on_Ques_Start_Button_clicked()
{
       ui->Ques_Start_Button->setDisabled(true);
       ui->Ques_NextOne_Button->setEnabled(true);
       //获取题目数量
       int Total = ui->Ques_Total_Text->text().toInt();
       //题目数量限制
       if(Total < 1 || Total > 10000){
              QMessageBox::information(this, "数量错误","请输入1- 10000的数量",QMessageBox::Yes);
              ui->Ques_Start_Button->setEnabled(true);
              return;
       }
     //
       Ques_G = new Question_Gen();
       bool x = Ques_G->Question_Gen_Many_Save(Total);
       //if(x == true) QMessageBox::information(this, "数量:",QString::fromStdString((to_string(Total))),QMessageBox::Yes);

       Ques_Total = Total;
       Ques_Index = 0;
       Current_Socre   = 0;
      // QMessageBox::information(this, "数量:",QString::fromStdString((to_string(Total))),QMessageBox::Yes);
       ui->Ques_Index_Label->setText("题目：" + QString::number(Ques_Index + 1) + "/" + QString::number(Ques_Total));
       ui->Ques_Out_Browser->setText(QString::fromStdString(Ques_G->Get_Index_Ex(Ques_Index)));

}

void PuPil_APP::on_Ques_NextOne_Button_clicked()
{
    Ques_Index++;
    ui->Ques_Index_Label->setText("题目：" + QString::number(Ques_Index + 1) + "/" + QString::number(Ques_Total));
    ui->Ques_Out_Browser->setText(QString::fromStdString(Ques_G->Get_Index_Ex(Ques_Index)));

}
