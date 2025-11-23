#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ageMap["Fish"]= 2;
     ageMap["Cat"]= 7;
     ageMap["Dog"]=5;
    ageMap["Mice"]= 8;

     ui->Letype->addItems(ageMap.keys());
      ui->Letype->setCurrentIndex(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Letype_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    int m= ageMap.value(ui->Letype->currentText());
    ui->Lemultiplier->setText(QString::number(m));
}


void Dialog::on_Calculate_clicked()
{
    bool ok = false;
    int v = ui->Levalue->text().toInt(&ok);
    if(!ok) ui->Levalue->setText("0");

    int value = ui->Levalue->text().toInt(&ok);
    int multiplier = ui->Lemultiplier->text().toInt(&ok);

    int result = value * multiplier;
    ui->Leresult->setText(QString::number(result));


}

