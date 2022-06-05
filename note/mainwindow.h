#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDesktopWidget>
#include <QMainWindow>
#include <QFile>
#include <QList>
#include <QFileInfo>
#include <QTextEdit>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSignalMapper>
#include "new_note.h"

class SearchHighLight;
class note;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<note> notes;
private slots:
    void connecting();

    void add_notes();

    void on_actionNew_note_triggered();

    void on_pushButton_6_clicked();

    void on_actionExit_triggered();

    void on_actionOpen_note_txt_triggered();

    void on_actionPrint_triggered();

    void on_actionFont_style_3_triggered();

    void on_actionFont_color_4_triggered();

    void on_actionNote_color_triggered();

    void on_actionSearch_note_triggered();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    friend class note;
};

class note{
public:
    QString label_name;
    note(const QString &label_name)
    {
        this->label_name = label_name;
    }
    note()
    {

    }
    QWidget *s_note = new QWidget;
    QGridLayout *lay = new QGridLayout(s_note);
    QPushButton *change = new QPushButton("Change");
    QLabel *label = new QLabel(label_name);
    QTextEdit *txt = new QTextEdit;

    QWidget *n = new QWidget;
    QGridLayout *lay_n = new QGridLayout(n);
    QLabel *lab_n = new QLabel(label_name);
    QTextEdit *txt_n = new QTextEdit;
    QPushButton *can_n = new QPushButton("cancel");
    QPushButton *ok_n = new QPushButton("ok");

    QLineEdit *find = new QLineEdit;
    QPushButton *search = new QPushButton("search");

    SearchHighLight *m_searchHighLight;
private:
    friend class MainWindow;
};

#endif // MAINWINDOW_H
