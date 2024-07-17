#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 dig[] = {7, 5, 3};
i64 N; 
i64 rec(string s = "0"){
    i64 ans = 0;
    if (stol(s) > N) return 0;
    if (find(all(s), '7') != s.end() and find(all(s), '5') != s.end() and find(all(s), '3') != s.end()) ans = 1;

    rep(i, 0, 3){
        ans += rec(s + char(dig[i] + '0'));
    }
    return ans;
}

int main()
{
    UNSYNC
    cin >> N;
    cout << rec() << '\n';
    return 0;
}
