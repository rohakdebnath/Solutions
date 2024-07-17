#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

char building[1000][1000];
bool vis[1000][1000];
int N, M; 

void dfs(int i, int j){
    if (building[i][j] == '#' or vis[i][j] or i < 0 or i >= N or j < 0 or j >= M) return;
    vis[i][j] = 1;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main()
{
    UNSYNC
    cin >> N >> M;
    rep(i, 0, N){
        rep(j, 0, M){
            cin >> building[i][j];
        }
    }

    int rooms = 0;
    rep(i, 0, N){
        rep(j, 0, M){
            if (!vis[i][j] and building[i][j] == '.'){
                dfs(i, j);
                ++rooms;
            }
        }
    }

    cout << rooms << '\n';
    return 0;
}
