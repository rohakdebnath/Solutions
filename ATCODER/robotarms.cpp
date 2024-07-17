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
    int N; cin >> N;
    vector<pair<int, int>> sch (N);
    rep(i, 0, N){
        int X, L; cin >> X >> L;
        sch[i] = {X - L, X + L};
    } 
    sort(all(sch), [&] (auto i, auto j) {return i.second < j.second;});
    int last = -INT32_MAX;
    int count = 0;
    rep(i, 0, N){
        if (sch[i].first >= last){
            ++count;
            last = sch[i].second;
        }
    }   
    cout << count << '\n';
    return 0;
}
