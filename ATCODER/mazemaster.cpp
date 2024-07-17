#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int H, W; cin >> H >> W;
    int grid[20][20];
    rep(i, 0, H){
        rep(j, 0, W){
            char c; cin >> c;
            grid[i][j] = (c == '#');
        }
    }
    
    int maxd = 0;
    rep(i, 0, H){
        rep(j, 0, W){
            if (grid[i][j] == 0){
                int dist[20][20]; memset(dist, 0, sizeof(dist));
                bool vis[20][20]; memset(vis, 0, sizeof(vis));
                queue<pair<int, int>> bfs;
                bfs.push({i, j});
                vis[i][j] = 1;
                while (!bfs.empty()){
                    auto top = bfs.front();
                    bfs.pop();
                    int x = top.first, y = top.second;
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    rep(t, 0, 4){
                        int nx = x + dx[t];
                        int ny = y + dy[t];
                        if (!vis[nx][ny] and nx >= 0 and nx < H and ny >= 0 and ny < W and !grid[nx][ny]){
                            bfs.push({nx, ny});
                            vis[nx][ny] = 1;
                            dist[nx][ny] = dist[x][y] + 1;
                            if (dist[nx][ny] > maxd){
                                maxd = dist[nx][ny];
                            }
                        }
                    }
                }
            }
        } 
    }

    cout << maxd << '\n';
    return 0;
}
