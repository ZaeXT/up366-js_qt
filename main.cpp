#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

std::string js_regex(std::string);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建一个文本输入框
    QPlainTextEdit textInput;
    textInput.setPlaceholderText("请粘贴page1.js内的文本");

    // 创建一个按钮
    QPushButton saveButton("解析");
    QString inputText, aw;
    // 当按钮被点击时的处理函数
    QObject::connect(&saveButton, &QPushButton::clicked, [&]()
                     {
        // 获取文本输入框的内容
    inputText = textInput.toPlainText();

        // 在这里可以将输入内容保存到文件或数据库中
        // 这里只是简单地弹出一个消息框显示输入内容
QMessageBox::information(nullptr, "解析成功", "输入内容已解析!");
    aw = QString::fromStdString(js_regex(inputText.toStdString()));
    QMessageBox::information(nullptr, "Answer", aw);
    // qDebug() << js_regex(inputText.toStdString());
    qDebug() << aw; });
    QPushButton quitb("Quit");
    QObject::connect(&quitb, &QPushButton::clicked, [&]()
                     { app.quit(); });
    // 创建一个布局，并将文本输入框和按钮添加到布局中
    QVBoxLayout layout;
    layout.addWidget(&textInput);
    layout.addWidget(&saveButton);
    layout.addWidget(&quitb);
    // 创建一个窗口，并将布局设置为窗口的主布局
    QWidget window;
    window.setLayout(&layout);
    window.show();
    return app.exec();
}
