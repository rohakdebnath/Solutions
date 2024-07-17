#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    i64 ctBA = 0;
    i64 ctB_ = 0;
    i64 ct_A = 0;
    i64 ans = 0;
    rep(i, 0, N){
        string s; cin >> s;
        for (i64 pos = s.find("AB"); pos != string::npos; pos = s.find("AB", pos + 1)) {
            ++ans;
        }
        if (s[0] == 'B' and *s.rbegin() == 'A') ++ctBA;
        else if (s[0] == 'B') ++ctB_;
        else if (*s.rbegin() == 'A') ++ct_A;
    }
    if (ctBA == 0){
        ans += min(ctB_, ct_A);
    } else if (ctBA and (ct_A + ctB_)){
        ans += ctBA + min(ct_A, ctB_);
    } else if (!(ct_A + ctB_)){
        ans += ctBA - 1;
    }
    cout << ans << '\n';
    return 0;
}
