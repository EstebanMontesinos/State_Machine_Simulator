#include <iostream>
#include<fstream>
#include "Node.h"
#include <vector>
#include <map>
using namespace std;
ifstream input;
string args1,args2,args3;
string state1,state2;
Node*node1;
Node*node2;
char transition;
int reader(string file);
int arguments(int argc,char **argv);
int print_SM();
vector<string>v;
char c;
//map
map<string,Node*>m1;
//iterators needed
map<string,Node*>::iterator i1;
map<char,Node*>::iterator i2;

//reading a file
int reader(string file){
    string read;
    input.open(file,ifstream::in);
    if(!input.is_open()){
        cerr<<"ERROR could not open file"<<endl;



    }
    while(input>>state1>>transition>>state2){
        i1=m1.find(state1);
        if(i1==m1.end())
        {
            m1[state1]=new Node(state1);
        }
        i1=m1.find(state2);
        if(i1==m1.end()){
            m1[state2]=new Node(state2);
        }
        m1[state1]->m2[transition]=m1[state2];
    }
    return 0;

}
int arguments(int argc,char**argv){
    if(argc!=4){
        cerr<<"Not enough arguments";
    }else{
        args1=argv[1];
        args2=argv[2];
        args3=argv[3];
    }
    return reader(args1);
}
int print_SM(){
    for(i1=m1.begin();i1!=m1.end();i1++) {
        string s1=i1->first;
        node1=i1->second;
        cout<<s1<<": ";
        for(i2=node1->m2.begin();i2!=node1->m2.end();i2++){
            node2=i2->second;
            cout<<"("<<i2->first<<", "<<node2->state<<")";
        }
        cout<<endl;

    }
    return 0;
}




int main(int argc,char **argv) {
    arguments(argc,argv);
    cout<<"State Machine:"<<endl;
    print_SM();
    cout<<"------------------------------------" << endl;
    i1=m1.find(args2);
    node1=i1->second;
    cout<<"Enter test: ";
    while(cin>>c){
        node1=node1->m2[c];
        v.push_back(node1->state);
    }
    cout<<"Path:S ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    if(args3==v[v.size()-1]){
        cout<<"accept!!!"<<endl;

    }
    else{
        cout<<"reject!!!"<<endl;
    }
    input.close();


    return 0;
}