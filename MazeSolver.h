#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include <vector>
#include <queue>

struct Point {
    int x, y;
};

class MazeSolver {
public:
    MazeSolver(const std::vector<std::vector<int>>& maze);
    std::vector<Point> solve(Point start, Point end);

private:
    struct Node {
        Point pt;
        int dist;
        Node* parent;
    };

    std::vector<std::vector<int>> maze;
    bool isValid(int row, int col) const;
    std::vector<Point> getNeighbors(Point p) const;
    std::vector<Point> buildPath(Node* node) const;
    void freeMemory(std::queue<Node*>& nodes) const;
};

#endif // MAZESOLVER_H

