
#include "diffculty_select_dialog.h"

DiffcultySelectDialog::DiffcultySelectDialog(QObject *parent)
    : QObject{parent} {

    // 初始化对话框
    diffculty_dialog = new QDialog;
    diffculty_dialog->setFixedSize(300,240);

    // 初始化三个按钮
    simple_button = new QPushButton(diffculty_dialog);
    simple_button->resize(90,48);
    simple_button->setText("简单模式");
    simple_button->move(110,20);

    medium_button = new QPushButton(diffculty_dialog);
    medium_button->resize(90,48);
    medium_button->setText("中等模式");
    medium_button->move(110,90);

    diffculty_button = new QPushButton(diffculty_dialog);
    diffculty_button->resize(90,48);
    diffculty_button->setText("困难模式");
    diffculty_button->move(110,160);

    // 关联按钮对应的难度
    connect(simple_button, &QPushButton::clicked, this, [=]() {
        this->diffculty = kSimple;
        QMessageBox::information(diffculty_dialog, "设置提示", "设置成功，难度为：简单");
        emit this->DiffcultySetting();  // 发送信号
    });

    connect(medium_button, &QPushButton::clicked, this, [=]() {
        this->diffculty = kMedium;
        QMessageBox::information(diffculty_dialog, "设置提示", "设置成功，难度为：中等");
        emit this->DiffcultySetting();  // 发送信号
    });

    connect(diffculty_button, &QPushButton::clicked, this, [=]() {
        this->diffculty = kDiffculty;
        QMessageBox::information(diffculty_dialog, "设置提示", "设置成功，难度为：困难");
        emit this->DiffcultySetting();  // 发送信号
    });
}


// 显示对话框
void DiffcultySelectDialog::ShowDialog() {
    diffculty_dialog->exec();
}

// 获取难度
int DiffcultySelectDialog::GetDiffculty() {
    return diffculty;
}
