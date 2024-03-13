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
    ll m,c,n; cin >> m;
    FOR(_,m){
        cin >> c >> n;
        int arr[40];
        int k=40;
        while (n>1){
            k--;
            arr[k]=n%2;
            n = n / 2;
        }
        pair<ll,ll> pr={1,1};
        while (k<40){
            if (arr[k]) pr.second+=pr.first;
            else pr.first+=pr.second;
            k++;
        }
        cout << c << " " << pr.S << "/" << pr.F << endl;
    }

    return 0;
}
