#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    char t; cin >> t;
    vector<string> cards (2*N); rep(i, 0, 2*N) cin >> cards[i];
    vector<string> ans;
    vector<string> trumps;

    per(i, 2*N - 1, 0){
        if (cards[i][1] == t){
            trumps.push_back(cards[i]);
            cards.erase(cards.begin() + i);
        }
    }

    while (!cards.empty()){
        string S = cards[0];
        bool fnd = false;
        rep(i, 1, cards.size()){
            if (cards[i][1] == S[1]){
                ans.push_back(cards[i]);
                ans.push_back(S);
                fnd = true;

                cards.erase(cards.begin() + i);
                cards.erase(cards.begin());
                break;
            }
        }
        if (!fnd and trumps.size() == 0) {
            cout << "IMPOSSIBLE\n";
            return;
        } else if (!fnd){
            ans.push_back(S);
            ans.push_back(trumps[0]);
            cards.erase(cards.begin());
            trumps.erase(trumps.begin());
        }
    }
    ans.insert(ans.end(), all(trumps));


    for (int i = 0; i < 2*N; i += 2) {
        if (ans[i][1] == ans[i + 1][1]){
            if (ans[i][0] > ans[i + 1][0]) cout << ans[i + 1] << ' ' << ans[i] << '\n';
            else cout << ans[i] << ' ' << ans[i + 1] << '\n';
        } else {
            if (ans[i][1] == t) cout << ans[i + 1] << ' ' << ans[i] << '\n';
            else cout << ans[i] << ' ' << ans[i + 1] << '\n';
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
