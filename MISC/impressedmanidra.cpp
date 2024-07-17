#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void decode(string s, int i, string ds){
    if (i > s.size()) return;
    if (i == s.size()){
        cout << ds << '\n';
    }
    if (i < s.size()){
        char c = s[i] - '0' + 'a' - 1;
        if (c >= 'a' and c <= 'z') decode(s, i + 1, ds + c);
    } 
    if (i + 1 < s.size()){
        char c = (s[i] - '0') * 10 + s[i + 1] - '0' + 'a' - 1;
        if (s[i] != '0' and c >= 'a' and c <= 'z'){
            decode(s, i + 2, ds + c);
        }
    }
}

int main()
{
    UNSYNC
    string s; cin >> s;
    string f = "";
    for (char c: s){
        f += to_string(c - 'a' + 1);
    }
    decode(f, 0, "");
    return 0;
}
