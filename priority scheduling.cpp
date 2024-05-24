#include <bits/stdc++.h>

using namespace std;

void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}
int main()
{
	code();
	int i,n;
	cin>>n;
	vector<int>table[n+1];
	int at,bt,pr;
	map<pair<int,int>,vector<pair<int,int>>>m;
	for(i=0;i<n;i++)
	{
		cin>>pr>>at>>bt;
		table[i+1].push_back(pr);
		table[i+1].push_back(at);
		table[i+1].push_back(bt);
		m[{at,-1*pr}].push_back({bt,-1*(i+1)});
	}
	priority_queue<pair<int,pair<int,int>>>q;
	int cnt=0;
	int ct=0;
	vector<pair<int,int>>vec;
	int wt,tat,pid;
	while(cnt<n)
	{
		for(auto &p : m)
		{
			if(p.first.first<=ct)
			{
				vec.push_back({p.first.first,p.first.second});
				for(auto &p1 : p.second)
				{
					q.push({p.first.second,{p1.first,p1.second}});
				}
			}
			else break;
		}
		if(q.empty())
		{
			auto p=*m.begin();
			ct=p.first.first;
			vec.push_back({p.first.first,p.first.second});
			for(auto &p1 : p.second)
			{
				q.push({p.first.second,{p1.first,p1.second}});
			}
		}
		for(auto &p : vec) m.erase({p.first,p.second});
		vec.clear();
		if(!q.empty())
		{
			auto it=q.top();
			q.pop();
			cnt++;
			//cout<<it.first<<endl;
			bt=it.second.first;
			pid=-1*it.second.second;
			ct=ct+bt;
			cout<<it.first<<" "<<pid<<endl;
			cout<<ct<<endl;
			tat=ct-table[pid][1];
			wt=tat-table[pid][2];
			table[pid].push_back(ct);
			table[pid].push_back(tat);
			table[pid].push_back(wt);
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<i<<" ";
		for(auto &p : table[i]) cout<<p<<" ";
		cout<<endl;
	}
	return 0;
}