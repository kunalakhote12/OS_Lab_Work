#include<iostream>
using namespace std;
int main()
{
	int n,temp,min,d,tt=0;
	float atat=0,awt=0,stat=0,swt=0;
	cout<<"Enter the Number of processes: ";
	cin>>n;
	int PID[n],AT[n],BT[n],CT[n],TAT[n],WT[n];
	cout<<"Enter the process ID's(Number only): ";
	for(int i=0;i<n;i++)
		cin>>PID[i];
	cout<<"Enter the arrival time: ";
	for(int i=0;i<n;i++)
		cin>>AT[i];
	cout<<"Enter the burst time: ";
	for(int i=0;i<n;i++)
		cin>>BT[i];
	for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
        {
            if(BT[i]>BT[j])
            {
            	temp=PID[i];
                PID[i]=PID[j];
                PID[j]=temp;
                
            	temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;
				
				  
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
			     
            }
        }
    }
    min=AT[0];
    for(int i=0;i<n;i++)
    {
        if(min>AT[i])
        {
            min=AT[i];
            d=i;
        }
    }
    tt=min;
    CT[d]=tt+BT[d];
    tt=CT[d];

    for(int i=0;i<n;i++)
    {
        if(AT[i]!=min)
        {
        	CT[i]=BT[i]+tt;
            tt=CT[i];
        }
	}
    for(int i=0;i<n;i++)
    {
		TAT[i]=CT[i]-AT[i];
        stat=stat+TAT[i];
        WT[i]=TAT[i]-BT[i];
        swt=swt+WT[i];
    }
    atat=stat/n;
    awt=swt/n;
    cout<<"Average Turn around time: "<<atat;
    cout<<"\nAverage waiting time: "<<awt;
	return 0;
}
