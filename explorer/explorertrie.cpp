#pragma GCC optimize(2)
#define DEBUG
#define REP(i, first, last)  for(int i = first; i <= last; ++i)
#define DOW(i, first, last)  for(int i = first; i >= last; --i)
#include<bits/stdc++.h>
using namespace std;

/*------以下模板来自`OI WIKI`，但是"稍"作修改（------*/
class trie {
    public:
    // private:
        struct edgeNode {
            int nex, self, val;
            edgeNode *lst;
            edgeNode() {
                lst = NULL;
                nex = 0;
                self = 0;
                val = 0;
            }
        };
        
        edgeNode edge[2505][10086];
        int cnt;
        bool exist[2505];  // 该结点结尾的字符串是否存在

    // private:
        int getc(string s, int begin, int last) {  //获取c值
            int ret = 0;
            REP (i, begin + 1, last - 1) {
                int tmp = s[i] - '0';
                ret *= 10;
                ret += tmp;
            }
            return ret;
        }

    public:
        void insert(string s) {  // 插入字符串
            int l = s.length();
            int p = 0;
            edgeNode *lst_node = NULL;
            int cur_vertex_begin = -1;
            for (int i = 0; i < l; i++) {
                if(s[i] == '\\' || i == l - 1) {
                    if(cur_vertex_begin != -1) {
                        int c = getc(s, cur_vertex_begin, (i == l - 1) ?l :i);
                        if (!edge[p][c].nex) {
                            edge[p][c].nex = ++cnt;  // 如果没有，就添加结点
                            edge[p][c].lst = lst_node;
                            edge[p][c].self = p;
                            edge[p][c].val = c;

                            #ifdef DEBUG
                                cout << "add " << p << ' ' << c << ' ' << edge[p][c].nex << ' ' << edge[p][c].lst->self << ' ' << edge[p][c].val <<endl;
                            #endif 

                            exist[p] = 1;
                        }
                        lst_node = &edge[p][c];
                        p = edge[p][c].nex;
                    }
                    cur_vertex_begin = i;
                }
            }

            #ifdef DEBUG
                cout << "exist " << p << ' ' << exist[p] <<endl;
            #endif

            if(exist[p]) {
                cout << "create=>ERROR\n";
                return ;
            }
            exist[p] = 1;
            cout << "create=>OK\n";
        }

        void list(string s) {
            int l = s.length();
            int p = 0;
            int cur_vertex_begin = -1;
            for (int i = 0; i < l; i++) {
                if(s[i] == '\\' || i == l - 1) {
                    if(cur_vertex_begin != -1) {
                        int c = getc(s, cur_vertex_begin, (i == l - 1) ?l  :i);

                        #ifdef DEBUG
                            cout << "getc " <<cur_vertex_begin << ' ' << ((i == l - 1) ?(l + 1) :i) << ' ' <<  c << endl;
                        #endif

                        if (!edge[p][c].nex) {
                            cout << "list=>ERROR\n";
                            return ;
                        }
                        p = edge[p][c].nex;
                    }
                    cur_vertex_begin = i;
                }
            }
            REP(i, 0, 9999) {
                if(edge[p][i].nex) {
                    cout << s << '\\' << i <<endl;
                }
            }
        }

        void find(int folder) {
            queue<edgeNode> Q;
            REP(i, 0, cnt) {
                if(edge[i][folder].nex) {
                    Q.push(edge[i][folder]);
                }
            }
            edgeNode *p;
            stack<int> dir_stk;
            while(!Q.empty()) {
                while(!dir_stk.empty())
                    dir_stk.pop();
                edgeNode cur = Q.front();
                dir_stk.push(cur.val);
                p = &cur;
                Q.pop();
                while (p != 0) {

                    #ifdef DEBUG
                        cout << "finding " << p->self << ' ' << p->val <<endl;
                    #endif

                    p = &cur;
                    dir_stk.push(p->val);
                    cur = *p->lst;
                }
                cout << "T:\\";
                REP(i, 0, dir_stk.size() - 1) {
                    cout << dir_stk.top() <<'\\';
                    dir_stk.pop();
                }
                cout << dir_stk.top() << endl;
                dir_stk.pop();
            }
        }
        // bool find(string s, int l) {  // 查找字符串
        //     int p = 0;
        //     for (int i = 0; i < l; i++) {
        //     int c = s[i] - 'a';
        //     if (!edge[p][c]) return 0;
        //     p = edge[p][c];
        //     }
        //     return exist[p];
        // }

        trie() {
            cnt = 0;
            memset(exist, 0, sizeof(exist));
        }
};

/*----------------------------------------------*/

trie explorer_tree;

int main() {
    // ios :: sync_with_stdio(false);
    // string test = "\\11\\13\\1454\\241";
    // string test2 = "\\11\\13\\1454";
    // explorer_tree.insert(test);
    // explorer_tree.insert(test2);
    // explorer_tree.list(test2);
    explorer_tree.insert("F:\\1\\2\\132");
    explorer_tree.insert("F:\\1\\2\\89\\132");
    explorer_tree.insert("F:\\1\\2\\231");
    explorer_tree.list("F:\\1\\2");
    explorer_tree.find(132);
    return 0;
}