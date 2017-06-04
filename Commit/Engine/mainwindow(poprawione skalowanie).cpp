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
    int i, ymax=0, xmax=0, ymin=0, xmin=0;
    Conwerter con;
    vector<string> result;
    QVector<double> x(MAX), y(MAX);
    QString XMAX=ui->lineEdit->text();
    string exp=XMAX.toStdString();
    result = con.ONP(exp);
ymax=con.Parser(result, 0, 0);
ymin=ymax;
    for (i=0; i<MAX; ++i)
    {

      y[i] = con.Parser(result, i, i);
      x[i] = i;
      if(y[i]>MAX/2)
          y[i]=MAX/2;
      if(y[i]<-MAX/2)
          y[i]=-MAX/2;
      if(y[i]>ymax)
        ymax=y[i];
      if(y[i]<ymin)
        ymin=y[i];
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0, i);
    ui->customPlot->yAxis->setRange(ymin, ymax);

    ui->customPlot->replot();

}
