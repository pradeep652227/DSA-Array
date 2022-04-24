#include <iostream>
#include <vector>
using namespace std;

int Delete(vector<int>&arr, int target);// left shifting
int  survived(vector<int>arr,int k);

int main()
{     int k;
//    vector<int>arr{0,1,2,3,4,5,6}; k=3;
     vector<int>arr{0,1,2,3}; k=2;
//    int size; 
//    cout<<"Enter number of array elements"<<endl;
//    cin>>size;
//    cout<<"Enter the array elements"<<endl; int temp{};
//    for(int i=0;i<size;i++)
//    {
//        cin>>temp; arr.push_back(temp);
//    }
//    int k;
//    cout<<"Kth person?, which is to be killed "<<endl; cin>>k;
    cout<<"The survived person is :"<<survived(arr,k)<<endl;
    
    return 0;
}

int Delete(vector<int>&arr, int target)
{
    for(int i=target+1;i<(int)arr.size();i++)
        arr[i-1]=arr[i];
        
        arr.pop_back();
    cout<<"Reduced size array "; for(auto &i:arr) cout<<i<<" "; cout<<endl;
        return arr.size();
}

int survived(vector<int>arr,int k)
{
    int target{}, pistol{0};
    int size{ arr.size() };
    for(;size>1;)
    {
        target=pistol+(k-1);
        if(target>=size)
            target-=size;
            cout<<"Target= "<<target<<" ";
        cout<<"Previous size= "<<arr.size()<<"  ";
        cout<<"Reduced size= "<<Delete(arr,target)<<endl;
        size--;
        pistol=(target+1)-1;//-1 for managing the original indexing after arr.pop_back(); 
        
        if(pistol>=size)
            pistol-=size;
         cout<<"pistol= "<<pistol<<endl;
        cout<<endl;
    }
    
    return(arr.at(0));
}
