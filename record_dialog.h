
#ifndef RECORD_DIALOG_H
#define RECORD_DIALOG_H


#include <QList>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QObject>

class RecordDialog : public QObject {
    Q_OBJECT

private:
    QDialog *record_dialog;  // 显示记录的对话框
    QStringList records; // 存储记录的容器
    QLabel *literal_1;  // 记录文字提示信息
    QLabel *literal_2;  // 记录文字提示信息
    QLabel *literal_3;  // 记录文字提示信息
    QPushButton *clear_button;  // 清楚记录按钮


public:
    explicit RecordDialog(QObject *parent = nullptr);

public:
    // 获取历史分数
    int GetRecord(int i);
    // 设置历史记录
    void SetRecord(int i, int score);

public:
    // 显示对话框
    void ShowDialog();
    // 显示记录
    void DisplayRecord();
    // 读文件
    void Read();
    // 写文件
    void Write();

signals:

};

#endif // RECORD_DIALOG_H
