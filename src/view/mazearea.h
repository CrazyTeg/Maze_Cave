#pragma once

#include <QFile>
#include <QTime>
#include <QtGui/QImage>
#include <QtGui/QKeyEvent>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidget>

#include "../controller/controller.h"

class MazeArea : public QWidget {
  Q_OBJECT

 private:
  s21::Controller *controller_;
  QImage maze_image_, maze_path_;
  QPoint pointBegin_, pointEnd_;
  s21::Position posBegin_, posEnd_;
  double cellWidth_, cellHeight_;
  bool isBeginSet_, isEndSet_;

  void paintEvent(QPaintEvent *event) override;
  inline void clearMaze();
  inline void clearPath();
  inline void clearImage(QImage &image);
  inline void gridSnap();
  inline QPoint positionToPoint(s21::Position pos);
  void drawMaze();
  void drawCells();
  void drawPath();

 protected:
  void mousePressEvent(QMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

 public:
  explicit MazeArea(QWidget *parent = nullptr);
  void setController(s21::Controller *controller) { controller_ = controller; }
  void drawFromFile(QString filename);
  void drawGenerate(int width, int height);
  void saveFile(const QString &fileName);
};
