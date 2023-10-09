#pragma once

class MyButton : public QPushButton {
    Q_OBJECT

  public:
    MyButton();
    ~MyButton();

  public slots:
    void on_clicked();
};
