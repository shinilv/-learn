#include <bits/stdc++.h>
#define int long long

signed main() {
    std::map<std::string, std::string> mp;
    mp["red"] = "SSS";
    mp["blue"] = "FFF";
    mp["green"] = "MMM";
    std::string s;
    std::cin >> s;
    if (mp.count(s)) {
        std::cout << mp[s] << '\n';
    } else {
        std::cout << "Unknown\n";
    }
    return 0;
} 