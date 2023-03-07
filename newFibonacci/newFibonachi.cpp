#define MAXN 10000
#include<bits\stdc++.h>
using namespace std;

int m, n, t, k;
vector<vector<int> > mat;
vector<int> F1;
vector<vector<int> > mem;

void DFS() {
    
}

vector<int> matrixTimesLeft(vector<int> vec, vector<vector<int> > mat) {
    vector<int> res;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            res[i] += mat[i][j] * vec[i];
        }
    }
    return res;
}

void init() {
    cin >> m >> n >> t >> k;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    
    for (int i = 1; i <= m; ++i)
        cin >> F1[i];
}

int main() {
    init();
    return 0;
}