#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTreeLazyRangeMinAdd {
    vector<T> tree, lazy;
    vector<T> *arr;
    int n, root, n4, end;

    // 下推懒惰标记
    void push_down(int cl, int cr, int p) {
        if (cl != cr && lazy[p]) {
            int cm = cl + (cr - cl) / 2;
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p];
            tree[p * 2 + 1] += lazy[p];
            lazy[p] = 0;
        }
    }

    // 上推更新父节点
    void push_up(int p) {
        tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
    }

    // 区间最小值查询
    T range_min(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        int m = cl + (cr - cl) / 2;
        T min_val = numeric_limits<T>::max();
        push_down(cl, cr, p);
        if (l <= m) min_val = min(min_val, range_min(l, r, cl, m, p * 2));
        if (r > m) min_val = min(min_val, range_min(l, r, m + 1, cr, p * 2 + 1));
        return min_val;
    }

    // 区间加法更新
    void range_add(int l, int r, T val, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            lazy[p] += val;
            tree[p] += val;
            return;
        }
        int m = cl + (cr - cl) / 2;
        push_down(cl, cr, p);
        if (l <= m) range_add(l, r, val, cl, m, p * 2);
        if (r > m) range_add(l, r, val, m + 1, cr, p * 2 + 1);
        push_up(p);
    }

    // 构建线段树
    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        push_up(p);
    }

public:
    explicit SegTreeLazyRangeMinAdd(vector<T> v) {
        n = v.size();
        n4 = n * 4;
        tree.resize(n4, numeric_limits<T>::max());
        lazy.resize(n4, 0);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    // 查询区间 [l, r] 的最小值（1-based）
    T query_min(int l, int r) {
        return range_min(l - 1, r - 1, 0, end, root);
    }

    // 区间 [l, r] 加 val（1-based）
    void add(int l, int r, T val) {
        range_add(l - 1, r - 1, val, 0, end, root);
    }
};

class BT {
private:
    vector<int> tree;
public:
    BT(int n) : tree(n + 1) {}

    void add(int i, int val) {
        while (i < tree.size()) {
            tree[i] += val;
            i += i & -i;
        }
    }
    int get(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};
void solve() {
    int ac, dr;
    std::cin >> ac >> dr;
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> cnt(n + 10), f(n + 10);
    for (int i = 1; i <= n; i++) {
        int v = std::min(n + 1, std::max(a[i] - ac, 0LL) + std::max(b[i] - dr, 0LL));
        cnt[v]++;
    }
    int pre = 0;
    for (int i = 0; i <= n + 2; i++) {
        f[i] = pre - i;
        pre += cnt[i];
    }
    SegTreeLazyRangeMinAdd<int> sig(f);
    BT bt(n + 10);
    for (int i = 0; i <= n + 1; i++) {
        bt.add(i + 1, cnt[i]);
    }
    int m;
    std::cin >> m;
    while (m--) {
        int k, x, y;
        std::cin >> k >> x >> y;
        int t = std::max(a[k] - ac, 0LL) + std::max(b[k] - dr, 0LL);
        t = std::min(n + 1, t);
        sig.add(t + 2, n + 3, -1);
        bt.add(t + 1, -1);
        a[k] = x, b[k] = y;      
        t = std::max(a[k] - ac, 0LL) + std::max(b[k] - dr, 0LL);
        t = std::min(n + 1, t);
        sig.add(t + 2, n + 3, 1);
        bt.add(t + 1, 1);
        int l = 1, r = n + 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (sig.query_min(1, mid) >= 0) l = mid;
            else r = mid - 1;
        }
        std::cout << bt.get(l) << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}