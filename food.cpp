
#include "food.h"

Food::Food(QObject *parent)
    : QObject{parent} {

    RandomPos();
    wight_ = 10;
}

void Food::RandomPos() {
    // 随机生成一个位置
    int sept = 20;
    std::default_random_engine e(time(0));  // 随机数引擎，设置种子
    std::uniform_int_distribution<unsigned> ux(0, 31);  // x的范围
    std::uniform_int_distribution<unsigned> uy(0, 23);  // y的范围

    pos_.setX(ux(e) * sept + 10);
    pos_.setY(uy(e) * sept + 10);
}

// 获取食物的位置
QPoint Food::GetPos() {
    return pos_;
}

// 获取食物的分数权重
int Food::GetWigth() {
    return wight_;
}

