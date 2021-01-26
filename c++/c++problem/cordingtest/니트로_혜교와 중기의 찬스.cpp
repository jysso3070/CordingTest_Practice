#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int weight[101][101][11];
vector<pair<int, int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
int dp[2048][11];
bool map_range(int x, int y, int w, int h) {
    return (x >= 0 && x < w&& y >= 0 && y < h);
}

void settingCoins(const vector<vector<int>>& maze, vector<pair<int, int>>& coins)
{
    coins.push_back(make_pair(0, 0));
    for (int i = 0; i < maze.size(); ++i)
    {
        for (int j = 0; j < maze[i].size(); ++j)
        {
            if (maze[i][j] == 2)
                coins.push_back(make_pair(i, j));
        }
    }
}

void BFS(const vector<vector<int>>& maze, const pair<int, int>& coinPos, int coinIndex)
{
    int n = maze.size();
    int m = maze[0].size();
    bool v[101][101];
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            v[i][j] = false;
            weight[i][j][coinIndex] = 99999999;
        }
    }

    queue<pair<int, int>> q;
    q.push(coinPos);
    v[coinPos.first][coinPos.second] = true;
    weight[coinPos.first][coinPos.second][coinIndex] = 0;

    while (!q.empty())
    {
        pair<int, int> qd = q.front();
        q.pop();
        for (int i = 0; i < dir.size(); ++i)
        {
            int x = qd.first + dir[i].first;
            int y = qd.second + dir[i].second;

            if (map_range(x, y, n, m) && maze[x][y] != 1 && v[x][y] == false)
            {
                v[x][y] = true;
                weight[x][y][coinIndex] = weight[qd.first][qd.second][coinIndex] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
}

int findminWeight(int coinIndex, int mask, const vector<pair<int, int>>& coins, int ex, int ey)
{
    int max_mask = (1 << coins.size()) - 1;
    if (max_mask == mask)
        return weight[ex][ey][coinIndex];

    int& res = dp[mask][coinIndex];
    if (dp[mask][coinIndex] != INT_MAX)
        return res;
    for (int i = 0; i < coins.size(); ++i)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newMask = mask | (1 << i);
            int x = coins[i].first;
            int y = coins[i].second;
            res = min(res, findminWeight(i, newMask, coins, ex, ey) + weight[x][y][coinIndex]);
        }
    }
    return res;
}

int minMoves(vector<vector<int>> maze, int x, int y)
{
    for (int i = 0; i < 2048; ++i)
    {
        for (int j = 0; j < 11; ++j)
            dp[i][j] = INT_MAX;
    }

    vector<pair<int, int>> coins;
    settingCoins(maze, coins);

    for (int i = 0; i < coins.size(); ++i)
        BFS(maze, coins[i], i);
    int res = findminWeight(0, 1, coins, x, y);
    if (res >= 99999999)
        return -1;
    return res;
}

int main() {
    vector<vector<int>>
    minMoves()
}