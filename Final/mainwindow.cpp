#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Conwerter.h"
#include<climits>
#define MAX 1000
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("GuParser");
   // setupDemo(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    Conwerter con;
    int i, ymax, ymin, value;
    vector<string> result;
    QVector<double> x(MAX), y(MAX);
    QString XMAX=ui->lineEdit->text();
    QString XMAX_2=ui->lineEdit_2->text();
    QString XMAX_3=ui->lineEdit_3->text();
    int xmin=XMAX_2.toInt();
    int xmax=XMAX_3.toInt();
    if((xmax-xmin)>MAX)
    {
        if(xmin<-MAX/2)
            xmin=-MAX/2;
        if(xmax>MAX/2)
            xmax=MAX/2;
    }
    string exp=XMAX.toStdString();
    result = con.ONP(exp);
    ymin=con.Parser(result, xmin, xmin);
    ymax=ymin;
    value=xmin;
    for (i=0;i<MAX; ++i, ++value)
    {
        y[i] = con.Parser(result, value, value);
        x[i] = value;
        if((y[i]>ymax)&&(i<xmax))
          ymax=y[i];
        if((y[i]<ymin)&&(i<xmax))
          ymin=y[i];
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(xmin, xmax);
    ui->customPlot->yAxis->setRange(ymin, ymax);

    ui->customPlot->replot();

}
