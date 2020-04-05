#include"../PCal_Head/Fraction.h"
#include"../PCal_Head/Question.h"
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

Fraction::Fraction() {

}

//重载构造函数，需要传入分子和分母，分母不能为0
Fraction::Fraction(int Numerator, int Denominator){
	////如果分数分子分母太大或为负，直接返回-1
	if (Denominator > 10000 || Numerator > 10000 || Denominator <= 0 || Numerator < 0) {
		Fra_Denominator = -1;
		Fra_Numerator = 1;
		Fra_Isinteger = true;
		return;
	}
	Fra_Numerator = Numerator;
	Fra_Denominator = Denominator;
	if (Denominator == 1 || Numerator == 0) {
		Fra_Isinteger = true;
	}
	else {
		Fra_Isinteger = false;
	}
	this->Simplify();
}

void Fraction::Set(int Numerator, int Denominator){
	//如果分数分子分母太大或为负，直接返回-1
	if (Denominator > 10000 || Numerator > 10000 || Denominator <= 0 || Numerator < 0) {
		Fra_Denominator = -1;
		Fra_Numerator = 1;
		Fra_Isinteger = true;
		return;
	}

	Fra_Numerator = Numerator;
	Fra_Denominator = Denominator;

	if (Denominator == 1 || Numerator == 0) {
		Fra_Isinteger = true;
	}
	else {
		Fra_Isinteger = false;
	}
	this->Simplify();
}

Fraction Fraction::Simplify(){
	////如果分数分子分母太大或为负，直接返回-1
	if (Fra_Denominator > 10000 || Fra_Numerator > 10000 || Fra_Denominator <= 0 || Fra_Numerator < 0) {
		return Fraction(1, -1);
	}
	//如果分母是1，或者分子是0
	if (Fra_Denominator == 1 || Fra_Numerator == 0) {
		//分子是0，将分母改为1，整数标识改1
		if (Fra_Numerator == 0) {
			Fra_Denominator = 1;
			Fra_Isinteger = true;
			return *this;
		}
		//不是0，分母是1，则整数标志改1
		Fra_Isinteger = true;
		return *this;
	}

	int OrginA = Fra_Numerator;
	int OrginB = Fra_Denominator;
	int Temp;

	while (OrginB != 0){
		Temp = OrginA % OrginB;
		OrginA = OrginB;
		OrginB = Temp;
	}
	Fra_Numerator	/= OrginA;
	Fra_Denominator /= OrginA;

	//分母为1，则整数标志设1，直接返回
	if (Fra_Denominator == 1) {
		Fra_Isinteger = true;
		return *this;
	}

	Fra_Isinteger = false;
	return *this;
}


//返回字符串形式
string Fraction::ToString() {
	string Fra_String = "";
	//如果是整数
	if (Fra_Isinteger) {
		Fra_String += to_string(Fra_Numerator);
		return Fra_String;
	}
	else {
		Fra_String += to_string(Fra_Numerator);
		Fra_String += "/";
		Fra_String += to_string(Fra_Denominator);
		return Fra_String;
	}
	return "";
}


//加
Fraction Fraction::Add(Fraction fraction) {
	int Numerator = fraction.GetDenominator() * Fra_Numerator + fraction.GetNumerator() * Fra_Denominator;
	int Dnominator = fraction.GetDenominator() * Fra_Denominator;
	Fraction Result(Numerator, Dnominator);
	return Result.Simplify();
}

//减
Fraction Fraction::Subtract(Fraction fraction) {
	int Numerator = fraction.GetDenominator() * Fra_Numerator - fraction.GetNumerator() * Fra_Denominator;
	int Dnominator = fraction.GetDenominator() * Fra_Denominator;
	Fraction Result(Numerator, Dnominator);
	return Result.Simplify();
}

// 乘
Fraction Fraction::Multiply(Fraction fraction) {
	int Numerator = Fra_Numerator * fraction.GetNumerator();
	int Dnominator = fraction.GetDenominator() * Fra_Denominator;
	Fraction Result(Numerator, Dnominator);
	return Result.Simplify();
}

//倒数
Fraction Fraction::Reciprocal(){
	Fraction Result(Fra_Denominator, Fra_Numerator);
	return Result;
}

//除
Fraction Fraction::DividedBy(Fraction fraction){
	return this->Multiply(fraction.Reciprocal());
}

//得到分子变量值
int Fraction::GetNumerator(){
	return Fra_Numerator;
}

//得到分母变量值
int Fraction::GetDenominator(){
	return Fra_Denominator;
}

//得到是否为整数标志
bool Fraction::GetIsinteger(){
	return Fra_Isinteger;
}