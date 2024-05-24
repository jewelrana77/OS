#include<bits/stdc++.h>

using namespace std;

map<int,vector<int>>m;
vector<int>a[1000];

int main()
{
    printf("Enter number of frames\n");
    int i,j,n,sze;
    cin>>n;
    cout<<"Enter the size of the reference string"<<endl;
    cin>>sze;
    cout<<"Enter the reference string"<<endl;
    int str[sze];
    for(i=0;i<sze;i++)
    {
        cin>>str[i];
        m[str[i]].push_back(i);
    }
    for(auto &p : m) p.second.push_back(1e9+7);
    int index=0;
    vector<int>vec(n,-1);
    m[-1].push_back(1e9+7);
    for(auto &p : m)
    {
        reverse(p.second.begin(),p.second.end());
    }
    map<int,int>m1;
    int h=0;
    vector<int>hits(sze,-1);
    cout<<"By applying Page replacement Algorithm We get"<<endl;
    for(i=0;i<sze;i++)
    {
        if(m1.find(str[i])!=m1.end())
        {
            m[str[i]].pop_back();
            h++;
            hits[i]=1;
        }
        else
        {
            int v=0;
            int k=-1;
            for(j=0;j<n;j++)
            {
                if(m[vec[j]][m[vec[j]].size()-1]>v)
                {
                    v=m[vec[j]][m[vec[j]].size()-1];
                    k=j;
                }
            }
            m1.erase(vec[k]);
            vec[k]=str[i];
            m[str[i]].pop_back();
            m1[str[i]]=i;
        }
        for(j=0;j<n;j++) a[j].push_back(vec[j]);
    }
    int k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i].size();j++)
        {
            if(a[i][j]==-1) cout<<"  ";
            else cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(k=0;k<sze;k++)
    {
        if(hits[k]==1) cout<<"H ";
        else cout<<"M ";
    }
    cout<<endl;
    printf("Hit Ratio is %lf%\n",((double)h/(double)sze)*100);
    printf("Miss Ratio is %lf%\n",((double)(sze-h)/(double)sze)*100);
    return 0;
}
