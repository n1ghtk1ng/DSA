#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>
#include<time.h>

using namespace std;
typedef long long ll ;
typedef vector<int> vi ;
typedef pair<int,int>  pp;
typedef vector<pp>  vpp ;
typedef vector<ll> VI ;
typedef pair<ll,ll>  PP;
typedef vector<PP>  VPP ;
#define pb push_back
#define mp make_pair
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define pi(a) printf("%d\n", a)
#define sl(a) scanf("%I64d",&a)
#define pl(a) printf("%I64d\n", a)
#define f(i,n) for(i=0;i<n;i++)
#define fr(i,n) for(i=n-1;i>=0;i--)
#define f1(i,n) for(i=1;i<=n;i++)
struct st{
	int x;
	int y;
};
bool fun(const st &a,const st &b)
{
	return a.x<b.x;
}
