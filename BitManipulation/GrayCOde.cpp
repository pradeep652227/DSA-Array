#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

vector<string> getGray(int n);

int main()
{   int n;
    cin>>n;
    
    vector<string> str=getGray(n);
    
    for(auto &i:str)
        cout<<i<<" ";
        cout<<endl;
    return 0;
}

vector<string> getGray(int n)
{
//    int msb=log2(n);
//        
//        int prevBit=n&(1<<msb);
//        
//        int gray{};
//        gray=gray|prevBit;
//        
//        int temp{};
//        
//        for(int i=msb;i>0;i--)
//        {   temp=prevBit>>1;
//            if((n&temp)==0)
//            gray=gray|temp;
//            
//            prevBit=1<<(i-1);
//        }
//        
//        return gray;

    if(n==1)
        return {"0","1"};
    vector<string> str;
    
    str=getGray(n-1);
    
    vector<string> temp;
    int size=str.size() -1;
    
    int k{};string ch;
     
     ch="0";
        for(int i=0;i<=size;i++)
        {
            temp.push_back(ch);
            temp[k]=temp[k]+str[i];
            k++;
        }
    ch="1";
    
            for(int i=size;i>=0;i--)
        {
            temp.push_back(ch + str[i]);
        }
    
    
    return temp;
}