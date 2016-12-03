#include <bits/stdc++.h>
using namespace std;

///template by Sakib Rahman///

///*************************************************************///
#define NL              printf("\n")
#define nl              '\n'
#define XX              first
#define YY              second
#define SF              scanf
#define PF              printf
#define MOD             1000000007
#define EPS             1e-9
#define MP              make_pair
#define PB              push_back
#define PPB             pop_back
#define PI              acos(-1.0)
#define INF             1<<30
///*************************************************************///
#define READ()          freopen("input.txt", "r", stdin)
#define WRITE()         freopen("output.txt", "w", stdout)
#define BOOST           std::ios_base::sync_with_stdio(0);
#define MEM(n, val)     memset((n), val, sizeof(n))
#define DEBUGI(x)       printf("Debug  %d !!\n",x)
#define DEBUGD(x)       printf("Debug  %llf !!\n",x)
#define DEBUGL(x)       printf("Debug  %lld !!\n",x)
#define PC()            printf("Case %d: ", test++)
///*************************************************************///
#define ABS(x)          ((x)<0?-(x):(x))
#define FABS(x)         ((x)+eps<0?-(x):(x))
#define MAX(a,b)        ((a)>(b)?(a):(b))
#define MIN(a,b)        ((a)<(b)?(a):(b))
#define FOR(I,J,K)      for(I = J; I < K; I++)
#define REV(I,J,K)      for(I = J; I > K; I--)
#define ssz(a)          strlen(a)
#define gcd(a,b)        ll _gcd(int a,int b){if(b%a == 0) return a; _gcd(b%a,a);}
#define lcm(a,b)        ((a*b)/gcd(a,b))
#define VSORT(v)        sort(v.begin(),v.end())
#define UNIQUE(V)       (V).erase(unique((V).begin(),(V).end()),(V).end())
#define DIGIT(x,y)      (((int)(log10((x))/log10((y))))+1)
#define cmpr            bool compare(const pair<int,int>&i,const pair<int,int>&j){return i.first < j.first;}
///************************************************************///
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq;

string color[10]={"RED","GREEN","BLUE","BLACK","WHITE","YELLOW","ORANGE","PINK","VIOLET","CYAN"};

int n, node;
int Graph[110][110],arr[110];

int next(int x){
	int i;
	while(1){
		arr[x]=(arr[x]+1)%(n+1);
		if(arr[x]==0)
			return 0;
		FOR(i,1,node+1)
			if(Graph[x][i] && arr[x] == arr[i])
				break;
		if(i==node + 1)
			return 0;
	}
}

void graphColoring(int a){
	int i;
	next(a);
	if(arr[a] == 0)
		return;
	if(a == node){
		FOR(i,1,node+1)
			cout<<"Node "<<i<<" :: "<<color[arr[i]]<<endl;
	}
	else
		graphColoring(a+1);
}

int main(){
	///BOOST;
	///READ();
	///WRITE();
	int edge, x, y,i;
	cin>>node>>edge;
	FOR(i,0,edge){
		cin>>x>>y;
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}

	memset(arr,0,sizeof(arr));

	PF("Number of Colors: ");
	SF("%d",&n);
	PF("Color order:\n\n");
	graphColoring(1);

	return 0;
}