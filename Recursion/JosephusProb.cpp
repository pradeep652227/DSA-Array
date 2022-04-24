#include <iostream>
#include <vector>

using namespace std;
/* Two approaches:- 1.) My Approach( Array based, basically, I used D.S Array to represent/ store n people )
 *                  2.) General solution */
 
 /*For Anticlockwise solution, use n-ans */

//int survivor(vector<int> &persons,int gun, int k);
int jos(int n, int k);

int main()
{ 
//   vector<int> persons; int n; int k;
//   cout<<"Enter the number of persons in this death game "; cin>>n;
//   cout<<"What is the position of the person which is to be killed in every itieration? ";cin>>k;
//   for(int i=1;i<=n;i++)
//       persons.push_back(i);
//   cout<<endl;
//   
//   cout<<"Survivor among "<<n<<" people is "<<survivor(persons,0, k-1);
 
   int n,k;
   cout<<"Enter the number of persons in this death game "; cin>>n;
   cout<<"What is the position of the person which is to be killed in every itieration? ";cin>>k;
   cout<<endl;
   
   cout<<"Survivor among "<<n<<" people is "<<jos(n,k);
    return 0;
}

/*int survivor(vector<int> &persons,int gun, int k)
{   
    int size{ persons.size() };
    
    if( size == 1 )
        return persons.at(0);
    
    int target= (gun + k)% size;// person to be killed is in the index- target
    
    persons.erase(persons.begin() + target ); // target is now erased or the array is left shifted i.e the problem has now reduced to a smaller one.
    
    survivor(persons, target, k);// implementing the smaller problem
}*/

int jos(int n, int k)
{
    if(n==1)
        return 0;
    
    return (jos(n-1,k) + k)%n ;  
}

