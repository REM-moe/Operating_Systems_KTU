#include<stdio.h>

struct Process {
  int p_id ;
  int priority;
  int arrival_time;
  int burst_time;
  int completion_time;
  int TAT;
  int waiting_time;
};

void main() {
  printf("Enter Number Of Process: ");
  int pnum = 0;
  scanf("%d",&pnum);
  
  struct Process process[pnum];

  for(int i =0; i<pnum; i++) {
    process[i].p_id = 0;
 	process[i].priority = 0;
 	process[i].arrival_time= 0;
 	process[i].burst_time = 0;
 	process[i].completion_time  = 0;
 	process[i].TAT = 0;
 	process[i].waiting_time = 0;
 	
	process[i].p_id += i+1;
 	
 	
    printf("Enter arrival Time for process number [ %d ] ", process[i].p_id);
    scanf("%d",&process[i].arrival_time);
    printf("Enter Burst Time For Process number [ %d ] ", process[i].p_id);
    scanf("%d",&process[i].burst_time);
    printf("Enter Priority Of Process number [ %d ] ", process[i].p_id);
    scanf("%d",&process[i].priority);
  }

  // Since We are Using First Come First Serve We Sort the Struct array based on Arrival Time; 
  //Bubble Sort is fine
  for(int j =0; j<pnum; j++) {
    for (int k = 0; k<pnum-j ;k++) {
      if (process[k].arrival_time > process[k+1].arrival_time) {
        struct Process temp[pnum];
        
        
	temp[0].p_id = 0;
 	temp[0].priority = 0;
 	temp[0].arrival_time= 0;
 	temp[0].burst_time = 0;
 	temp[0].completion_time  = 0;
 	temp[0].TAT = 0;
 	temp[0].waiting_time = 0;
        
        
        
        temp[0] = process[k];
        process[k] = process[k+1];
        process[k+1] = temp[0];
      }
    }
  }
  
  // Next Sort Using Priority (Higher Number = Higher Priority)
	for(int j=1;j<pnum-1;j++){
		for(int k=1; k<pnum-j; k++){
		if(process[k].priority < process[k+1].priority){
		
		struct Process temp[pnum];
        temp[0] = process[k];
        process[k] = process[k+1];
        process[k+1] = temp[0];      
			}
		}
	}

  // Calculation
  int sum = 0; 
  float AverageTAT, AverageWT, TotalTAT, TotalWT = 0.0;

  for(int i =0; i<pnum; i++) {
    sum = sum + process[i].burst_time;
      
    process[i].completion_time = process[i].completion_time + sum;
      
    process[i].TAT = process[i].completion_time - process[i].arrival_time;
    
    process[i].waiting_time = process[i].TAT - process[i].burst_time;

    TotalTAT += process[i].TAT;

    TotalWT += process[i].waiting_time;
    }
	  printf("\n ***** PRIORITY SCHEDULING ***** \n ");
	  printf("\nPID \t priority \t AT \t BT \t CT \t TAT\t WT\n");
  for(int i =0; i<pnum; i++) {
    printf("%d \t %d \t\t %d \t %d \t %d \t %d\t %d\n",process[i].p_id, process[i].priority, process[i].arrival_time, process[i].burst_time, process[i].completion_time, process[i].TAT, process[i].waiting_time);
  }
      printf("Average Turn Around Time: %f \n Average Waiting Time: %f \n", TotalTAT/pnum, TotalWT/pnum);
}
