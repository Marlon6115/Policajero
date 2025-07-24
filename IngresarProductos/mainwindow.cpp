#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QDoubleValidator>
#include <QIntValidator>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar los botones con su funcion
    connect(ui->crearButton, &QPushButton::clicked, this, &MainWindow::crearProducto);
    connect(ui->actualizarButton, &QPushButton::clicked, this, &MainWindow::actualizarProducto);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_tableWidget_itemSelectionChanged);

    // Deshabilitar el botón "Actualizar" al inicio, ya que no se puede actualizar sin selección
    ui->actualizarButton->setEnabled(false);
    ui->crearButton->setEnabled(true);

    // Configurar validadores para cantidad y precio
    ui->cantidadEdit->setValidator(new QIntValidator(0, 9999, this));  // Solo números enteros para la cantidad
    ui->precioEdit->setValidator(new QDoubleValidator(0.0, 9999.0, 2, this));  // Números flotantes o enteros para el precio
}
MainWindow::~MainWindow()
{
    delete ui;
}

// Función para crear un nuevo producto
void MainWindow::crearProducto() {
    QString nombre = ui->nombreEdit->text();
    QString cantidad = ui->cantidadEdit->text();
    QString precio = ui->precioEdit->text();

    // Validar que los campos no estén vacíos
    if (nombre.isEmpty() || cantidad.isEmpty() || precio.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llene todos los campos.");
        return;
    }

    // Validar que la cantidad sea un número entero y mayor que 0
    if (cantidad.toInt() <= 0) {
        QMessageBox::warning(this, "Cantidad inválida", "La cantidad debe ser un número entero mayor que 0.");
        return;
    }

    // Validar que el precio sea un numero
    bool precioValido;
    precio.toDouble(&precioValido);
    if (!precioValido || precio.toDouble() <= 0) {
        QMessageBox::warning(this, "Precio inválido", "El precio debe ser un número flotante o entero mayor que 0.");
        return;
    }

    // Verificar si ya existe un producto con el mismo nombre o código
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, 1)->text() == nombre) {
            QMessageBox::warning(this, "Producto duplicado", "Este producto ya existe en la tabla.");
            return;
        }
    }

    // Generar un código aleatorio para el producto
    QString codigo = generarCodigo();

    // Agregar el producto a la tabla
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(codigo));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(cantidad));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(precio));

    // Limpiar los campos de entrada
    ui->nombreEdit->clear();
    ui->cantidadEdit->clear();
    ui->precioEdit->clear();
}

// Función para generar un código aleatorio de producto
QString MainWindow::generarCodigo() {
    QString codigo = "P" + QString::number(QRandomGenerator::global()->bounded(1000, 9999));
    return codigo;
}

// Función para actualizar un producto seleccionado
void MainWindow::actualizarProducto() {
    int row = ui->tableWidget->currentRow();

    // Verificar que hay una fila seleccionada
    if (row == -1) {
        QMessageBox::warning(this, "Selección inválida", "Por favor, seleccione un producto de la tabla para actualizar.");
        return;
    }

    // Obtener los datos de los campos de texto
    QString nuevoNombre = ui->nombreEdit->text();
    QString nuevaCantidad = ui->cantidadEdit->text();
    QString nuevoPrecio = ui->precioEdit->text();

    // Validar que los campos no estén vacíos
    if (nuevoNombre.isEmpty() || nuevaCantidad.isEmpty() || nuevoPrecio.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llene todos los campos para actualizar el producto.");
        return;
    }

    // Actualizar los datos del producto en la tabla
    ui->tableWidget->item(row, 1)->setText(nuevoNombre);
    ui->tableWidget->item(row, 2)->setText(nuevaCantidad);
    ui->tableWidget->item(row, 3)->setText(nuevoPrecio);

    // Verificar si la cantidad es 0, y eliminar el producto si es el caso
    if (nuevaCantidad.toInt() == 0) {
        ui->tableWidget->removeRow(row);
    }

    // Limpiar los campos de entrada
    ui->nombreEdit->clear();
    ui->cantidadEdit->clear();
    ui->precioEdit->clear();

    // Desactivar el botón de actualizar después de la actualización
    ui->actualizarButton->setEnabled(false);

    // Habilitar el botón de crear
    ui->crearButton->setEnabled(true);
}

// Función que se activa cuando se selecciona una fila en la tabla
void MainWindow::on_tableWidget_itemSelectionChanged() {
    // Deshabilitar el botón de crear al seleccionar un producto para actualización
    if (ui->tableWidget->currentRow() != -1) {
        ui->actualizarButton->setEnabled(true);
        ui->crearButton->setEnabled(false);
    } else {
        ui->actualizarButton->setEnabled(false);
        ui->crearButton->setEnabled(true);
    }
}
