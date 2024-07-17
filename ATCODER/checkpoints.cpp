#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

struct Point
{
    int x = 0;
    int y = 0;
};
int operator-(const Point& a, const Point& b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{
    UNSYNC
    int N, M; cin >> N >> M;
    vector<Point> students (N); rep(0, N) cin >> students[i].x >> students[i].y;
    vector<Point> checkpoints (M); rep(0, M) cin >> checkpoints[i].x >> checkpoints[i].y;
    for (int i = 0; i < N; ++i)
    {
        int mindis = INT32_MAX;
        int index = 0;
        for (int j = 0; j < M; ++j)
        {
            int dis = students[i] - checkpoints[j];
            if (dis < mindis)
            {
                index = j + 1;
                mindis = dis;
            }
        }
        cout << index << '\n';
    }
    return 0;
}
