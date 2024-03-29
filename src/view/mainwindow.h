#pragma once

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

#include "../controller/controller.h"
#include "cavewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 private:
  Ui::MainWindow *ui;
  CaveWindow *caveWindow;

 public:
  explicit MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_button_load_clicked();
  void on_button_save_clicked();
  void on_btn_generate_clicked();
  void on_btn_sel_clicked();
};

QString truncater(QString str, int size);

QString path_file();
