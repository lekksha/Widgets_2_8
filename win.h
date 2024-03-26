#ifndef win_h
#define win_h
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Counter : public QLineEdit {
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent = 0) : QLineEdit(contents, parent) {}
signals:
    void tick_signal();
public slots:
    void add_one() {
        QString str = text();   // сохранить текст, который написан в переменную
        int r = str.toInt();    // перевести сохраненный текст в число
        if (r != 0 && r % 5 == 0)
            emit tick_signal();
        r++;
        str.setNum(r);  // переводим число в строку
        setText(str);   // устанавливаем значение строки
    }
};


class Win: public QWidget {
    Q_OBJECT
protected:
    QLabel *label1;
    QLabel *label2;
    Counter *edit1;
    Counter *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = 0);
};
#endif
