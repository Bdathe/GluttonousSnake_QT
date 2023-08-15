
#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent) {

    // 设置主窗口大小
    setFixedSize(kWidgetLength,KWidgetWidth);

    // 初始化开始按钮
    start_button = new QPushButton(this);  // 依赖于主窗口
    start_button->setText("开始游戏");
    start_button->setFixedSize(90,48);
    start_button->move((kWidgetLength / 2) - 50, (KWidgetWidth / 4) - 50);

    // 初始化难度选择按钮
    diffculty_button = new QPushButton(this);
    diffculty_button->setText("难度选择");
    diffculty_button->setFixedSize(90,48);
    diffculty_button->move((kWidgetLength / 2) - 50, (KWidgetWidth / 4) + 15);

    // 初始化查看记录按钮
    record_button = new QPushButton(this);
    record_button->setText("历史记录");
    record_button->setFixedSize(90,48);
    record_button->move((kWidgetLength / 2) - 50, (KWidgetWidth / 4) + 85);


    // 初始化退出按钮
    exit_button = new QPushButton(this);
    exit_button->setText("退出游戏");
    exit_button->setFixedSize(90,48);
    exit_button->move((kWidgetLength / 2) - 50, (KWidgetWidth / 4) + 150);


    // 初始化难度选择对话框
    diff_select_dialog = new DiffcultySelectDialog(this);
    connect(diffculty_button, &QPushButton::clicked, this, [=]() {
        diff_select_dialog->ShowDialog();
    });

    connect(record_button, &QPushButton::clicked, this, [=]() {
        // 创建对话框
        record_dialog = new RecordDialog(this);
        record_dialog ->ShowDialog();
    });

    connect(start_button, &QPushButton::clicked, this, [=](){  // 点击按钮，显示窗口
        // 创建游戏窗口
        game_window = new GameWindow(diffculty);  // 传入难度
        // 显示游戏窗口
        game_window->show();
    });


    // 绑定难度设置
    connect(diff_select_dialog, &DiffcultySelectDialog::DiffcultySetting, this, [=]() {
        diffculty = diff_select_dialog->GetDiffculty();  // 接收难度
    });

    // 退出按钮关联关闭窗口事件
    connect(exit_button, QPushButton::clicked, this, &QWidget::close);
}


Widget::~Widget() {

}


