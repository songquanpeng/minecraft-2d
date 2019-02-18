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

QT_BEGIN_NAMESPACE

class Ui_ArchiveManager
{
public:

    void setupUi(QDialog *ArchiveManager)
    {
        if (ArchiveManager->objectName().isEmpty())
            ArchiveManager->setObjectName(QStringLiteral("ArchiveManager"));
        ArchiveManager->resize(400, 300);

        retranslateUi(ArchiveManager);

        QMetaObject::connectSlotsByName(ArchiveManager);
    } // setupUi

    void retranslateUi(QDialog *ArchiveManager)
    {
        ArchiveManager->setWindowTitle(QApplication::translate("ArchiveManager", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArchiveManager: public Ui_ArchiveManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVEMANAGER_H
