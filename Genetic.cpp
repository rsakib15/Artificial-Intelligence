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


int arr1[5]={0,1,1,0,1},arr2[5]={1,1,0,0,0},arr3[5]={0,1,0,0,0},arr4[5]={1,0,0,1,1};
int cross1[5],cross2[5],cross3[5],cross4[5];

int bin[5]={1,2,4,8,16};

int f1,f2,f3,f4,f5;

double sum;
double Max=0;
double res;

map<int, int>v1;

int sum1=0,sum2=0,sum3=0,sum4=0;

int Round(double num){
    if( (num + 0.5) >= (int(num) + 1))
        return int(num)+1;
    else
        return int(num);
}

int value(int *arr){
    int i,sum=0;
    int j=0;
    REV(i,4,-1){
        sum+=arr[i]*bin[j];
        j++;
    }
    return sum;
}

int randomGenerator(){
    int i;
	for (i = 0; i<5; i++){
		arr1[i] = rand() % 2;
		arr2[i] = rand() % 2;
		arr3[i] = rand() % 2;
		arr4[i] = rand() % 2;
	}

	cout << "Starting Population:" << endl;
	FOR(i,0,5){
		cout << arr1[i] << "\t";
	}
	cout << endl;
	FOR(i,0,5){
		cout << arr2[i] << "\t";
	}
	cout << endl;

	FOR(i,0,5){
		cout << arr3[i] << "\t";
	}
	cout << endl;
	FOR(i,0,5){
		cout << arr4[i] << "\t";
	}

	cout<<endl;
}


int fitness(){
    int sum1=value(arr1);
    int sum2=value(arr2);
    int sum3=value(arr3);
    int sum4=value(arr4);
    cout << "Sum 1: "<< sum1 << endl;
	cout << "Sum 2: "<< sum2 << endl;
	cout << "Sum 3: "<< sum3 << endl;
	cout << "Sum 4: "<< sum4 << endl;


    double fitness1, fitness2, fitness3, fitness4,fitness5, avg;
	fitness1 = sum1*sum1;
	Max=max(Max,fitness1);
	fitness2 = sum2*sum2;
	Max=max(Max,fitness2);
	fitness3 = sum3*sum3;
	Max=max(Max,fitness3);
	fitness4 = sum4*sum4;
	Max=max(Max,fitness4);

	cout << "Fitness 1: "<<fitness1 << endl;
	cout << "Fitness 2: "<< fitness2 << endl;
	cout << "Fitness 3: "<< fitness3 << endl;
	cout << "Fitness 4: "<< fitness4 << endl;

    sum= fitness1 + fitness2 + fitness3 + fitness4;
	avg = sum / 4;
    cout<<"Sum is : "<<sum<<endl;
	cout<<"Avarage is : "<<avg<<endl;
	cout<<"Max Is: "<<Max<<endl;

	f1 = Round(fitness1 / avg);
	f2 = Round(fitness2 / avg);
	f3 = Round(fitness3 / avg);
	f4 = Round(fitness4 / avg);
	f4 = Round(fitness4 / avg);

	cout << "Fit 1: "<<f1 << endl;
	cout << "Fit 2: "<< f2 << endl;
	cout << "Fit 3: "<< f3 << endl;
	cout << "Fit 4: "<< f4 << endl;
	cout << "Fit 5: "<< f5 << endl;
}

int crossoverpoint[5]={3,3,1,1};

void selection(){
	for(int i=0;i<4;i++){
        int r=rand()%4;
        v1[i] = r;
	}

	for(int i=0;i<4;i++){
        cout<<v1[i]<<endl;
	}
}


void crossover(){
	if (v1[0] == 0){
		for (int i = 0; i < 5; i++){

			cross1[i] = arr1[i];
		}
	}

	else if (v1[0]==1){
		for (int i = 0; i < 5; i++){
            if(crossover)
            cross1[i] = arr2[i];
		}

	}
	else if (v1[0]==2){
		for (int i = 0; i < 5; i++){
			cross1[i] = arr3[i];
		}
	}
	else if (v1[0] == 3){
		for (int i = 0; i < 5; i++){
			cross1[i] = arr4[i];
		}
	}

	if (v1[1] == 0){
		for (int i = 0; i < 5; i++){
			cross2[i] = arr1[i];
		}

	}
	else if (v1[1] == 1){
		for (int i = 0; i < 5; i++){
			cross2[i] = arr2[i];
		}

	}
	else if (v1[1] == 2){
		for (int i = 0; i < 5; i++){
			cross2[i] = arr3[i];
		}
	}
	else if (v1[1] == 3){
		for (int i = 0; i < 5; i++){
			cross2[i] = arr4[i];
		}
	}

	if (v1[2] == 0){
		for (int i = 0; i < 5; i++){
			cross3[i] = arr1[i];
		}

	}
	else if (v1[2] == 1){
		for (int i = 0; i < 5; i++){
			cross3[i] = arr2[i];
		}

	}
	else if (v1[2] == 2){
		for (int i = 0; i < 5; i++){
			cross3[i] = arr3[i];
		}
	}
	else if (v1[2] == 3){
		for (int i = 0; i < 5; i++){
			cross3[i] = arr4[i];
		}
	}

	if (v1[3] == 0){
		for (int i = 0; i < 5; i++){
			cross4[i] = arr1[i];
		}

	}
	else if (v1[3] == 1){
		for (int i = 0; i < 5; i++){
			cross4[i] = arr2[i];
		}

	}
	else if (v1[3] == 2){
		for (int i = 0; i < 5; i++){
			cross4[i] = arr3[i];
		}
	}
	else if (v1[3] == 3){
		for (int i = 0; i < 5; i++){
			cross4[i] = arr4[i];
		}
	}
}



void mutation(){
	for (int i = 0; i < 5; i++){
		arr1[i] = cross1[i];
		arr2[i] = cross2[i];
		arr3[i] = cross3[i];
		arr4[i] = cross4[i];
	}
}


int main(){
    randomGenerator();
    int i;
    FOR(i,0,5){

        fitness();
        selection();
        crossover();
        mutation();

    cout << "\nAfter the mutation:" << endl;
	for (int i = 0; i < 5; i++){
		cout << arr1[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 5; i++){
		cout << arr2[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 5; i++){
		cout << arr3[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 5; i++){
		cout << arr4[i] << "\t";
	}
	cout << endl;
}

	cout<<"Maximum is : "<<Max<<endl;


}