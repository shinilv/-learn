#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void write(__int128 x){
    if (x > 9)
        write(x / 10ll);
    putchar(x % 10 + '0');
}

int main() {
    __int128 a = 1;
    for (__int128 i = 2; i <= 50; i++) {
        a *= i;
        write(a);
        cout << '\n';
    }
    write(a);
}