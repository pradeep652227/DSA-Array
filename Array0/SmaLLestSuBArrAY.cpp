#include <iostream>
#include <climits>
#include <vector>
/* KADANE'S ALGORITHM*/
using namespace std;
int Min(int min,int b)
{
    if(min<b)
        return min;
    else
        return b;
}
int main()
{
    int s{0};
    cout<<"Enter the sum: "; cin>>s;
    int n; 
    cout<<"Enter length of the array:"; cin>>n;
    vector <int>arr;
    
    int element{};cout<<"Enter elements of the array one by one"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>element; arr.push_back(element);
    }
    
    int window_sum{0},window_start{},windowEnd{},min_length{INT_MAX};
    int length{};
    for(windowEnd=0;windowEnd<n;windowEnd++)
    {
        window_sum+=arr.at(windowEnd); length++;
        while(window_sum>=s)
        {
            min_length=Min(length,min_length);
            window_sum-=arr.at(window_start);  length--;
            window_start++;
        }
    }
    
    if(min_length==INT_MAX)
        cerr<<" 0"<<endl;
        else
            cout<<"Minimum length is:"<<min_length<<endl;
    
            
    return 0;
}