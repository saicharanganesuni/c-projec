#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class WeatherWindow;
}

class WeatherWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WeatherWindow(QWidget *parent = nullptr);
    ~WeatherWindow();
private:
    QNetworkAccessManager *manager;
    void fetchWeather();

private slots:
    void onWeatherReply(QNetworkReply *reply);
private:
    Ui::WeatherWindow *ui;
};

#endif // WEATHERWINDOW_H
