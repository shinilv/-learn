#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)

const int MAXN = 300005;

struct Node {
    int l, r;
    int minn, cnt;  // 区间最小值
    int lazy;  // 懒标记（区间加）
} tr[MAXN << 2];

int N;
long long A[MAXN];

// push_up: 合并子区间
void push_up(int p) {
    tr[p].minn = min(tr[ls].minn, tr[rs].minn);
    tr[p].cnt = tr[ls].cnt + tr[rs].cnt;
}

// push_down: 下传lazy标记
void push_down(int p) {
    if (tr[p].lazy == 0) return;
    int tag = tr[p].lazy;
    tr[ls].minn += tag;
    tr[rs].minn += tag;
    tr[ls].lazy += tag;
    tr[rs].lazy += tag;
    tr[p].lazy = 0;
}

// build: 建树
void build(int l, int r, int p = 1) {
    tr[p].l = l;
    tr[p].r = r;
    tr[p].lazy = 0;
    if (l == r) {
        tr[p].minn = A[l];
        tr[p].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    push_up(p);
}



int query(int L, int R, int k, int p = 1) {
    if (tr[p].cnt == 0) {
        return 0;
    }
    if (L <= tr[p].l && tr[p].r <= R && tr[p].minn > k) {
        tr[p].minn -= k;
        tr[p].lazy -= k;
        return tr[p].cnt * k;
    }
    if (tr[p].l == tr[p].r) {
        int res = tr[p].minn;
        tr[p].cnt = 0;
        tr[p].minn = 1e18;
        return res;
    }
    push_down(p);
    int res = 0;
    if (L <= tr[ls].r) {
        res += query(L, R, k, ls);
    }
    if (R >= tr[rs].l) {
        res += query(L, R, k, rs);
    }
    push_up(p);
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    build(1, N);

    int Q; cin >> Q;
    while (Q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << query(l, r, k) << '\n';
    }
    return 0;
}
