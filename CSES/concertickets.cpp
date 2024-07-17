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

int main()
{
    UNSYNC
    int n, m; cin >> n >> m;
    multiset<int> ticket;
    rep(i, 0, n){
        int t; cin >> t;
        ticket.insert(t);
    }
    rep(i, 0, m){
        int h; cin >> h;
        auto it1 = ticket.lower_bound(h);
        if (it1 == ticket.begin()){
            if (*it1 != h){
                cout << "-1\n";
            } else{
                cout << h << '\n';
                ticket.erase(it1);
            }
        } else {
            if (it1 == ticket.end()){
                --it1;
                ticket.erase(it1);
                cout << *it1 << '\n';
            }
            else{
                if (*it1 == h){
                    cout << h << '\n';
                    ticket.erase(it1);
                }else {
                    --it1;
                    cout << *it1 << '\n';
                    ticket.erase(it1);
                }
            }
        }
    }
    return 0;
}
