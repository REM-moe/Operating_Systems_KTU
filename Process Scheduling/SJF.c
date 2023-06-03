#include<stdio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int n,at[50],bt[50],i,p[50],j,k,sum=0,ct[50]={0},tat[50],wt[50];
	float ttat=0,twt=0,awt=0,atat=0;
	printf("Enter no of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("Arrival Time of Process P%d: ",p[i]);
		scanf("%d",&at[i]);
		printf("Burst Time of Process P%d: ",p[i]);
		scanf("%d",&bt[i]);
	}
	printf("Entered data can be represented in tabular form\n");
	printf("\tProcess\t\tArrival Time\tBurst Time\n");
	
	for(i=0;i<n;i++){
		printf("\tP%d\t\t%d\t\t%d\n",p[i],at[i],bt[i]);
	}
	
	for(j=1;j<n;j++){
		for(k=0;k<n-j;k++){
			swap(&p[k],&p[k+1]);
		if(at[k]>at[k+1]){
				swap(&p[k],&p[k+1]);
				swap(&at[k],&at[k+1]);
				swap(&bt[k],&bt[k+1]);
			}
		}
	}
	
	for(j=1;j<n-1;j++){
		for(k=1; k<n-j; k++){
			swap(&p[k],&p[k+1]);
		if(bt[k]>bt[k+1]){
				swap(&p[k],&p[k+1]);
				swap(&at[k],&at[k+1]);
				swap(&bt[k],&bt[k+1]);
			}
		}
	}
	
	
	for(i=0;i<n;i++){
		sum=sum+bt[i];
		ct[i]=ct[i]+sum;
		tat[i]=ct[i]-at[i];
		ttat=ttat+tat[i];
		wt[i]=tat[i]-bt[i];
		twt=twt+wt[i];
	}
		printf("After the completion of all processes\n");
		printf("\tProcess\t\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
	printf("\t\tSHORTEST JOB FIRST\n");
	for(i=0;i<n;i++){
		printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
		atat=ttat/n;
		awt=twt/n;
	printf("Average Turnaround Time=%0.2f",atat);
	printf("\n");
	printf("Average Waiting Time=%0.2f\n",awt);
	return 0;
}


