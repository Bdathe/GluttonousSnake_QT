
#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QObject>

class GameOverDialog : public QObject
{
    Q_OBJECT
public:
    explicit GameOverDialog(QObject *parent = nullptr);

private:
    QDialog *game_over_dialog;  // 游戏结束对话框
    QPushButton *ok_button;  // 游戏结束对话框上的确定按钮
    QLabel *over_msg_label;  // 结束提示信息

public:
    // 设置提示信息
    void SetMsgLabel(QString msg);
    // 运行模态对话框
    void ShowDialog();
    // 关闭游戏结束对话框
    void CloseDialog();


signals:
    // 本剧游戏结束信号
    void Finish();
};

#endif // GAMEOVERDIALOG_H
