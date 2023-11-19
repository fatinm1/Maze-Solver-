#include "MazeSolver.h"
#include <iostream>

int main() {
    std::vector<std::vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    MazeSolver solver(maze);
    Point start = {0, 0};
    Point end = {4, 4};
    cout << "Expected output: " << "(0, 0) (1, 0) (2, 0) (2, 1) (2, 2) (2, 3) (2, 4) (3, 4) (4, 4)" << endl;
    std::vector<Point> path = solver.solve(start, end);
    if (!path.empty()) {
        for (const auto& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ") ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found in the maze." << std::endl;
    }

    return 0;
}
