#include <iostream>
using namespace std;

class dates {
  private:
    int day, month, year, last;
  public:
    void input();
  void Month();
  void Day();
  void output();
  void valid();
};

void dates::input() {
  cout << "\nEnter the Date DD MM YYYY :";
  cin >> day >> month >> year;
}
//Month
void dates::Month() {
  if (month > 0 && month <= 12) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
      last = 31;
      Day();
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      last = 30;
      Day();
    } else if (month == 2) {
      if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
        last = 29;
        Day();
      } else {
        last = 28;
        Day();
      }
    }
  } else
    cout << "Invalid";
}
//Day
void dates::Day() {
  if (day > 0 && day <= last) {
    valid();

  } else
    cout << "Invalid";
}
//output
void dates::output() {
  if (day == last) {
    if (month == 12) {
      day = 1;
      month = 1;
      year++;
    } else {
      day = 1;
      month++;
    }
  } else if (day != last) {
    day++;
  }
  cout << day << "/" << month << "/" << year;
}
//valid
void dates::valid() {
  cout << "\n Valid \n";
  output();
}

int main() {
  dates d;
  d.input();
  d.Month();
  return 0;
}
