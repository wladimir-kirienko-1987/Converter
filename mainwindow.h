#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_textChanged(const QString &arg1);

//    void on_comboBox_2_currentIndexChanged(int index);

//    void on_comboBox_3_currentIndexChanged(int index);

    void Update();

private:
    Ui::MainWindow *ui;

    QStringList types;//типы конвертирования

    QStringList weight;//масса

    QStringList time;//время

    QVector<QStringList> CTypes_;

    double Convert(double InValue, int TypeUnits, int FromUnits, int ToUnits);

};



#endif // MAINWINDOW_H
