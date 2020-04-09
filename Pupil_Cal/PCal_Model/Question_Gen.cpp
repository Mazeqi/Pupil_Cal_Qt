#include"../PCal_Head/Question.h"
#include"../PCal_Head/Fraction.h"
#include<random>
#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <QRandomGenerator>
#define QUESTION_MAX_NUM 10001

using namespace std;
Question_Gen::Question_Gen(){
	
	Quetions_Sum	= 10;
	Questions_Total = 0;
	Cal_Max_Num		= 100;
	Cal_Min_Num		= 0;
	Questions_Str	= new string[QUESTION_MAX_NUM];
	Postfix_Ex		= new string[QUESTION_MAX_NUM];
	Results			= new Fraction[QUESTION_MAX_NUM];
	Inter_Result	= new Fraction*[QUESTION_MAX_NUM]; //先开辟行

	for (int i = 0; i < QUESTION_MAX_NUM; i++){
		Inter_Result[i] = new Fraction[1000];
	}
	Inter_Result_Total = new int[QUESTION_MAX_NUM];
}

Question_Gen::Question_Gen(int In_Max_Num){

	if (!(In_Max_Num > 0)){
		In_Max_Num = 100;
	}

	Quetions_Sum	= 10;
	Questions_Total = 0;
	Cal_Max_Num		= In_Max_Num;
	Cal_Min_Num		= 0;

	Questions_Str	= new string[QUESTION_MAX_NUM];
	Postfix_Ex		= new string[QUESTION_MAX_NUM];
	Results			= new Fraction[QUESTION_MAX_NUM];
	Inter_Result	= new Fraction*[QUESTION_MAX_NUM]; //先开辟行

	for (int i = 0; i < QUESTION_MAX_NUM; i++){
		Inter_Result[i] = new Fraction[1000];
	}
	Inter_Result_Total = new int[QUESTION_MAX_NUM];
}
int Question_Gen::Random(int Left, int Right){
/*
	//随机值播种
	std::random_device Rand;
	
	//选择生成算法
	std::default_random_engine Alogrithms(Rand());

	//选择left 到 right 范围的数,使用均匀分布
	std::uniform_int_distribution<int> Uniform_Dist(Left, Right);

	return Uniform_Dist(Alogrithms);
*/

      int  Num = QRandomGenerator::global()->bounded(Left,Right+1);
      return Num;
}
string Question_Gen::Cal_Char_Gen(int Char_Site){
	if (Char_Site == 0){
		return "+";
	}
	else if (Char_Site == 1){
		return "-";
	}
	else if (Char_Site == 2){
		return "*";
	}
	else if (Char_Site == 3){
		return "/";
	}
	else{
		return " ";
	}
}
//生成多个问题
bool Question_Gen::Question_Gen_Many_Save(int Nums){

	string Dir = "PCal_Files";
	if (_access(Dir.c_str(), 0) != 0) {
		_mkdir(Dir.c_str());
	} 

	ofstream OutFile_Ex("PCal_Files/Exercises.txt");
    ofstream OutFile_Post_Ex("PCal_Files/Postfix.txt");
    ofstream OutFile_Ans("PCal_Files/Answers.txt");

    if (!OutFile_Ex || !OutFile_Ans ||!OutFile_Post_Ex){
		cout << "Unable to open otfile";
		return false;
	}
    for (int i = 0; i < Nums; i++){
        string Ques = Question_Gen_One();
		
		if (Ques == ""){
			i--;
		}
		else{
            string Ans = Get_Index_Ans(i);
            string Post_Ex = Get_Index_Post_Ex(i);
            OutFile_Ex << i + 1 << ". " << Ques << "\n\n";
            OutFile_Post_Ex << i + 1 << ". " << Post_Ex << "\n\n";
            OutFile_Ans << i + 1 << ". " << Ans << "\n\n";

		}
	}
	OutFile_Ex.close();
    OutFile_Post_Ex.close();
    OutFile_Ans.close();
	return true;
}
string Question_Gen::Question_Gen_One(){

	string Question_i = "";
	
	//运算符的数量
	int Opera_Char_Sum = Random(1, 3);

	//运算数的数量
    //int Opera_Num_Sum = Opera_Char_Sum + 1;

	string Opera_Char;
	string Opera_Num;

	int Opera_Num_i;
	int Opera_Char_i;

	//先生成一个单运算符的式子,如果1则生成一个分数
	if (Random(0, 1) == 1){
		int Numerator = Random(Cal_Min_Num, Cal_Max_Num);
		int Denominator = Random(Cal_Min_Num, Cal_Max_Num);
		Fraction Fra(Numerator, Denominator);
		Question_i += Fra.ToString() + ' ';

	}
	else
	{
		Opera_Num_i = Random(Cal_Min_Num, Cal_Max_Num);
		Opera_Num = to_string(Opera_Num_i);
		Question_i += Opera_Num + ' ';
	}
	

	Opera_Char_i = Random(0, 3);
	Opera_Char = Cal_Char_Gen(Opera_Char_i);
	Question_i += Opera_Char + ' ';

	if (Random(0, 1) == 1){
		int Numerator = Random(Cal_Min_Num, Cal_Max_Num);
		int Denominator = Random(Cal_Min_Num, Cal_Max_Num);
		Fraction Fra(Numerator, Denominator);
		Question_i += Fra.ToString() + ' ';

	}
	else
	{
		Opera_Num_i = Random(Cal_Min_Num, Cal_Max_Num);
		Opera_Num = to_string(Opera_Num_i);
		Question_i += Opera_Num + ' ';
	}

	//运算符不只一个
	for (int i = 1; i < Opera_Char_Sum; i++){

		int R_Brackets = Random(0, 1); //是否加上括号
		if (R_Brackets){
            Question_i = "(" + Question_i + ") ";
		}

		Opera_Char_i = Random(0, 3);
		Opera_Char = Cal_Char_Gen(Opera_Char_i);
		Question_i += Opera_Char + ' ';

		//1则为分数
		if (Random(0, 1) == 1){
			int Numerator = Random(Cal_Min_Num, Cal_Max_Num);
			int Denominator = Random(Cal_Min_Num, Cal_Max_Num);
			Fraction Fra(Numerator, Denominator);
			Question_i += Fra.ToString() + ' ';

		}
		else
		{
			Opera_Num_i = Random(Cal_Min_Num, Cal_Max_Num);
			Opera_Num = to_string(Opera_Num_i);
			Question_i += Opera_Num + ' ';
		}
	}

	if (Ex_IsSame(Question_i) || Ex_IsNo()){
		return "";
    }
	Questions_Str[Questions_Total++] = Question_i;
	return Question_i;
}

bool Question_Gen::Ex_IsSame(string Ques){
	
	Question_Cal Cal;

	//得到后缀表达式
	Postfix_Ex[Questions_Total] = Cal.Postfix_Ex_Gen(Ques);

	string Post_Q_Str = Postfix_Ex[Questions_Total];
	
	//得到中间结果的个数
	int Value_Sum = Cal.Postfix_Ex_Cal(Inter_Result[Questions_Total], Post_Q_Str);
	
	//将最终结果存入Result
	Results[Questions_Total] = Inter_Result[Questions_Total][Value_Sum - 1];
	
	Inter_Result_Total[Questions_Total] = Value_Sum;

	bool IsSame = false;
	for (int i = 0; i < Questions_Total; i++){

		if (Inter_Result_Total[i] != Inter_Result_Total[Questions_Total]){
			continue;
		}

		bool Is_Fist = true;

		for (int j = Inter_Result_Total[i] - 1; j >= 0; j--) {

			//如果是最后栈顶的一个数
			if (Is_Fist) {
				Is_Fist = false;
				if (Inter_Result[i][j].Subtract(Inter_Result[Questions_Total][j]).GetNumerator() != 0) {
					break;
				}
				//如果是出栈的一对数
			}
			else {
				//有不相等的就不用往下了
				if (!((Inter_Result[i][j].Subtract(Inter_Result[Questions_Total][j]).GetNumerator() == 0 && Inter_Result[i][j - 1].Subtract(Inter_Result[Questions_Total][j - 1]).GetNumerator() == 0) ||
					(Inter_Result[i][j - 1].Subtract(Inter_Result[Questions_Total][j]).GetNumerator() == 0 && Inter_Result[i][j - 1].Subtract(Inter_Result[Questions_Total][j]).GetNumerator() == 0))) {
					break;
				}
				//因为考虑了两个成对的数，所以再-1
				j--;
				//如果一条式子可以找到最后，那么说明他们相等
				if (j == 0){
					IsSame = true;
					return IsSame;
				}
			}
			
		}
	}
	if (Questions_Total == 0){
		IsSame = false;
	}
	return IsSame;
}

bool Question_Gen::Ex_IsNo(){

	for (int i = 0; i < Inter_Result_Total[Questions_Total]; i++) {
		if (Inter_Result[Questions_Total][i].GetDenominator() == -1
			|| Inter_Result[Questions_Total][i].GetNumerator() > Cal_Max_Num
			|| Inter_Result[Questions_Total][i].GetDenominator() > Cal_Max_Num) {
			return true;
		}
	}
	return false;
}

//返回答案
string Question_Gen::Get_Index_Ans(int index){
	if (index < 0 || index >= Questions_Total || index > QUESTION_MAX_NUM){
		return "";
	}
	string Ans = Results[index].ToString();
	return Ans;
}

//返回前缀表达式
string Question_Gen::Get_Index_Ex(int index){
	if (index < 0 || index >= Questions_Total || index > QUESTION_MAX_NUM){
		return "";
	}
	string Ex = Questions_Str[index];
	return Ex;
}

//返回后缀表达式
string Question_Gen::Get_Index_Post_Ex(int index){
	if (index < 0 || index >= Questions_Total || index > QUESTION_MAX_NUM){
		return "";
	}
	string Post_Ex = Postfix_Ex[index];
	return Post_Ex;
}

//返回问题的数量
int Question_Gen::Get_Questions_Total(){
	return Questions_Total;
}

void Question_Gen::Set_Ques_Total_Zeros(){
    Questions_Total = 0;
}
