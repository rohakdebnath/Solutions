#include <bits/stdc++.h>
using namespace std;

int b[3][3], x[3], sc[3];

void chk_ill() {
    if (x[1] < x[2] or x[1] - x[2] > 1) {
        cout << "illegal", exit(0);
    }
}

void chk_win() {
    if (b[0][0] == b[1][1] and b[1][1] == b[2][2]) ++sc[b[0][0]];
    if (b[0][2] == b[1][1] and b[1][1] == b[2][0]) ++sc[b[0][2]];
    for (int i = 0; i <= 2; ++i) {
        if (b[i][0] == b[i][1] and b[i][1] == b[i][2]) ++sc[b[i][0]];
        if (b[0][i] == b[1][i] and b[1][i] == b[2][i]) ++sc[b[0][i]];
    }
}

void chk_drw() {
    if ((sc[1] and sc[2]) or (sc[1] > 0 and x[2] == x[1]) or (sc[2] > 0 and x[1] > x[2])) {
        cout << "illegal", exit(0);
    }
    if (sc[1] > sc[2]) {
        cout << "the first player won", exit(0);
    }
    if (sc[1] < sc[2]) {
        cout << "the second player won", exit(0);
    }
}

void chk_turn() {
    if (!x[0]) return;
    if (x[1] > x[2] and x[1] - x[2] == 1) {
        cout << "second", exit(0);
    }
    if (x[1] == x[2]) {
        cout << "first", exit(0);
    }
}

void solve() {
    char c;
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            while ((c = getchar()) != 'X' and c != '0' and c != '.');
            if (c == 'X') b[i][j] = 1;
            if (c == '0') b[i][j] = 2;
            ++x[b[i][j]];
        }
    }
    chk_ill();
    chk_win();
    chk_drw();
    chk_turn();
    cout << "draw", exit(0);
}

int main() {
    solve();
    return 0;
}
