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
    string s; getline(cin, s);
    string t = "";
    for (char c: s){
        if (c == ' ') continue;
        else t += c;
    }
    int N; cin >> N;
    rep(i, 0, t.size()){
        cout << t[i];
        if ((i + 1) % 5 == 0) cout << '\n';
    }

    return 0;
}
