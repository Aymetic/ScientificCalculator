#include "function.h"

double getSin( double number )
{
    double answer = 0;
    // 计算弧度
    double radian = ( number * 3.1415926 ) / 180.0;
    answer = sin( radian );

    return answer;
}

double getCos( double number )
{
    double answer = 0;
    // 计算弧度
    double radian = ( number * 3.1415926 ) / 180.0;
    answer = cos( radian );

    return answer;
}

double getTan( double number )
{
    double answer = 0;
    // 计算弧度
    double radian = ( number * 3.1415926 ) / 180.0;
    answer = tan( radian );

    return answer;
}

double getFac( double number )
{
    double answer = 1;

    for ( double i = 2; i <= number; ++i )
    {
        answer *= i;
    }

    return answer;
}

double getLn( double number )
{
    double answer = 0;

    answer = log( number );

    return answer;
}

double getLg( double number )
{
    double answer = 0;

    answer = log10( number );

    return answer;
}

double getSqrt( double number )
{
    double answer = 0;

    answer = sqrt( number );

    return answer;
}

double getPow( double baseNumber, double powNumber )
{
    double answer = 0;

    answer = pow( baseNumber, powNumber );

    return answer;
}
