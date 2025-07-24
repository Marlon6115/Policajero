/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *nombreEdit;
    QLabel *label_2;
    QLineEdit *cantidadEdit;
    QLabel *label_3;
    QLineEdit *precioEdit;
    QPushButton *crearButton;
    QPushButton *actualizarButton;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 51, 16));
        nombreEdit = new QLineEdit(centralwidget);
        nombreEdit->setObjectName("nombreEdit");
        nombreEdit->setGeometry(QRect(100, 10, 191, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 10, 61, 16));
        cantidadEdit = new QLineEdit(centralwidget);
        cantidadEdit->setObjectName("cantidadEdit");
        cantidadEdit->setGeometry(QRect(360, 10, 61, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(430, 10, 51, 16));
        precioEdit = new QLineEdit(centralwidget);
        precioEdit->setObjectName("precioEdit");
        precioEdit->setGeometry(QRect(470, 10, 81, 20));
        crearButton = new QPushButton(centralwidget);
        crearButton->setObjectName("crearButton");
        crearButton->setGeometry(QRect(570, 10, 91, 31));
        actualizarButton = new QPushButton(centralwidget);
        actualizarButton->setObjectName("actualizarButton");
        actualizarButton->setEnabled(false);
        actualizarButton->setGeometry(QRect(570, 47, 91, 31));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 100, 611, 192));
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->setColumnCount(4);
        MainWindow->setCentralWidget(centralwidget);
        cantidadEdit->raise();
        nombreEdit->raise();
        label_3->raise();
        precioEdit->raise();
        crearButton->raise();
        actualizarButton->raise();
        label->raise();
        label_2->raise();
        tableWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 700, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Agregar Productos", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Nombre:</p></body></html>", nullptr));
        nombreEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Cantidad:", nullptr));
        cantidadEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Precio:", nullptr));
        precioEdit->setText(QString());
        crearButton->setText(QCoreApplication::translate("MainWindow", "Crear", nullptr));
        actualizarButton->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", " C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Cantidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Precio C/U", nullptr));
#if QT_CONFIG(tooltip)
        tableWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>    // Variable para la fila seleccionada</p><p>    int selectedRow = -1;</p><p><br/></p><p>    // Generador de c\303\263digo aleatorio</p><p>    auto generarCodigo = []() {</p><p>        return &quot;P&quot; + QString::number(QRandomGenerator::global()-&gt;bounded(1000, 9999));</p><p>    };</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
