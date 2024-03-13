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

vvi dp(105, vi(205));

int n;
string s, t;

int rec(int i, int res) {
    if (i == n && !res) return 0;
    if (i == n && res) return INF;
    if (~dp[i][res+100]) return dp[i][res+100];
    int ans = INF;
    if (s[i] == t[i]) ans = min(ans, rec(i+1, res));
    if (s[i] == '0') {
        if (t[i] == '1') ans = min(ans, rec(i+1, res) + 1);
        if (t[i] == '0') ans = min(ans, rec(i+1, res + 1) + (res >= 0));
    }
    if (s[i] == '0' && t[i] == '1') ans = min(ans, rec(i+1, res-1) + (res <= 0));
    if (s[i] == '1' && t[i] == '0') ans = min(ans, rec(i+1, res+1) + (res >= 0));
    if (s[i] == '?') {
        ans = min(ans, rec(i+1, res) + 1);
        if (t[i] == '1') ans = min(ans, rec(i+1, res - 1) + 1 + (res <= 0));
        if (t[i] == '0') ans = min(ans, rec(i+1, res + 1) + 1 + (res >= 0));
    }
    dp[i][res+100] = ans;
    return ans;
}

int main() {
    int Q; cin >> Q;
    FOR(i, Q) {
        cin >> s >> t;
        n = s.length();
        FORE(x, dp) {
            FORE(y, x) y = -1;
        }
        int ans = rec(0, 0);
        cout << "Case " << i+1 << ": " << (ans >= INF ? -1 : ans) << endl;
    }

    return 0;
}
