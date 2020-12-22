#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aboutdialog.h"
#include "bepexpression.h"
#include "function.h"
#include <QDateTime>
#include <QDebug>
#include <QEvent>
#include <QLabel>
#include <QMainWindow>
#include <QTextBrowser>
#include <QTimer>
#include <string>

QT_BEGIN_NAMESPACE
using namespace std;
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timerUpdate();  //更新时间
    void clearHistory(); //清除历史记录

protected:
    void dealMenuBar(); //处理menu的信号与槽

private slots:

    void on_buttonC_clicked(); //Clear被按下

    void on_buttonLeftBracket_clicked(); //左括号被按下

    void on_buttonFactorial_clicked(); //阶乘负号被按下

    void on_buttonRadical_clicked(); //根号键被按下

    void on_buttonSin_clicked(); //Sin被按下

    void on_buttonCos_clicked(); //Cos被按下

    void on_buttonTan_clicked(); //Tan被按下

    void on_buttonSquare_clicked(); //平方键被按下

    void on_buttonPower_clicked(); //幂函数键被按下

    void on_buttonLn_clicked(); //ln键被按下

    void on_buttonLg_clicked(); //lg键被按下

    void on_button0_clicked(); //0被按下

    void on_button1_clicked(); //1被按下

    void on_button2_clicked(); //2被按下

    void on_button3_clicked(); //3被按下

    void on_button4_clicked(); //4被按下

    void on_button5_clicked(); //5被按下

    void on_button6_clicked(); //6被按下

    void on_button7_clicked(); //7被按下

    void on_button8_clicked(); //8被按下

    void on_button9_clicked(); //9被按下

    void on_buttonPI_clicked(); //常数Π被按下

    void on_buttonE_clicked(); //常数e被按下

    void on_buttonAdd_clicked(); //加号被按下

    void on_buttonSubtract_clicked(); //减号被按下

    void on_buttonMultiply_clicked(); //乘号被按下

    void on_buttonDivid_clicked(); //除号被按下

    void on_buttonEqual_clicked(); //等号被按下

    void on_buttonSpot_clicked(); //小数点被按下

    void on_buttonRightBracket_clicked(); //右括号被按下

private:
    Ui::MainWindow *ui;
    QLabel *showtime;
    AboutDialog myDialog;
    enum functionSituation
    {
        EMPTY = 0, //空
        SQUARE,    //平方
        POWER,     //幂
        SQRT,      //平方根
        LG,        // 10为底的对数
        LN,        // e为底的对数
        FAC,       //阶乘
        SIN,       //正弦
        COS,       //余弦
        TAN,       //正切
        NUM        //普通数字计算
    };
    int flag;          //标志，用于识别计算器处于哪种计算模式
    void moveCursor(); //移动光标至括号内
};
#endif // MAINWINDOW_H
