#include <iostream>

using namespace std;

void diskMove(int n,int s,int d,int h,int &count);// ( s-> Sourche, d->Destination, h-> Helper )towers
int main()
{   
    int n;cin>>n;
    int s=1,
        h=2,
        d=3;
        
    int count{0};
    diskMove(n,s,d,h,count);
    
    return 0;
}

void diskMove(int n,int s,int d,int h,int &count)
{
    if(n==1)
    {   count++;
        cout<<count<<".) "<<"Move disk number "<<n<<" from tower "<<s<<" to tower "<<d<<endl;
        return;
    }
    
    diskMove(n-1,s,h,d,count);
        count++;
        cout<<count<<".) "<<"Move disk number "<<n<<" from tower "<<s<<" to tower "<<d<<endl;
    diskMove(n-1,h,d,s,count);
        
}