#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    image=new QImage("image.jpeg");
    police= QFont("ubuntu",11,11,false);
   couleur1= QColor(Qt::red);
    couleur2= QColor(Qt::green);
    couleur3= QColor(Qt::blue);
    couleurfond=QColor(Qt::white);
    couleuraxe=QColor(Qt::gray);
 stylegraph=ui->Combotype->currentText();
    largeur=ui->Spinlargeur->value();
    hauteur=ui->Spinhauteur->value();

    margex=ui->Spinmargex->value();
    margey=ui->Spinmargey->value();
    pasx=ui->Spinpasx->value();
    pasy=ui->Spinpasy->value();
    montrergrill=ui->checkBoxgrill->isChecked();

    ui->Buttonfont->setText(police.family()+","+QString::number(police.pointSize()));

        ui->actionQuitter->setShortcut(QKeySequence::Quit);
        ui->actionCharger->setShortcut(QKeySequence::Open);
        ui->actionSauvergarder_le_graphique_sous->setShortcut(QKeySequence::SaveAs);



    {  QString sColor("QPushButton  { background-color : ");
        sColor.append(couleur1.name());
        sColor.append("; }");
    ui->Buttoncolor1->setStyleSheet(sColor);

    QString sColor2("QPushButton  { background-color : ");
    sColor2.append(couleur2.name());
    sColor2.append("; }");
ui->Buttoncolor2->setStyleSheet(sColor2);

QString sColor3("QPushButton  { background-color : ");
sColor3.append(couleur3.name());
sColor3.append("; }");
ui->Buttoncolor3->setStyleSheet(sColor3);

QString sColor4("QPushButton  { background-color : ");
sColor4.append(couleurfond.name());
sColor4.append("; }");
ui->Buttoncolorfond->setStyleSheet(sColor4);


QString sColor5("QPushButton  { background-color : ");
sColor5.append(couleuraxe.name());
sColor5.append("; }");
ui->Buttoncoloraxe->setStyleSheet(sColor5);
    }

ui->menuhelper->setIcon(ui->menuhelper->style()->standardIcon(QStyle::SP_DialogHelpButton));
    connect(ui->action_propos_de_Graphiques,&QAction::triggered,this,&MainWindow::aboutb);
    connect(ui->action_propos_de_Qt,&QAction::triggered,this,&MainWindow::about);
    connect(ui->actionDessiner_le_graphique,&QAction::triggered,this,&MainWindow::graph);
    connect(ui->actionCharger, &QAction::triggered,this,&MainWindow::newFile);
    connect(ui->actionQuitter, &QAction::triggered,this,&QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aboutb(){

    QMessageBox::about(this,"À propos de Graphiques","Cette application a été réalisée par Dorian LETORT pour un projet de Qt de L3 Informatique");


}
void MainWindow::about(){
QMessageBox::aboutQt(this,"À propos de qt");

}

void MainWindow::graph(){
ui->tableWidget->setMinimumWidth(200);
ui->graphicsView->setMinimumSize(this->largeur,this->hauteur);
int L=this->largeur;
int h=this->hauteur;
_pix= new QPixmap(L,h);

   QPainter painter(_pix);
    QPen pen;
    pen.setColor(this->couleuraxe);
    pen.setWidth(2);
    painter.fillRect(rect(), this->couleurfond);
    QPoint pima;
    pima.setX((3*L)/4);
    pima.setY((3*h)/4);
    painter.drawImage(pima,*image);
    painter.setPen(pen);
    painter.drawLine(L/2,0,L/2,h);
    painter.drawLine(0,h/2,L,h/2);


    pen.setWidth(1);
    painter.setPen(pen);
    if(this->montrergrill==true){
        int i=this->margey;
        while(i < this->hauteur){
            painter.drawLine(0,i,L,i);
            i=i+this->margey;
        }
        int y=this->margex;
        while(y < this->largeur){
            painter.drawLine(y,0,y,h);
            y=y+this->margex;
        }

    }



    scene=new QGraphicsScene();
    scene->addPixmap(*_pix);
    ui->graphicsView->setScene(scene);
    adjustSize();


}

void MainWindow::newFile(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Chargé un fichier ..."), QString(), tr("Tableur (*.csv)"));
   QString title="Graphique ["+filename+"]";
    this->setWindowTitle(title);
    QFile data(filename);

   if(data.exists() && data.open(QIODevice::ReadOnly))
    {
       QTextStream in(&data);
       int row=0;
       while(!in.atEnd()){

        QString ligne = in.readLine();
        QStringList enreg =ligne.split(',');



        if(row==0){
           ui->tableWidget->setColumnCount(enreg.size());

              ui->tableWidget->setHorizontalHeaderLabels(enreg);

        }

else{
        ui->tableWidget->insertRow(row-1);

        for(int col=0;col<enreg.size();col++){

            ui->tableWidget->setItem(row-1,col,new QTableWidgetItem(enreg[col]));
        }}

    row++;
       }

       data.close();
   }
    adjustSize();
   ui->actionDessiner_le_graphique->setEnabled(true);

    }






void MainWindow::on_Buttoncolor1_clicked()
{

    QColor coulor =QColorDialog::getColor(couleur1,this);
    if(coulor.isValid())
    {this->couleur1=coulor;
        QString sColora("QPushButton  { background-color : ");
                sColora.append(couleur1.name());
                sColora.append("; }");
            ui->Buttoncolor1->setStyleSheet(sColora);


    }

}

void MainWindow::on_Buttoncolor2_clicked()
{
    QColor coulor2 =QColorDialog::getColor(couleur2,this);
    if(coulor2.isValid())
    {this->couleur2=coulor2;
        QString sColora("QPushButton  { background-color : ");
                sColora.append(couleur2.name());
                sColora.append("; }");
            ui->Buttoncolor2->setStyleSheet(sColora);


    }

}

void MainWindow::on_Buttoncolor3_clicked()
{
    QColor coulor3 =QColorDialog::getColor(couleur3,this);
    if(coulor3.isValid())
    {this->couleur3=coulor3;
        QString sColora("QPushButton  { background-color : ");
                sColora.append(couleur3.name());
                sColora.append("; }");
            ui->Buttoncolor3->setStyleSheet(sColora);


    }

}

void MainWindow::on_Buttoncolorfond_clicked()
{
    QColor coulor4 =QColorDialog::getColor(couleurfond,this);
    if(coulor4.isValid())
    {this->couleurfond=coulor4;
        QString sColora("QPushButton  { background-color : ");
                sColora.append(couleurfond.name());
                sColora.append("; }");
            ui->Buttoncolorfond->setStyleSheet(sColora);


    }

}

void MainWindow::on_Buttoncoloraxe_clicked()
{
    QColor coulor5 =QColorDialog::getColor(couleuraxe,this);
    if(coulor5.isValid())
    {this->couleuraxe=coulor5;
        QString sColora("QPushButton  { background-color : ");
                sColora.append(couleuraxe.name());
                sColora.append("; }");
            ui->Buttoncoloraxe->setStyleSheet(sColora);


    }
}

void MainWindow::on_Combotype_editTextChanged(const QString &arg1)
{stylegraph=arg1;

}

void MainWindow::on_Buttonfont_clicked()
{

    bool ok;
    police = QFontDialog::getFont(&ok,police,this,tr("Choisir une police"));
    ui->Buttonfont->setText(police.family()+","+QString::number(police.pointSize()));

}

void MainWindow::on_Spinlargeur_valueChanged(int arg1)
{
    this->largeur=arg1;

}

void MainWindow::on_Spinhauteur_valueChanged(int arg1)
{
    this->hauteur=arg1;
}

void MainWindow::on_Spinmargex_valueChanged(int arg1)

{
    this->margex=arg1;
}




void MainWindow::on_Spinmargey_valueChanged(int arg1)
{
    this->margey=arg1;
}


void MainWindow::on_Spinpasx_valueChanged(int arg1)
{
    this->pasx=arg1;
}

void MainWindow::on_Spinpasy_valueChanged(int arg1)
{
    this->pasy=arg1;
}

void MainWindow::on_checkBoxgrill_stateChanged(int arg1)
{
    this->montrergrill=arg1;
}
