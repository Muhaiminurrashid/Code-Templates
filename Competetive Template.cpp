#include<bits/stdc++.h>
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define ll long long
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
const char nl = '\n';
#define ump unordered_map
using namespace std;
const int MOD = 1e9 + 7;

void io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// sieve
const int N = 1e7 + 10;
vector<bool>isPrime(N, 1);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    int k = 1;
    for (int i = 2; i < N; i++) {
        if (isPrime[i] == true) {
            for (int j = i * 2; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
// prime factor
void pf() {
    ump<int, int>prime_factors;
    prime_factors.clear();
    int num = n;
    while (num > 1) {
        int prime_factor = hp[num];
        while (num % prime_factor == 0) {
            num /= prime_factor;
            prime_factors[prime_factor]++;
        }
    }
}
// binary multi
ll binMulti(ll a, ll b) {
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % MOD;
        }
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}
// binary expo
ll binexpIter(int a, int b, int mod) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a ) % mod;
        b >>= 1;
    }
    return ans;
}


// binary search
int binary_search(vi &v, int c) {
    int lo = 0, hi = v.size() - 1;
    int a = -1;
    while (hi >= lo) {
        ll mid = lo + (hi - lo) / 2;
        if (v[mid] > c) {
            a = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return a;
}


void solve() {

}
int main() {
    io()
    int tt = 1;
    //cin >> tt;
    for (int t = 1; t <= tt; t++) {
        //cout << "Case " << t << ": ";
        // cout << (solve() ? "YES\n" : "NO\n");
        solve();
    }
}
