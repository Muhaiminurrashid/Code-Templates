#include<bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;

struct segtree {
    int size;
    vector<ll>sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0LL);
    }
    void build(vector<int>&a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
        sums[x] = sums[x * 2 + 1] + sums[2 * x + 2];
    }
    void build(vector<int>&a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];

    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    ll sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        else if (lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }
    ll sum (int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    vector<int>a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    st.build(a);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << (st.sum(l, r)) << nl;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    for (int t = 1; t <= tt; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
}