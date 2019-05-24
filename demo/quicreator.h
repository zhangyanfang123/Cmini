#ifndef QUICREATOR_H
#define QUICREATOR_H

#include <QMainWindow>

namespace Ui
{
class QUICreator;
}

class QUICreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit QUICreator(QWidget *parent = 0);
    ~QUICreator();

private:
    Ui::QUICreator *ui;

private slots:
    void initForm();
    void initTableWidget();
    void initTreeWidget();
    void initListWidget();
    void initOther();
    void initStyle();
    void initTranslator();
    void on_action_3_triggered();
    void on_textEdit_textChanged();
    void on_textEdit_2_textChanged();
    void on_action_1_triggered();
    void on_action_2_triggered();
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_8_triggered();
    void on_action_4_triggered();
    void on_action_9_triggered();
    void on_action_C_2_triggered();
    void on_action_O_triggered();
    void on_action_triggered();
    void on_action_S_triggered();
    void on_action_C_triggered();
    void on_action_10_triggered();
    void on_action_5_triggered();
    void on_action_11_triggered();
};

#endif // QUICREATOR_H
