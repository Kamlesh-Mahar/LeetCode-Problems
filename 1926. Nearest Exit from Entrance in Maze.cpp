class Solution {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::queue<std::pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if ((x != entrance[0] || y != entrance[1]) && (x == 0 || x == rows - 1 || y == 0 || y == cols - 1)) {
                    return steps;
                }

                maze[x][y] = '+';

                for (const auto& dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] == '.') {
                        q.push({newX, newY});
                        maze[newX][newY] = '+';
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
