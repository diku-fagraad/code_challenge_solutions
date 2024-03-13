//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> ii;
typedef vector<bool> vb;

#define INF (int)1e9+1
#define INFLL (ll)1e18+1
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORS(i, n) for(int i = 1; i <= n; i++)
#define FORB(i, s, n) for(int i = s; i < n; i++)
#define FORE(x, v) for (auto &x : v)
#define REP(n) for (int _ = 0; _ < n; _++)
#define PB push_back
#define F first
#define S second
#define SORT(v) sort(v.begin(), v.end())
#define FILL(v, x) fill(v.begin(), v.end(), x)

int main() {
    int Q; cin >> Q;
    REP(Q) {
        ll n; cin >> n;
        vll L(n, 0), R(n, 0), v(n); FORE(x, v) cin >> x;
        FOR(i, n) {
            if (!i) continue;
            if (v[i-1] % v[i] == 0) L[i] = L[i-1] + 1;
        }
        for (int i = n-2; ~i; i--) {
            if (v[i+1] % v[i] == 0) R[i] = R[i+1] + 1;
        }
        ll mx = 0;
        FOR(i, n) {
            mx = max(mx, (L[i] + R[i] + 1) * v[i]);
        }
        cout << mx << endl;
    }

    return 0;
}
