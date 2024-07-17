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
    int N, K; cin >> N >> K;
    vector<Movie> movies (N);
    rep(i, 0, N) cin >> movies[i].start >> movies[i].end;
    sort(all(movies));
    multiset<int> order;
    int watched = 0;
    rep(i, 0, N){
        if (order.empty()){
            order.insert(movies[i].end);
            ++watched;
        } else {
            auto it = order.lower_bound(movies[i].start);
            if (it != order.begin()) --it;
            if (*it <= movies[i].start){
                order.erase(it);
                order.insert(movies[i].end);
                ++watched;
            }
            else if (sci(order.size()) < K) order.insert(movies[i].end), ++watched;
        }
    }
    cout << watched << '\n';
    return 0;
}
