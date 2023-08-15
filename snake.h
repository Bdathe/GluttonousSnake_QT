
#ifndef SNAKE_H
#define SNAKE_H

#include "food.h"
#include <QObject>

// 方向枚举
enum Direction {
    UP, DOWN, LEFT, RIGHT
};

class Snake : public QObject
{
    Q_OBJECT

private:
    QPoint* snake_;  // 蛇
    int len_;  // 蛇长度
    Direction dir_;  // 当前方向
    int score_;  // 得分

public:
public:
    // 构造
    explicit Snake(QObject *parent = nullptr);
    // 析构
    ~Snake();

public:
    // 获取第i节蛇的坐标
    QPoint GetPos(int i);
    // 获取蛇的方向
    Direction GetDir();
    // 设置蛇的方向
    void SetDir(Direction dir);
    // 获取蛇的长度
    int Getlen();
    // 设置蛇的长度
    void SetLen(int len);
    // 获取得分
    int GetScore();

public:
    // 移动蛇
    void MoveSnake();
    // 食物出现的位置是否合理
    void CheckFoodPos(Food *food);
    // 蛇是否吃了食物
    bool IsEatFood(Food *food);
    // 吃食物操作
    void EatFood(Food *food);
    // 蛇死亡的判断
    bool IsDeath();

signals:
    // 蛇吃食物信号
    void Eat();
    // 蛇死亡的信号
    void Death();

};

#endif // SNAKE_H
