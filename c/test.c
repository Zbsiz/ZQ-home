#include <stdio.h>

int main()
{
  int ma_id;
  char ma_name[80];
  char ma_desc[80];
  int ma_year;

  scanf("%d %s %d", &ma_id, &ma_name, &ma_year);
  printf("%d,%s,%d", ma_id, ma_name, ma_year);
}
