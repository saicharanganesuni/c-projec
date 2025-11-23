#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>

WeatherWindow::WeatherWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, &WeatherWindow::onWeatherReply);

    fetchWeather();
}

WeatherWindow::~WeatherWindow()
{
    delete ui;
}

void WeatherWindow::fetchWeather()
{
    QString url = "https://api.open-meteo.com/v1/forecast?"
                  "latitude=32.3668&longitude=-86.3000&current_weather=true";

    manager->get(QNetworkRequest(QUrl(url)));
}

void WeatherWindow::onWeatherReply(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return;

    QJsonObject root = doc.object();
    QJsonObject cw = root["current_weather"].toObject();

    double temp = cw["temperature"].toDouble();
    double wind = cw["windspeed"].toDouble();
    int code = cw["weathercode"].toInt();

    ui->lblTemp->setText(QString::number(temp) + " °C");
    ui->lblWind->setText(QString::number(wind) + " km/h");

    // Optional: Simple weather code map
    QString condition = "Unknown";
    if (code == 0) condition = "Clear Sky";
    else if (code == 1) condition = "Mainly Clear";
    else if (code >= 2 && code <= 3) condition = "Cloudy";

    ui->lblCondition->setText(condition);
}
