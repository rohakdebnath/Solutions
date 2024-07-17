#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    UNSYNC
    ordered_set<int> os;
    int N, K; cin >> N >> K; --K; //question says K skips, or in other words (K + 1)th
    rep(i, 0, N){
        os.insert(i + 1);
    }
    int pos = K % N;
    while(os.size()){
        int ele = *os.find_by_order(pos);
        os.erase(ele);
        cout << ele << ' ';
        if (os.size()){
            pos = (pos + K) % os.size();
        }
    }
    cout << '\n';
    return 0;
}
