#include <bits/stdc++.h>
// #pragma GCC optimize(2)
using namespace std;
int n, x[4000010], v[4000010];
inline bool check(double t)
{
	double maxx = -1, minn = 2000000000;
	for (int i = 1; i <= n; i++)
	{
		maxx = max(x[i] - t * v[i], maxx);
		minn = min(x[i] + t * v[i], minn);
	}
	if (minn >= maxx)
	{
		return false;
	}
	return true;
}
// inline int read(){
//     int x=0,f=1;
//     char ch=getchar();
//     while(ch<'0'||ch>'9'){
//         if(ch=='-')
//             f=-1;
//         ch=getchar();
//     }
//     while(ch>='0'&&ch<='9'){
//         x=(x<<1)+(x<<3)+(ch^48);
//         ch=getchar();
//     }
//     return x*f;
// }
// inline char nc(){
//     static char buf[100000],*p1=buf,*p2=buf;
//     return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
// }
// inline int read(){
//     char ch=nc();int sum=0;
//     while(!(ch>='0'&&ch<='9'))ch=nc();
//     while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+(ch^48),ch=nc();
//     return sum;
// }
inline int read()
{
	char ch = getchar();
	int sum = 0;
	while (!(ch >= '0' && ch <= '9'))
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
	return sum;
}
int main()
{
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	//	freopen("7656767.out","w",stdout);
	//	register int t=clock();
	n = read();
	for (register int i = 1; i <= n; i++)
	{
		x[i] = read();
	}
	for (register int i = 1; i <= n; i++)
	{
		v[i] = read();
	}
	double l = 0, r = 1000000000, mid;
	while (r - l >= 1e-7)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid;
		}
		else
			r = mid;
	}
	printf("%.5lf\n", l);
	//	cout<<clock()-t;
}
