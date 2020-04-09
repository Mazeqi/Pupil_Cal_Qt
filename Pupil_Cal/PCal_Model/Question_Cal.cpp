#include<string>
#include"../PCal_Head/Question.h"
#include<stack>
#include"../PCal_Head/Fraction.h"

Question_Cal::Question_Cal(){

}
Fraction Question_Cal::Fra_Cal(Fraction a, Fraction b, char x)
{
	if (x == '+'){
		return a.Add(b);
	}
	else if (x == '-'){
		return a.Subtract(b);
	}
	else if (x == '*'){
		return a.Multiply(b);
	}
	else if (x == '/'){
		return a.DividedBy(b);
	}
	Fraction error(1000, 1000);
	return error;
}

int Question_Cal::Postfix_Ex_Cal(Fraction *Value_S, string Ques){
	int Total = 0; //计算值的个数
	stack <Fraction> Postfix_S;

	int i = 0;
	bool IsRNumertor = false;//当出现1'1/2之类的数
	int RNumer = 0;
	while (Ques[i] != '\0'){
		if (Ques[i] == ' '){
			i++;
			continue;
		}
		//cout << Ques.length() <<endl;
		// 遇到数则push到栈中
		if (Ques[i] >= '0' && Ques[i] <= '9'){
			Fraction fra;
			int Numerator;
			int Denominator;
			Numerator = atoi(&Ques[i]);
			
			

			while (Ques[i] >= '0' && Ques[i] <= '9') i++;
			
			if (Ques[i] == '\''){
				i += 1;
				IsRNumertor = true;
				RNumer = Numerator;
				continue;
			}
			
			if (Ques[i] == '/'){
				i += 1;
				Denominator = atoi(&Ques[i]);
				while (Ques[i] >= '0' && Ques[i] <= '9') i++;
				
				if (IsRNumertor == true){
					Numerator += RNumer * Denominator;
					IsRNumertor = false;
				}
				
				Fraction f(Numerator, Denominator);
				fra = f;
			}
			else {
				Fraction f(Numerator, 1);
				fra = f;
			}
			Postfix_S.push(fra);
		}
		else {
			//遇到符号则弹出两个数出来运算
			Fraction Num1, Num2;

			Num2 = Postfix_S.top();
			Postfix_S.pop();
			Value_S[Total++] = Num2;

			Num1 = Postfix_S.top();
			Postfix_S.pop();
			Value_S[Total++] = Num1;

			Fraction Result = Fra_Cal(Num1, Num2, Ques[i]);
			Postfix_S.push(Result);
			i++;
		}
		
	}
	Fraction value = Postfix_S.top();
	Postfix_S.pop();
	Value_S[Total++] = value;

	return Total;
}

//中缀转后缀
string	Question_Cal::Postfix_Ex_Gen(string Ques){

	string PostQ = "";
	stack <char> Char_S;
	int i = 0;
	while (i <= Ques.length() - 1){
		//值为数字时
		if (Ques[i] >= '0' && Ques[i] <= '9'){
			while (Ques[i] >= '0' && Ques[i] <= '9'){
				PostQ += Ques[i];
				i++;
			}

			//遇到空格要加上空格
			if (Ques[i] == ' ' || Ques[i] == '\0' || Ques[i] == ')')
			{
				PostQ += ' ';
				if (Ques[i] == '\0')
					break;
			}
            if(Ques[i] == '\''){
                PostQ += '\'';
                i++;
            }
			if (Ques[i] == '/'){
				PostQ += '/';
				i++;
			}
			continue;
		}
		//遇到左括号想都不用想直接push
		else if (Ques[i] == '('){
			Char_S.push(Ques[i]);
		}
		else if (Ques[i] == ')'){
			while (Char_S.top() != '('){
				PostQ += Char_S.top();
				Char_S.pop();
			}
			PostQ += ' ';
			Char_S.pop();//把（输出。
		}
		else if (Ques[i] == '-' || Ques[i] == '+'){
			if (Char_S.empty() == 1 || Char_S.top() == '('){
				Char_S.push(Ques[i]);
			}
			else{
				while (Char_S.empty() != 1){
					if (Char_S.top() == '('){
						break;
					}
					PostQ += Char_S.top();
					Char_S.pop();
				
				}
				Char_S.push(Ques[i]);
				PostQ += ' ';
			}
		}
		else if (Ques[i] == '*' || Ques[i] == '/'){
			if (Char_S.empty() == 1 || Char_S.top() == '(' || Char_S.top() == '+' || Char_S.top() == '-'){
				Char_S.push(Ques[i]);
			}
			else{
				while (Char_S.empty() != 1){
					if (Char_S.top() == '('){
						break;
					}
					PostQ += Char_S.top();
					Char_S.pop();
				}
				Char_S.push(Ques[i]);
				PostQ += ' ';
			}
		}

		i++;
	}
	while (Char_S.empty() != 1){
		PostQ += Char_S.top();
		Char_S.pop();
	}
	//PostQ += ' ';
	return PostQ;
}
