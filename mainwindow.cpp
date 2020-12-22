#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag     = EMPTY;
    showtime = new QLabel(this);

    //更新时间，在statusbar右边显示，1000ms刷新一次
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerUpdate);
    timer->start(1000);
    ui->statusbar->addPermanentWidget(showtime);

    //写在这里有点乱，所以做成了一个函数
    dealMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    showtime->setText(time.toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void MainWindow::clearHistory()
{
    ui->historyDisplay->clear();
}

void MainWindow::dealMenuBar()
{
    //连接按键退出槽
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    //连接历史记录清空槽
    connect(ui->actionClearHistory, &QAction::triggered, this,
            &MainWindow::clearHistory);
    //连接对话框打开槽
    connect(ui->actionAbout, &QAction::triggered, &myDialog, &QDialog::open);
}

void MainWindow::on_buttonC_clicked()
{
    ui->textDisplay->clear();
    flag = EMPTY;
    ui->textDisplay->setEnabled(true);
}

void MainWindow::on_buttonLeftBracket_clicked()
{
    ui->textDisplay->insert("(");
}

void MainWindow::on_buttonRightBracket_clicked()
{
    ui->textDisplay->insert(")");
}

void MainWindow::moveCursor()
{
    QString text       = ui->textDisplay->text();
    int cursorPosition = text.lastIndexOf(")");
    if (text.lastIndexOf((")")) != -1)
        ui->textDisplay->setCursorPosition(cursorPosition);
}

void MainWindow::on_buttonFactorial_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("!");

    QString text      = ui->textDisplay->text();
    QString preString = text;
    preString.chop(1); //删除掉感叹号
    bool isNumber    = true;
    double preNumber = preString.toDouble(&isNumber);

    if (!isNumber)
        ui->statusbar->showMessage("错误的计算格式，请修改!", 5000);
    else
    {
        flag = FAC;
        moveCursor();
        ui->textDisplay->setFocusPolicy(Qt::NoFocus);
    }
}

void MainWindow::on_buttonRadical_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("√()");
    QString text = ui->textDisplay->text();

    if (text.at(0) != "√")
        ui->statusbar->showMessage("错误的计算格式，请修改!", 5000);
    else
    {
        flag = SQRT;
        moveCursor();
        ui->textDisplay->setFocusPolicy(Qt::NoFocus);
    }
}

void MainWindow::on_buttonSin_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("sin()");
    flag = SIN;
    moveCursor();
    ui->textDisplay->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::on_buttonCos_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("cos()");
    flag = COS;
    moveCursor();
    ui->textDisplay->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::on_buttonTan_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("tan()");
    flag = TAN;
    moveCursor();
    ui->textDisplay->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::on_buttonSquare_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("^2");

    //判断输入的底数是否为数字
    QString text;
    text              = ui->textDisplay->text();
    QString preString = text;
    preString.chop(2);
    bool isNumber    = true;
    double preNumber = preString.toDouble(&isNumber);

    if (!isNumber)
        ui->statusbar->showMessage("错误的计算格式，请修改!");
    else
    {
        flag = SQUARE;
        moveCursor();
        ui->textDisplay->setFocusPolicy(Qt::NoFocus);
    }
}
// TODO
void MainWindow::on_buttonPower_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("^()");

    //判断输入的底数是否为数字
    QString text;
    text              = ui->textDisplay->text();
    QString preString = text;
    preString.chop(3);
    bool isNumber    = true;
    double preNumber = preString.toDouble(&isNumber);

    if (!isNumber)
        ui->statusbar->showMessage("错误的计算格式，请修改!", 3000);
    else
    {
        flag = POWER;
        moveCursor();
        ui->textDisplay->setFocusPolicy(Qt::NoFocus);
    }
}

void MainWindow::on_buttonLn_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("ln()");
    flag = LN;
    moveCursor();
    ui->textDisplay->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::on_buttonLg_clicked()
{
    if (flag != EMPTY)
    {
        ui->statusbar->showMessage("此函数暂不支持混合运算!", 3000);
        return;
    }
    ui->textDisplay->insert("lg()");
    flag = LG;
    moveCursor();
    ui->textDisplay->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::on_button0_clicked()
{
    ui->textDisplay->insert("0");
}

void MainWindow::on_button1_clicked()
{
    ui->textDisplay->insert("1");
}

void MainWindow::on_button2_clicked()
{
    ui->textDisplay->insert("2");
}

void MainWindow::on_button3_clicked()
{
    ui->textDisplay->insert("3");
}

void MainWindow::on_button4_clicked()
{
    ui->textDisplay->insert("4");
}

void MainWindow::on_button5_clicked()
{
    ui->textDisplay->insert("5");
}

void MainWindow::on_button6_clicked()
{
    ui->textDisplay->insert("6");
}

void MainWindow::on_button7_clicked()
{
    ui->textDisplay->insert("7");
}

void MainWindow::on_button8_clicked()
{
    ui->textDisplay->insert("8");
}

void MainWindow::on_button9_clicked()
{
    ui->textDisplay->insert("9");
}

void MainWindow::on_buttonPI_clicked()
{
    ui->textDisplay->insert("3.1415926535");
}

void MainWindow::on_buttonE_clicked()
{
    ui->textDisplay->insert("2.7182818285");
}

void MainWindow::on_buttonAdd_clicked()
{
    ui->textDisplay->insert("+");
}

void MainWindow::on_buttonSubtract_clicked()
{
    ui->textDisplay->insert("-");
}

void MainWindow::on_buttonMultiply_clicked()
{
    ui->textDisplay->insert("*");
}

void MainWindow::on_buttonDivid_clicked()
{
    ui->textDisplay->insert("/");
}

void MainWindow::on_buttonEqual_clicked()
{
    double answerNumber  = 0;
    QString qExpression  = ui->textDisplay->text();
    string stdExpression = qExpression.toStdString(); //转化为c++的string

    if (flag != EMPTY) //函数模式
    {
        // enum functionSituation{EMPTY = 0,SQUARE,POWER,SQRT,LG,LN,FAC,SIN,COS,TAN,NUM};
        switch (flag)
        {
        case SQUARE:
        {
            //将形似于x^2的表达式中的x提取出来
            QString qNumber = qExpression;
            qNumber.chop(2);
            double number = qNumber.toDouble();

            answerNumber = getPow(number, 2);
            break;
        }
        case POWER:
        {
            //将形似于x^(y)的表达式中的x提取出来
            int Length   = qExpression.length();
            int position = qExpression.indexOf("^");
            //分离出底数和指数
            QString qBaseNumber = qExpression;
            qBaseNumber.chop(Length - position);
            double baseNumber = qBaseNumber.toDouble();

            QString qPowNumber = qExpression.mid(position + 2);
            qPowNumber.chop(1);
            double powNumber = qPowNumber.toDouble();

            answerNumber = getPow(baseNumber, powNumber);
            break;
        }
        case SQRT:
        {
            //将形似于√(x)的表达式中的x提取出来
            QString qNumber = qExpression.mid(2);
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());

            answerNumber = getSqrt(number);
            break;
        }
        case LG:
        {
            //将形似于lg(x)的表达式中的x提取出来
            QString qNumber = qExpression.mid(3);
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());

            answerNumber = getLg(number);
            break;
        }
        case LN:
        {
            //将形似于ln(x)的表达式中的x提取出来
            QString qNumber = qExpression.mid(3);
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());

            answerNumber = getLn(number);
            break;
        }
        case FAC:
        {
            //将形似于x!的表达式中的x提取出来
            QString qNumber = qExpression;
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());

            answerNumber = getFac(number);
            break;
        }
        case SIN:
        {
            //将形似于sin(x)的表达式中的x提取出来
            QString qNumber = qExpression.mid(4);
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());

            answerNumber = getSin(number);
            break;
        }
        case COS:
        {
            //将形似于cos(x)的表达式中的x提取出来
            QString qNumber = qExpression.mid(4);
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());
            answerNumber  = getCos(number);
            break;
        }
        case TAN:
        {
            //将形似于tan(x)的表达式中的x提取出来
            QString qNumber = qExpression.mid(4);
            qNumber.chop(1);
            double number = solve(qNumber.toStdString());
            answerNumber  = getTan(number);
            break;
        }
        }
        QString answerString = QString::number(answerNumber, 'g', 6);
        //重置光标位置和标志，以进行下一次运算
        ui->textDisplay->setCursorPosition(ui->textDisplay->text().size());
        ui->textDisplay->insert("=" + answerString);
        flag = EMPTY;
        //记录历史信息
        ui->historyDisplay->append(ui->textDisplay->text());
        ui->statusbar->showMessage("记得Clear再进行下一次运算哦~", 3000);
    }
    else //普通算式模式
    {
        try
        {
            if (!analysis(stdExpression.c_str())) //尝试判断表达式是否合法
            {
                answerNumber = solve(stdExpression); // 用这个参数接返回的计算值
                QString answerString = QString::number(answerNumber, 'g', 6);
                //重置光标位置和标志，以进行下一次运算
                ui->textDisplay->setCursorPosition(ui->textDisplay->text().size());
                ui->textDisplay->insert("=" + answerString);
                flag = EMPTY;
                //记录历史信息
                ui->historyDisplay->append(ui->textDisplay->text());
                ui->statusbar->showMessage("记得Clear再进行下一次运算哦~", 3000);
            }
        }
        catch (int errorCode)
        {
            switch (errorCode)
            {
            case 1:
                ui->statusbar->showMessage("运算符位置不正确，请检查后重试",3000);
                break;
            case 2:
                ui->statusbar->showMessage("左右括号不匹配，请检查后重试", 3000);
                break;
            case 3:
                ui->statusbar->showMessage("存在不合法字符，请检查后重试", 3000);
                break;
            }
        }
    }
}

void MainWindow::on_buttonSpot_clicked()
{
    ui->textDisplay->insert(".");
}
