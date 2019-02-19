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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ArchiveManager
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *renameBtn;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resetBtn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *quitBtn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ArchiveManager)
    {
        if (ArchiveManager->objectName().isEmpty())
            ArchiveManager->setObjectName(QStringLiteral("ArchiveManager"));
        ArchiveManager->resize(1920, 1080);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lancher/image/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArchiveManager->setWindowIcon(icon);
        ArchiveManager->setStyleSheet(QLatin1String("QDialog#ArchiveManager{\n"
"border-image: url(:/lancher/image/background_hit.jpg);\n"
"}"));
        gridLayout = new QGridLayout(ArchiveManager);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 328, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(459, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(ArchiveManager);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 80));
        lineEdit->setMaximumSize(QSize(300, 80));
        lineEdit->setStyleSheet(QLatin1String("font: 18pt \"Georgia\";\n"
"background-color: rgba(0, 255, 0, 100);"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        renameBtn = new QPushButton(ArchiveManager);
        renameBtn->setObjectName(QStringLiteral("renameBtn"));
        renameBtn->setMinimumSize(QSize(150, 80));
        renameBtn->setMaximumSize(QSize(150, 80));
        renameBtn->setStyleSheet(QLatin1String("font: 18pt \"Georgia\";\n"
"background-color: rgba(0, 255, 0, 100);"));

        horizontalLayout->addWidget(renameBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(ArchiveManager);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimumSize(QSize(300, 80));
        spinBox->setMaximumSize(QSize(300, 80));
        spinBox->setStyleSheet(QLatin1String("font: 18pt \"Georgia\";\n"
"background-color: rgba(0, 255, 0, 100);"));
        spinBox->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        resetBtn = new QPushButton(ArchiveManager);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        resetBtn->setMinimumSize(QSize(150, 80));
        resetBtn->setMaximumSize(QSize(150, 80));
        resetBtn->setStyleSheet(QLatin1String("font: 18pt \"Georgia\";\n"
"color: rgb(255, 0, 0);\n"
"background-color: rgba(0, 255, 0, 100);"));

        horizontalLayout_2->addWidget(resetBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        startBtn = new QPushButton(ArchiveManager);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setMinimumSize(QSize(300, 80));
        startBtn->setMaximumSize(QSize(300, 80));
        startBtn->setStyleSheet(QLatin1String("font: 18pt \"Georgia\";\n"
"background-color: rgba(0, 255, 0, 100);\n"
""));

        horizontalLayout_3->addWidget(startBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        quitBtn = new QPushButton(ArchiveManager);
        quitBtn->setObjectName(QStringLiteral("quitBtn"));
        quitBtn->setMinimumSize(QSize(150, 80));
        quitBtn->setMaximumSize(QSize(150, 80));
        quitBtn->setStyleSheet(QLatin1String("font: 18pt \"Georgia\";\n"
"background-color: rgba(0, 255, 0, 100);"));

        horizontalLayout_3->addWidget(quitBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(908, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(ArchiveManager);
        QObject::connect(quitBtn, SIGNAL(clicked()), ArchiveManager, SLOT(close()));

        QMetaObject::connectSlotsByName(ArchiveManager);
    } // setupUi

    void retranslateUi(QDialog *ArchiveManager)
    {
        ArchiveManager->setWindowTitle(QApplication::translate("ArchiveManager", "Dialog", nullptr));
        lineEdit->setText(QString());
        renameBtn->setText(QApplication::translate("ArchiveManager", "Rename", nullptr));
        resetBtn->setText(QApplication::translate("ArchiveManager", "Reset", nullptr));
        startBtn->setText(QApplication::translate("ArchiveManager", "Start Game", nullptr));
        quitBtn->setText(QApplication::translate("ArchiveManager", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArchiveManager: public Ui_ArchiveManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVEMANAGER_H
