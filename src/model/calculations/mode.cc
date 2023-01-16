#include "mode.h"

namespace s21 {

auto GenerateRandomBool() -> bool {
    std::random_device random;
    std::default_random_engine engine{random()};
    std::uniform_int_distribution<int> dist{0, 1};
    return static_cast<bool>(dist(engine));
}

}  // namespace s21