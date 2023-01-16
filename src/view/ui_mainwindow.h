#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "mazearea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QWidget *wrapper;
  MazeArea *render_area;

  QGridLayout *gridLayout;
  QHBoxLayout *hl_panel;
  QVBoxLayout *vl_load;
  QVBoxLayout *vl_generate;
  QGridLayout *grid;
  QHBoxLayout *horizontalLayout;
  QGridLayout *gridLayout_2;
  QHBoxLayout *horizontalLayout_2;

  QLabel *label_filename;
  QLabel *label_height;
  QLabel *label_width;

  QSpinBox *spinBox_width;
  QSpinBox *spinBox_height;

  QPushButton *button_load;
  QPushButton *button_save;
  QPushButton *btn_generate;
  QPushButton *btn_sel;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(550, 660);
    MainWindow->setMinimumSize(QSize(550, 660));
    MainWindow->setMaximumSize(QSize(550, 660));
    MainWindow->setStyleSheet(QString::fromUtf8("background-color: #006363;"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMaximumSize(QSize(16777215, 16777215));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(5, 5, 5, 10);
    hl_panel = new QHBoxLayout();
    hl_panel->setSpacing(5);
    hl_panel->setObjectName(QString::fromUtf8("hl_panel"));
    hl_panel->setContentsMargins(5, 0, 5, -1);
    vl_load = new QVBoxLayout();
    vl_load->setSpacing(5);
    vl_load->setObjectName(QString::fromUtf8("vl_load"));
    vl_load->setContentsMargins(0, -1, 5, -1);

    label_filename = new QLabel(centralwidget);
    label_filename->setObjectName(QString::fromUtf8("label_filename"));
    label_filename->setStyleSheet(
        QString::fromUtf8("color: #FFFFFF;\n"
                          "border: none;\n"
                          "background-color: #006363;\n"
                          "padding-left: 2px;\n"
                          "text-transform: uppercase;\n"
                          "letter-spacing: 2.5px;"));

    vl_load->addWidget(label_filename);

    QString labelStyle = "color: #FFFFFF;\n border: none;\n padding-left: 20px;\n"
                         "text-transform: uppercase;\n letter-spacing: 2.5px;";
    QString buttonStyle = "QPushButton {\n text-transform: uppercase;\n letter-spacing: 2.5px;\n"
                          "color: #FFFFFF;\n background-color: #5CCCCC;\n border-radius: 5px;\n}\n"
                          "\n QPushButton:hover {\n background: #003020;\n color: #5CCCCC;\n }\n"
                          "\n QPushButton:pressed {\n background: #003020;\n color: #FCFEF1;\n }";


    hl_panel->addLayout(vl_load);

    vl_generate = new QVBoxLayout();
    vl_generate->setSpacing(15);
    vl_generate->setObjectName(QString::fromUtf8("vl_generate"));
    grid = new QGridLayout();
    grid->setObjectName(QString::fromUtf8("grid"));
    label_height = new QLabel(centralwidget);
    label_height->setObjectName(QString::fromUtf8("label_height"));
    label_height->setStyleSheet(labelStyle);

    grid->addWidget(label_height, 1, 0, 1, 1);

    spinBox_width = new QSpinBox(centralwidget);
    spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
    spinBox_width->setStyleSheet(
        QString::fromUtf8("color: #AFA3A5;\n"
                          "background-color: #202020;"));
    spinBox_width->setMinimum(1);
    spinBox_width->setMaximum(50);
    spinBox_width->setValue(10);

    grid->addWidget(spinBox_width, 0, 1, 1, 1);

    label_width = new QLabel(centralwidget);
    label_width->setObjectName(QString::fromUtf8("label_width"));
    label_width->setStyleSheet(labelStyle);

    grid->addWidget(label_width, 0, 0, 1, 1);

    spinBox_height = new QSpinBox(centralwidget);
    spinBox_height->setObjectName(QString::fromUtf8("spinBox_height"));
    spinBox_height->setStyleSheet(
        QString::fromUtf8("color: #AFA3A5;\n"
                          "background-color: #202020;\n"
                          ""));
    spinBox_height->setMinimum(1);
    spinBox_height->setMaximum(50);
    spinBox_height->setValue(10);

    grid->addWidget(spinBox_height, 1, 1, 1, 1);

    vl_generate->addLayout(grid);

    hl_panel->addLayout(vl_generate);

    gridLayout->addLayout(hl_panel, 2, 0, 1, 1);

    wrapper = new QWidget(centralwidget);
    wrapper->setObjectName(QString::fromUtf8("wrapper"));
    wrapper->setMinimumSize(QSize(520, 520));
    wrapper->setStyleSheet(QString::fromUtf8("background-color:#001010"));
    gridLayout_2 = new QGridLayout(wrapper);
    gridLayout_2->setSpacing(0);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    gridLayout_2->setContentsMargins(10, 10, 10, 10);
    render_area = new MazeArea(wrapper);
    render_area->setObjectName(QString::fromUtf8("render_area"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(
        render_area->sizePolicy().hasHeightForWidth());
    render_area->setSizePolicy(sizePolicy1);
    render_area->setMinimumSize(QSize(500, 500));

    gridLayout_2->addWidget(render_area, 0, 0, 1, 1);

    gridLayout->addWidget(wrapper, 0, 0, 1, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(5);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(5, -1, 5, -1);
    button_load = new QPushButton(centralwidget);
    button_load->setObjectName(QString::fromUtf8("button_load"));
    button_load->setMinimumSize(QSize(0, 35));
    button_load->setMaximumSize(QSize(16777215, 30));
    button_load->setStyleSheet(buttonStyle);

    vl_load->addWidget(button_load);

    btn_sel = new QPushButton(centralwidget);
    btn_sel->setObjectName(QString::fromUtf8("btn_sel"));
    btn_sel->setMinimumSize(QSize(0, 35));
    btn_sel->setMaximumSize(QSize(1677715, 30));
    btn_sel->setStyleSheet(buttonStyle);

    horizontalLayout_2->addWidget(btn_sel);

    button_save = new QPushButton(centralwidget);
    button_save->setObjectName(QString::fromUtf8("button_save"));
    button_save->setMinimumSize(QSize(0, 35));
    button_save->setMaximumSize(QSize(1677715, 30));
    button_save->setStyleSheet(buttonStyle);

    horizontalLayout_2->addWidget(button_save);

    btn_generate = new QPushButton(centralwidget);
    btn_generate->setObjectName(QString::fromUtf8("btn_generate"));
    btn_generate->setMinimumSize(QSize(0, 35));
    btn_generate->setMaximumSize(QSize(16777215, 30));
    btn_generate->setStyleSheet(buttonStyle);

    horizontalLayout_2->addWidget(btn_generate);

    gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "Maze", nullptr));
    label_filename->setText(QString());
    label_height->setText(
        QCoreApplication::translate("MainWindow", "Height:", nullptr));
    label_width->setText(
        QCoreApplication::translate("MainWindow", "Width:", nullptr));
    button_load->setText(
        QCoreApplication::translate("MainWindow", "Load from file", nullptr));
    button_save->setText(
        QCoreApplication::translate("MainWindow", "SAVE", nullptr));
    btn_sel->setText(
        QCoreApplication::translate("MainWindow", "into the cave", nullptr));
    btn_generate->setText(
        QCoreApplication::translate("MainWindow", "Generate", nullptr));
  }
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE
