/********************************************************************************
** Form generated from reading UI file 'archivemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVEMANAGER_H
#define UI_ARCHIVEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArchiveManager
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *createBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *startBtn;
    QPushButton *editBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *ArchiveManager)
    {
        if (ArchiveManager->objectName().isEmpty())
            ArchiveManager->setObjectName(QStringLiteral("ArchiveManager"));
        ArchiveManager->resize(1920, 1080);
        ArchiveManager->setStyleSheet(QLatin1String("QDialog#ArchiveManager{\n"
"border-image: url(:/lancher/image/background_hit.jpg);\n"
"}"));
        widget = new QWidget(ArchiveManager);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 1899, 264));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(448, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        createBtn = new QPushButton(widget);
        createBtn->setObjectName(QStringLiteral("createBtn"));
        createBtn->setMinimumSize(QSize(700, 80));
        createBtn->setMaximumSize(QSize(700, 80));
        createBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        horizontalLayout->addWidget(createBtn);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitBtn = new QPushButton(widget);
        quitBtn->setObjectName(QStringLiteral("quitBtn"));
        quitBtn->setMinimumSize(QSize(200, 80));
        quitBtn->setMaximumSize(QSize(200, 80));
        quitBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        horizontalLayout->addWidget(quitBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        widget1 = new QWidget(ArchiveManager);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 300, 1908, 770));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget1);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(960, 540));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 958, 538));
        startBtn = new QPushButton(scrollAreaWidgetContents);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(100, 30, 620, 60));
        startBtn->setMinimumSize(QSize(620, 60));
        startBtn->setMaximumSize(QSize(620, 60));
        startBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));
        editBtn = new QPushButton(scrollAreaWidgetContents);
        editBtn->setObjectName(QStringLiteral("editBtn"));
        editBtn->setGeometry(QRect(770, 30, 120, 60));
        editBtn->setMinimumSize(QSize(120, 60));
        editBtn->setMaximumSize(QSize(120, 60));
        editBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 1, 2, 1);

        horizontalSpacer_5 = new QSpacerItem(468, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 218, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(ArchiveManager);

        QMetaObject::connectSlotsByName(ArchiveManager);
    } // setupUi

    void retranslateUi(QDialog *ArchiveManager)
    {
        ArchiveManager->setWindowTitle(QApplication::translate("ArchiveManager", "Dialog", nullptr));
        createBtn->setText(QApplication::translate("ArchiveManager", "Create", nullptr));
        quitBtn->setText(QApplication::translate("ArchiveManager", "Quit", nullptr));
        startBtn->setText(QString());
        editBtn->setText(QApplication::translate("ArchiveManager", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArchiveManager: public Ui_ArchiveManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVEMANAGER_H
