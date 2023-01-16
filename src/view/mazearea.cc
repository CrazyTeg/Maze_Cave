#include "mazearea.h"

MazeArea::MazeArea(QWidget *parent)
    : QWidget(parent),
      maze_image_(QSize(500, 500), QImage::Format_ARGB32),
      maze_path_(QSize(500, 500), QImage::Format_ARGB32) {
  setFocusPolicy(Qt::ClickFocus);
  clearMaze();
  clearPath();
}

void MazeArea::paintEvent(QPaintEvent *event) {
  QPainter drawLine(this);
  QRect dirtyRect = event->rect();
  drawLine.drawImage(dirtyRect, maze_image_, dirtyRect);
  drawLine.drawImage(dirtyRect, maze_path_, dirtyRect);
}

inline void MazeArea::clearImage(QImage &image) {
  image.fill(QColor(0, 0, 0, 0));
}

inline void MazeArea::clearMaze() { clearImage(maze_image_); }

inline void MazeArea::clearPath() {
  clearImage(maze_path_);
  isBeginSet_ = false;
  isEndSet_ = false;
}

void MazeArea::drawFromFile(QString filename) {
  clearMaze();
  clearPath();
  controller_->maze()->setFromFile(filename.toStdString());
  drawMaze();
}

void MazeArea::drawGenerate(int width, int height) {
  clearMaze();
  clearPath();
  controller_->maze()->setSizes(width, height);
  controller_->maze()->generateMaze();
  drawMaze();
}

void MazeArea::saveFile(const QString &fileName) {
  int xx = controller_->maze()->getRows();
  int yy = controller_->maze()->getColumns();
  QString newName = {fileName + QString::number(xx) + "x" +
                     QString::number(yy) + "_" +
                     QTime::currentTime().toString("ss") + ".txt"};
  std::string fileStd = newName.toStdString();
  std::ofstream file{fileStd};
  file << xx << ' ' << yy << std::endl;
  for (int i{0}; i < xx; ++i) {
    for (int j{0}; j < yy; ++j) {
      file << controller_->maze()->getVerticalWalls()(i, j) << ' ';
    }
    file << std::endl;
  }
  file << std::endl;
  for (int i{0}; i < xx; ++i) {
    for (int j{0}; j < yy; ++j) {
      file << controller_->maze()->getHorizontalWalls()(i, j) << ' ';
    }
    file << std::endl;
  }
  QMessageBox msgBox;
  msgBox.setText("The file has been saved :)");
  msgBox.exec();
}

void MazeArea::drawMaze() {
  // Draw start line
  QPainter drawLine(&maze_image_);
  drawLine.setPen(QPen(Qt::white, 2));
  drawLine.drawLine(0, 1, 500, 1);
  drawLine.drawLine(1, 500, 1, 0);
  // Draw walls
  cellWidth_ = 500.0 / controller_->maze()->getColumns();
  cellHeight_ = 500.0 / controller_->maze()->getRows();
  for (int i = 0; i < controller_->maze()->getRows(); i++) {
    for (int j = 0; j < controller_->maze()->getColumns(); j++) {
      int x0 = cellWidth_ * j;
      int y0 = cellHeight_ * i;
      int x1 = cellWidth_ * (j + 1);
      int y1 = cellHeight_ * (i + 1);
      if (controller_->maze()->getVerticalWalls()(i, j)) {
        if (j + 1 == controller_->maze()->getColumns()) {
          x0--;
          x1--;
        }
        drawLine.drawLine(x1, y0, x1, y1);
      }
      if (controller_->maze()->getHorizontalWalls()(i, j)) {
        if (i + 1 == controller_->maze()->getRows()) {
          y0--;
          y1--;
        }
        if (j + 1 == controller_->maze()->getColumns()) {
          x0++;
          x1++;
        }
        drawLine.drawLine(x0, y1, x1, y1);
      }
    }
  }
  update();
}

inline void MazeArea::gridSnap() {
  posBegin_.x = pointBegin_.x() / cellWidth_;
  posBegin_.y = pointBegin_.y() / cellHeight_;

  posEnd_.x = pointEnd_.x() / cellWidth_;
  posEnd_.y = pointEnd_.y() / cellHeight_;
}

void MazeArea::drawCells() {
  clearImage(maze_path_);
  QPainter drawLine(&maze_path_);
  if (isBeginSet_) {
    drawLine.setPen(QPen(Qt::yellow, 2, Qt::DotLine));
    drawLine.drawRect(
        QRect(QPoint(posBegin_.x * cellWidth_, posBegin_.y * cellHeight_),
              QSize(cellWidth_, cellHeight_)));
  }
  if (isEndSet_) {
    drawLine.setPen(QPen(Qt::red, 2, Qt::DotLine));
    drawLine.drawRect(
        QRect(QPoint(posEnd_.x * cellWidth_, posEnd_.y * cellHeight_),
              QSize(cellWidth_, cellHeight_)));
  }
}

inline QPoint MazeArea::positionToPoint(s21::Position pos) {
  int xpos = pos.x * cellWidth_ + cellWidth_ / 2;
  int ypos = pos.y * cellHeight_ + cellHeight_ / 2;
  return QPoint(xpos, ypos);
}

void MazeArea::drawPath() {
  QPainter drawLine(&maze_path_);
  drawLine.setPen(QPen(Qt::yellow, 2));
  std::vector<s21::Position> way = controller_->findWay(posBegin_, posEnd_);
  if (way.empty()) return;
  for (unsigned i = 0; i < way.size() - 1; i++) {
    drawLine.drawLine(positionToPoint(way[i]), positionToPoint(way[i + 1]));
  }
}

void MazeArea::mousePressEvent(QMouseEvent *event) {
  if (controller_->maze()->getRows() != 0) {
    if (event->button() == Qt::LeftButton) {
      pointBegin_ = event->pos();
      isBeginSet_ = true;
    } else if (event->button() == Qt::RightButton) {
      pointEnd_ = event->pos();
      isEndSet_ = true;
    }
    gridSnap();
    drawCells();
    if (isBeginSet_ && isEndSet_) {
      drawPath();
    }
    update();
  }
}

void MazeArea::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Escape) {
    clearPath();
    update();
  }
}
