***** THE CODE IS NOT CORRECT *****
*                                  *
*                                  *
*                                  *
***********************************


#include <stdio.h>

#include<math.h>

int main() {
  int r[100], i, n, t = 0, h;
  printf("Enter number of requests\n");
  scanf("%d", & n);
  printf("Enter sequence of requests\n");
  for (i = 0; i < n; i++) {
    scanf("%d", & r[i]);
  }
  printf("Initial head position\n");
  scanf("%d", & h);
  printf("%d", h);
  for (i = 0; i < n; i++) {
    printf("=>%d", r[i]);
    t = t + (r[i] - h);
    h = r[i];
  }
  printf("\nTotal head movement=%d\n", t);
  return 0;
}
