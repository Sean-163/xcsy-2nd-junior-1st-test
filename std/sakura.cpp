#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int n, q, m, p;
int a[MAXN];

struct Node
{
	int lS, rS, F, S;
} T[MAXN << 2];

struct st
{
	int ll, rr;
} to[MAXN];

Node pushup(Node A, Node B)
{
	Node ret;
	ret.S = A.S + B.S;
	ret.lS = max(A.lS, A.S + B.lS);
	ret.rS = max(B.rS, B.S + A.rS);
	ret.F = max(A.F, B.F);
	ret.F = max(ret.F, A.rS + B.lS);
	return ret;
}

void build(int rt, int l, int r)
{
	if (l == r)
	{
		T[rt].F = T[rt].lS = T[rt].rS = T[rt].S = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
	T[rt] = pushup(T[rt << 1], T[rt << 1 | 1]);
	return;
}

Node query(int x, int y, int l, int r, int rt)
{
	if (x <= l && r <= y)
		return T[rt];
	int mid = (l + r) >> 1;
	if (y <= mid)
		return query(x, y, l, mid, rt << 1); // ������Ͳ�ѯ����û�н�������������
	if (x > mid)
		return query(x, y, mid + 1, r, rt << 1 | 1);

	return pushup(query(x, y, l, mid, rt << 1), query(x, y, mid + 1, r, rt << 1 | 1));
}

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

int main()
{
	freopen("sakura.in", "r", stdin);
	freopen("sakura.out", "w", stdout);
	ios ::sync_with_stdio(false);
	p = read();
	n = read();
	m = read();
	for (int i = 1; i <= p; i++)
	{
		to[i].ll = read(), to[i].rr = read();
	}
	for (int i = 1; i <= m + 10; i++)
		a[i] = -2e9;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int k = read();
			a[j] = max(a[j], k);
		}
	build(1, 1, m);
	for (int i = 1; i <= p; i++)
	{
		cout << query(to[i].ll, to[i].rr, 1, m, 1).F << endl;
	}
	return 0;
}
