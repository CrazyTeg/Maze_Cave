#ifndef POINTCOORDINATES_H
#define POINTCOORDINATES_H

namespace s21 {
struct PointCoordinates {
    int x{};
    int y{};

 PointCoordinates() = default;
 ~PointCoordinates() = default;
 PointCoordinates(const PointCoordinates&) = default;
 PointCoordinates(int coordX, int coordY);
 auto operator=(const PointCoordinates&) -> PointCoordinates&;
};

auto operator==(const PointCoordinates& left, const PointCoordinates& right) -> bool;
auto operator!=(const PointCoordinates& left, const PointCoordinates& right) -> bool;
auto operator+(const PointCoordinates& left, const PointCoordinates& right) -> PointCoordinates;

}  // namespace s21

#endif // POINTCOORDINATES_H
