#include<bits/stdc++.h>
using namespace std;
#define max 30
int main()
{
  
int i, j, n, t, p[max], bt[max], wt[max], tat[max];
  
float awt = 0, atat = 0;
  

  
cout << "enter the no of processes" << endl;
  
cin >> n;
  
cout << "enter the process no" << endl;
  
for (i = 0; i < n; i++)
    
    {
      
cin >> p[i];
    
}
  
cout << "enter the burst time of the process";
  
for (i = 0; i < n; i++)
    
    {
      
cin >> bt[i];
    
}




 
//applying bubble sort 
  for (i = 0; i < n; i++)
  
  {
    
 
for (j = 0; j < n - 1; j++)
      
      {
	
if (bt[j] > bt[j + 1])
	  
	  {
	    
t = bt[j];
	    
bt[j] = bt[j + 1];
	    
bt[j + 1] = t;
	    
 
t = p[j];
	    
p[j] = p[j + 1];
	    
p[j + 1] = t;
	  
}
      
}
  
}


cout << "process" << "\t" << "burst time" << "\t" << "waiting time" << "\t" <<
  "turn around time" << "\n";

 
for (i = 0; i < n; i++)
  
  {
    
wt[i] = 0;
    
tat[i] = 0;
    
for (j = 0; j < i; j++)
      
      {
	
wt[i] = wt[i] + bt[j];
      
}
    
tat[i] = wt[i] + bt[i];
    
awt = awt + wt[i];
    
atat = atat + tat[i];
    
cout <<"\t"<< p[i] << "\t" << bt[i] << "\t" << "\t"<< wt[i] << "\t" << "\t" << tat[i]<<endl;
  
}


 
awt = awt / n;

atat = atat / n;

cout << "avg waiting time=" <<" "<< awt<<endl;

cout << "avg turn around time=" <<" "<< atat<<endl;

return 0;

}





 
