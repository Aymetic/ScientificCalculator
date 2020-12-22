#ifndef BEPEXPRESSION_H
#define BEPEXPRESSION_H
/**
 * 后台处理表达式头文件
 * 此头文件用于实现
 * 1.表达式检验
 * 2.格式化(处理负数)
 * 3.比较运算符优先级
 * 4.中缀表达式转换为后缀表达式
 * 5.计算结果
 * */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int analysis(const char *expression);           //检验算术表达式的合法性
string format(string str);                      //处理负号开头的表达式，处理方法是在前面加个0
int comparePriorities(char c);                  //比较运算符优先级
vector<string> Infix2Suffix(string str);        //中缀表达式转后缀
double result(vector<string> suffixExpression); //计算后缀表达式结果
double solve(string str);                       //调用前几个函数，相当于main函数，一步到位求解表达式

#endif // BEPEXPRESSION_H
