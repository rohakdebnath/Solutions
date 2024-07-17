#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

struct Job
{
    i64 start;
    i64 deadl;
};

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<Job> timings (N);
    rep(0, N) cin >> timings[i].start >> timings[i].deadl;
    sort(all(timings), [&] (Job& a, Job& b) {return a.deadl < b.deadl;});
    bool survive = true;
    i64 tottime = 0;
    rep(0, N)
    {
        tottime += timings[i].start;
        if (tottime > timings[i].deadl)
        {
            survive = false;
            break;
        }
    }
    cout << (survive ? "Yes\n" : "No\n");
    return 0;
}
