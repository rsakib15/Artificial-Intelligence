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

int board[100],cnt=0;




void printBoard(int n){
    int i,j;
    cnt++;
    printf("Case %d:\n",cnt);
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            if(board[i]==j)
                PF("Q");
            else
                PF("-");
        }
        NL;
    }
    NL;
}

int checkBoard(int r,int c){
    int i;
    FOR(i,1,r){
        if(board[i]==c)
            return 0;
        else{
            if(abs(board[i]-c)==abs(i-r))
                return 0;
        }
    }
    return 1;
}


void NQUEEN(int r,int n){
    int i;
    FOR(i,1,n+1){
        if(checkBoard(r,i)){
            board[r]=i;
            if(r!=n)
                NQUEEN(r+1,n);
            else
                printBoard(n);
        }
    }
}

int main(){
    //BOOST;
    //READ();
    //WRITE();

    int n;
    SF("%d",&n);
    NQUEEN(1,n);

    return 0;
}