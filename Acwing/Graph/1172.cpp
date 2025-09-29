#include <bits/stdc++.h>
#define int long long

const int N = 4e4 + 10;
int dep[N], fath[N], siz[N], son[N], top[N];
std::vector<std::vector<int>> g(N);

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;   // 当前节点深度 = 父节点深度 + 1
    fath[u] = f;           // 记录父节点
    siz[u] = 1;            // 初始化子树大小为 1（自身）
    son[u] = 0;            // 初始化重儿子为 0（表示无）

    for (auto &v : g[u]) { // 遍历 u 的所有邻居
        if (v == f) continue; // 跳过父节点（避免往回走）

        dfs1(v, u);          // 递归处理子节点 v

        siz[u] += siz[v];    // 累加子树大小
        if (siz[v] > siz[son[u]]) // 如果 v 的子树比当前记录的重儿子还大
        son[u] = v;        // 更新重儿子为 v
    }
}

void dfs2(int u, int t) {
    top[u] = t;                    // u 所在链的顶端是 t

    if (son[u])                    // 如果 u 有重儿子
        dfs2(son[u], t);             // 优先遍历重儿子，继承同一条链（链头不变）

    for (auto &v : g[u]) {         // 遍历其他轻儿子
        if (v == fath[u] || v == son[u])
        continue;                  // 跳过父节点和重儿子
        dfs2(v, v);                  // 轻儿子开启新链，链头就是自己
    }
}
int lca(int x, int y) {
    while (top[x] != top[y]) {     // 当 x 和 y 不在同一条链上
        if (dep[top[x]] < dep[top[y]])
        std::swap(x, y);                // 保证 x 的链头更深（或更高？见下文解释）

        x = fath[top[x]];            // 将 x 跳到当前链头的父节点
    }
    // 此时 x 和 y 在同一条链上
    return dep[x] < dep[y] ? x : y; // 深度小的为 LCA
}

signed main() {
    int n, u, v;
    std::cin >> n;
    int root = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> u >> v;
        if (v == -1) {
            root = u;
            continue;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(root, 0);
    dfs2(root, root);
    int m;
    std::cin >> m;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        int t = lca(a, b);
        if (t == a) {
            std::cout << "1\n";
        } else if (t == b) {
            std::cout << "2\n";
        } else {
            std::cout << "0\n";
        }
    }
    return 0;
} 
