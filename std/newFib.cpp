// #define DEBUG
#define MAXN 100000000
#define variable_type long long
#include <bits\stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
variable_type m, n, k;
variable_type mem[MAXN];

variable_type newFib(variable_type n)
{
    if (mem[n] != 0)
        return mem[n] % mo;

    variable_type ret = 0;
    for (variable_type i = 1; i <= n / k; ++i)
    {
        mem[i] = newFib(i) % mo;
        ret += mem[i] % mo;
    }
    mem[n] = ret % mo;
    return ret % mo;
}

void specialQuestion()
{
    if (n < k)
    {
        cout << 0;
        exit(0);
    }
}

void init()
{
    cin >> n >> k;
    cin >> mem[1];
    specialQuestion();
}

int main()
{
    freopen("newFib.in", "r", stdin);
    freopen("newFib.out", "w", stdout);
    init();
    cout << newFib(n) % mo;
    return 0;
}
