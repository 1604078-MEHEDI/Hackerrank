/// Topic: Dp
///https://www.hackerrank.com/challenges/sherlock-and-cost/problem
/// tutorial: https://docs.google.com/document/d/1b9hxNgLFGQtCQYjGkMvtJqs1Y7KWGGwG-ScXKSLXX40/edit
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll Mod = 1e9 + 7;
ll dp[maxn][105];
ll a[maxn];
ll n;

ll solve(ll last, ll pos)
{
	if (pos == n) return 0;

	ll &ret = dp[pos][last];
	if (ret != -1) return ret;

	ll x = abs(last - 1) + solve(1, pos + 1); // last element 1 set
	ll y = abs(last - a[pos]) + solve(a[pos], pos + 1);
	return ret = max(x, y);
}

void ieterative()
{
	for (ll i = 0; i < n - 1; i++) {
		dp[i + 1][0] = max(dp[i][0], dp[i][1] + abs(a[i] - 1));
		dp[i + 1][1] = max(dp[i][0] + abs(a[i + 1] - 1), dp[i][1] + abs(a[i] - a[i + 1]));
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
	return;
}

int main()
{
	FASTIO
	///*
	//double start_time = clock();
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
//*/
	int T;
	cin >> T;
	//T = 1;
	for (int cs = 1; cs <= T; cs++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 100; j++)
				dp[i][j] = 0;
		}
		ieterative();
		//cout << max(solve(1, 1), solve(a[0], 1)) << endl;
	}

	//double end_time = clock();
	//printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
	return 0;
}
