#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef long long ll;
typedef pair<int,int> ii;

#define EL printf("\n")
#define OK puts("OK")
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define X  first
#define Y  second
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))

struct Trie {
    Trie * c[2];
    int d, f;
};
typedef Trie * trie;

trie New() {
    trie a = new Trie();
    a->d = a->f = 0;
    return a;
}

int n, m, ans;
trie root = New();

int main()
{
    //freopen("INP.INP", "r", stdin);
    //freopen("OUT.OUT", "w", stdout);

    scanf("%d%d", &n,&m);
    while (n--) {
        int k; scanf("%d", &k);
        trie a = root;
        while (k--) {
            int i; scanf("%d", &i);
            a->d++;
            if (a->c[i] == nullptr) a->c[i] = New();
            a = a->c[i];
        }
        a->f++;
    }
    while (m--) {
        int k; scanf("%d", &k);
        ans = 0;
        trie a = root;
        int i;
        for (i=1;i<=k;i++) {
            int j; scanf("%d", &j);
            a = a->c[j];
            if (a == nullptr) break;
            ans += a->f;
        }
        if (a != nullptr) ans += a->d;
        for (int j=i+1;j<=k;j++) scanf("%d", &i);
        printf("%d\n", ans);
    }

    return 0;
}
