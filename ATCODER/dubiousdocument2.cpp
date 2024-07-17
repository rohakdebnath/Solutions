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

bool fitting(string s1, string s2){
    rep(i, 0, s1.size()){
        if (!(s1[i] == '?' or (s1[i] == s2[i]))){
            return false;
        }
    }
    return true;
}

int main()
{
    UNSYNC
    string s, t; cin >> s >> t;
    if (s.size() < t.size()){
        cout << "UNRESTORABLE\n";
        return 0;
    }
    bool found = false;
    per(i, s.size() - t.size(), 0){
        string sub = s.substr(i, t.size());
        if (fitting(sub, t)){
            s.replace(i, t.size(), t);
            found = true;
            break;
        }
    }

    transform(s.begin(), s.end(), s.begin(), [&](char c) {
        return (c == '?') ? 'a' : c;
    });
    if (found) cout << s << '\n';
    else cout << "UNRESTORABLE\n";
    return 0;
}
