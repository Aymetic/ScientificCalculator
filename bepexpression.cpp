#include "bepexpression.h"

string format(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            if (i == 0)
            {
                str.insert(0, 1, '0');
            }
            else if (str[i - 1] == '(')
            {
                str.insert(i, 1, '0');
            }
        }
    }
    return str;
}

int comparePriorities(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

vector<string> Infix2Suffix(string str)
{
    vector<string> suffixExpression; //存储后缀表达式
    stack<char> operatorStack;
    for (int i = 0; i < str.length(); i++)
    {
        string temp = "";
        switch (str[i])
        {
        //
        case '+':
        case '-':
        case '*':
        case '/':
        {
            if (operatorStack.empty() || operatorStack.top() == '(')
            {
                operatorStack.push(str[i]);
            }
            else
            {
                //栈不为空且栈顶元素优先级大于这个位置的运算符，优先级大的先入栈
                while (!operatorStack.empty() && comparePriorities(operatorStack.top()) >= comparePriorities(str[i]))
                {
                    temp += operatorStack.top();
                    suffixExpression.push_back(temp);
                    operatorStack.pop();
                    temp = "";
                }
                operatorStack.push(str[i]);
            }
            break;
        }
        case '(':
        {
            operatorStack.push(str[i]);
            break;
        }
        case ')':
        {
            while (operatorStack.top() != '(')
            {
                temp += operatorStack.top();
                suffixExpression.push_back(temp);
                operatorStack.pop();
                temp = "";
            }
            operatorStack.pop();
            break;
        }
        //除去+-*、/和括号，剩下的就是数字
        default:
        {
            if ((str[i] >= '0' && str[i] <= '9'))
            {
                temp += str[i];
                //若是连续数字，若不是则跳过而直接放入逆波兰表达式
                while (i + 1 < str.size() && str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '.')
                {
                    temp += str[i + 1];
                    ++i;
                }
                suffixExpression.push_back(temp);
            }
        }
        }
    }
    while (!operatorStack.empty())
    {
        string temp = "";
        temp += operatorStack.top();
        suffixExpression.push_back(temp);
        operatorStack.pop();
    }
    return suffixExpression;
}

double result(vector<string> suffixExpression)
{
    stack<double> suffixStack; //后缀表达式计算栈
    double num, op1, op2;      //定义数字、操作数1和2
    for (int i = 0; i < suffixExpression.size(); i++)
    {
        string temp = suffixExpression[i];
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            // c_str()函数是将string转化为标准char*，atof()是将字符串转化为浮点数
            num = atof(temp.c_str());
            suffixStack.push(num); //数字压入栈
        }
        else if (suffixExpression[i] == "+")
        {
            //因为是后缀表达式，所以先出栈的是操作数2，后出来的是操作数1
            op2 = suffixStack.top(); //取栈顶
            suffixStack.pop();       //栈顶出栈
            op1 = suffixStack.top();
            suffixStack.pop();
            suffixStack.push(op1 + op2);
        }
        else if (suffixExpression[i] == "-")
        {
            op2 = suffixStack.top();
            suffixStack.pop();
            op1 = suffixStack.top();
            suffixStack.pop();
            suffixStack.push(op1 - op2);
        }
        else if (suffixExpression[i] == "*")
        {
            op2 = suffixStack.top();
            suffixStack.pop();
            op1 = suffixStack.top();
            suffixStack.pop();
            suffixStack.push(op1 * op2);
        }
        else if (suffixExpression[i] == "/")
        {
            op2 = suffixStack.top();
            suffixStack.pop();
            op1 = suffixStack.top();
            suffixStack.pop();
            suffixStack.push(op1 / op2);
        }
    }
    return suffixStack.top();
}

double solve(string str)
{
    str = format(str);
    vector<string> suffixExpression = Infix2Suffix(str);
    double k = result(suffixExpression);
    return k;
}
/**
 * 如果不合法，程序会抛异常
 * 异常代码解释：
 * 1-运算符位置不正确
 * 2-左右括号不匹配
 * 3-存在不合法字符
 * 如果正确的话，程序最后会返回一个整数0
 * */
int analysis(const char *expression)
{
    int opt = 0;
    int length = strlen(expression);
    bool isNumberEnd = false;
    int numberBracket = 0; //括号总数，检测到左括号就+1，检测到右括号就-1

    for (int i = 0; i < length;)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            if (isNumberEnd)
                throw 1;
            isNumberEnd = true; //此时检测到数字，所以置为真，因为下面要把连续的数字吃掉
            while (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.')
                ++i;
        }
        //数字吃掉了，轮到运算符
        char const *sop = "(+-*/)";
        opt = strchr(sop, expression[i++]) - sop; //计算运算符优先级，从左到右优先级依次增高
        if (opt < 0 || opt > 6)
            throw 3;
        if (opt == 0) //匹配到左括号
        {
            if (isNumberEnd) //此时括号数应为0，否则为错
                throw 1;
            numberBracket++;
        }
        if (opt == 5) //匹配到右括号
        {
            if (numberBracket <= 0) //如果是右括号，那么nbracket必大于0
                throw 2;
            numberBracket--;
        }
        if (opt > 0 && opt < 6 && !isNumberEnd) //运算符正确但后面没有数字
            throw 1;
        if (opt > 0 && opt < 5) //匹配到+-*和/，数字末端置false
            isNumberEnd = false;
    }
    if (numberBracket) //括号不匹配
        throw 2;
    if (!isNumberEnd) //运算符缺少运算数
        throw 1;

    return 0;
}
