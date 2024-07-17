#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

struct Movie{
    int start = 0;
    int end = 0;
    friend bool operator<(const Movie& a, const Movie& b) {return a.end < b.end;}
};

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<Movie> movies (N);
    rep(i, 0, N) cin >> movies[i].start >> movies[i].end;
    sort(all(movies));
    int counter = 0;
    int currend = -1;
    rep(i, 0, N){
        if (movies[i].start >= currend){
            ++counter;
            currend = movies[i].end;
        }
    }
    cout << counter << '\n';
    return 0;
}
