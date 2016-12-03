#include <bits/stdc++.h>
using namespace std;

int agent(string location,string status){
    if(location=="A"){
        if(status=="Dirty")
            cout<<"The Vaccum- cleaner is sucking the dirt! "<<endl;
        else if(status=="Clean"){
            location="right";
            cout<< "The location A is cleaned" <<endl;
            cout<< "It has now moved to location " << location<<endl;
        }
    }

    else if(location=="B"){
        if(status=="Dirty")
            cout<<"The Vaccum- cleaner is sucking the dirt! "<<endl;
        else if(status=="Clean"){
            location="left";
            cout<< "The location B is cleaned" <<endl;
            cout<< "It has now moved to location " << location<<endl;
        }
    }

}

int main(){
    agent("A","Clean");
    agent("B","Dirty");
    agent("A","Clean");
}