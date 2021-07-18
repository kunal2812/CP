#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926536;
typedef long long ll;
typedef vector<ll> vli;
typedef pair<ll, ll> pii;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define fill(a, b) memset(a, b, sizeof(a))
#define mod 1000003
#define this_is_my_fucking_code_u_r_seeing_my_hard_work_fuck_offff \
    ios_base::sync_with_stdio(false);                              \
    cin.tie(nullptr);                                              \
    cout.tie(nullptr)

void solve()
{
    ll n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    ll prefix_a[n];
    ll prefix_b[n];
    fill(prefix_b, 0);
    fill(prefix_a, 0);
    prefix_a[0] = a[0];
    prefix_b[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        prefix_a[i] = a[i] + prefix_a[i - 1];
        prefix_b[i] = b[i] + prefix_b[i - 1];
    }
    int sum_a = 0;
    int sum_b = 0;
    int minus = n / 4;
    minus=minus-1;
    sum_a = prefix_a[n - 1];
    sum_b = prefix_b[n - 1];
    if(minus>=0)
    {
        sum_a=sum_a-prefix_a[minus];
        sum_b=sum_b-prefix_b[minus];
    }
    if (sum_a >= sum_b)
    {
        cout << "0\n";
        return;
    }
    int k = n+1;
    while(sum_a<sum_b)
    {
        sum_a = 0;
        sum_b = 0;
        sum_a = sum_a + (k-n)*100;
        ll minus_new = 0;
        minus_new = k / 4;
        minus_new = minus_new - 1;
        sum_a = sum_a + prefix_a[n - 1];
        sum_b = sum_b + prefix_b[n - 1];
        if (minus_new >= 0)
        {
            sum_a = sum_a - prefix_a[minus_new];
        }
        ll minu = 0;
        minu = minus_new - (k - n);
        if (minu >= 0)
        {
            sum_b = sum_b - prefix_b[minu];
        }
       // cout << sum_a << "   " << sum_b << "   k=" << k << endl;
        if (sum_a >= sum_b)
        {
            //    cout << sum_a << "   " << sum_b << endl;
            cout << (k - n) << endl;
            return;
        }
        k++;
    }
    return;
}

int main()
{
    //this_is_my_fucking_code_u_r_seeing_my_hard_work_fuck_offff;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //scanf("%d", &t);
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}