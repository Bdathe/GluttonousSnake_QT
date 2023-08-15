

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H


#include "snake.h"
#include "food.h"
#include "game_over_dialog.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QStringList>


#include <QFile>

const int kGameLength = 640;
const int kGameWidth = 480;
const int kGameExtra = 50;
const QString kRemindInfo = "当前分数为：";

class GameWindow : public QWidget {
    Q_OBJECT

public:
    Snake  *snake;  // 蛇
    Food   *food;  // 食物
    QTimer *timer;  // 定时器
    int diffculty;  // 难度，即定时时间
    GameOverDialog *game_over_dialog;  // 游戏结束对话框
    QLabel *score_show;  // 显示分数的标签
    QString score_inf;  // 分数信息
    QStringList records;  // 历史记录

public:
    explicit GameWindow(int diff, QWidget *parent = nullptr);

public:
    // 按键按下事件
    virtual void keyPressEvent(QKeyEvent *event);
    // 绘图事件
    virtual void paintEvent(QPaintEvent *event);
    // 更新窗口
    void Update();
    // 游戏结束提示
    void GameOver();
    // 读取文件
    void Read();
    // 写文件
    void Write();

signals:
    // 更新记录信号
    void UpdateRecord();

};

#endif // GAME_WINDOW_H
