#include <iostream>
#include <vector>


using namespace std;
/*Stocks Buy and Sell- 1 transaction allowed*/

int maxProfit(vector<int>&arr);

int main()
{   
    int n;
    cin>>n;
    vector<int>arr;
    
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp; arr.push_back(temp);
    }
    
    cout<<"Max profit in ";for(auto &i:arr) cout<<i<<" ";
    cout<<"is:- "<<endl<<maxProfit(arr);
    
return 0;
}

int maxProfit(vector<int>&arr)
{   
    int n=arr.size();
    int min_stock{arr[0]};
    int max_profit{arr[1]-arr[0]};
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]<min_stock)
            min_stock=arr[i];
        
        max_profit=max(max_profit,arr[i]-min_stock);
            
    }
    
    return max_profit;
}