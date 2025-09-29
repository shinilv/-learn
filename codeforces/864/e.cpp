#include <bits/stdc++.h>
#define int long long

int n, m;
const int N = 1e5 + 10, M = 5e6 + 10;
int phi[M], p[M], pc, a[N];
bool st[M];

void init(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!st[i]) {
			phi[i] = i - 1;
			p[pc++] = i;
		}
		for(int j = 0; p[j] <= n / i; j++) {
			st[i * p[j]] = true;
			if(i % p[j] == 0) {
				phi[i * p[j]] = p[j] * phi[i];
				break;
			}
			phi[i * p[j]] = (p[j] - 1) * phi[i];
		}
	}
}

struct node {
    int l, r, cnt, mx, len, flag;
}tr[4 * N];

void pushup(node& root, node& le, node& ri) {
    root.len = le.len + ri.len;
    root.flag = le.flag && ri.flag;
    root.cnt = le.cnt + ri.cnt;
    int x = le.mx, y = ri.mx;
    while (x != y) {
        if (x > y) {
            x = phi[x], root.cnt += le.len;
        } else {
            y = phi[y], root.cnt += ri.len;
        }
    }
    root.mx = x;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    // std::cout << u << '\n';
    if (l == r) {
        tr[u] = {l, r, 0, a[r], 1, a[r] == 1};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void update(int u, int l, int r) {
    if (tr[u].flag) return;
    if (tr[u].l == tr[u].r) {
        tr[u].mx = phi[tr[u].mx];
        tr[u].flag = (tr[u].mx == 1);
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) update(u << 1, l, r);
    if (r > mid) update(u << 1 | 1, l, r);
    pushup(u);
}

node query(int u, int l, int r) {
    // std::cout << u << '\n';
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u];
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) {
        return query(u << 1, l, r);
    }
    if (l > mid) {
        return query(u << 1 | 1, l, r);
    }
    node res, le = query(u << 1, l, r), ri = query(u << 1 | 1, l, r);
    pushup(res, le, ri);
    return res;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    init(5e6);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if (op == 1) {
            update(1, l, r);
        } else {
            // std::cout << l << ' ' << r << '\n';
            std::cout << query(1, l, r).cnt << '\n';
        }
    }
    return 0;
}