#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QList>

namespace Ui {
    class MainWindow;
}

class QMdiSubWindow;

class ScriptEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void executeRemoteCode(QString code);

    void log(QString const & message, QString const & category = "INFO");

private:
    void sendRaw(QString message);

    void spawn(QString type, QString subtype, QString variant);

    void loadPickups(QMenu * menu, QString fileName, QString pickupVariant);

    ScriptEditor * openFile(QString fileName);

    void renderWindowsMenu();

    void updateActions();

    void loadTemplates();

    void addTemplate(QString name, QString contents);

    void on_createTemplateClick();

    void on_pickupClick();

private slots:
    void on_actionQuit_triggered();

    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionRun_triggered();

    void on_clientConnected();

    void on_disconnected();

    void on_readReady();

    void on_actionAdd_Half_Red_triggered();

    void on_actionAdd_Red_triggered();

    void on_actionAdd_Half_Soul_triggered();

    void on_actionAdd_Soul_triggered();

    void on_actionAdd_Half_Black_triggered();

    void on_actionAdd_Black_triggered();

    void on_actionAdd_Golden_Heart_triggered();

    void on_actionAdd_Eternal_Heart_triggered();

    void on_actionAdd_Half_Container_triggered();

    void on_actionAdd_Container_triggered();

    void on_actionAdd_Coin_triggered();

    void on_actionAdd_Bomb_triggered();

    void on_actionAdd_Key_triggered();

    void on_actionAdd_Golden_Bomb_triggered();

    void on_actionAdd_Golden_Key_triggered();

    void on_actionFull_Charge_triggered();

    void on_actionIncrease_Charge_triggered();

    void on_actionDischarge_triggered();

    void on_actionAdd_Nickel_triggered();

    void on_actionAdd_Dime_triggered();

    void on_actionReroll_Enemies_triggered();

    void on_actionBattery_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_triggered();

    void on_mdiArea_subWindowActivated(QMdiSubWindow *arg1);

private:
    Ui::MainWindow *ui;
    QTcpServer * server;
    QList<QTcpSocket*> sockets;
};

#endif // MAINWINDOW_H
