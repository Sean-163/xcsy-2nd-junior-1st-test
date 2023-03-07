#define MAXN 10000000
// #define DEBUG
#include<bits\stdc++.h>
using namespace std;

int m, n, k;
int mem[MAXN];

int newFib(int n) {
    if(mem[n] != -1)
        return mem[n];
    int ret = 0;
    for(int i = 1; i <= n / k; ++i) {
        ret += newFib(i);
    }
    return ret;
}

void init() {
    cin >> n >> k;
    memset(mem, -1, sizeof(mem));
    cin >> mem[1];
}

int main() {
    init();
    cout << newFib(n);
    return 0;
}