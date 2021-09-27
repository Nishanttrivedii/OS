#include<iostream>
using namespace std;

int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    cout<<"enter burst time and priority"<<endl;
    for(i=0;i<n;i++)
    {cin>>bt[i];
     cin>>p[i];
        pr[i]=i+1;           //contains process number
    }
 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
   cout << "process" << "\t" << "burst time" << "\t" << "waiting time" << "\t" <<
  "turn around time" << "\n";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculating turn around time
        total+=tat[i];
       cout <<"\t"<< p[i] << "\t" << bt[i] << "\t" << "\t"<< wt[i] << "\t" << "\t" << tat[i]<<endl;
    }
 
    avg_tat=total/n;     //average turnaround time
  cout << "avg waiting time=" <<" "<< awt<<endl;

cout << "avg turn around time=" <<" "<< atat<<endl;

 
	return 0;
}