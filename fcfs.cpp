#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,n,at,bt;
    cout<<"Enter Number of Process"<<endl;
    cin>>n;
    multimap<int,pair<int,int>>m;
    int ct=0;
    vector<int>vec[n+1];
    for(i=0;i<n;i++)
    {
        cout<<"Enter arrival time of process "<<i+1<<"  ";
        cin>>at;
        cout<<"Enter brust time of process "<<i+1<<"  ";
        cin>>bt;
        m.insert({at,{bt,i+1}});
    }
    int tat,wt;
    for(auto &p : m)
    {
        if(p.first>ct) ct=p.first;
        ct=ct+p.second.first;
        tat=ct-p.first;
        wt=tat-p.second.first;
        vec[p.second.second].push_back(p.first);
        vec[p.second.second].push_back(p.second.first);
        vec[p.second.second].push_back(ct);
        vec[p.second.second].push_back(tat);
        vec[p.second.second].push_back(wt);
    }
    i=0;
    cout<<"Pro      AT      BT      CT      TAT     WT"<<endl;
    for(auto &p : vec)
    {
        if(i>0)
        {
            cout<<i<<"      ";
            for(auto &p1 : p) cout<<p1<<"       ";
            cout<<endl;
        }
        i++;
    }
    return 0;
}
