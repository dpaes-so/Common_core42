#include <stdio.h>
#include <time.h>

int main()
{
  clock_t begin, end;
  double time_spent;

  begin = clock();
  time_spent = (double)begin / CLOCKS_PER_SEC;
  for(time_spent=0.0; time_spent<62000.0; time_spent++)
  {
      printf("hello \n");

      if(time_spent==5.0)
      break;
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf(" %lf\n", time_spent);
}