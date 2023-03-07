// #define DEBUG
#define REP(i, first, last) for (int i = first; i <= last; ++i)
#define DOW(i, first, last) for (int i = first; i >= last; --i)
#include <bits/stdc++.h>
using namespace std;

/*-------以下模板来自`OI WIKI，但是稍作修改（`-------*/
class trie
{
public:
    // private:
    int nex[505][50005], cnt;
    bool exist[505]; // 该结点结尾的字符串是否存在

    // private:
    int getc(string s, int begin, int last)
    { // 获取c值
        int ret = 0;
        REP(i, begin + 1, last - 1)
        {
            int tmp = s[i] - '0';
            ret *= 10;
            ret += tmp;
        }
        return ret;
    }

public:
    void insert(string s)
    { // 插入字符串
        int l = s.length();
        int p = 0;
        int cur_vertex_begin = -1;
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '\\' || i == l - 1)
            {
                if (cur_vertex_begin != -1)
                {
                    int c = getc(s, cur_vertex_begin, (i == l - 1) ? l : i);
                    if (!nex[p][c])
                    {
                        nex[p][c] = ++cnt; // 如果没有，就添加结点

#ifdef DEBUG
                        cout << "add " << p << ' ' << c << endl;
#endif

                        exist[p] = 1;
                    }
                    p = nex[p][c];
                }
                cur_vertex_begin = i;
            }
        }

#ifdef DEBUG
        cout << "exist " << p << ' ' << exist[p] << endl;
#endif

        if (exist[p])
        {
            cout << "create=>ERROR\n";
            return;
        }
        exist[p] = 1;
        cout << "create=>OK\n";
    }

    void list(string s)
    {
        int l = s.length();
        int p = 0;
        int cur_vertex_begin = -1;
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '\\' || i == l - 1)
            {
                if (cur_vertex_begin != -1)
                {
                    int c = getc(s, cur_vertex_begin, (i == l - 1) ? l : i);

#ifdef DEBUG
                    cout << "getc " << cur_vertex_begin << ' ' << ((i == l - 1) ? (l + 1) : i) << ' ' << c << endl;
#endif

                    if (!nex[p][c])
                    {
                        cout << "list=>ERROR\n";
                        return;
                    }
                    p = nex[p][c];
                }
                cur_vertex_begin = i;
            }
        }
        REP(i, 0, 9999)
        {
            if (nex[p][i])
            {
                cout << s << '\\' << i << endl;
            }
        }
    }

    void find()
    {
    }
    // bool find(string s, int l) {  // 查找字符串
    //     int p = 0;
    //     for (int i = 0; i < l; i++) {
    //     int c = s[i] - 'a';
    //     if (!nex[p][c]) return 0;
    //     p = nex[p][c];
    //     }
    //     return exist[p];
    // }

    trie()
    {
        cnt = 0;
        memset(nex, 0, sizeof(nex));
        memset(exist, 0, sizeof(exist));
    }
};

/*----------------------------------------------*/

trie explorer_tree;

int main()
{
    // string test = "\\11\\13\\1454\\241";
    // string test2 = "\\11\\13\\1454";
    // explorer_tree.insert(test);
    // explorer_tree.insert(test2);
    // explorer_tree.list(test2);
    explorer_tree.insert("\\1\\2\\132");
    explorer_tree.insert("\\1\\2\\89");
    explorer_tree.insert("\\1\\2\\231");
    explorer_tree.list("\\1\\2");
    return 0;
}