#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/cave.h"
#include "../model/maze.h"
#include "../model/pacman.h"

namespace s21 {

class Controller {
 private:
  Maze maze_;
  Cave cave_;
  Pacman pacman_;

 public:
  Maze* maze() { return &maze_; }
  Cave* cave() { return &cave_; }
  Pacman* pacman() { return &pacman_; }
  std::vector<Position> findWay(Position begin, Position end) {
    pacman_.getMaze(&maze_);
    return pacman_.findWay(begin, end);
  }
  // Controller();
  // ~Controller() = default;
  // Controller(const Controller&) = delete;
  // Controller(Controller&&) = delete;
  // auto operator=(const Controller&) -> Controller& = delete;
  // auto operator=(Controller&&) -> Controller&& = delete;
};

}  // namespace s21

#endif  // CONTROLLER_H
