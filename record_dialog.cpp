
#include "record_dialog.h"

RecordDialog::RecordDialog(QObject *parent)
    : QObject{parent} {

    // 初始化对话框
    record_dialog = new QDialog;
    record_dialog->setFixedSize(300,240);

    // 初始化清空记录按钮
    clear_button = new QPushButton(record_dialog);
    clear_button->setText("清空记录");
    clear_button->resize(90,40);
    clear_button->move(100,180);

    this->Read();

    // 初始化标签
    literal_1 = new QLabel(record_dialog);
    literal_1->resize(100,50);
    literal_1->move(110,20);

    literal_2 = new QLabel(record_dialog);
    literal_2->resize(100,50);
    literal_2->move(110,60);


    literal_3 = new QLabel(record_dialog);
    literal_3->resize(100,50);
    literal_3->move(110,100);

    // 显示记录
    DisplayRecord();

    // 关联清空记录按钮
    connect(clear_button, &QPushButton::clicked, this, [=]() {
        this->records.clear();

        records.append("0");
        records.append("0");
        records.append("0");
        this->Write();

        // 弹出提示
        QMessageBox::information(record_dialog, "清空提示", "清空成功");

        // 显示新记录
        DisplayRecord();
    });
}

// 获取历史分数
int RecordDialog::GetRecord(int i) {
    int tmp = records.at(i).toInt();
    return tmp;
}

// 设置历史记录
void RecordDialog::SetRecord(int i, int score) {
    records[i] = QString::number(score);
}

void RecordDialog::ShowDialog() {
    record_dialog->exec();
}

void RecordDialog::DisplayRecord() {
    // 初始化文字信息
    QString tmp_info = "第一名：" + records.at(0);
    literal_1->setText(tmp_info);

    tmp_info = "第二名：" + records.at(1);
    literal_2->setText(tmp_info);

    tmp_info = "第三名：" + records.at(2);
    literal_3->setText(tmp_info);
}

// 读文件
void RecordDialog::Read() {
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
void RecordDialog::Write() {
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

