#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Helper to print the maze
void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }
}

// BFS to find shortest path
bool bfs(vector<vector<char>>& maze, pair<int,int> start, pair<int,int> end) {
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    vector<vector<pair<int,int>>> parent(ROWS, vector<pair<int,int>>(COLS, {-1,-1}));

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty()) {
        pair<int, int> current = q.front(); q.pop();
        int x = current.first;
        int y = current.second;

        if (x == end.first && y == end.second) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < ROWS && ny < COLS &&
                maze[nx][ny] != '#' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
            }
        }
    }

    if (!found) {
        cout << "No path found!" << endl;
        return false;
    }

    // Backtrack to mark the path
    pair<int,int> curr = end;
    while (curr != start) {
        pair<int, int> prev = parent[curr.first][curr.second];
        int px = prev.first;
        int py = prev.second;
        if (curr != end)
            maze[curr.first][curr.second] = '*'; // Path
        curr = {px, py};
    }

    return true;
}

int main() {
    vector<vector<char>> maze(ROWS, vector<char>(COLS, '.'));

    // Take walls input
    int wallCount;
    cout << "Enter number of walls: ";
    cin >> wallCount;
    cout << "Enter wall positions (row col):" << endl;
    for (int i = 0; i < wallCount; i++) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = '#';
    }

    // Take start and end positions
    pair<int,int> start, end;
    cout << "Enter start position (row col): ";
    cin >> start.first >> start.second;
    maze[start.first][start.second] = 'S';

    cout << "Enter end position (row col): ";
    cin >> end.first >> end.second;
    maze[end.first][end.second] = 'E';

    cout << "\nInitial Maze:\n";
    printMaze(maze);

    if (bfs(maze, start, end)) {
        cout << "\nPath Found (marked with *):\n";
        maze[start.first][start.second] = 'S';
        maze[end.first][end.second] = 'E';
        printMaze(maze);
    }

    return 0;
}
