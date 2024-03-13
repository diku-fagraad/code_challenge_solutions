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
    ll b; cin >> b;
    map<string,ll> mp;
    FOR(i,b){
        string s; cin >> s;
        mp[s]=i+1;
    }
    string s; cin >> s;
    string tm="";
    ll mlt=1,sm=0;
    vector<string> ar;
    for (auto c: s){
        tm+=c;
        if (mp[tm]){
            ar.PB(tm);
            tm="";
        }
    }
    for (int i=ar.size()-1; i>=0; i--){
        sm+=(mp[ar[i]]-1)*mlt;
        mlt*=b;
    }
    cout << sm << endl;
    return 0;
}
