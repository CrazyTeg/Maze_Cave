#include "pointcoordinates.h"

namespace s21 {

PointCoordinates::PointCoordinates(int coordX, int coordY)
    : x{coordX}, y{coordY} {}

auto operator==(const PointCoordinates& left, const PointCoordinates& right) -> bool {
  return left.x == right.x && left.y == right.y;
}

auto operator!=(const PointCoordinates& left, const PointCoordinates& right)
    -> bool {
  return left.x != right.x || left.y != right.y;
}

auto operator+(const PointCoordinates& left, const PointCoordinates& right)
    -> PointCoordinates {
  return PointCoordinates(left.x + right.x, left.y + right.y);
}

}  // namespace s21
