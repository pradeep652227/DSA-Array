#include <iostream>
#include <vector>

using namespace std;

//void func_Leaders(vector<int>&arr);
void func_Leaders(vector<int>&arr, int &max,vector<int> &temp);
void swap(int &a ,int &b)
{
    a^=b;
    b^=a;
    a^=b;
}

int main()
{   vector<int>arr;
    int n;
    cin>>n; int temp{}; for(int i=0;i<n;i++){ cin>>temp; arr.push_back(temp); }
    
//    func_Leaders(arr);
        vector<int>Leaders;
        Leaders.push_back(arr.at(n-1));
        func_Leaders(arr,arr.at(n-1), Leaders);
        
        cout<<"Leaders in the array are:- "; 
       
        int i{0},j{Leaders.size()-1};
        while(i<j)
        {
            swap(Leaders[i],Leaders[j]);
            i++;j--;
        }
        
        for(auto &i:Leaders)
            cout<<i<<" ";
        
    return 0;
}

/*void func_Leaders(vector<int>&arr)
{
    int size{arr.size()};
    int max{arr.at(size-1)};
    
    cout<<max<<" ";// Right most element is always a leader 
    for(int j=size-1;j>0;j--)
    {
        if(arr.at(j-1) > max )
         {   cout<<arr.at(j-1)<<" ";
             max=arr.at(j-1);
         }
    }
    cout<<endl;
}
*/

/*My Approach*/
void func_Leaders(vector<int>&arr, int &max, vector<int>&temp)
{
    if(arr.size()==1)
        return ;
    
    int curr_elem=arr.at(arr.size()-1);
    arr.pop_back();
    if(curr_elem>max)
    {
        max=curr_elem;
        temp.push_back(max);
    }
    func_Leaders(arr, max, temp);
    arr.push_back(curr_elem);
}