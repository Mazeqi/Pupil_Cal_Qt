#pragma once
#ifndef __QUESTION_HEAD__
#define __QUESTION_HEAD__
#include<string>
#include"../PCal_Head/Fraction.h"
using namespace std;

//此类用于生成随机问题
class Question_Gen{

private:

	//需要生成的问题的数量
	int Quetions_Sum;		

	//参与计算的最大值
	int Cal_Max_Num;	

	//参与计算的最小值
	int Cal_Min_Num;		

	//动态变化的值，统计已生成的问题数量
	int Questions_Total;

	//中间结果的个数
	int *Inter_Result_Total;

	//问题栈
	string *Questions_Str;

	//后缀表达式，数和运算符间有空格
	string *Postfix_Ex;
				
	//结果，用分数表示
	Fraction *Results;						

	//保存中间结果，即为每个问题后缀表达式计算过程中出栈的数
	Fraction **Inter_Result;

public:

	//友元
	friend class Question_Cal;

	//构造函数
	Question_Gen();

	//参与计算的最大值
	Question_Gen(int In_Max_Num);	

	//生成一个问题
	string Question_Gen_One();		

	//生成多个问题,并保存
	bool Question_Gen_Many_Save(int Nums);


	//随机生成一个在left到right的数
	int Random(int Left, int Right);	

	//返回+-*/符号
	string Cal_Char_Gen(int Char_Site);

	//辨别式子是否重复出现
	bool Ex_IsSame(string Ques);

	//判断式子的结果，或者中间计算过程的数字是否超过Cal_Max_Num
	bool Ex_IsNo();

	//返回第index个问题的答案
	string Get_Index_Ans(int index);

	//返回第index个问题
	string Get_Index_Ex(int index);

	//返回第index个问题的后缀表达式
	string Get_Index_Post_Ex(int index);

	int Get_Questions_Total();

    //将数量设成0
    void Set_Ques_Total_Zeros();
};


//此类用于计算问题
class Question_Cal{

public:
	Question_Cal();

	//友元
	//friend class Question_Gen;				

	//中缀转后缀
	string	Postfix_Ex_Gen(string Ques);		

	//将后缀表达式进行计算，返回值的个数, Value_S是一个一维数组，返回中间值的个数，并且将中间值写入到一维数组中去，Ques是后缀表达式
	int Postfix_Ex_Cal(Fraction  *Value_S, string Ques);		

	//两个数之间的计算
    Fraction Fra_Cal(Fraction a, Fraction b, char x);
};

#endif 
