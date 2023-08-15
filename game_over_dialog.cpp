
#include "game_over_dialog.h"

GameOverDialog::GameOverDialog(QObject *parent)
    : QObject{parent} {

    // 创建游戏结束的提示窗口
    game_over_dialog = new QDialog;
    game_over_dialog->setFixedSize(320,180);

    // 创建按钮
    ok_button = new QPushButton(game_over_dialog);
    ok_button->setText("确定");
    ok_button->resize(80,50);
    ok_button->move(130,120);

    // 设置提示信息
    over_msg_label = new QLabel(game_over_dialog);
    over_msg_label->setFixedSize(250,100);
    over_msg_label->move(50,20);

    // 绑定确定按钮，发送本局游戏结束信号
    connect(ok_button, &QPushButton::clicked, this, [=]() {
        emit this->Finish();
    });
}

// 设置提示信息
void GameOverDialog::SetMsgLabel(QString msg) {
    over_msg_label->setText(msg);
}


// 运行模态对话框
void GameOverDialog::ShowDialog() {
    game_over_dialog->exec();
}

// 关闭游戏结束对话框
void GameOverDialog::CloseDialog() {
    game_over_dialog->close();
}

