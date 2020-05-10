void print_header(int year, int month) {
  if (month == 1) {
    printf("====January %d====\n", year);
  } else if (month == 2) {
    printf("===February %d====\n", year);
  } else if (month == 3) {
    printf("=====March %d=====\n", year);
  } else if (month == 4) {
    printf("=====April %d=====\n", year);
  } else if (month == 5) {
    printf("======May %d======\n", year);
  } else if (month == 6) {
    printf("=====June %d======\n", year);
  } else if (month == 7) {
    printf("=====July %d======\n", year);
  }else if (month == 8) {
    printf("====August %d=====\n", year);
  } else if (month == 9) {
    printf("===September %d===\n", year);
  } else if (month == 10) {
    printf("====October %d====\n", year);
  } else if (month == 11) {
    printf("===November %d====\n", year);
  } else if (month == 12) {
    printf("===December %d====\n", year);
  }
  printf("Su Mo Tu We Th Fr Sa\n");
}

const int base_year = 1589;
const int SUNDAY = 0;
const int base_year_jan_1 = SUNDAY;

/////////////////////////////////////////////////////////////////////////////

// is_leap_year(year) determines if the year is a leap year, 
// according to the Gregorian Calendar
bool is_leap_year(int year) {
  assert (year >= 0);
  if(year % 400 == 0){
    return true;
  }
  else if (year % 100 == 0){
    return false;
  }
  else if(year % 4 == 0){
    return true;
  }
  else {
    return false;
  }
}

// days_in_month(year, month) returns the number of days in the 
// corresponding month
int days_in_month(int year, int month) {
  if(month == 2){
    if(is_leap_year(year)){
      return 29;
    }
    else{
      return 28;
    }
  }
  else if(month == 1 || month == 3 ||month == 5||month == 7||month == 8 ||month == 10 ||month == 12){
    return 31;
  }
  else{
    return 30;
  }

}

// day_of_the_week(year, month, day) finds the "day of the week" 
// for the given date
int day_of_the_week(int year, int month, int day) {
  int count = 0;
  for(int i = 1589; i <= year; i++){
    if(i == year){
    for(int j = 1; j < month; j++){
      count = count + (days_in_month(i, j));
    }
    }
    else{
    for(int j = 1; j<=12; j++){
      count = count + (days_in_month(i, j));
      }
    }
  }
  count = count + day;
  

  if (count%7 == 0){
    return 6;
  }  else {
    return count%7-1;
  }
}

// print_calendar(year, month) prints a "pretty" calendar for the given month
// effects: produces output
void print_calendar(int year, int month) {
  int start = day_of_the_week(year, month, 1);  
  print_header(year, month);
  for(int i = 0; i<start; i++){
  printf("   ");
  }
  
  for(int i = 1; i <= days_in_month(year, month); i++){
    if(start % 7 == 6){
    printf("%2d\n", i);
    start++;
    }
    else if(i == days_in_month(year, month)){
      printf("%2d", i);
       start++;
    }
    else{
    printf("%2d ", i);
      start++;
    }
  }
  printf("\n");
  
}


int main(void) {
  assert(is_leap_year(2020));
  assert(is_leap_year(2000));
  assert(!is_leap_year(2001));
  assert(!is_leap_year(1900));
  
  assert(days_in_month(2020, 1) == 31);
  assert(days_in_month(2020, 2) == 29);
  assert(days_in_month(2020, 3) == 31);
  assert(days_in_month(2020, 4) == 30);
  assert(days_in_month(2019, 5) == 31);
  assert(days_in_month(2001, 6) == 30);
  
  assert(day_of_the_week(2020, 3, 9) == 1);
  assert(day_of_the_week(2020, 3, 10) == 2);
  assert(day_of_the_week(2020, 3, 11) == 3);
  assert(day_of_the_week(2020, 3, 12) == 4);
  assert(day_of_the_week(2020, 3, 13) == 5);
  assert(day_of_the_week(2020, 3, 14) == 6);
  assert(day_of_the_week(2020, 3, 15) == 0);
  
  //print_calendar(2020, 1);
  print_calendar(2020, 12);
  //print_calendar(2000, 3);
  
  
}
