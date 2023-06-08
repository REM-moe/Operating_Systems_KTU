#include<stdio.h>

int q[100];
int front = -1, rear = -1;
void insert(int m) {
  if (front == -1) {
    front = 0;
  }
  rear = rear + 1;
  q[rear] = m;
}
int delete() {
  int y;
  y = q[front];
  front = front + 1;
  return y;
}
int main() {
  int times = 0, l, exist[50] = {
    0
  }, temp[50], tq, n, i, j, k, at[50], bt[50], p[50], sum = 0, ct[50] = {
    0
  }, tat[50], wt[50];
  float awt = 0, atat = 0, ttat = 0, twt = 0;
  printf("enter number of processes: ");
  scanf("%d", & n);
  for (i = 0; i < n; i++) {
    p[i] = i + 1;
    printf("arrival time of process p%d : ", p[i]);
    scanf("%d", & at[i]);
    printf("burst time of process p%d : ", p[i]);
    scanf("%d", & bt[i]);
    temp[i] = bt[i];
  }
  printf("Entered data can be represented in table form as\n");
  printf("\tProcess\t\tArrival Time\tBurst Time\n");
  for (i = 0; i < n; i++) {
    printf("\tP%d\t\t%d\t\t%d\n", p[i], at[i], bt[i]);
  }
  printf("enter the time quantum\n");
  scanf("%d", & tq);
  insert(0);
  exist[0] = 1;
  while (front <= rear) {
    l = delete();
    if (bt[l] >= tq) {
      bt[l] = bt[l] - tq;
      times = times + tq;
    } else {
      times = times + bt[l];
      bt[l] = 0;
    }
    for (i = 0; i < n; i++) {
      if (exist[i] == 0 && at[i] <= times) {
        insert(i);
        exist[i] = 1;
      }
    }
    if (bt[l] == 0) {
      ct[l] = times;
      tat[l] = ct[l] - at[l];
      ttat = ttat + tat[l];
      wt[l] = tat[l] - temp[l];
      twt = twt + wt[l];
    } else {
      insert(l);
    }
  }
  printf("After the completion of all processes\n");
  printf("\tProcess\t\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");\
  for (i = 0; i < n; i++) {
    printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], temp[i], ct[i], tat[i], wt[i]);
  }
  atat = ttat / n;
  awt = twt / n;
  printf("Average turnaround time=%0.2f\n", atat);
  printf("Average waiting time=%0.2f\n", awt);
  return 0;
}
