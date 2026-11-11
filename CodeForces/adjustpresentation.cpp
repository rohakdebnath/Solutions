//technique learnt from jiangly: how to make a function corresponding to the correct order of a and first occs of b
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<int> b (m); for (int i = 0; i < m; ++i) cin >> b[i], --b[i];

    int v = 0;
    vector<int> pa (n);
    for (int i = 0; i < n; ++i) {
        pa[a[i]] = i;
    }
    map<int, int> f;
    auto add = [&] (int i) {
        auto [it, added] = f.emplace(i, b[i]);
        if (!added) return;

        auto r = next(it);
        if (r != f.end()) {
            v += (pa[r->second] != pa[b[i]] + 1);
        }
        if (it != f.begin()) {
            auto l = prev(it);
            v += (pa[b[i]] - 1 != pa[l->second]);
            if (r != f.end()) {
                v -= (pa[r->second] - 1 != pa[l->second]);
            }
        }
    };
    auto remove = [&] (int i) {
        auto it = f.find(i);
        if (it == f.end()) return;

        auto r = next(it);
        if (r != f.end()) {
            v -= (pa[r->second] != pa[b[i]] + 1);
        }
        if (it != f.begin()) {
            auto l = prev(it);
            v -= (pa[b[i]] - 1 != pa[l->second]);
            if (r != f.end()) {
                v += (pa[r->second] - 1 != pa[l->second]);
            }
        }
        f.erase(it);
    };
    auto valid = [&] () {
        return (v == 0 and (f.begin()->second == a[0]));
    };

    vector<set<int>> ids (n);
    for (int i = 0; i < m; ++i) {
        ids[b[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (!ids[i].empty()) {
            add(*ids[i].begin());
        }
    }
    cout << (valid() ? "YA\n": "TIDAK\n");
    while (q--) {
        int s, t; cin >> s >> t; --s, --t; //b[s] = t

        remove(s);
        ids[b[s]].erase(s);
        if (!ids[b[s]].empty()) {
            add(*ids[b[s]].begin());
        }
        b[s] = t;
        if (!ids[t].empty()) {
            remove(*ids[t].begin());
        }
        ids[t].insert(s);
        add(*ids[t].begin());

        cout << (valid() ? "YA\n": "TIDAK\n");
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

//notes:
//order of first occurances of the characters in b should be the same as the order of characters in a, 
//eg a = 3 1 2 4 and b = 3 1 1 2 3 4 the order of first occurances of b is 3 1 2 4, so it's valid. we can maintain a variable 'd' which counts the number of misorders in an first occurances of elements of b, d = 0 means correct order
//the set of b (sorted by index of first occ, maybe we can use a map for it) should be a prefix of a, we can store the indexes where 'i' appears in a set to quickly access the first occurance after updates
//we can update b[s] = t easily. first remove the index s from the set of b[s], and insert s in set of t. now we need to account for the changes made in b[s] and t
//we erase b[s] from my map, insert b[s] corresponding to the second smallest index. 
//remove the smallest index in the set of t, insert s on set of t, then again insert the smallest index from the set of t.

//on how to measure d:
//relative order can be measured by determining the correct or incorrect order of only it's neighbours, this function is not uniquely mapped to each permutation but = 0 uniqely (due to how we are calculating) if the neighbours are in correct order, which is enough
//in general we insert an element between two existing numbers, we inc v if the relative order of the inserted element with it's right neighbour is wrong. same for left
//if the relative order of the left and right elements are not correct "before" adding this element in between them, then dec v by 1, since they are no longer neighbours and thus their "unorderedness" should not reflect in our v
