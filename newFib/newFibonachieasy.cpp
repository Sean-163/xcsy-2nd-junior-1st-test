// #define DEBUG
#define MAXN 100000000
#define variable_type long long
#include<bits\stdc++.h>
using namespace std;

variable_type m, n, k;
variable_type mem[MAXN];

int newFib(variable_type n) {
    if(mem[n] != -1)
        return mem[n];

    variable_type ret = 0;
    for(variable_type i = 1; i <= n / k; ++i) {
        mem[i] = newFib(i);
        ret += mem[i];
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