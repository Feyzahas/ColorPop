#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QMainWindow>
using namespace std;
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
    void on_actionLoad_triggered();


    void on_tValueSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void mouseReleaseEvent(QMouseEvent *e);

    void dispPoint();
private:
    Ui::MainWindow *ui;
    vector<QPoint> points;
    QString fname;
};

#endif // MAINWINDOW_H
