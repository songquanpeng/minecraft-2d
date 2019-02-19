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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *createBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QPushButton *startBtn;
    QPushButton *editBtn;
    QPushButton *startBtn_2;
    QPushButton *editBtn_2;
    QPushButton *startBtn_3;
    QPushButton *editBtn_3;
    QPushButton *startBtn_4;
    QPushButton *editBtn_4;
    QPushButton *startBtn_5;
    QPushButton *editBtn_5;

    void setupUi(QDialog *ArchiveManager)
    {
        if (ArchiveManager->objectName().isEmpty())
            ArchiveManager->setObjectName(QStringLiteral("ArchiveManager"));
        ArchiveManager->resize(1920, 1080);
        ArchiveManager->setStyleSheet(QLatin1String("QDialog#ArchiveManager{\n"
"border-image: url(:/lancher/image/background_hit.jpg);\n"
"}"));
        layoutWidget = new QWidget(ArchiveManager);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1899, 264));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(448, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        createBtn = new QPushButton(layoutWidget);
        createBtn->setObjectName(QStringLiteral("createBtn"));
        createBtn->setEnabled(false);
        createBtn->setMinimumSize(QSize(700, 80));
        createBtn->setMaximumSize(QSize(700, 80));
        createBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        horizontalLayout->addWidget(createBtn);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitBtn = new QPushButton(layoutWidget);
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

        layoutWidget1 = new QWidget(ArchiveManager);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 300, 1908, 770));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(468, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 218, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);

        scrollArea = new QScrollArea(layoutWidget1);
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
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        startBtn = new QPushButton(scrollAreaWidgetContents);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setMinimumSize(QSize(620, 60));
        startBtn->setMaximumSize(QSize(620, 60));
        startBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(startBtn, 0, 0, 1, 1);

        editBtn = new QPushButton(scrollAreaWidgetContents);
        editBtn->setObjectName(QStringLiteral("editBtn"));
        editBtn->setMinimumSize(QSize(120, 60));
        editBtn->setMaximumSize(QSize(120, 60));
        editBtn->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(editBtn, 0, 1, 1, 1);

        startBtn_2 = new QPushButton(scrollAreaWidgetContents);
        startBtn_2->setObjectName(QStringLiteral("startBtn_2"));
        startBtn_2->setMinimumSize(QSize(620, 60));
        startBtn_2->setMaximumSize(QSize(620, 60));
        startBtn_2->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(startBtn_2, 1, 0, 1, 1);

        editBtn_2 = new QPushButton(scrollAreaWidgetContents);
        editBtn_2->setObjectName(QStringLiteral("editBtn_2"));
        editBtn_2->setMinimumSize(QSize(120, 60));
        editBtn_2->setMaximumSize(QSize(120, 60));
        editBtn_2->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(editBtn_2, 1, 1, 1, 1);

        startBtn_3 = new QPushButton(scrollAreaWidgetContents);
        startBtn_3->setObjectName(QStringLiteral("startBtn_3"));
        startBtn_3->setMinimumSize(QSize(620, 60));
        startBtn_3->setMaximumSize(QSize(620, 60));
        startBtn_3->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(startBtn_3, 2, 0, 1, 1);

        editBtn_3 = new QPushButton(scrollAreaWidgetContents);
        editBtn_3->setObjectName(QStringLiteral("editBtn_3"));
        editBtn_3->setMinimumSize(QSize(120, 60));
        editBtn_3->setMaximumSize(QSize(120, 60));
        editBtn_3->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(editBtn_3, 2, 1, 1, 1);

        startBtn_4 = new QPushButton(scrollAreaWidgetContents);
        startBtn_4->setObjectName(QStringLiteral("startBtn_4"));
        startBtn_4->setMinimumSize(QSize(620, 60));
        startBtn_4->setMaximumSize(QSize(620, 60));
        startBtn_4->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(startBtn_4, 3, 0, 1, 1);

        editBtn_4 = new QPushButton(scrollAreaWidgetContents);
        editBtn_4->setObjectName(QStringLiteral("editBtn_4"));
        editBtn_4->setMinimumSize(QSize(120, 60));
        editBtn_4->setMaximumSize(QSize(120, 60));
        editBtn_4->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(editBtn_4, 3, 1, 1, 1);

        startBtn_5 = new QPushButton(scrollAreaWidgetContents);
        startBtn_5->setObjectName(QStringLiteral("startBtn_5"));
        startBtn_5->setMinimumSize(QSize(620, 60));
        startBtn_5->setMaximumSize(QSize(620, 60));
        startBtn_5->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(startBtn_5, 4, 0, 1, 1);

        editBtn_5 = new QPushButton(scrollAreaWidgetContents);
        editBtn_5->setObjectName(QStringLiteral("editBtn_5"));
        editBtn_5->setMinimumSize(QSize(120, 60));
        editBtn_5->setMaximumSize(QSize(120, 60));
        editBtn_5->setStyleSheet(QLatin1String("background-color: rgba(0, 255, 127,100);\n"
"font: 75 18pt \"Georgia\";"));

        gridLayout_3->addWidget(editBtn_5, 4, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 1, 2, 1);


        retranslateUi(ArchiveManager);

        QMetaObject::connectSlotsByName(ArchiveManager);
    } // setupUi

    void retranslateUi(QDialog *ArchiveManager)
    {
        ArchiveManager->setWindowTitle(QApplication::translate("ArchiveManager", "Dialog", nullptr));
        createBtn->setText(QApplication::translate("ArchiveManager", "Have Fun\357\274\201", nullptr));
        quitBtn->setText(QApplication::translate("ArchiveManager", "Quit", nullptr));
        startBtn->setText(QString());
        editBtn->setText(QApplication::translate("ArchiveManager", "Edit", nullptr));
        startBtn_2->setText(QString());
        editBtn_2->setText(QApplication::translate("ArchiveManager", "Edit", nullptr));
        startBtn_3->setText(QString());
        editBtn_3->setText(QApplication::translate("ArchiveManager", "Edit", nullptr));
        startBtn_4->setText(QString());
        editBtn_4->setText(QApplication::translate("ArchiveManager", "Edit", nullptr));
        startBtn_5->setText(QString());
        editBtn_5->setText(QApplication::translate("ArchiveManager", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArchiveManager: public Ui_ArchiveManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVEMANAGER_H
