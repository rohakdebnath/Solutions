// C. The Fragmented Guardian: Reunion of the Lost Mind-2
// time limit per test1 second
// memory limit per test256 megabytes
// Long before recorded time, Arctavia was shielded by a colossal celestial being known simply as The Guardian — a timeless protector forged from pure astral essence. The Guardian's presence kept storms calm, beasts tamed, and the skies bright.But during the Night of the Shattered Star, a meteor of forbidden magic struck the Guardian, splintering its consciousness into N self-aware fragments.These fragments — tiny glowing orbs resembling floating embers — scattered across the kingdom.Some drifted into ancient forests, some hid inside abandoned temples, and some wandered through towns unseen by human eyes.For centuries, the fragments survived alone — confused, drifting, and incomplete.

// Recently, an ethereal pulse rippled across Arctavia.Each fragment felt a faint pull… a reminder of their forgotten unity. Whenever two fragments come close enough, they instinctively merge their memories, forming a larger and more stable group.You, the Royal Chronicler, have been tasked by the astronomers to monitor these reunions.

// At the start:There are N fragments, each forming a group of size 1.As the fragments meet and reunite, groups merge.Some meetings are redundant — two fragments might already belong to the same reunited cluster. The astronomers wish to analyze the Guardian's reformation process. You are given Q mystical encounters.Each encounter describes two fragments that suddenly sense each other's presence:

// Event: Fragment A encounters Fragment B, triggering a potential merging of their groups.After each encounter, the astronomers ask:"Among all existing fragment-groups, output the minimum difference between two groups.If there is only one group, output 0. At first, everyone is in their own group.

// Input
// First line: two integers N and Q

// N = number of Guardian fragments

// Q = number of recognition events

// Each of the next Q lines contains two integers A and B, meaning fragment A encounters fragment B.

// 1≤N≤1e5

// 1≤Q≤1e5

// Output
// For each event, print one line:output the minimum difference between two groups. If there is only one group, output 0. At first, everyone is in their own group .



#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> s;

public:
    DSU(T n) : parent(n), s(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    T find(T x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    bool merge(T x_, T y_) {
        T x = find(x_);
        T y = find(y_);

        if (x == y) return false; 

        if (s[x] < s[y]) {
            parent[x] = y;
            s[y] += s[x];
        } else {
            parent[y] = x;
            s[x] += s[y];
        };
        return true;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    int size (int x) {
        return s[find(x)];
    }
};

void solve() {
    int n, q; cin >> n >> q;
    DSU d (n);
    set<int> sizes;
    for (int i = 0; i < n; ++i) sizes.insert(1);
    int s = 0;
    while (q--) {
        int x, y; cin >> x >> y;
        --x; --y;
        int s1 = d.size(x), s2 = d.size(y);
        if (d.merge(x, y)) {

        }
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
