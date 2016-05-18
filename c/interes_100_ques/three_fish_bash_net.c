/*
 * 某人从1990年1月1日起开始“三天打鱼两天晒网”，问这个人在以后的某一天中是“打鱼”还是“晒网”？
 * 生词  fish_net  渔网
 */

#include <stdio.h>

/* 定义日期结构体 */
typedef struct date
{
  int year;
  int month;
  int day;
} DATE;

/* 函数声明 */
int countDay(DATE);
int runYear(int);

int main()
{
  DATE today;  // 指定日期
  int totalDay;   // 指定日期距离1990年1月1日的天数
  int result;     // totalDay对5取余的结果

  /* 输入指定日期，包括年，月，日*/
  printf("Please input 指定日期 包括年，月，日 如：1999 1 31\n");
  scanf("%d%d%d", &today.year, &today.month, &today.day);
  
  /* 求出指定日期距离1990年1月1日的天数 */
  totalDay=countDay(today);

  /* 天数%5，判断输出打鱼还是晒网 */
  result=totalDay%5;

  if (result>0 && result <4)
    printf("今天打鱼\n");
  else
    printf("今天晒网\n");
}

/* 判断是否为闰年，是返回1,否返回0 */
int runYear(int year)
{
  if ((year%4==0 && year%100!=0) || (year%400==0)) //是润年
    return 1;
  else return 0;
}

/* 计算指定日期距离1990年1月1日的天数 */
int countDay(DATE currentDay)
{
  int perMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30};  // 每月天数数组

  int totalDay=0,year,i;

  /* 求出指定日期之前的每一年的天数累加的和 */
  for (year=1990; year<currentDay.year; year++)
  {
    if (runYear(year))   /* 判断是否为闰年 */
      totalDay=totalDay+366;
    else
      totalDay=totalDay+365;
  }

  /* 如果为闰年，则2月份为29天 */
  if (runYear(currentDay.year))
    perMonth[2]+=1;
  
  /* 将本年内的天数累加到 totalDay 中 */
  for (i=0; i<currentDay.month; i++)
    totalDay+=perMonth[i];

  /* 将本月内的天数累加到 totalDay 中 */
  totalDay+=currentDay.day;

  /* 返回 totalDay */
  return totalDay;
}