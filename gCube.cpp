#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define forn(i, a, b) for(int i = (a); i < (b); ++i)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)
#define fore(i, a, b) forn(i, a, b + 1)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define fill(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gl(x) cin >> x
#define gi(x) scanf("%d", &x)
#define pls(x) cout << x << " "
#define pln(x) cout << x << "\n"
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << x << " "
#define dbs(x) cerr << x << " "

#define foreach(c, it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

int main()
{
    long long int T,i,z;
    cin>>T;
    for(z=1;z<=T;z++)
    {
        long long int N,m;
        cin>>N>>m;
        double A[N+1],dp[N+1];
        for(i=0;i<N;i++)
        {
            cin>>A[i];
        }
        dp[0]=A[0];
        for(i=1;i<N;i++)
        {
            dp[i]=dp[i-1]*A[i];
        }

        printf("Case #%lld:\n",z);
        for(i=0;i<m;i++)
        {
            long long int l,r;
            cin>>l>>r;
            double ans;
            if(l==0){
                ans=dp[r];
            }
            else
            {
                ans=dp[r]/dp[l-1];
            }
            //cout<<ans<<endl;
            printf("%.9lf\n",pow(ans,1.0/(r-l+1)));

        }

    }
}