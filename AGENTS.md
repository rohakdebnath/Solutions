# C++ style

Follow the user's newer competitive-programming style when writing C++.
Representative files: `MISC/inmobi1.cpp`, `MISC/inmobi2.cpp`,
`MISC/inmobi3.cpp`, `MISC/inmobi4.cpp`, `MISC/prefixfunc.cpp`, and
`CodeForces/919D.cpp`. Do not use the older `UNSYNC` template as a reference.

- Start with `#include <bits/stdc++.h>`, then `using namespace std;` and
  `using i64 = long long;`.
- Usually put the solution in `void solve()`. Use `signed main()` with its
  opening brace on the next line, explicit fast I/O on one line,
  `solve();`, and `return 0;`. Add a test-case loop only when required.
- Use four-space indentation. Opening braces for `solve`, most helpers,
  structs, loops, and conditionals go on the same line. Preserve local
  formatting when editing existing code.
- Prefer ordinary loops such as `for (int i = 0; i < n; ++i)` and range loops
  such as `for (int u: adj[v])`. Do not reintroduce `UNSYNC`, `rep`, `sci`,
  `all`, `VI`, or `VVI` macros from older files.
- Use compact declarations and input, e.g. `int n, m; cin >> n >> m;`.
  Group closely related variables. Keep short single-statement branches
  and loops on one line when readable.
- Use spaces around operators and after commas. Prefer `and` and `or`
  for logical combinations, as in the newer examples.
- Use short, conventional names such as `n`, `m`, `a`, `ans`, `adj`,
  `dp`, `vis`, `curr`, `pref`, and `suff`.
- Prefer local STL containers, zero-based indexing, and straightforward
  functions or capturing lambdas. Use small structs when the algorithm
  benefits from them; avoid unnecessary abstraction.
- Use `int` normally and `i64` where the value range requires it.
- Output with `cout` and `'\n'`; array output may use `" \n"[i == n - 1]`.
- Keep comments sparse and useful, explaining an invariant or DP meaning
  rather than narrating each statement.
- These are style preferences, not reasons to copy bugs, incomplete code,
  or unnecessary complexity. Do not reformat unrelated existing code.

Typical skeleton:

```cpp
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
```
