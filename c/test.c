#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int ma_id;
  char ma_name[80] = "soss";
  char ma_desc[80];
  int ma_year;

  fgets(ma_desc, 79, stdin);
  printf("%s\n", ma_desc);
//  scanf("%d %s %d", &ma_id, &ma_name, &ma_year);
  strcpy(ma_name, ma_desc);
  printf("%d,%s,%d", ma_id, ma_name, ma_year);

}
