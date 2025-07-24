#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void crearProducto();  // Declaración de la función crearProducto()
    void actualizarProducto();  // Declaración de la función actualizarProducto()
    void on_tableWidget_itemSelectionChanged();  // Declaración del slot que maneja la selección de la tabla

private:
    Ui::MainWindow *ui;

    QString generarCodigo();  // Declaración de la función generarCodigo()
};

#endif // MAINWINDOW_H
