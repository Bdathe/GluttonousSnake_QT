
#include "snake.h"

Snake::Snake(QObject *parent)
    : QObject{parent} {
    // 初始化

    snake_ = new QPoint[100];
    len_ = 3;
    dir_ = RIGHT;
    score_ = 0;

    // 初始化设置前三节坐标
    // 蛇头
    snake_[0] = QPoint(50,10);
    // 第一节
    snake_[1] = QPoint(30,10);
    // 第三节
    snake_[2] = QPoint(10,10);
}

Snake::~Snake() {
    delete snake_;
}

// 获取第i节蛇的坐标
QPoint Snake::GetPos(int i) {
    return snake_[i];
}

// 获取蛇的方向
Direction Snake::GetDir() {
    return dir_;
}

// 设置蛇的方向
void Snake::SetDir(Direction dir) {
    dir_ = dir;
}

// 获取蛇的长度
int Snake::Getlen() {
    return len_;
}

// 设置蛇的长度
void Snake::SetLen(int len) {
    len_ = len;
}

// 获取得分
int Snake::GetScore() {
    return score_;
}

// 移动蛇
void Snake::MoveSnake() {
    // 覆盖，后一节的状态等于前一节的状态
    for (int i = len_ - 1; i >= 1; i--) {
        snake_[i] = snake_[i - 1];
    }

    // 移动蛇头
    if (dir_ == RIGHT) {
        int tmp = snake_[0].x() + 20;
        snake_[0].setX(tmp);
    } else if (dir_ == LEFT) {
        int tmp = snake_[0].x() - 20;
        snake_[0].setX(tmp);
    } else if (dir_ == UP) {
        int tmp = snake_[0].y() - 20;
        snake_[0].setY(tmp);
    } else {
        int tmp = snake_[0].y() + 20;
        snake_[0].setY(tmp);
    }
}

// 检测食物生成位置是否合理
void Snake::CheckFoodPos(Food *food) {
    bool flag = false;  // 检测食物生成位置是否合理的标志

    while (!flag) {
        for (int i = 0; i < len_; i++) {
            if (snake_[i] == (*food).GetPos()) {
                (*food).RandomPos();
                break;
            }
        }

        flag = true;
    }
}

// 蛇是否吃了食物
bool Snake::IsEatFood(Food *food) {
    if (snake_[0] == (*food).GetPos())
        return true;

    return false;
}

// 吃食物操作
void Snake::EatFood(Food *food) {
    // 蛇身增加
    len_++;
    // 得分增加
    score_ += (*food).GetWigth();

    // 更新
    MoveSnake();  // 生成加入新结点后的蛇的坐标

    // 重新生成食物位置
    (*food).RandomPos();
    CheckFoodPos(food);
}

// 判断蛇是否死亡
bool Snake::IsDeath() {
    // 判断蛇头是否撞墙
    if (snake_[0].x() < 10 || snake_[0].x() > 630 || snake_[0].y() < 0 || snake_[0].y() > 470) {
        return true;
    }

    // 判断是否自己吃自己
    for (int i = 1; i < len_; i++) {
        if (snake_[0] == snake_[i])
            return true;
    }

    return false;
}
