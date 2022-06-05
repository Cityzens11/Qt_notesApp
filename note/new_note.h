#ifndef NEW_NOTE_H
#define NEW_NOTE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class new_note;
}

class new_note : public QDialog
{
    Q_OBJECT

public:
    explicit new_note(QWidget *parent = nullptr);
    ~new_note();
    QString title;
    void setTitle(const QString &TITLE)
    {
        title = TITLE;
    }
signals:
    void added_note();
private slots:
    void on_pushButton_clicked();

private:
    Ui::new_note *ui;
};

#endif // NEW_NOTE_H
