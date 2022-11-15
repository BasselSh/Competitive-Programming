#include <iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <iomanip>


#define pi acos(-1)
#define eps 0.000001
using namespace std;
double d;
struct ang_ev
{
    double val;
    double id;
    int state;// 1 is start,   2 is end // 3 is one point (start and end at the same time)
    int coin;
    double range;
    ang_ev(){coin=0; range=0;}
};
vector<ang_ev> ang;

struct vec
{
    double x;
    double y;
    vec operator*(double d)
    {
        vec v;
        v.x=x*d;
        v.y=y*d;
        return v;
    }
    vec operator/(double d)
    {
        vec v;
        v.x=x/d;
        v.y=y/d;
        return v;
    }
    void norm()
    {
        double d=sqrt(x*x+y*y);
        x=x/d;
        y=y/d;
    }
    vec rot_90_cc()
    {
        vec vv;
        vv.x=-y;
        vv.y=x;
        return vv;
    }
    vec rot_90_c()
    {
        vec vv;
        vv.x=y;
        vv.y=-x;
        return vv;
    }
};

struct pt
{
    double x;
    double y;
    pt(){x=0; y=0;}
    vec operator-(pt p)
    {
        vec v;
        v.x=x-p.x;
        v.y=y-p.y;
        return v;
    }
    pt operator+(vec v)
    {
        pt p;
        p.x=x+v.x;
        p.y=y+v.y;
        return p;
    }
};
double dis(pt p1)
{
    double x=p1.x;
    double y=p1.y;
    return sqrt(x*x+y*y);
}
pt org;
struct ev
{
    double val;
    int state;
    int id;
};
vector<ev> evts;

struct cir
{
    pt s;
    pt e;
    int state;
    pt c;
    double r;
    int id;
    void update(int i)
    {
        vec nn;
        nn=c-org;
        nn.norm();
        s=org+nn*(dis(c)-r);
        e=org+nn*(dis(c)+r);
       // cout<<"dis="<<dis(e);
        ev ev1,ev2;
        ev1.val=dis(s);
        ev1.id=i;
        ev1.state=1;
        ev2.val=dis(e);
        ev2.id=i;
        ev2.state=2;
        evts.push_back(ev1);
        evts.push_back(ev2);
    }
};


double ins(cir cc)
{
  //  cout<<"D="<<d<<endl;
    vec nn;
    nn=cc.c-org;
    nn.norm();
    if(dis(cc.c)>(d+eps+cc.r))
    {
        return -1;
    }
    if(fabs(dis(cc.c)-(d+cc.r))<=eps||( fabs(d-(dis(cc.c)+cc.r))<=eps))
    {
        pt pp;
        pp=org+nn*d;
        double tt=atan2(pp.y,pp.x);
    //    cout<<"ang="<<tt<<endl;
    //    if(tt<0) tt+=2*pi;
        ang_ev vv;
        vv.id=cc.id;
        vv.val=tt;
        vv.state=3;
        vv.range=0;
        ang.push_back(vv);
        return 0;
    }
    double dmid=d-(d+cc.r)/(2.0*dis(cc.c));
    double dd=sqrt(d*d-dmid*dmid);
    vec nn1,nn2;
    pt pmid;
    pmid=org+nn*dmid;
    nn1=nn.rot_90_c();
    nn1=nn1*dd;
    pt p1,p2;
    p1=pmid+nn1;
    nn2=nn.rot_90_cc();
    nn2=nn2*dd;
    p2=pmid+nn2;
    double ang1=atan2(p1.y,p1.x);
    double ang2=atan2(p2.y,p2.x);
    double det=ang2-ang1;
  //  if(ang1<0) ang1+=2*pi;
  //  if(ang2<0) ang2+=2*pi;
    ang_ev an1,an2;
    an1.range=fabs(det);
    an2.range=fabs(det);
    an1.val=ang1;
    an1.id=cc.id;
    an1.state=1;
    an2.val=ang2;
    an2.id=cc.id;
    an2.state=2;
    ang.push_back(an1);
    ang.push_back(an2);
    return fabs(det);
}
bool cmp(ev v1, ev v2)
{
    return v1.val<=v2.val;
}
bool cmp_ang(ang_ev v1, ang_ev v2)
{
    if(fabs(v1.val-v2.val)<eps)
    {
        if(v1.state==v2.state)
        return v1.range>v2.range;
        else
        return v1.state<v2.state;
    }
    return v1.val<v2.val;
}

int main()
{
    int max_res=0;
    int cnt=0;
    vector<int> inds;
    int n;
    cin>>n>>d;
    double x,y,r;
    vector<cir> cc;
    cir tt;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>r;
        tt.c.x=x;
        tt.c.y=y;
        tt.r=r;
        tt.update(i);
        cc.push_back(tt);
    }
    sort(evts.begin(),evts.end(),cmp);
    int in=1;
    int j=0;
    double range=0;
    double max=0;
    int id_max;
    double d0=d;
    while(true)
    {
    //    cout<<"T";
        while(evts[j].val<=(in*d0)|| fabs(evts[j].val-(in*d0))<eps)
        {
        //    cout<<"J="<<j<<endl;
          //  cout<<"L";
            if(j==2*n)
            {
          //      cout<<"H"<<endl;
                break;
            }
          //  cout<<"J="<<j<<endl;
         //   cout<<"L";
            if(evts[j].state==1)
            {
                inds.push_back(evts[j].id);
            }
            if(evts[j].state==2)
            {
                if( fabs(evts[j].val-(in*d0))<eps)
                {
                    break;
                }
                else
                {
                    inds.erase(find(inds.begin(),inds.end(),evts[j].id));
                }

            }
            j++;
        }
      //  cout<<"ID="<<inds[0]<<endl;
        d=in*d0;
      //  cout<<"d="<<d<<endl;
        in++;
        int lll=inds.size();
        for(int i=0;i<lll;i++)
        {
         //   cout<<"K";
            range=ins(cc[inds[i]]);
         //   cout<<"r"<<range<<endl;
            if(range>max)
            {
                max=range;
                id_max=ang.size()-2; // id of start of segment
              //  cout<<"idm"<<ang[id_max].val<<endl;
            }
        }
        if(j==2*n)
        {
            if(evts[j-1].val>(d)||fabs(evts[j-1].val-(d))<eps)
            {
                j--;
               // cout<<"new="<<j;

            }
            else
            {
                break;
            }

        }
    }
    double id_v=ang[id_max].val;
  //  cout<<"val"<<id_v<<endl;
    sort(ang.begin(),ang.end(),cmp_ang);
    int uu=ang.size();
    int fin_id;
    for(int i=0;i<uu;i++)
    {
        if(ang[i].val==id_v)
        {
            fin_id=i;
            break;
        }
    }
  //  cout<<ang[0].val<<" "<<ang[1].val<<" "<<ang[2].val<<" "<<ang[3].val<<endl;
    int rr=ang.size();
    for(int i=0;i<rr;i++)
    {
        if(fabs(ang[i].val-ang[(i+1)%rr].val)<eps)
        {
            ang[i].coin++;
            ang[(i+1)%rr].coin++;
            if(i==rr-1)
            {
                ang[i].val=ang[(i+1)%rr].val;
            }
            else
            {
               ang[(i+1)%rr].val=ang[i].val;
            }
        }
    }
  //  cout<<ang[0].coin<<" "<<ang[1].coin<<" "<<ang[2].coin<<" "<<ang[3].coin<<endl;
   // cout<<ang[0].val<<"<"<<ang[1].val;
    int l=ang.size();
   // cout<<"idmax"<<fin_id<<endl;
    for(int i=fin_id;i<l+fin_id;i++)
    {
      //  cout<<"M";
      //  cout<<cnt;
        if(ang[i%l].state==1)
        {
            cnt++;
          //  cout<<"cntk"<<cnt<<endl;
            if(cnt>max_res) max_res=cnt;
            continue;
        }
        if(ang[i%l].state==2)
        {
            cnt--;
       //     cout<<"cntl"<<cnt<<endl;
            continue;
        }
        if(ang[i%l].state==3)
        {
            cnt=cnt+(1+ang[i%l].coin);
          //  cout<<"coin"<<i%l<<endl;
           // cout<<"cntm"<<cnt<<endl;
            if(cnt>max_res) max_res=cnt;
            cnt-=1+ang[i%l].coin;
            i+=ang[i%l].coin;
            continue;
        }
    }
    cout<<max_res;
    return 0;
}
