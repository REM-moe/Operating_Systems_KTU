#include <stdio.h>

typedef struct P{
  int pno;
  int AT;
  int WT;
  int BT;
  int CT;
  int TAT;
  int PR;
} PS;

int main(int argc, char *argv[]) {
  int pno;
  printf("\t PRIORITY \nEnter Number Of Processes: ");
  scanf("%d",&pno);
  PS process[pno];
  for( int i=0; i<pno; i++) {
    process[i].pno = i+1;
    printf("Enter Priority: ");
    scanf("%d",&process[i].PR);
    printf("Enter AT: ");
    scanf("%d",&process[i].AT);
    printf("Enter BT: ");
    scanf("%d",&process[i].BT);
    process[i].CT = 0;
    process[i].WT = 0;
    process[i].TAT = 0;
  }

  for (int i = 0; i<pno; i++) {
    for (int j = 0; j<pno-1; j++) {
      if(process[j].AT > process[j+1].AT) {
        PS temp;
        temp = process[j];
        process[j] = process[j+1];
        process[j+1] = temp;
      }
    }
  }
  
  for (int i = 1; i<pno-1; i++) {
    for (int j = 1; j<pno-i; j++) {
      if(process[j].PR < process[j+1].PR) {
        PS temp;
        temp = process[j];
        process[j] = process[j+1];
        process[j+1] = temp;
      }
    }
  }

  int sum = 0;
  float ttat, twt = 0;
  for (int i = 0; i<pno; i++) {
    sum += process[i].BT;
    process[i].CT = sum + process[i].CT;
    process[i].TAT = process[i].CT - process[i].AT;
    ttat += process[i].TAT;
    process[i].WT = process[i].TAT - process[i].BT;
    twt += process[i].WT;
  }

  printf("PN \t PR \t AT \t BT \t CT \t TT \t WT \t \n");
  for (int i = 0;i<pno; i++) {
    printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t\n",process[i].pno, process[i].PR, process[i].AT, process[i].BT, process[i].CT, process[i].TAT, process[i].WT);
  }
  float avgWT = twt/pno;
  float avgTT = ttat/pno;
  printf("Average TAT: %f \t Average WT: %f \n", avgTT, avgWT);
  return 0;
}