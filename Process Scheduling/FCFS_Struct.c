#include<stdio.h>

struct Process {
  int p_id ;
  int arrival_time;
  int burst_time;
  int completion_time;
  int TAT;
  int waiting_time;
};

void main() {
  printf("Enter Number Of Process: ");
  int pnum;
  scanf("%d",&pnum);
  
  struct Process process[pnum];

  for(int i =0; i<pnum; i++) {
    process[i].p_id = 0;
    process[i].p_id = process[i].p_id + i+1;
    printf("Enter arrival Time for process number [ %d ]", process[i].p_id);
    scanf("%d",&process[i].arrival_time);
    printf("Enter Burst Time For Process number [ %d ]", process[i].p_id);
    scanf("%d",&process[i].burst_time);
  }

  // Since We are Using First CCome First Serve We Sort the Struct array based on Arrival Time; 
  //Bubble Sort is fine
  for(int j =0; j<pnum; j++) {
    for (int k = 0; k<pnum-j ;k++) {
      if (process[k].arrival_time > process[k+1].arrival_time) {
        struct Process temp[pnum];
        temp[k] = process[k];
        process[k] = process[k+1];
        process[k+1] = temp[k];
      }
    }
  }

  // Calculation
  int sum =0; 
  float AverageTAT, AverageWT, TotalTAT, TotalWT = 0.0;

  for(int i =0; i<pnum; i++) {
    sum = sum + process[i].burst_time;
      
    process[i].completion_time = process[i].completion_time + sum;
      
    process[i].TAT = process[i].completion_time - process[i].arrival_time;
    
    process[i].waiting_time = process[i].TAT - process[i].burst_time;

    TotalTAT += process[i].TAT;

    TotalWT += process[i].waiting_time;
    }
  printf("\n ***** FIRST COME FIRST SERVE ***** \n ");
  printf("\nPID \t AT \t BT \t CT \t TAT\n WT");
  for(int i =0; i<pnum; i++) {
    printf("%d \t %d \t %d \t %d \t %d\t %d\n",process[i].p_id, process[i].arrival_time, process[i].burst_time, process[i].completion_time, process[i].TAT, process[i].waiting_time);
    printf("Average Turn Around Time: %f \n Average Waiting Time: %d", TotalTAT/pnum, TotalWT/pnum);
  }
}
