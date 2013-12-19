/********************************************************************************
** Form generated from reading UI file 'mapform.ui'
**
** Created: Wed Dec 18 20:32:49 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPFORM_H
#define UI_MAPFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapForm
{
public:
    QSplitter *splitter;
    QPushButton *PBtn_Start;
    QPushButton *PBtn_Destination;

    void setupUi(QWidget *MapForm)
    {
        if (MapForm->objectName().isEmpty())
            MapForm->setObjectName(QString::fromUtf8("MapForm"));
        MapForm->resize(480, 272);
        MapForm->setMinimumSize(QSize(480, 272));
        MapForm->setMaximumSize(QSize(480, 272));
        splitter = new QSplitter(MapForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 230, 61, 41));
        splitter->setOrientation(Qt::Vertical);
        PBtn_Start = new QPushButton(splitter);
        PBtn_Start->setObjectName(QString::fromUtf8("PBtn_Start"));
        PBtn_Start->setIconSize(QSize(10, 10));
        splitter->addWidget(PBtn_Start);
        PBtn_Destination = new QPushButton(splitter);
        PBtn_Destination->setObjectName(QString::fromUtf8("PBtn_Destination"));
        PBtn_Destination->setIconSize(QSize(10, 10));
        splitter->addWidget(PBtn_Destination);

        retranslateUi(MapForm);

        QMetaObject::connectSlotsByName(MapForm);
    } // setupUi

    void retranslateUi(QWidget *MapForm)
    {
        MapForm->setWindowTitle(QApplication::translate("MapForm", "Map", 0, QApplication::UnicodeUTF8));
        PBtn_Start->setText(QApplication::translate("MapForm", "Start", 0, QApplication::UnicodeUTF8));
        PBtn_Destination->setText(QApplication::translate("MapForm", "Des", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapForm: public Ui_MapForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPFORM_H
