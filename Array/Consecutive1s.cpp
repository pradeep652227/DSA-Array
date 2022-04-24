#include <iostream>
#include <vector>


using namespace std;
/*Maximum Consectuve 1s*/

int max1s(vector<bool>&arr);

int main()
{   
    int n;
    cin>>n;
    vector<bool>arr;
    
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp; arr.push_back(temp);
    }
    
    cout<<"Max consecutive 1s in ";for(auto i:arr) cout<<i<<" ";
    cout<<" are:-"<<endl;
    
    cout<<max1s(arr)<<endl;

return 0;

}

int max1s(vector<bool>&arr)
{   
    int n=arr.size();
    if(n==0)
        return -1;
    
    int len{0};
    int max_len{0};
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            len++;
        else
        {
            max_len=max(max_len,len);
            len=0;
        }
    }
    
    return max(max_len,len);
}