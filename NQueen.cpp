#include <bits/stdc++.h>
using namespace std;

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

int queen[20];
int column[20];
int diagonal1[40];
int diagonal2[40];

void printboard(int n){
    int i;
    PF("row -- column : \n");
        FOR(i,1,n+1){
            PF("%d %d ",i,queen[i]);
            cout<<endl;
    }
}

void nqueen(int att,int n){
    //cout<<att<<endl;   //1
    int i;
    if(att==n+ 1){
        printboard(n);
        return;
    }


    FOR(i,1,n+1){
    //i=3
    cout<<"i+at: "<<i+att<<endl; //4
    cout<<"i-at: "<<n+i-att<<endl; //2

        if(column[i] || diagonal1[i+att] || diagonal2[n+i-att])
            continue;

        queen[att]=i;
            cout<<"Queen: "<<att<<" "<<queen[att]<<endl;

        column[i]=true;
        diagonal1[i+att]=true;
        diagonal2[abs(n+i-att)]=true;

        nqueen(att+1,n);

        column[i]=false;
        diagonal1[i+att]=false;
        diagonal2[n+i-att]=false;
    }
}



int main()
{
    WRITE();
    int n=8;
    nqueen(1,4);
}