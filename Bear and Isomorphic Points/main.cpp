#include <iostream>
#include<complex>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<iterator>

#define pi acos(-1.0)
#define eps 0.0000001
#define pt complex<double>
#define x real()
#define y imag()

using namespace std;

struct seg
{
    pt p1,p2;
    seg(){p1=pt(0,0); p2=pt(0,0);}
    seg(pt _p1, pt _p2) {p1=_p1; p2=_p2;}
};
double fin_ang(pt p1)
{
    double k=arg(p1);
    if(k<0)
    k+=2*pi;
    return k;
}
bool check(pt p1, pt p2)
{
    pt t1,t2;
    t1=p2-p1;
    t2=-p2;
    if((conj(t1)*t2).y>0)
    return 1;
    else return 0;
}
vector< pair< double, pt> > p;
vector<seg> ss;
vector< pair< double, pt> >::iterator ta,tb;

void two_pointers()
{
    while(true)
        {
            while(!check((*ta).second,(*tb).second))
            {
                ta++;
                if(ta==p.end())
                return;

            }
            while(check((*ta).second,(*tb).second))
            {
                tb++;
                if(tb==p.end())
                tb=p.begin();
            }
            if(tb==p.begin())
            ss.push_back(seg((*ta).second,(*(p.end()-1)).second));
            else
            ss.push_back(seg((*ta).second,(*(tb-1)).second));
        }
}
bool cmp(pair< double, pt> p1,pair< double, pt> p2)
{
    if(p1.first==p2.first)
    {
        double t1=hypot(p1.second.x,p1.second.y);
        double t2=hypot(p2.second.x,p2.second.y);
        return t1<t2;
    }
    else return p1.first<p2.first;
}
int main()
{

    pt temp;
    pt li;
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        cin>>li.x>>li.y;
        for(int j=1;j<n;j++)
        {
            pt temp;
            double an;
            cin>>temp.x>>temp.y;
            pt tt;
            tt=temp-li;
            an=fin_ang(tt);
            p.push_back(make_pair(an,tt));
        }
        sort(p.begin(),p.end(),cmp);
        pt a,b;


        ta=p.begin();
        a=(*ta).second;
        for(int j=1;j<n;j++)
        {
            tb=ta+j;
            b=(*tb).second;
            if(check(a,b)==0)
            {
                if(j>1)
                {
                    ss.push_back(seg(a,(*(tb-1)).second));
                }
                break;
            }
        }
        ta++;
        two_pointers();

        p.clear();
        ss.clear();
    }
    return 0;
}
