/********************************************************************************
** Form generated from reading UI file 'new_note.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_NOTE_H
#define UI_NEW_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_new_note
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *new_note)
    {
        if (new_note->objectName().isEmpty())
            new_note->setObjectName(QString::fromUtf8("new_note"));
        new_note->resize(793, 564);
        new_note->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background:rgb(46, 52, 54);\n"
"}\n"
"QTextEdit{\n"
"color:rgb(186, 189, 182);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(new_note);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(new_note);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        pushButton = new QPushButton(new_note);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(new_note);

        QMetaObject::connectSlotsByName(new_note);
    } // setupUi

    void retranslateUi(QDialog *new_note)
    {
        new_note->setWindowTitle(QApplication::translate("new_note", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("new_note", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_note: public Ui_new_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_NOTE_H
