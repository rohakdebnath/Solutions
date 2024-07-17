#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> move(const vector<int>& g){
    cout << "next ";
    rep(i, 0, g.size()) cout << g[i] << " \n"[i == g.size() - 1];
    cout.flush();
    int N; cin >> N;
    vector<int> positions (10);
    rep(i, 0, N){
        string s; cin >> s;
        for (char c: s) positions[c - '0'] = i;
    }
    return positions;
}

int main()
{
    UNSYNC
    move({0, 1});
    vector<int> pos = move({1});
    while (pos[0] != pos[1]){
        move({0, 1});
        pos = move({1});
    }

    while (pos[1] != pos[2]){
        pos = move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    }
    cout << "done\n";
    return 0;
}
