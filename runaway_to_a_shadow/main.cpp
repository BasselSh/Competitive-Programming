#include<bits/stdc++.h>
#define eps 0.00000001
#define pi acos(-1)
#define ll long long
#define endl '\n'

ios_base::sync_with_stdio(false);
using namespace std;
struct vecc
{
    double x;
    double y;
    vecc(){}
    vecc operator/(double d)
    {
        vecc v;
        v.x=x/d;
        v.y=y/d;
        return v;
    }
    vecc operator*(double d)
    {
        vecc v;
        v.x=x*d;
        v.y=y*d;
        return v;
    }
};

struct pt
{
    double x;
    double y;

    pt operator+(vecc v)
    {
        pt t;
        t.x=x+v.x;
        t.y=y+v.y;
        return t;
    }
    vecc operator-(pt p)
    {
        vecc v;
        v.x=x-p.x;
        v.y=y-p.y;
        return v;
    }
};
double dis(pt a, pt b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}
struct cir
{
    pt p;
    double r;
};
struct ev
{
    double ang;
    bool state;

};

vecc rot(vecc v, double ang)
{
    vecc t;
    t.x=v.x*cos(ang)-v.y*sin(ang);
    t.y=v.x*sin(ang)+v.y*cos(ang);
    return t;
}
struct myclass
{
    bool operator()(ev v1,ev v2)
    {
        if(v1.ang==v2.ang)
        {
            return v1.state==1;
        }
        return v1.ang<v2.ang;
    }
}obj;



int main()
{
    deque<ev> evt;
    pt p0;
    int v,t,n;
    cin>>p0.x>>p0.y>>v>>t;
    cin>>n;
    cir cc[n];
    int r0=v*t;
    for(int i=0;i<n;i++)
    {
        cin>>cc[i].p.x>>cc[i].p.y>>cc[i].r;
    }
    double d;
    double dd;
    pt p1,p2;
    vecc nn;
    double an;
    for(int i=0;i<n;i++)
    {
        if(fabs(dis(cc[i].p,p0)-cc[i].r)<eps||(dis(cc[i].p,p0)<cc[i].r))
        {
            cout<<1;
            return 0;
        }
        if((dis(cc[i].p,p0)-(cc[i].r+r0))<0)
        {

            if((d=dis(cc[i].p,p0))<=r0)
            {

                 nn=(cc[i].p-p0);
                 an=asin(cc[i].r/d);
                 dd=sqrt(d*d-cc[i].r*cc[i].r);

            }
            else
            {
                //cout<<"PP"<<endl;
                nn=(cc[i].p-p0);
                 an=acos((cc[i].r*cc[i].r-d*d-r0*r0)/(-2.0*d*r0));
               //  cout<<"ang="<<an<<endl;
                 dd=cc[i].r;

            }
          //  cout<<"ang="<<an*180.0/pi<<endl;
          //  cout<<"nn="<<nn.x<<","<<nn.y<<endl;
                p1=p0+rot(nn,an)*dd/d;
                ev t1;
                t1.ang=atan2(p1.y,p1.x);
                if(t1.ang<0) t1.ang+=2*pi;
                t1.state=false;
                evt.push_back(t1);
                p2=p0+rot(nn,-an)*dd/d;
                ev t2;
                t2.ang=atan2(p2.y,p2.x);
                if(t2.ang<0) t2.ang+=2*pi;
                t2.state=true;
                evt.push_back(t2);
        }
    }
    sort(evt.begin(),evt.end(),obj);
  //  cout<<"PP"<<evt.back().ang<<endl;//<<(*evt.rend()).state<<endl;
    if(evt[0].state==0)
    {
        evt.back().ang=evt.back().ang-2*pi;
        evt.push_front(evt.back());
        evt.pop_back();
    }
    int cnt=0;
    double fst;
    double sec;
    double sum=0;
    for(int i=0;i<evt.size();i++)
    {
        if(evt[i].state==1)
        {
            if(cnt==0)
            {
                fst=evt[i].ang;
            }
            cnt++;
        }

        else
        {
            cnt--;
            if(cnt==0)
            {
                sec=evt[i].ang;
                sum+=sec-fst;
            }

        }
      //  cout<<evt[i].ang<<","<<evt[i].state<<endl;
    }
    cout<<setprecision(11)<<sum/(2.0*pi);
    return 0;
    {

    }
}
