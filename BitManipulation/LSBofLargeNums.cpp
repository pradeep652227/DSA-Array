#include <iostream>

using namespace std;

    
int main(int argc, char **argv)
{    
  int n;
  cin>>n;

int lsb{}, temp{n}, loop_var{},flag{},count{};

while(temp!=0)
{
    if(temp&(0xff))
    {
        while(1)
        {   
            if( (temp&(1<<loop_var))!=0)
            {
                lsb=loop_var; flag=1;break;
            }
            loop_var++; 
        }
        
        if(flag==1)
            break;
    }
    else{
        temp>>=8;
        count+=8;
        loop_var=0;
    }
}  

cout<<"loop_var= "<<loop_var<<" LSB "<<lsb+count<<endl;  
	return 0;
}


