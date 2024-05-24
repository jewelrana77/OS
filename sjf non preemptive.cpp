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
		m[at].push_back({bt,i+1});
	}
	priority_queue<pair<int,pair<int,int>>>q;
	int cnt=0;
	int ct=0;
	vector<int>vec;
	int wt,tat;
	while(cnt<n)
	{
		for(auto &p : m)
		{
			if(p.first<=ct)
			{
				vec.push_back(p.first);
				for(auto &p1 : p.second)
				{
					cnt++;
					q.push({-1*p1.first,{p1.second,p.first}});
				}
			}
			else break;
		}
		if(q.empty())
		{
			auto p=*m.begin();
			ct=p.first;
			vec.push_back(p.first);
			for(auto &p1 : p.second)
			{
				cnt++;
				q.push({-1*p1.first,{p1.second,p.first}});
			}
		}
		for(auto &p : vec) m.erase(p);
		vec.clear();
		while(!q.empty())
		{
			auto it=q.top();
			q.pop();
			ct=ct+(-1*it.first);
			tat=ct-it.second.second;
			wt=tat+it.first;
			table[it.second.first].push_back(ct);
			table[it.second.first].push_back(tat);
			table[it.second.first].push_back(wt);
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