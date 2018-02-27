#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

const double m_convert[2][11] = {
 {100, 1, 10, 0.1, 0.2, 1000, 0.001, 0.01, 1000000, 28.349523125, 453.59237}, //Гектограмм Грамм Декаграмм Дециграмм Карат Килограмм Миллиграмм Сантиграмм Тонна Унция Фунт
 {86400, 0.000001, 0.001, 60, 604800, 1, 3600, 0, 0, 0, 0 }//День Микросекунда  Миллисекунда Минута Неделя Секунда Час
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    types << "Вес/Macca" << "Время";
    weight <<"Гектограмм" << "Грамм" << "Декаграмм" << "Дециграмм" << "Карат" << "Килограмм" << "Миллиграмм" << "Сантиграмм" << "Тонна" << "Унция" << "Фунт";
    time << "День" << "Микросекунда" << "Миллисекунда" << "Минута"<< "Неделя" << "Секунда" << "Час";

    CTypes_.push_back(weight);
    CTypes_.push_back(time);

    ui->comboBox->clear();
    ui->comboBox->addItems(types);
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_2->addItems(weight);
    ui->comboBox_3->addItems(weight);
    ui->lineEdit->setText("0");

    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(Update()));
    connect(ui->comboBox_3, SIGNAL(currentIndexChanged(int)), this, SLOT(Update()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_2->addItems(CTypes_.at(index));
    ui->comboBox_3->addItems(CTypes_.at(index));
}

void MainWindow::Update()
{
    QString InValue = ui->lineEdit->text();
    double res = Convert(InValue.toDouble(), ui->comboBox->currentIndex(), ui->comboBox_2->currentIndex(),  ui->comboBox_3->currentIndex());
    QString OutValue = QString();
    OutValue.setNum(res);
    ui->lineEdit_2->setText(OutValue);
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Update();
}

double MainWindow::Convert(double InValue, int TypeUnits, int FromUnits, int ToUnits)
{
    if (FromUnits == ToUnits) return InValue;
    return ((m_convert[TypeUnits][FromUnits] / m_convert[TypeUnits][ToUnits]) * InValue);

}

//void MainWindow::on_comboBox_2_currentIndexChanged(int index)
//{
//    Update();
//}

//void MainWindow::on_comboBox_3_currentIndexChanged(int index)
//{
//    Update();
//}

void MainWindow::on_action_triggered()
{
    close();
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox Msgbox;
    Msgbox.setText("Конвертер величин");
    Msgbox.exec();
}
