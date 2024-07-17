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
    int grid[50][50];
    int dist[50][50]; memset(dist, 0, sizeof(dist));
    dist[0][0] = 1;
    int ans = H * W;
    rep(i, 0, H){
        rep(j, 0, W){
            char c; cin >> c;
            if (c == '#') --ans;
            grid[i][j] = (c == '.');
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.second, y = p.first;
        rep(i, 0, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and nx < W and ny >= 0 and ny < H and grid[ny][nx] and !dist[ny][nx]){
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    if (dist[H - 1][W - 1] == 0){
        cout << "-1\n";
        return 0;
    }
    ans -= dist[H - 1][W - 1];
    cout << ans << '\n';
    return 0;
}
