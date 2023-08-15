
#include "game_window.h"

GameWindow::GameWindow(int diff, QWidget *parent)
    : QWidget{parent} {

    // 初始化游戏窗口
    setFixedSize(kGameLength,kGameWidth + kGameExtra);

    // 创建蛇
    snake = new Snake();
    // 创建食物
    food = new Food();
    // 创建游戏结束提示对话框
    game_over_dialog = new GameOverDialog(this);

    // 创建分数标签
    score_show = new QLabel(this);
    score_show->resize(100,50);
    score_show->move(10, 475);
    score_inf = kRemindInfo + QString::number(0);
    score_show->setText(score_inf);

    // 绑定确认按钮和关闭本局游戏事件
    connect(game_over_dialog, &GameOverDialog::Finish, this, [=]() {
        // 关闭游戏结束提示对话框
        game_over_dialog->CloseDialog();
        // 关闭当前窗口
        this->close();
        // 销毁蛇
        snake->~Snake();
    });

    // 创建定时器
    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
    // 绑定计时器,时间到了会调用槽函数
    connect(timer, &QTimer::timeout, this, &GameWindow::Update);
    // 启动计时器
    timer->start(diff);

    // 绑定蛇吃食物事件
    connect(snake, &Snake::Eat, this, [=](){
        snake->EatFood(food);
        score_inf = kRemindInfo + QString::number(snake->GetScore());
        score_show->setText(score_inf);
    });

    // 绑定蛇死亡事件
    connect(snake, &Snake::Death, this, &GameWindow::GameOver);

    // 绑定更新记录
    connect(this, &GameWindow::UpdateRecord, this,[=]() {
        this->Write();
    });
}

// 按键按下事件
void GameWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        if (snake->GetDir() != DOWN) {
            snake->SetDir(UP);
        }

    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        if (snake->GetDir() != UP) {
            snake->SetDir(DOWN);
        }

    } else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        if (snake->GetDir() != RIGHT) {
            snake->SetDir(LEFT);
        }

    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        if (snake->GetDir() != LEFT) {
            snake->SetDir(RIGHT);
        }
    }
}


// 绘画事件
void GameWindow::paintEvent(QPaintEvent *event) {
    // 定义一个画家
    QPainter *painter = new QPainter(this);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);\

    // 绘制分数显示区域
    painter->drawLine(QPoint(0,kGameWidth),QPoint(kGameLength,kGameWidth));

    // 绘制蛇
    for (int i = 0; i < snake->Getlen(); i++) {
        // 绘制圆
        painter->drawEllipse(snake->GetPos(i), 10, 10);
    }

    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    // 绘制食物
    painter->drawEllipse(food->GetPos(), 10, 10);

    snake->MoveSnake();
}

// 更新窗口
void GameWindow::Update() {
    update();

    if (snake->IsEatFood(food)) {  // 发送食物被吃的信号
        emit snake->Eat();
    }

    if (snake->IsDeath()) {  // 发送死亡信号
        emit snake->Death();
    }
}

// 游戏结束提示
void GameWindow::GameOver() {
    // 关闭定时器
    timer->stop();

    // 读取分数
    Read();

    // 将新分数，与其他三个分数排序
    int nums[4] = {0};
    nums[3] = snake->GetScore();
    for (int i = 0; i < 3; i++) {
        nums[i] = records[i].toInt();
    }

    // 排序
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (nums[j] < nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }

    // 取前三名
    for (int i = 0; i < 3; i++) {
        records[i] = QString::number(nums[i]);
    }

    emit this->UpdateRecord();  // 发送信号

    QString msg = "游戏结束，得分为：";
    msg.append(QString::number(snake->GetScore()));
    msg.append("，请再接再厉！");

    // 设置结束信息
    game_over_dialog->SetMsgLabel(msg);

    // 创建模态窗口
    game_over_dialog->ShowDialog();
}

// 读取文件
void GameWindow::Read() {
    // 读取文件信息
    QFile file("E:\\Project_Code\\Qt_study\\GluttonousSnake\\record.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //使用QTextStream一行一行读取文件
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();  // 整行读取
        records.push_back(line);
    }
    file.close();
}

// 写文件
void GameWindow::Write() {
    // 将记录写入文件
    QFile file("E:\\Project_Code\\Qt_study\\GluttonousSnake\\record.txt");
    //打开文件，不存在则创建
    if (file.open(QFile::WriteOnly | QIODevice::Text)) {
        QTextStream s(&file);
        for(QString line : records) {
            s << line << "\n";
        }
    }

    file.close();
}

