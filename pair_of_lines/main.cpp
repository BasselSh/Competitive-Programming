#include <iostream>
#include <math.h>
#include <vector>
#define eps 0.00000001
#define ll long long
using namespace std;

struct pt
{
    ll x;
    ll y;

};
bool collinear(pt a, pt b ,pt c)
{
    double x1=b.x-a.x;
    double y1=b.y-a.y;
    double x2=c.x-a.x;
    double y2=c.y-a.y;
   // cout<<"col"<<fabs(x1*y2-y1*x2)<<endl;
    return fabs(x1*y2-y1*x2)<eps;
}


int main()
{
    int n;
    vector<pt> nn;
    cin>>n;
    pt p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    if(n<=3)
    {
        cout<<"YES";
        return 0;
    }
    int kk=0;
    bool tt=true;
    for(int i=0;i<n;i++)
    {
        if(!collinear(p[kk],p[(kk+1)%n],p[(kk+2)%n]))
        {
            kk=i;
            tt=false;
            break;
        }
        kk++;
    }
    if(tt)
    {
        cout<<"YES";
        return 0;
    }
   // cout<<"KK="<<kk<<endl;
    int k1=kk;
    int k2=kk+1;
    int k3=kk+2;
    nn.push_back(p[k3]);
    bool test=true;
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i==k1||i==k2||i==k3) continue;
            if(collinear(p[i],p[k1],p[k2]))
            {
                continue;
            }
            if(nn.size()==1)
            {

                nn.push_back(p[i]);
                continue;
            }
            if(!collinear(p[i],nn[0],nn[1]))
            {
                test=false;
                break;
            }

        }
        if(test)
        {
            cout<<"YES";
            return 0;
        }
        nn.clear();
        k1++;
        k2=(k2+1-kk)%3+kk;
        k3=(k3+1-kk)%3+kk;
        nn.push_back(p[k3]);
        test=true;
    }
    cout<<"NO";
    return 0;
}
