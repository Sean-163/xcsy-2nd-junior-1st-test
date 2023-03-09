#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> M;
map<string, string> cf;
void _start()
{
	cf["T:"] = "T:";
	cout << "start=>OK" << endl;
}
void _create(string s)
{
	vector<string> V;
	while (s.find_first_of("\\") != string::npos)
	{
		V.push_back(s.substr(0, s.find_first_of("\\")));
		s = s.substr(s.find_first_of("\\") + 1);
	}
	V.push_back(s);
	if (cf.count(s) == 1)
	{
		cout << "create=>ERROR" << endl;
		return;
	}
	vector<string>::iterator it;
	string pth = "";
	for (it = V.begin(); it < V.end() - 1; it++)
	{
		pth += *it;
		cf[*it] = pth;
		pth += "\\";
		M[*it].push_back(*(it + 1));
	}
	pth += *it;
	cf[*it] = pth;
	cout << "create=>OK" << endl;
}
void _list(string s)
{
	s = s.substr(s.find_last_of("\\") + 1);
	if (cf.count(s) == 0)
	{
		cout << "list=>ERROR" << endl;
		return;
	}
	cout << M[s].size() << endl;
	vector<string>::iterator it;
	for (it = M[s].begin(); it < M[s].end(); it++)
	{
		cout << cf[*it] << endl;
	}
	cout << "list=>OK" << endl;
}
void _find(string s)
{
	if (cf.count(s) == 0)
	{
		cout << "find=>ERROR" << endl;
	}
	else
	{
		cout << "find=>OK" << endl
			 << cf[s] << endl;
	}
}
void _end()
{
	cout << cf.size() << endl;
	for (auto ap : cf)
	{
		cout << ap.second << endl;
	}
	cout << "end=>OK" << endl;
}
int main()
{
	freopen("explorer.in", "r", stdin);
	freopen("explorer.out", "w", stdout);
	string s1, s2;
	while (114514)
	{
		cin >> s1;
		if (s1 != "start" && s1 != "end")
		{
			cin >> s2;
		}
		if (s1 == "start")
		{
			_start();
		}
		else if (s1 == "create")
		{
			_create(s2);
		}
		else if (s1 == "list")
		{
			_list(s2);
		}
		else if (s1 == "find")
		{
			_find(s2);
		}
		else if (s1 == "end")
		{
			_end();
			return 0;
		}
	}
}
