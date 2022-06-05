#include "new_note.h"
#include "ui_new_note.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
new_note::new_note(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_note)
{
    ui->setupUi(this);

}

new_note::~new_note()
{
    delete ui;
}

void new_note::on_pushButton_clicked()
{
   QFile file("notes/"+title+".txt");
   if(file.open(QFile::WriteOnly|QFile::Text|QFile::Append))
   {
       QTextStream out(&file);
       out<<ui->textEdit->toPlainText();
       file.flush();
       file.close();

   }
   else
       QMessageBox::warning(this, "Warning!", "File was not created, try again");
   close();
}
