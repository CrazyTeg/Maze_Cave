#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->render_area->setController(controller);
  caveWindow = new CaveWindow(controller);
}

MainWindow::~MainWindow() {
  delete ui;
  delete caveWindow;
}

void MainWindow::on_button_load_clicked() {
  QString filename =
      QFileDialog::getOpenFileName(this, ("Open file"), path_file(), "*.txt");
  if (filename.isEmpty()) return;
  try {
    ui->render_area->drawFromFile(filename);
  } catch (std::exception &ex) {
    QMessageBox msgBox;
    msgBox.setText("Error file");
    msgBox.exec();
  }

  ui->label_filename->setText(truncater(filename, 18));
}

void MainWindow::on_button_save_clicked() {
  QString fileName = {path_file() + "maze_"};
  ui->render_area->saveFile(fileName);
}

void MainWindow::on_btn_generate_clicked() {
  ui->render_area->drawGenerate(ui->spinBox_width->value(),
                                ui->spinBox_height->value());
}

void MainWindow::on_btn_sel_clicked() {
  hide();
  caveWindow->show();
}

QString truncater(QString str, int size) {
  qsizetype n = str.lastIndexOf('/') + 1;
  str = str.right(str.size() - n);
  if (str.size() > size) {
    str.truncate(size - 3);
    QString dots = "...";
    str += dots;
  }
  return str;
}

QString path_file() {
  QString temp_path = QDir::currentPath();
#ifdef __APPLE__
  return temp_path + "/../../../../src/data/";
#endif
  return temp_path + "/../src/data/";
}
















