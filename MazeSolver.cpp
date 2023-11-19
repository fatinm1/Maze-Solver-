#include "MazeSolver.h"
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

MazeSolver::MazeSolver(const std::vector<std::vector<int>>& maze) : maze(maze) {}

bool MazeSolver::isValid(int row, int col) const {
    return (row >= 0) && (row < maze.size()) && (col >= 0) && (col < maze[0].size()) && maze[row][col] == 0;
}

std::vector<Point> MazeSolver::getNeighbors(Point p) const {
    return { {p.x - 1, p.y}, {p.x + 1, p.y}, {p.x, p.y - 1}, {p.x, p.y + 1} };
}

std::vector<Point> MazeSolver::buildPath(Node* node) const {
    std::vector<Point> path;
    while (node) {
        path.push_back(node->pt);
        node = node->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

void MazeSolver::freeMemory(std::queue<Node*>& nodes) const {
    while (!nodes.empty()) {
        delete nodes.front();
        nodes.pop();
    }
}

std::vector<Point> MazeSolver::solve(Point start, Point end) {
    if (maze.empty()) return {};

    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::queue<Node*> nodes;
    Node* startNode = new Node({start, 0, nullptr});
    nodes.push(startNode);
    visited[start.x][start.y] = true;

    while (!nodes.empty()) {
        Node* curr = nodes.front();
        Point pt = curr->pt;
        if (pt.x == end.x && pt.y == end.y) {
            auto path = buildPath(curr);
            freeMemory(nodes);
            return path;
        }

        nodes.pop();
        for (const auto& neighbor : getNeighbors(pt)) {
            if (isValid(neighbor.x, neighbor.y) && !visited[neighbor.x][neighbor.y]) {
                visited[neighbor.x][neighbor.y] = true;
                Node* nextNode = new Node({neighbor, curr->dist + 1, curr});
                nodes.push(nextNode);
            }
        }
    }

    freeMemory(nodes);
    return {};
}

