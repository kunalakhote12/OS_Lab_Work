#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of process : ";
    cin>>n;
    int AT[n],BT[n],WT[n],TAT[n];
    float stat,swt,atat,awt;
    /*cout<<"Enter Arrival time respectively : ";
    for(int i=0;i<n;i++)
        cin>>AT[i];*/
    cout<<"Enter Burst time respectively : ";
    for(int i=0;i<n;i++)
        cin>>BT[i];
    WT[0]=0;
    for(int i=1;i<n;i++)
    {
        WT[i]=BT[i-1]+WT[i-1];
    }
    for(int i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
    }
    for(int i=0;i<n;i++)
    {
    	swt=swt+WT[i];
    	stat=stat+TAT[i];
	}
	awt=swt/n;
	atat=stat/n;
	cout<<"Average Turn around time: "<<atat;
    cout<<"\nAverage waiting time: "<<awt;
    return 0;
}
