#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
#include "weatherwindow.h"

void LoginDialog::on_btnLogin_clicked()
{
    // Optional: validate username/password
    WeatherWindow *w = new WeatherWindow();
    w->show();
    this->close();
}


