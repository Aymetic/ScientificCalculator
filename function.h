#ifndef FUNCTION_H
#define FUNCTION_H

#include <cmath>
#include <iostream>
#include <string>
#define PI 3.141592
using namespace std;

double getSin( double number );                       //正弦函数
double getCos( double number );                       //余弦函数
double getTan( double number );                       //正切函数
double getFac( double number );                       //阶乘函数
double getLn( double number );                        // ln函数
double getLg( double number );                        // lg函数
double getSqrt( double number );                      //平方幂函数
double getPow( double baseNumber, double powNumber ); //幂函数

#endif // FUNCTION_H
