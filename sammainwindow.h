#ifndef SAMMAINWINDOW_H
#define SAMMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SamMainWindow; }
QT_END_NAMESPACE

class SamMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SamMainWindow(QWidget *parent = nullptr);
    ~SamMainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_actionSave_triggered();

    void on_QuitButton_clicked();

private:
    Ui::SamMainWindow *ui;
};
#endif // SAMMAINWINDOW_H
