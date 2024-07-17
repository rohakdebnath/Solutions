// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define all(x) x.begin(), x.end()
// #define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
// #define per(i, fin, x) for (i64 i = fin; i >= x; --i)

// void solve()
// {
//     string s; cin >> s;
//     i64 N = s.size();
//     vector<i64> p;
//     rep(i, 0, N) if (s[i] != 'a') p.push_back(i);
//     if (p.size() == 0){
//         cout << N - 1 << '\n';
//         return;
//     }
//     i64 ans = 0;
//     i64 m = p.size();
//     rep(c, 1, m + 1){
//         if (m % c) continue;
//         i64 srv = 1;
//         rep(i, c, m){
//             if (s[p[i]] != s[p[i - c]]){ //this one checks if the supposed 't' is even repeating
//                 srv = 0;
//                 break;
//             }
//             if (i % c and p[i] - p[i - c] != p[i - 1] - p[i - c - 1]){ // this one checks if the supposed 't' is correctly spaced
//                 srv = 0;
//                 break;
//             }
//         }
//         if (!srv) continue;
//         i64 l = p[0], r = N - p[m - 1] - 1, y = N;
//         for (i64 i = c; i < m; i += c) y = min(y, p[i] - p[i - 1] - 1); //this one finds the minimum gap between patterns 
//         rep(i, 0, l + 1) ans += max<i64>(0, min(r, y - i) + 1); //this one tries to spread the pattern including the a's in it. Notice that as long as i + r <= y or r <= y - i, we can spread the pattern till r on the right side for every left spread of length i (r + 1 unique patterns for each i). as soon as r > y - i, we can only spread till y - i on the right (y - i + 1 unique patterns), after y - i = 0, we cant spread it right anymore (while the left spread is i, so like one unique pattern) and after i exceeds y, we cannot spread it anywhere (no patterns)
//     }
//     cout << ans << '\n';
// }

// int main()
// {
//     UNSYNC
//     i64 T;
//     cin >> T;
//     while(T--) solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> zfunc(string& s){
    int N = s.size();
    vector<int> z (N);
    int l = 0, r = 0;
    rep(i, 1, N){
        if (i < r){
            z[i] = min<int>(r - i, z[i - l]);
        }
        while(z[i] + i < N and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void solve()
{
    string s; cin >> s; int N = s.size();
    vector<int> np (N, N);
    per(i, N - 1, 0){
        if (s[i] != 'a') np[i] = i;
        else if (i + 1 < N) np[i] = np[i + 1];
    }
    if (np[0] == N){
        cout << N - 1 << '\n';
        return;
    }
    string r = s.substr(s.find_first_not_of('a'));
    vector<int> z = zfunc(r);

    i64 ans = 0;
    int ini = np[0];
    for (int len = 1; ini + len <= N; ++len){
        int cur = ini + len;
        int mn = ini;
        int srv = 1;
        while (cur < N){
            if (np[cur] == N) break;
            int dis = np[cur] - cur;
            cur += dis;
            mn = min(mn, dis);
            if (z[cur - ini] < len){
                srv = 0;
                break;
            }
            cur += len;
        }
        if (srv) ans += mn + 1;
    }
    cout << ans << '\n';
}   

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
