
#ifndef DIFFCULTYSELECTDIALOG_H
#define DIFFCULTYSELECTDIALOG_H


#include <QDialog>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>

const int kSimple = 500;
const int kMedium = 200;
const int kDiffculty = 100;


class DiffcultySelectDialog : public QObject
{
    Q_OBJECT
public:
    explicit DiffcultySelectDialog(QObject *parent = nullptr);

private:
    int diffculty = 200;  // 难度
    QDialog *diffculty_dialog;  // 难度选择主对话框，模态
    QPushButton *simple_button;  // 简单
    QPushButton *medium_button;  // 中等
    QPushButton *diffculty_button;  // 困难


public:
    // 显示对话框
    void ShowDialog();
    // 获取难度
    int GetDiffculty();

signals:
    // 难度设置的信号
    void DiffcultySetting();
};

#endif // DIFFCULTYSELECTDIALOG_H
