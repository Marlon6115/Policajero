#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDate>
#include <QCoreApplication>
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->dateEdit->setDate(QDate::currentDate());

    connect(ui->btnCalcular, &QPushButton::clicked, this, &MainWindow::calcularVentas);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcularVentas()
{

    QString ruta = QCoreApplication::applicationDirPath() + "/ventas.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir ventas.txt");
        return;
    }

    QTextStream in(&archivo);
    QDate fechaSeleccionada = ui->dateEdit->date();
    double totalDia = 0.0;
    double totalMes = 0.0;

    QString linea;
    QDate fechaFactura;

    while (!in.atEnd()) {
        linea = in.readLine().trimmed();

        if (linea.contains(QRegularExpression("^\\d{4}-\\d{2}-\\d{2}"))) {

            fechaFactura = QDate::fromString(linea.left(10), "yyyy-MM-dd");
        }

        if (linea.startsWith("TOTAL FACTURA: $")) {
            double monto = linea.mid(QString("TOTAL FACTURA: $").length()).toDouble();

            if (fechaFactura == fechaSeleccionada) {
                totalDia += monto;
            }

            if (fechaFactura.month() == fechaSeleccionada.month() &&
                fechaFactura.year() == fechaSeleccionada.year()) {
                totalMes += monto;
            }
        }
    }

    archivo.close();

    ui->dia->setText("Total del día: $" + QString::number(totalDia, 'f', 2));
    ui->mes->setText("Total del mes: $" + QString::number(totalMes, 'f', 2));
}
