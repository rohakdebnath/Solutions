#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define rep(i, ini, x) for (int i = ini; i < x; ++i)

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> G (N); rep(i, 0, N) cin >> G[i];
    int hp, s; cin >> hp >> s;

    priority_queue<int> restore;
    int i;
    for (i = 1; i < N; ++i){
        int dmg = max(0, G[i] - G[i - 1]);
        restore.push(dmg);
        while (hp <= dmg and s and !restore.empty()){
            int highestrestore = restore.top();
            hp += highestrestore;
            restore.pop();
            --s;
        }
        hp -= dmg;
        if (hp <= 0){
            break;
        }
    }
    cout << i - 1 << '\n';
    return 0;
}
