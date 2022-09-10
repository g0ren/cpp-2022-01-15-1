#include <iostream>
using namespace std;
#define ABS(X) (((X)>0)?(X):-(X))

const int year[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int leapyear[12] { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// A year is a leap year if it's divisible by 400
// OR if it's divisible by 4, but not by 100
bool isLeapYear(int year) {
	return (!(year % 400) || (!(year % 4) && (year % 100)));
}

long totalDays(int year, int month, int day) {
	int r { 0 };
	for (int i = 0; i < year; i++) {
		if (isLeapYear(i)) {
			r += 366;
		} else {
			r += 365;
		}
	}
	for (int i = 1; i < month; i++) {
		if (isLeapYear(year)) {
			r += ::leapyear[i - 1];
		} else {
			r += ::year[i - 1];
		}
	}
	r += day - 1;
	return r;
}

long dateDifference(int year1, int month1, int day1, int year2, int month2,
		int day2) {
	long totaldays1 { 0 }, totaldays2 { 0 };
	totaldays1 = totalDays(year1, month1, day1);
	totaldays2 = totalDays(year2, month2, day2);
	return ABS(totaldays1 - totaldays2);
}

int main() {
	int year1 { 0 }, month1 { 0 }, day1 { 0 }, year2 { 0 }, month2 { 0 }, day2 {
			0 };

	cout << "Enter date #1 (year, month, day)" << endl;
	cin >> year1 >> month1 >> day1;

	cout << "Enter date #2 (year, month, day)" << endl;
	cin >> year2 >> month2 >> day2;

	cout << "The difference between " << day1 << "/" << month1 << "/" << year1
			<< " and " << day2 << "/" << month2 << "/" << year2 << " is "
			<< dateDifference(year1, month1, day1, year2, month2, day2)
			<< " days";
	return 0;
}
