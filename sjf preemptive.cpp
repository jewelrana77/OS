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
	int at,bt;
	map<int,vector<pair<int,int>>>m;
	for(i=0;i<n;i++)
	{
		cin>>at>>bt;
		table[i+1].push_back(at);
		table[i+1].push_back(bt);
		m[at].push_back({-1*bt,-1*(i+1)});
	}
	priority_queue<pair<int,int>>q;
	int cnt=0;
	int ct=0;
	vector<int>vec;
	int wt,tat;
	int pid;
	while(cnt<n)
	{
		if(q.empty())
		{
			auto p=*m.begin();
			ct=p.first;
			vec.push_back(p.first);
			for(auto &p1 : p.second)
			{
				q.push({p1.first,p1.second});
			}
		}
		for(auto &p : vec) m.erase(p);
		vec.clear();
		while(!q.empty())
		{
			auto it=q.top();
			bt=-1*it.first;
			pid=it.second;
			q.pop();
			ct++;
			bt--;
			if(m.find(ct)!=m.end())
			{
				auto it=m.find(ct);
				for(auto &p : it->second)
				{
					q.push({p.first,p.second});
				}
				vec.push_back(ct);
			}
			for(auto &p : vec) m.erase(p);
			vec.clear();
			if(bt<=0)
			{
				int apid=abs(pid);
			    cout<<"y"<<pid<<endl;
				cnt++;
				table[apid].push_back(ct);
				tat=ct-table[apid][0];
				wt=tat-table[apid][1];
				table[apid].push_back(tat);
				table[apid].push_back(wt);
			}
			else
			{
				q.push({-1*bt,pid});
			}
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
