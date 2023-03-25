#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define p64 pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define um unordered_map<int, int>
#define us unordered_set<int>
#define pb push_back
#define ln "\n"
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
vp64 pf(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<int, int> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<int, int> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
    return ans;
}
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t) % mod;
    else
        return (a * (t * t) % mod) % mod;
}

// by inforkc
void inforkc()
{
    int n, m;
    cin >> n >> m;
    int mn = 0, mx = 0;
    while (n--)
    {
        string s;
        cin >> s;
        // occupied(o) = total bright(b) - two bedroom with both light on(t)
        // proof :-
        // o = single on + double one on + double both on
        // b = single on + double one on + 2* double both on
        // so,  O = b - double both on
        //  i.e. O = b - t
        // so to minimize o it we have to maximize t and vise versa
        int b = 0;
        for (auto i : s)
            if (i == '1')
                b++;
        int c = 0;
        int t = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                c++;
            }
            else
            {
                t += c / 2;
                c = 0;
            }
        }
        t += c / 2;
        t = min(m / 4, t);
        mn += b - t;
        t = 0;
        c = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                c++;
            }
            else if (s[i - 1] != s[i])
            {
                c++;
            }
            else
            {
                t += c / 2;
                c = 1;
            }
        }
        t += c / 2;
        if (t >= m / 4)
            t = 0;
        else
            t = m / 4 - t;
        mx += b - t;
    }
    cout << mn << " " << mx << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}