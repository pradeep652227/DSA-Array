#include <iostream>
#include <cmath>

using namespace std;

int kthgramm(int n,int k);

int main()
{
    int n,k;
    // cin>>n>>k;
    n=4,k=3;
    cout<<kthgramm(n,k)<<endl;

}

int kthgramm(int n,int k)
{
    if(n==1 && k==1)
        return 0;
    
    int size=pow(2,n-1);
    int mid=size/2;

    if(k<=mid)
    return kthgramm(n-1,k);
    else
    return !kthgramm(n-1,k-mid);    
}