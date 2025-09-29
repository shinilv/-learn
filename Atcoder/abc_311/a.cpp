#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    // 了解set的用法：https://www.runoob.com/cplusplus/cpp-libs-set.html
    std::set<char> se;
    for (int i = 0; i < n; i++) {
        se.insert(s[i]);
        if (se.size() == 3) {
            std::cout << i + 1 << '\n';
            return 0;
        }
    }
    return 0;
}