/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *okBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(667, 485);
        About->setMinimumSize(QSize(667, 485));
        About->setMaximumSize(QSize(667, 485));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lancher/image/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        About->setWindowIcon(icon);
        About->setStyleSheet(QStringLiteral("border-image: url(:/lancher/image/dialog.png);"));
        gridLayout = new QGridLayout(About);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(About);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(551, 291));
        textBrowser->setMaximumSize(QSize(551, 291));
        textBrowser->setStyleSheet(QStringLiteral("border-image: url(:/lancher/image/textView.png);"));

        gridLayout->addWidget(textBrowser, 1, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        okBtn = new QPushButton(About);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setMinimumSize(QSize(551, 81));
        okBtn->setMaximumSize(QSize(551, 81));
        okBtn->setCursor(QCursor(Qt::PointingHandCursor));
        okBtn->setStyleSheet(QLatin1String("border-image: url(:/lancher/image/button2.png);\n"
"font: 75 20pt \"Georgia\";"));

        gridLayout->addWidget(okBtn, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);


        retranslateUi(About);
        QObject::connect(okBtn, SIGNAL(released()), About, SLOT(close()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Form", nullptr));
        textBrowser->setHtml(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213"
                        "\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0p"
                        "x;\"><span style=\" font-size:16pt; font-weight:600;\">\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227\346\265\213\350\257\225\346\226\207\345\255\227</span></p></body></html>", nullptr));
        okBtn->setText(QApplication::translate("About", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
