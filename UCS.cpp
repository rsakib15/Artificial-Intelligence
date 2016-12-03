#include <bits/stdc++.h>
using namespace std;
vector<int> Graph[1000];
vector<int> Weight[1000];

struct data{
	vector<int>path;
	int cost;
	bool operator>(const data & r) const{
		return cost > r.cost;
	}
};

void displayPath(struct data p){
    vector<int>::iterator i;
	cout<<"Path: ";
    for (i = p.path.begin(); i != p.path.end(); ++i){
        cout<<" "<<*i;
    }
    cout<<endl;
    cout<<"Cost: "<<p.cost;
}


void UniformCost(int src, int dest){
	int current=0, position=0;
	priority_queue<data,vector<data>,greater <data> > pq;
	data st;

	st.path.push_back(src);
	st.cost = 0;
    pq.push(st);

	vector<int>::iterator it;
	vector<int>::iterator i;

	while(!pq.empty()){
		data currentPQ, tempPQ;
		currentPQ = pq.top();
		current = currentPQ.path.back();
		//cout<<current<<endl;

		//cout<<"current: "<<current<<" "<<currentPQ.cost<<endl;
		pq.pop();
		i=Graph[current].begin();

		if(current == dest){
			cout<<"found"<<endl;
			displayPath(currentPQ);
			return;
		}
		else{
			for (it = Graph[current].begin(); it != Graph[current].end();it++){

			    cout<<"Current : " << current<< " I: "<<*it<<endl;
				tempPQ = currentPQ;
				cout<<"IT: "<<*it<<endl;
				tempPQ.path.push_back(*it);


				position = find(Graph[current].begin(), Graph[current].end(), *it) - i;
				//cout<< *it<<endl;
				cout<<"pos: "<<position<<endl;
				tempPQ.cost += Weight[current][position];
				pq.push(tempPQ);
			}
		}
	}
}


int main(){
    freopen("input.txt","r",stdin);
	int n, a, b, c;
	int T;
	cin>>T;
	int s = 0, e = 0;
	cin>>n>>e;
	for(int i = 0; i<e; i++){
		cin>>a>>b>>c;
        Graph[a].push_back(b);
        Weight[a].push_back(c);
	}
	cin>>s;
	cin>>e;
	UniformCost(s, e);
}