#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int N = 0, E = 0;
    rep(i, 0, n){
        if (s[i] == 'N') ++N;
        else if (s[i] == 'S') --N;
        else if (s[i] == 'W') --E;
        else ++E;
    }

    if (abs(N) % 2 or abs(E) % 2){
        cout << "NO\n";
    } else {
        N /= 2, E /= 2;
        if (s[0] == 'E'){
            --E;
        } else if (s[0] == 'W'){
            ++E;
        } else if (s[0] == 'N'){
            --N;
        } else {
            ++N;
        }
        s[0] = 'R';
        rep(i, 1, n){
            if (s[i] == 'N' and N > 0){
                s[i] = 'R'; --N;
            } else if (s[i] == 'S' and N < 0){
                s[i] = 'R'; ++N;
            } else if (s[i] == 'E' and E > 0){
                s[i] = 'R'; --E;
            } else if (s[i] == 'W' and E < 0){
                s[i] = 'R'; ++E;
            } else {
                s[i] = 'H';
            }
        }
        int countR = count(all(s), 'R');
        if (countR == int(s.size())){
            cout << "NO\n";
        } else {
            cout << s << '\n';
        }
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
