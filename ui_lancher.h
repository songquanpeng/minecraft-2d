/********************************************************************************
** Form generated from reading UI file 'lancher.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANCHER_H
#define UI_LANCHER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lancher
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *startBtn;
    QPushButton *aboutBtn;
    QPushButton *settingBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Lancher)
    {
        if (Lancher->objectName().isEmpty())
            Lancher->setObjectName(QStringLiteral("Lancher"));
        Lancher->resize(800, 500);
        Lancher->setMinimumSize(QSize(800, 500));
        Lancher->setMaximumSize(QSize(800, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lancher/image/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Lancher->setWindowIcon(icon);
        Lancher->setLayoutDirection(Qt::LeftToRight);
        Lancher->setStyleSheet(QLatin1String("QWidget#Lancher{\n"
"    border-image: url(:/lancher/image/background.png);\n"
"}"));
        gridLayout = new QGridLayout(Lancher);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(222, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(Lancher);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(311, 100));
        label->setMaximumSize(QSize(311, 16777215));
        label->setStyleSheet(QLatin1String("font: 75 22pt \"Georgia\";\n"
"color: rgb(255, 255, 255);\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        startBtn = new QPushButton(Lancher);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setMinimumSize(QSize(311, 71));
        startBtn->setMaximumSize(QSize(311, 71));
        startBtn->setCursor(QCursor(Qt::PointingHandCursor));
        startBtn->setStyleSheet(QLatin1String("font: 12pt \"Georgia\";\n"
"background-image: url(:/lancher/image/button.png);"));

        verticalLayout->addWidget(startBtn);

        aboutBtn = new QPushButton(Lancher);
        aboutBtn->setObjectName(QStringLiteral("aboutBtn"));
        aboutBtn->setMinimumSize(QSize(311, 71));
        aboutBtn->setMaximumSize(QSize(311, 71));
        aboutBtn->setCursor(QCursor(Qt::PointingHandCursor));
        aboutBtn->setStyleSheet(QLatin1String("font: 12pt \"Georgia\";\n"
"background-image: url(:/lancher/image/button.png);"));

        verticalLayout->addWidget(aboutBtn);

        settingBtn = new QPushButton(Lancher);
        settingBtn->setObjectName(QStringLiteral("settingBtn"));
        settingBtn->setMinimumSize(QSize(311, 71));
        settingBtn->setMaximumSize(QSize(311, 71));
        settingBtn->setCursor(QCursor(Qt::PointingHandCursor));
        settingBtn->setStyleSheet(QLatin1String("font: 12pt \"Georgia\";\n"
"background-image: url(:/lancher/image/button.png);"));

        verticalLayout->addWidget(settingBtn);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(221, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(Lancher);

        QMetaObject::connectSlotsByName(Lancher);
    } // setupUi

    void retranslateUi(QWidget *Lancher)
    {
        Lancher->setWindowTitle(QApplication::translate("Lancher", "Lancher", nullptr));
        label->setText(QApplication::translate("Lancher", "MineCraft", nullptr));
        startBtn->setText(QApplication::translate("Lancher", "Start Game", nullptr));
        aboutBtn->setText(QApplication::translate("Lancher", "About", nullptr));
        settingBtn->setText(QApplication::translate("Lancher", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lancher: public Ui_Lancher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANCHER_H
