#include<iostream>
using namespace std;
class fcfs
{
public:
void input()
{
//cout<<"hi";
int i,awt,att;
int n;
awt=0;att=0;
cin>>n;
int arr[3][n];
for(i=0;i<n;i++)
{
cout<<"First enter the processing time and then the arrival time"<<endl;
cin>>arr[0][i];
cout<<endl;
cin>>arr[1][i];
cout<<endl;
}
for(i=0;i<n;i++)
{
if(i==0)
arr[2][i]=arr[0][i];
else
arr[2][i]=arr[0][i]+arr[2][i-1];
}
for(i=0;i<n-1;i++)
awt+=arr[2][i]-arr[1][i];
awt=awt/n;
for(i=0;i<n;i++)
att+=arr[2][i];
att=att/n;
cout<<awt<<" "<<att;
cout<<endl;
for(i=0;i<n;i++)
{
a[i]=a[0]
}
/*for(i=0;i<n;i++)
{
cout<<arr[0][i]<<" "<<arr[1][i]<<" "<<arr[2][i];
cout<<endl;
}*/
}

};
int main()
{
fcfs ob;
ob.input();
return 0;
}
