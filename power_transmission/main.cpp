#include <iostream>
#include<map>
#include<set>

#define eps 0.0000001
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
struct m
{
    int a;
    int b;
    void insert(int x,int y)
    {
        int t=gcd(x,y);
        b=x/t;
        a=y/t;
    }
};


int main()
{
    set<pair<int,int> > ss;
    map<pair<int,int>,int> mp;
    int n;
    cin>>n;
    int x[n];
    int y[n];
    m mm[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int k=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            mm[k].insert(x[j]-x[i],y[j]-y[i]);
            cout<<mm[k].a<<","<<mm[k].b<<endl;
            mp[make_pair(mm[k].a,mm[k].b)]+=1;
            ss.insert(make_pair(mm[k].a,mm[k].b));
            k++;
        }
    }
    int cnt=0;
    int temp;
    for(int i=0;i<ss.size();i++)
    {
        if(mp[make_pair(mm[i].a,mm[i].b)]>1)
      //  cout<<temp;
        cnt+=mp[make_pair(mm[i].a,mm[i].b)]-1;
    }
   // cout<<"cnt="<<cnt<<endl;
    int n1=(n*(n-1))/2;
    int ans=(n1*(n1-1))/2-(cnt*(cnt-1))/2;
    cout<<ans;
    return 0;
}
