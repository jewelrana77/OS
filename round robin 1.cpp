#include<bits/stdc++.h>

using namespace std;

struct processes
{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
int main()
{
    int i,n,at,bt,tq;
    cin>>n;
    cin>>tq;
    int ct=1e9+7;
    processes p[n+1];
    map<pair<int,int>,int>process,m;
    for(i=0;i<n;i++)
    {
        cin>>at>>bt;
        p[i+1].at=at;
        p[i+1].bt=bt;
        m[{at,i+1}]=bt;
    }
    queue<pair<int,int>>pq;
    for(auto &p : m)
    {
        pq.push(p.first);
    }
    queue<pair<int,int>>q;
    while(!pq.empty() || !q.empty())
    {
        if(!pq.empty() && q.empty())
        {
            auto it=pq.front();
            ct=it.first;
            while(!pq.empty())
            {
                auto it=pq.front();
                if(ct>=it.first)
                {
                    q.push({it.second,p[it.second].bt});
                    pq.pop();
                }
                else break;
            }
        }
        auto it=q.front();
        q.pop();
        if(it.second>0)
        {
            ct=ct+min(tq,it.second);
            it.second=it.second-min(tq,it.second);
        }
        while(!pq.empty())
        {
            auto it1=pq.front();
            if(ct>=it1.first)
            {
                q.push({it1.second,p[it1.second].bt});
                pq.pop();
            }
            else break;
        }
        if(it.second==0) p[it.first].ct=ct;
        else
        {
            q.push({it.first,it.second});
        }
    }
    for(i=1;i<=n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    cout<<"PID"<<"   "<<"AT"<<"  "<<"BT"<<"  "<<"CT"<<"  "<<"TAT"<<" "<<"WT"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<i<<"  "<<p[i].at<<"   "<<p[i].bt<<"   "<<p[i].ct<<"   "<<p[i].tat<<"  "<<p[i].wt<<endl;
    }
    return 0;
}
