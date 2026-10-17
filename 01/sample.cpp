#ifndef __PROGTEST__
#include <cassert>
#include <iostream>
#include <memory>
#include <limits>
#include <optional>
#include <algorithm>
#include <bitset>
#include <list>
#include <array>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <random>
#include <functional>
#include <compare>
#include <utility>


struct Lever {
  int row;
  std::vector<bool> conf;
};

struct Position {
  int row;
  int col;

  friend auto operator <=> (Position, Position) = default;
};

constexpr bool WALL = true;
constexpr bool EMPTY = false;

using Maze = std::vector<std::vector<bool>>;

struct Solution {
  int length;
  std::vector<bool> lever_config;
  std::vector<Position> path;
};

#endif

std::optional<Solution> find_path(
  const std::vector<std::vector<bool>>& maze,
  const std::vector<Lever>& levers,
  Position goblet
) {
  // TODO implement
}

#ifndef __PROGTEST__


namespace examples {

struct Example {
  int length;
  Position goblet;
  Maze maze;
  std::vector<Lever> levers;
};

constexpr bool W = WALL;
constexpr bool _ = EMPTY;

const Example EXAMPLES[] = {
  { 16, Position{5, 5},
    Maze{
      { _, _, _, _, W },
      { _, _, _, W, _ },
      { _, _, W, _, _ },
      { _, W, _, _, _ },
      { W, _, _, _, _ },
    },
    {
      Lever{4, { 0, 0, 1, 0, 0 }},
    }
  },
  {
    4, Position{3, 3},
    Maze{
      { _, _, _ },
      { _, _, _ },
      { _, _, _ },
    },
    {},
  },
  {
    -1, Position{3, 3},
    Maze{
      { _, _, _ },
      { W, W, W },
      { _, _, _ },
    },
    {},
  },
  {
    14, Position{4, 4},
    Maze{
      { _, W, _, _ },
      { W, _, W, W },
      { W, W, W, W },
      { _, W, W, _ },
    },
    {
      Lever{2, { 0, 1, 0, 0 }},
      Lever{4, { 0, 0, 1, 0 }},
    },
  },
  {
    6, Position{4, 4},
    Maze{
      { _, _, _, _ },
      { _, _, _, _ },
      { _, _, _, _ },
      { _, _, _, _ },
    },
    {
      Lever{10, { 0, 0, 1, 0 }},
    },
  },
  {
    23, Position{1, 4},
    Maze{
      { W, W, W, W },
    },
    {
      Lever{10, { 1 }},
    },
  },
};

}

int main() {
  for (auto&& t : examples::EXAMPLES) {
    auto res = find_path(t.maze, t.levers, t.goblet);
    if (t.length == -1) assert(!res);
    else {
      assert(res);
      assert(t.length == res->length);
    }

    // TODO check the rest
  }

  std::cout << "All tests passed\n";
}

#endif


