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
    string s; cin >> s;
    int c = accumulate(all(s), 0, [&] (int x, char c) {return (c >= 'a') + x;});
    if (c > s.size() / 2){
        transform(all(s), s.begin(), [] (char c) {return tolower(c);});
    } else {
        transform(all(s), s.begin(), [] (char c) {return toupper(c);});
    }
    cout << s << '\n';
    return 0;
}
