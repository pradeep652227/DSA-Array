#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout<<"Enter the string: "; getline(cin,str);
    string _str{NULL}; int k; 
    cout<<"Enter number of distinct characters: "; cin>>k;   int temp{k};
    
    string max_str{NULL}; int window_start{0};
    
    for(int i=0;i<static_cast<int>(str.length());i++)
    {
        if(_str.find(str.at(i))==string::npos && k>0)
        {
            _str.push_back(str.at(i)); k--;
        }
        else if(_str.find(str.at(i))!= string::npos)
            _str.push_back(str.at(i));
            
        else if(k==0)    // WINDOW SLIDING
        {
          while(
        }
            
    }
    
    cout<<"Longest String with "<<temp<<" distinct characters is:-\t"<<max_str<<"\t"<<_str<<endl;
    cout<<max_str.length()<<endl;
    return 0;
    
}