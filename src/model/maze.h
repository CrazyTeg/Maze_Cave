#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "matrix.h"

namespace s21 {

constexpr int kEmpty = 0;

class Maze {
 private:
  int rows_{0}, cols_{0};
  Matrix v_walls_, h_walls_;
  std::ifstream file_;
  std::vector<int> sideLine_;
  int counter_{1};

 public:
  void setSizes(int rows, int cols);
  void setFromFile(std::string filename);
  int getRows() { return rows_; }
  int getColumns() { return cols_; }
  Matrix& getVerticalWalls() { return v_walls_; }
  Matrix& getHorizontalWalls() { return h_walls_; }
  void generateMaze();

 private:
  inline void allocateWalls();
  void parseSize();
  void parseWalls(Matrix& matrix);
  /*Создаем пустую строку*/
  void fillEmptyValue();
  /*Присваиваем уникальное множество*/
  void assignUniqueSet();
  /*Добавление правой вертикальной стенки*/
  void addingVerticalWalls(int row);
  /* Объединение ячеек в одно множество */
  void mergeSet(int index, int element);
  /* Подсчет ячеек, которые содержаться в уникальном множестве */
  int calculateUniqueSet(int element);
  /* Подсчет горизонтальных стен у ячеек уникального множества */
  int calculateHorizontalWalls(int element, int row);
  /* Проверка Если ячейка в своем множестве одна
   Если ячейка одна в своем множестве без нижней границы*/
  void checkedHorizontalWalls(int row);
  /*Добавление нижней горизонтальной стенки*/
  void addingHorizontalWalls(int row);
  /*Подготовка новой строки*/
  void preparatingNewLine(int row);
  /* Добавление последней строки */
  void addingEndLine();
  /* Проверка условий на добавление последней строки */
  void checkedEndLine();
  void clearGenerator();
};

}  // namespace s21

#endif
