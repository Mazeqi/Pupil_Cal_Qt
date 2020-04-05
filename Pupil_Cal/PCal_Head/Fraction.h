#pragma once
#ifndef __FRACTION_HEAD__
#define __FRACTION_HEAD__
#include <string>
#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction();

	//重载构造函数，需要传入分子和分母，分母不能为0
	Fraction(int Numerator, int Denominator);

	//设置分子分母，同构造函数
	void Set(int Numerator, int Denominator);

	//化简，返回Fraction类，更改原对象
	Fraction Simplify();

	//加另一个分数，不更改原对象，返回一个新对象
	Fraction Add(Fraction fraction);

	//减另一个分数，不更改原对象，返回一个新对象
	Fraction Subtract(Fraction fraction);

	//乘另一个分数，不更改原对象，返回一个新对象
	Fraction Multiply(Fraction fraction);

	//除以另一个分数，不更改原对象，返回一个新对象
	Fraction DividedBy(Fraction fraction);

	//倒数，不更改原对象，返回一个新对象
	Fraction Reciprocal();

	//转化为string字符串，整数为十进制整数，分数为a/b，不带空格
	string ToString();

	//得到分子变量值
	int GetNumerator();

	//得到分母变量值
	int GetDenominator();

	//得到是否为整数标志
	bool GetIsinteger();


private:
	//分子
	int Fra_Numerator;

	//分母
	int Fra_Denominator;

	//判断是否约分到整数
	bool Fra_Isinteger;

};
#endif