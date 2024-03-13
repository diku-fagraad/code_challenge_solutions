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
    int n; cin >> n;
    bool left = 1, right = 1;
    int lb = 8, rb = 8, lt = 8, rt = 8;
    REP(n) {
        char a, b, c; string in; cin >> in >> c; a = in[0]; b = in[1];
        if (c == 'b') {
            if (b == '+' || b == '-') {
                right = 0;
            }
            else {
                left = 0;
            }
        }
        else {
            if (b == '-') {
                rb--;
            }
            else if (b == '+') {
                rt--;
            }
            else if (a == '-') {
                lb--;
            }
            else if (a == '+') {
                lt--;
            }
        }
    }
    left = left && (bool)lb && (bool)lt;
    right = right && (bool)rb && (bool)rt;
    if (left) cout << 0 << endl;
    else if (right) cout << 1 << endl;
    else cout << 2 << endl;

    return 0;
}
