
#include<iostream>
using namespace std;

// Function to find the waiting time for all
// processes
void WaitingTime(int processes[], int n, int bt[],
	int wt[], int at[])
{
	int service_time[n];
	service_time[0] = at[0];
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++)
	{
		// Add burst time of previous processes
		service_time[i] = service_time[i-1] + bt[i-1];

		// Find waiting time for current process =
		// sum - at[i]
		wt[i] = service_time[i] - at[i];

		if (wt[i] < 0)
			wt[i] = 0;
	}
}

//turn around time calculation``
void TurnAroundTime(int processes[], int n, int bt[],
									int wt[], int tat[])
{
	// Calculating turnaround time by adding bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turn-around
// times.
void avgTime(int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n];

	// waiting time of all processes
	WaitingTime(processes, n, bt, wt, at);

	// turn around time for all processes
	TurnAroundTime(processes, n, bt, wt, tat);

	// Display processes with details
	cout << "Processes " << " Burst Time " << " Arrival Time "
		<< " Waiting Time " << " Turn-Around Time "
		<< " Completion Time \n";
	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int compl_time = tat[i] + at[i];
		cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"
			<< at[i] << "\t\t" << wt[i] << "\t\t "
			<< tat[i] << "\t\t " << completion_time << endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

int main()
{
	
	int processes[] = {1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	
	int burst_time[] = {5, 9, 6};

	
	int arrival_time[] = {0, 3, 6};

	avgTime(processes, n, burst_time, arrival_time);

	return 0;
}
