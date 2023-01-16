#ifndef MODE_H
#define MODE_H

#include <random>

namespace s21 {

enum class Mode { NONE = 0, MAZE, CAVE };

auto GenerateRandomBool() -> bool;

}  // namespace s21

#endif  // MODE_H