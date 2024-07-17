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
    int N = s.size();
    i64 ans = 0, M = 0;
    per(i, N - 1, 0){
        if (i > 0 and s[i] == 'C' and s[i - 1] == 'B'){
            ++M;
            --i;
        } else if (s[i] == 'A'){
            ans += M;
        } else {
            M = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
