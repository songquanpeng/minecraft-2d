/********************************************************************************
** Form generated from reading UI file 'worldeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORLDEDITDIALOG_H
#define UI_WORLDEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WorldEditDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteBtn;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *WorldEditDialog)
    {
        if (WorldEditDialog->objectName().isEmpty())
            WorldEditDialog->setObjectName(QStringLiteral("WorldEditDialog"));
        WorldEditDialog->resize(500, 300);
        WorldEditDialog->setStyleSheet(QLatin1String("#WorldEditDialog{\n"
"border-image: url(:/lancher/image/dialog.png);\n"
"}"));
        gridLayout = new QGridLayout(WorldEditDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(WorldEditDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(221, 31));
        lineEdit->setMaximumSize(QSize(221, 31));
        lineEdit->setStyleSheet(QStringLiteral("font: 9pt \"Georgia\";"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        deleteBtn = new QPushButton(WorldEditDialog);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setMinimumSize(QSize(231, 41));
        deleteBtn->setMaximumSize(QSize(231, 41));
        deleteBtn->setStyleSheet(QLatin1String("border-image: url(:/lancher/image/button3.PNG);\n"
"color: rgb(255, 0, 0);\n"
"font: 14pt \"Geogia\";"));

        verticalLayout->addWidget(deleteBtn);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okBtn = new QPushButton(WorldEditDialog);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setMinimumSize(QSize(93, 28));
        okBtn->setMaximumSize(QSize(93, 28));
        okBtn->setStyleSheet(QLatin1String("border-image: url(:/lancher/image/button3.PNG);\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 14pt \"Geogia\";"));

        horizontalLayout->addWidget(okBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelBtn = new QPushButton(WorldEditDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(93, 28));
        cancelBtn->setMaximumSize(QSize(93, 28));
        cancelBtn->setStyleSheet(QLatin1String("border-image: url(:/lancher/image/button3.PNG);\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 14pt \"Geogia\";"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(WorldEditDialog);
        QObject::connect(cancelBtn, SIGNAL(clicked()), WorldEditDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(WorldEditDialog);
    } // setupUi

    void retranslateUi(QDialog *WorldEditDialog)
    {
        WorldEditDialog->setWindowTitle(QApplication::translate("WorldEditDialog", "Dialog", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("WorldEditDialog", "Input new name here.", nullptr));
        deleteBtn->setText(QApplication::translate("WorldEditDialog", "Delete this world!", nullptr));
        okBtn->setText(QApplication::translate("WorldEditDialog", "OK", nullptr));
        cancelBtn->setText(QApplication::translate("WorldEditDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorldEditDialog: public Ui_WorldEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORLDEDITDIALOG_H
