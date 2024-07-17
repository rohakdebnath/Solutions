#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const string KEY = "KEY";
map<string, map<i64, i64>> vis;
i64 swapmem(string s, i64 remswap){
    i64 N = s.size();
    if (remswap < 0) return 0;
    if (N == 0) return 1;
    if (vis[s][remswap] != 0) return vis[s][remswap];
    rep(i, 0, 3){
        rep(j, 0, N){
            if (s[j] == KEY[i]){
                vis[s][remswap] += swapmem(s.substr(0, j) + s.substr(j + 1), remswap - j);
                break; //break because we only want to consider the first occurance of any character that we are looking for, consider KEEY, lets say we picked K first, remaining string is EEY, now lets say we are looking for an E next, there are two ways to pick an E, obviously we pick the first one and save ourselves a swap. Thats why we must break, If we work in an optimised manner, each string can only have a specific swap associated with it. In this way no two final/intermediate strings can be the same and require different swaps to reach them. You may wonder what happens to the intermediate string where we pick K then E then another E. Note that such a string will be selected through picking K then E then picking E from the string "EY" left after picking the first E from "EEY".
            }
        }
    }
    return vis[s][remswap];
}

int main()
{
    UNSYNC
    string s; cin >> s;
    i64 K; cin >> K;
    cout << swapmem(s, K) << '\n';
    return 0;
}
