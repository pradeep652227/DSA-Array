#include <iostream>
#include <vector>
/* My Approach is to use merge sort and while merging do this:- max_diff=( (max_diff>arr[r]-arr[l])?max_diff : (arr[r]-arr[l]) ); */
using namespace std;

int maxDiff(vector<int>&arr);

int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a, int b)
{
    return (a<b)?a:b;
}

int main()
{   
    int n;
    cin>>n;
    vector<int>arr;
    int temp; for(int i=0;i<n;i++) { cin>>temp; arr.push_back(temp); }
    
    cout<<"Maximum Difference in the array:-"<<endl; for(auto &i:arr) cout<<i<<" ";
    cout<<"iS\t"<<maxDiff(arr);
    
    cout<<endl;
    return 0;
}

int maxDiff(vector<int>&arr)
{   
    if(arr.size()==1)
        return arr.at(0);

 /*Considering Every elem. as arr[j] and keeping track of minimum element that we've found so far (to the left of arr[j] ) */
    int diff=arr.at(1)-arr.at(0); int min_val=arr[0];
    
    int n=arr.size();
    for(int j=1;j<n;j++)
    {
        diff=max(diff,arr[j]-min_val);
        min_val=min(min_val,arr[j]);
    }
    
    return diff;
}