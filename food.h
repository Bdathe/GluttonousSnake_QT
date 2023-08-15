
#ifndef FOOD_H
#define FOOD_H


#include <QObject>
#include <QPoint>
#include <random>


class Food : public QObject
{
    Q_OBJECT

private:
    QPoint pos_;  // 位置
    int wight_;  // 分数权重

public:
    explicit Food(QObject *parent = nullptr);

public:
    // 获取位置
    QPoint GetPos();
    // 获取分数权重
    int GetWigth();

public:
    // 随机生成食物的坐标
    void RandomPos();
    // 画食物
    void DrawFood();
};

#endif // FOOD_H
