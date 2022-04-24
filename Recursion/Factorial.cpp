#include <iostream>

using namespace std;

int fact(int n);

int main()
{   int n;cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}

int fact(int n)
{
    if(n==1 || n==0)
        return n;
    return n* fact(n-1);
}