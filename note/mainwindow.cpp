#include "mainwindow.h"
#include "searchhighlight.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    ui->widget_2->hide();
    QFile names("notes/_names_.txt");

    if(QFileInfo::exists("notes/_names_.txt"))
    {
        int num = 1;
        QFile file("notes/_names_.txt");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream in(&file);
        QString name;
        QString color;
        while(!in.atEnd())
        {
            if(num % 2 != 0)
                name = in.readLine();
            else{
                color = in.readLine();

                if(QFile::exists("notes/"+name+".txt"))
                {
                note _note(name);
                QFile txt("notes/"+name+".txt");
                QTextStream stream(&txt);
                txt.open(QIODevice::ReadOnly|QIODevice::Text);
                txt.seek(0);
                QString string = stream.readAll();
                _note.txt->setText(string);
                _note.txt_n->setText(string);
                txt.close();

                if(color == "blue"){
                    _note.n->setStyleSheet("background-color: rgb(114, 159, 207);");
                    _note.s_note->setStyleSheet("background-color: rgb(114, 159, 207);");}
                else if(color == "yellow"){
                    _note.n->setStyleSheet("background-color: rgb(233, 185, 110);");
                    _note.s_note->setStyleSheet("background-color: rgb(233, 185, 110);");}
                else if(color == "purple"){
                    _note.n->setStyleSheet("background-color: rgb(173, 127, 168);");
                    _note.s_note->setStyleSheet("background-color: rgb(173, 127, 168);");}


                _note.label->setStyleSheet("color:rgb(255, 255, 255); font:22px;");
                _note.label->setText(_note.label_name);
                _note.txt->setStyleSheet("background: transparent; border:0px; color:rgb(46, 52, 54);");
                _note.txt->setDisabled(true);
                _note.txt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

                _note.txt_n->setStyleSheet("background: transparent; border:0px; color:rgb(46, 52, 54);");
                _note.lab_n->setStyleSheet("color:rgb(255, 255, 255); font:22px;");
                _note.lab_n->setText(_note.label_name);
                _note.find->setStyleSheet("background:white;color:rgb(46, 52, 54);");
                _note.find->setPlaceholderText("Search word");

                _note.m_searchHighLight = new SearchHighLight(_note.txt_n->document());

                _note.lay->addWidget(_note.change, 0,1);
                _note.lay->addWidget(_note.label, 0,0);
                _note.lay->addWidget(_note.txt, 1,0,1,2);
                _note.lay_n->addWidget(_note.find, 0,0,1,2);
                _note.lay_n->addWidget(_note.search, 0, 2);
                _note.lay_n->addWidget(_note.lab_n, 1,0);
                _note.lay_n->addWidget(_note.txt_n, 2,0,1,3);
                _note.lay_n->addWidget(_note.can_n, 3,1);
                _note.lay_n->addWidget(_note.ok_n, 3,2);

                notes.push_back(_note);
                }
            }
            num++;
        }
        file.close();
        add_notes();
    }
    else
    {

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/////////////////////////////////////////////////////create new note

void MainWindow::connecting()
{
    int index = 0;
    while(index != notes.size()){
        notes[index].n->setGeometry(500, 225, 600, 500);

        connect(notes[index].search, &QPushButton::clicked, [this, index](){
            notes[index].m_searchHighLight->searchText(notes[index].find->text());
        });
        connect(notes[index].change, SIGNAL(clicked()), notes[index].n, SLOT(show()));
        connect(notes[index].can_n, SIGNAL(clicked()), notes[index].n, SLOT(hide()));
        connect(notes[index].ok_n, &QPushButton::clicked, [this, index](){
            QFile file("notes/"+notes[index].label_name+".txt");
            QTextStream out(&file);
            if(file.open(QFile::WriteOnly|QFile::Text))
                {out << notes[index].txt_n->toPlainText();
                file.flush();
                file.close();}
            else
                QMessageBox::warning(this, "title", "warning");
            notes[index].txt->clear();
            QFile _file("notes/"+notes[index].label_name+".txt");
            QTextStream in(&_file);
            if(_file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                _file.seek(0);
                notes[index].txt->setText(_file.readAll());
            }
            else
                QMessageBox::warning(this, "title", "Warning");
            _file.flush();
            _file.close();
            });

        connect(notes[index].ok_n, SIGNAL(clicked()), notes[index].n, SLOT(hide()));

        index++;
    }
}

void MainWindow::add_notes()
{
    connecting();
    int index = 0;
    for(int i=0; i < ((notes.size()/3) + 1) ; i++)
    {
        for(int j=0; j<3;j++)
        {
            if(index == notes.size())
                break;
            else{
                ui->gridLayout_6->addWidget(notes[index].s_note, i,j);
                index++;
                }
        }
    }

}

void MainWindow::on_actionNew_note_triggered()
{
    ui->widget_2->show();
}

void MainWindow::on_pushButton_6_clicked()//create "new note" button
{
    QFile names("notes/_names_.txt");
    QFile file("notes/"+ui->lineEdit->text()+".txt");

    if(QFileInfo::exists("notes/"+ui->lineEdit->text()+".txt")) {QMessageBox::warning(this, "Warning!", "Give new title!");}
    else
    {
        QTextStream out(&names);

        new_note add_note;//executing new widget
        add_note.setTitle(ui->lineEdit->text());
        add_note.setModal(true);
        add_note.exec();

        names.open(QFile::WriteOnly|QFile::Text|QFile::Append);
        out << ui->lineEdit->text() << "\n";
        out << ui->comboBox->currentText() << "\n";
        names.close();

        note a(ui->lineEdit->text());
        if(ui->comboBox->currentText() == "blue"){
            a.n->setStyleSheet("background-color: rgb(114, 159, 207);");
            a.s_note->setStyleSheet("background-color: rgb(114, 159, 207);");}
        else if(ui->comboBox->currentText() == "yellow"){
            a.n->setStyleSheet("background-color: rgb(233, 185, 110);");
            a.s_note->setStyleSheet("background-color: rgb(233, 185, 110);");}
        else if(ui->comboBox->currentText() == "purple"){
            a.n->setStyleSheet("background-color: rgb(173, 127, 168);");
            a.s_note->setStyleSheet("background-color: rgb(173, 127, 168);");}

        a.label->setStyleSheet("color:rgb(255, 255, 255); font:22px;");
        a.label->setText(a.label_name);
        a.txt->setStyleSheet("background: transparent; border:0px; color:rgb(46, 52, 54);");
        a.txt->setDisabled(true);
        a.txt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        a.txt_n->setStyleSheet("background: transparent; border:0px; color:rgb(46, 52, 54);");
        a.lab_n->setStyleSheet("color:rgb(255, 255, 255); font:22px;");
        a.lab_n->setText(a.label_name);
        a.find->setStyleSheet("background:white;color:rgb(46, 52, 54);");
        a.find->setPlaceholderText("Search word");

        a.m_searchHighLight = new SearchHighLight(a.txt_n->document());

        QFile text_ed("notes/"+ui->lineEdit->text()+".txt");
        QTextStream in(&text_ed);
        text_ed.open(QFile::ReadOnly);
        while (!in.atEnd()) {
            QString line = in.readLine();
            a.txt->setText(line);
            a.txt_n->setText(line);
        }
        text_ed.close();

        a.lay->addWidget(a.change, 0,1);
        a.lay->addWidget(a.label, 0,0);
        a.lay->addWidget(a.txt, 1,0,1,2);
        a.lay_n->addWidget(a.find, 0,0,1,2);
        a.lay_n->addWidget(a.search, 0, 2);
        a.lay_n->addWidget(a.lab_n, 1,0);
        a.lay_n->addWidget(a.txt_n, 2,0,1,3);
        a.lay_n->addWidget(a.can_n, 3,1);
        a.lay_n->addWidget(a.ok_n, 3,2);

        notes.push_front(a);
        add_notes();
    }
    ui->widget_2->close();
    ui->lineEdit->clear();

}
//////////////////////////////////////////////////ending of creating new note
void MainWindow::on_actionOpen_note_txt_triggered()
{
    QWidget *wid = new QWidget;
    wid->setGeometry(500, 225, 600, 500);
    QGridLayout *lay = new QGridLayout(wid);
    QComboBox *comb = new QComboBox;
    comb->addItem("yellow");
    comb->addItem("purple");
    comb->addItem("blue");
    QLabel *lab = new QLabel;
    QTextEdit *txt = new QTextEdit;
    txt->setReadOnly(true);
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *save = new QPushButton("save");
    lay->addWidget(lab,0,0);
    lay->addWidget(txt, 1, 0, 1, 3);
    lay->addWidget(cancel, 2, 1);
    lay->addWidget(save, 2, 2);
    lay->addWidget(comb, 2, 0);
    QString path = QFileDialog::getOpenFileName(this, "Open", "home/");
    QFileInfo fi(path);
    QString file_name = fi.fileName();
    int pos = file_name.lastIndexOf(QChar('.'));
    lab->setText(file_name);

    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        txt->setText(file.readAll());
        file.close();
    }
    else
        QMessageBox::warning(this, "Title", "Cannot open file");
    wid->show();

    connect(cancel, SIGNAL(clicked()), wid, SLOT(close()));
    connect(save, &QPushButton::clicked, [this, pos, comb, wid, file_name, txt]()
    {
        note op(file_name.left(pos));

        QFile names("notes/_names_.txt");
        QTextStream fil(&names);
        names.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
        fil << file_name.left((pos)) << "\n";
        fil << comb->currentText() << "\n";
        names.close();

        if(comb->currentText() == "blue"){
            op.n->setStyleSheet("background-color: rgb(114, 159, 207);");
            op.s_note->setStyleSheet("background-color: rgb(114, 159, 207);");}
        else if(comb->currentText() == "yellow"){
            op.n->setStyleSheet("background-color: rgb(233, 185, 110);");
            op.s_note->setStyleSheet("background-color: rgb(233, 185, 110);");}
        else if(comb->currentText() == "purple"){
            op.n->setStyleSheet("background-color: rgb(173, 127, 168);");
            op.s_note->setStyleSheet("background-color: rgb(173, 127, 168);");}
        op.label->setStyleSheet("color:rgb(255, 255, 255); font:22px;");
        op.txt->setStyleSheet("background: transparent; border:0px; color:rgb(46, 52, 54);");
        op.txt->setText(txt->toPlainText());
        op.txt->setDisabled(true);
        op.txt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        op.txt_n->setStyleSheet("background: transparent; border:0px; color:rgb(46, 52, 54);");
        op.lab_n->setStyleSheet("color:rgb(255, 255, 255); font:22px;");
        op.txt_n->setText(txt->toPlainText());
        op.lay->addWidget(op.change, 0,1);
        op.lay->addWidget(op.label, 0,0);
        op.lay->addWidget(op.txt, 1,0,1,2);
        op.lay_n->addWidget(op.find, 0,0,1,2);
        op.lay_n->addWidget(op.search, 0, 2);
        op.lay_n->addWidget(op.lab_n, 1,0);
        op.lay_n->addWidget(op.txt_n, 2,0,1,3);
        op.lay_n->addWidget(op.can_n, 3,1);
        op.lay_n->addWidget(op.ok_n, 3,2);
        op.find->setStyleSheet("background:white;color:rgb(46, 52, 54);");
        op.find->setPlaceholderText("Search word");

        op.m_searchHighLight = new SearchHighLight(op.txt_n->document());

        QFile f("notes/"+file_name);
        QTextStream out(&f);
        if(f.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            out << txt->toPlainText();
            f.close();
        }
        else
            QMessageBox::warning(this, "Title", "Cannot open file");
        notes.push_front(op);
        add_notes();
        wid->close();
    });
}

void MainWindow::on_actionPrint_triggered()
{
    QWidget *wid = new QWidget;
    wid->setGeometry(650, 370, 350, 120);
    QGridLayout *lay = new QGridLayout(wid);
    QLineEdit *line_edit = new QLineEdit;
    line_edit->setPlaceholderText("Enter title of existing note");
    wid->setFixedSize(350, 120);

    QTextEdit *textEdit = new QTextEdit;

    QPushButton *can = new QPushButton("cancel");
    QPushButton *print = new QPushButton("print");
    lay->addWidget(line_edit, 0,0,1,2);
    lay->addWidget(can, 1,0);
    lay->addWidget(print, 1,1);
    wid->show();
    connect(can, SIGNAL(clicked()), wid, SLOT(close()));
    connect(print, &QPushButton::clicked, [this, line_edit, textEdit, wid]()
    {
       QFile file("notes/"+line_edit->text()+".txt");
       if(file.open(QIODevice::ReadOnly|QIODevice::Text))
       {
           textEdit->setText(file.readAll());
           QPrinter printer;
           QPrintDialog dialog(&printer, this);
           dialog.setWindowTitle("Print Document");
           if(dialog.exec() == QDialog::Rejected)
               return;
           else
               textEdit->print(&printer);
           file.close();
       }
       else
           QMessageBox::warning(this, "Title", "There is no such note!");
       wid->close();
    });
}

void MainWindow::on_actionFont_style_3_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica[Cronyx]", 14), this);
    if(ok)
    {
        for(int i = 0; i < notes.size(); i++)
        {
            notes[i].txt->setFont(font);
            notes[i].label->setFont(font);
            notes[i].txt_n->setFont(font);
            notes[i].lab_n->setFont(font);
        }
    }
}

void MainWindow::on_actionFont_color_4_triggered()
{
    bool ok;
    QColor color = QColorDialog::getColor(Qt::yellow, this);
    if(&ok)
    {
        for(int i = 0; i < notes.size(); i++)
        {
            notes[i].txt->setTextColor(color);
            notes[i].txt_n->setTextColor(color);
        }
    }
}

void MainWindow::on_actionNote_color_triggered()
{
    QWidget *wid = new QWidget;
    wid->setGeometry(650, 370, 350, 120);
    QGridLayout *lay = new QGridLayout(wid);
    QComboBox *comb = new QComboBox;
    QPushButton *can = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    lay->addWidget(comb, 0, 0, 1, 3);
    lay->addWidget(can, 1, 1);
    lay->addWidget(ok, 1, 2);
    comb->addItem("Dark");
    comb->addItem("Bright-green");
    comb->addItem("Blue");
    wid->show();
    connect(can, SIGNAL(clicked()), wid, SLOT(close()));
    connect(ok, &QPushButton::clicked, [this, comb, wid]()
    {
        if(comb->currentText() == "Dark"){
            ui->centralwidget->setStyleSheet("background:rgb(33, 33, 42);");
            ui->menubar->setStyleSheet("color:rgb(255, 255, 255);background: rgb(40, 35, 62);");
            ui->menuFile->setStyleSheet("QMenu#menuFile{background-color:rgb(43, 42, 58); color:rgb(211, 215, 207);border: 0px;}""QMenu#menuFile::item:selected{background-color:#654321;color:rgb(243, 243, 243);}");
            ui->menuSearch->setStyleSheet("QMenu#menuSearch{background-color:rgb(43, 42, 58); color:rgb(211, 215, 207);border: 0px;}""QMenu#menuSearch::item:selected{background-color:#654321;color:rgb(243, 243, 243);}");
            ui->menuTools->setStyleSheet("QMenu#menuTools{background-color:rgb(43, 42, 58); color:rgb(211, 215, 207);border: 0px;}""QMenu#menuTools::item:selected{background-color:#654321;color:rgb(243, 243, 243);}");
            ui->widget->setStyleSheet("background:rgb(43, 42, 58);");
            ui->label->setStyleSheet("font: 22px;color:rgb(211, 215, 207);background: transparent;");
            ui->pushButton->setStyleSheet("QPushButton#pushButton{background: rgb(43,42,58); border: 0px; color:rgb(211, 215, 207);}""QPushButton#pushButton:hover{background: rgb(40, 35, 62);border: 0px;color:rgb(238, 238, 236);}""QPushButton#pushButton:hover:pressed{background:rgb(33, 33, 42);}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background: rgb(43,42,58); border: 0px; color:rgb(211, 215, 207);}""QPushButton#pushButton_2:hover{background: rgb(40, 35, 62);border: 0px;color:rgb(238, 238, 236);}""QPushButton#pushButton_2:hover:pressed{background:rgb(33, 33, 42);}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{background: rgb(43,42,58); border: 0px; color:rgb(211, 215, 207);}""QPushButton#pushButton_3:hover{background: rgb(40, 35, 62);border: 0px;color:rgb(238, 238, 236);}""QPushButton#pushButton_3:hover:pressed{background:rgb(33, 33, 42);}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{background: rgb(43,42,58); border: 0px; color:rgb(211, 215, 207);}""QPushButton#pushButton_4:hover{background: rgb(40, 35, 62);border: 0px;color:rgb(238, 238, 236);}""QPushButton#pushButton_4:hover:pressed{background:rgb(47, 18, 69);}");
            ui->widget_2->setStyleSheet("QWidget#widget_2{background:rgb(46, 52, 54);border-radius:20px;}");
            ui->lineEdit->setStyleSheet("QLineEdit#lineEdit{background:rgb(211, 215, 207);color:rgb(46, 52, 54);}");
            ui->comboBox->setStyleSheet("QComboBox#comboBox{color:rgb(211, 215, 207);selection-color: rgb(193, 125, 17);selection-background-color: rgb(43, 42, 58);}");
            ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5 {background:rgb(85, 87, 83);color:rgb(211, 215, 207);}""QPushButton#pushButton_5:hover{background:rgb(46, 52, 54);color:rgb(211, 215, 207);}");
            ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6 {background:rgb(85, 87, 83);color:rgb(211, 215, 207);}""QPushButton#pushButton_6:hover{background:rgb(46, 52, 54);color:rgb(211, 215, 207);}");
        }
        else if(comb->currentText() == "Blue")
        {
            ui->centralwidget->setStyleSheet("background:rgb(60, 176, 198)");
            ui->menubar->setStyleSheet("color:rgb(255, 255, 255);background:rgb(65, 232, 226);");
            ui->menuFile->setStyleSheet("QMenu#menuFile{background-color:rgb(59, 209, 219);color:rgb(255, 255, 255);border: 0px;}""QMenu#menuFile::item:selected{background-color: rgb(243, 243, 243);color:rgb(46, 52, 54);}");
            ui->menuSearch->setStyleSheet("QMenu#menuSearch{background-color:rgb(59, 209, 219);color:rgb(255, 255, 255);border: 0px;}""QMenu#menuSearch::item:selected{background-color: rgb(243, 243, 243);color:rgb(46, 52, 54);}");
            ui->menuTools->setStyleSheet("QMenu#menuTools{background-color:rgb(59, 209, 219);color:rgb(255, 255, 255);border: 0px;}""QMenu#menuTools::item:selected{background-color: rgb(243, 243, 243);color:rgb(46, 52, 54);}");
            ui->widget->setStyleSheet("background: rgb(28, 208, 248);");
            ui->label->setStyleSheet("font: 22px;color:rgb(238, 238, 236);background: transparent;");
            ui->pushButton->setStyleSheet("QPushButton#pushButton{background:rgb(28, 208, 248);border: 0px;color:rgb(243, 243, 243);}""QPushButton#pushButton:hover{background:rgb(186, 189, 182);border: 0px;color:rgb(255, 255, 255);}""QPushButton#pushButton:hover:pressed{background:rgb(65, 232, 226);color:rgb(255, 255, 255);}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background:rgb(28, 208, 248);border: 0px;color:rgb(243, 243, 243);}""QPushButton#pushButton_2:hover{background:rgb(186, 189, 182);border: 0px;color:rgb(255, 255, 255);}""QPushButton#pushButton_2:hover:pressed{background:rgb(65, 232, 226);color:rgb(255, 255, 255);}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{background:rgb(28, 208, 248);border: 0px;color:rgb(243, 243, 243);}""QPushButton#pushButton_3:hover{background:rgb(186, 189, 182);border: 0px;color:rgb(255, 255, 255);}""QPushButton#pushButton_3:hover:pressed{background:rgb(65, 232, 226);color:rgb(255, 255, 255);}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{background:rgb(67, 145, 183);border: 0px;color:rgb(243, 243, 243);}""QPushButton#pushButton_4:hover{background:rgb(186, 189, 182);border: 0px;color:rgb(255, 255, 255);}""QPushButton#pushButton_4:hover:pressed{background:rgb(65, 232, 226);color:rgb(255, 255, 255);}");
            ui->widget_2->setStyleSheet("QWidget#widget_2{background:rgb(61, 151, 207);border-radius:20px;}");
            ui->lineEdit->setStyleSheet("QLineEdit#lineEdit{background:rgb(255, 255, 255);color:rgb(46, 52, 54);}");
            ui->comboBox->setStyleSheet("QComboBox#comboBox{background:white;color:rgb(46, 52, 54);selection-color: rgb(193, 125, 17);selection-background-color: rgb(182, 219, 192);}");
            ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5 {background:rgb(238, 238, 236);color:rgb(46, 52, 54);}""QPushButton#pushButton_5:hover{background:rgb(46, 52, 54);color:rgb(211, 215, 207);}");
            ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6 {background:rgb(238, 238, 236);color:rgb(46, 52, 54);}""QPushButton#pushButton_6:hover{background:rgb(186, 189, 182);color:rgb(255, 255, 255);}");
        }
        else if(comb->currentText() == "Bright-green")
        {
            ui->centralwidget->setStyleSheet("background: rgb(211, 215, 207);");
            ui->menubar->setStyleSheet("color:rgb(31, 33, 40);background:rgb(182, 219, 192);");
            ui->menuFile->setStyleSheet("QMenu#menuFile{background-color:rgb(211, 215, 207); color:rgb(46, 52, 54);border: 0px;}""QMenu#menuFile::item:selected{background-color: rgb(182, 219, 192);color:rgb(243, 243, 243);}");
            ui->menuSearch->setStyleSheet("QMenu#menuSearch{background-color:rgb(211, 215, 207); color:rgb(46, 52, 54);border: 0px;}""QMenu#menuSearch::item:selected{background-color: rgb(182, 219, 192);color:rgb(243, 243, 243);}");
            ui->menuTools->setStyleSheet("QMenu#menuTools{background-color:rgb(211, 215, 207); color:rgb(46, 52, 54);border: 0px;}""QMenu#menuTools::item:selected{background-color: rgb(182, 219, 192);color:rgb(243, 243, 243);}");
            ui->widget->setStyleSheet("background: rgb(143, 166, 148);");
            ui->label->setStyleSheet("font: 22px;color:rgb(211, 215, 207);background: transparent;");
            ui->pushButton->setStyleSheet("QPushButton#pushButton{background:rgb(143, 166, 148); border: 0px; color:rgb(255, 255, 255);}""QPushButton#pushButton:hover{background:rgb(176, 207, 190);border: 0px;color:rgb(85, 87, 83);}""QPushButton#pushButton:hover:pressed{background:rgb(211, 215, 207);}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background: rgb(143, 166, 148); border: 0px; color:rgb(255, 255, 255);}""QPushButton#pushButton_2:hover{background:rgb(176, 207, 190);border: 0px;color:rgb(85, 87, 83);}""QPushButton#pushButton_2:hover:pressed{background:rgb(211, 215, 207);}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{background: rgb(143, 166, 148); border: 0px; color:rgb(255, 255, 255);}""QPushButton#pushButton_3:hover{background:rgb(176, 207, 190);border: 0px;color:rgb(85, 87, 83);}""QPushButton#pushButton_3:hover:pressed{background:rgb(211, 215, 207);}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{background: rgb(143, 166, 148); border: 0px; color:rgb(255, 255, 255);}""QPushButton#pushButton_4:hover{background:rgb(176, 207, 190);border: 0px;color:rgb(85, 87, 83);}""QPushButton#pushButton_4:hover:pressed{background:rgb(182, 219, 192);}");
            ui->widget_2->setStyleSheet("QWidget#widget_2{background:rgb(143, 166, 148);border-radius:20px;}");
            ui->lineEdit->setStyleSheet("QLineEdit#lineEdit{background:rgb(211, 215, 207);color:rgb(85, 87, 83);}");
            ui->comboBox->setStyleSheet("QComboBox#comboBox{color:rgb(85, 87, 83);selection-color: rgb(238, 238, 236);selection-background-color: rgb(182, 219, 192);}");
            ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5 {background:rgb(186, 189, 182);color:rgb(85, 87, 83);}""QPushButton#pushButton_5:hover{background:rgb(238, 238, 236);color:rgb(85, 87, 83);}");
            ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6 {background:rgb(186, 189, 182);color:rgb(85, 87, 83);}""QPushButton#pushButton_6:hover{background:rgb(238, 238, 236);color:rgb(85, 87, 83);}");
        }
        wid->close();
    });
}

void MainWindow::on_actionSearch_note_triggered()
{
    QWidget *search = new QWidget;
    QGridLayout *lay = new QGridLayout(search);
    QLineEdit *line = new QLineEdit;
    QPushButton *can = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    line->setPlaceholderText("search");
    lay->addWidget(line, 0,0,1,2);
    lay->addWidget(can, 1,0);
    lay->addWidget(ok, 1,1);
    search->setGeometry(650, 370, 350, 120);
    search->show();

    connect(can, SIGNAL(clicked()), search, SLOT(close()));
    connect(ok, &QPushButton::clicked, [this, line, search](){
        for(int j = 0; j<notes.size(); j++)
        {
            ui->gridLayout_6->removeWidget(notes[j].s_note);
            notes[j].s_note->hide();
        }
        for(int i = 0; i<notes.size(); i++)
        {
            if(line->text() == notes[i].label_name)
            {
                ui->gridLayout_6->addWidget(notes[i].s_note);
                notes[i].s_note->show();
                break;
            }
        }
        search->close();
    });
}

void MainWindow::on_pushButton_clicked()//home  button to show all notes
{
    for(int h = 0; h<notes.size(); h++)
    {
        ui->gridLayout_6->removeWidget(notes[h].s_note);
        notes[h].s_note->hide();
    }
    int index = 0;
    for(int i=0; i < ((notes.size()/3) + 1) ; i++)
    {
        for(int j=0; j<3;j++)
        {
            if(index == notes.size())
                break;
            else{
                ui->gridLayout_6->addWidget(notes[index].s_note, i,j);
                notes[index].s_note->show();
                index++;
                }
        }
    }
}

void MainWindow::on_pushButton_2_clicked()//search button to show only searched note
{
    QWidget *search = new QWidget;
    QGridLayout *lay = new QGridLayout(search);
    QLineEdit *line = new QLineEdit;
    QPushButton *can = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    line->setPlaceholderText("search");
    lay->addWidget(line, 0,0,1,2);
    lay->addWidget(can, 1,0);
    lay->addWidget(ok, 1,1);
    search->setGeometry(650, 370, 350, 120);
    search->show();

    connect(can, SIGNAL(clicked()), search, SLOT(close()));
    connect(ok, &QPushButton::clicked, [this, line, search](){
        for(int j = 0; j<notes.size(); j++)
        {
            ui->gridLayout_6->removeWidget(notes[j].s_note);
            notes[j].s_note->hide();
        }
        for(int i = 0; i<notes.size(); i++)
        {
            if(line->text() == notes[i].label_name)
            {
                ui->gridLayout_6->addWidget(notes[i].s_note);
                notes[i].s_note->show();
                break;
            }
        }
        search->close();
    });
}

void MainWindow::on_pushButton_4_clicked()//add note
{
    ui->widget_2->show();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_3_clicked()// EXIT#2
{
    QApplication::quit();
}
