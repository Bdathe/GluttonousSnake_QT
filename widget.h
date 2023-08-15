
#ifndef WIDGET_H
#define WIDGET_H

#include "game_window.h"  // 开始游戏窗口
#include "diffculty_select_dialog.h"  // 难度选择对话框
#include "record_dialog.h"  // 记录对话框
#include <QWidget>
#include <QWidget>
#include <QPushButton>

const int kWidgetLength = 480;
const int KWidgetWidth = 320;

class Widget : public QWidget {
    Q_OBJECT

private:
    QPushButton *start_button;  // 开始按钮
    QPushButton *diffculty_button;  // 难度选择按钮
    QPushButton *record_button;  // 查看最高成绩记录按钮
    QPushButton *exit_button;  // 退出按钮
    GameWindow *game_window;  // 游戏窗口
    DiffcultySelectDialog *diff_select_dialog;  // 难度选择对话框
    int diffculty = 200;  // 游戏难度，默认200
    RecordDialog *record_dialog;  // 记录对话框

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
