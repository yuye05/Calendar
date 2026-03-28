#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	bool is_leap_year();	//判断是否是闰年

	int day_of_month(); //一个月有多少天

	int day_of_year();	//计算这天是这一年的第多少天

	void input_date();	//输入日期

	void print_calendar();	//打印日历

	void print_day_of_year();	//打印这天是这一年的第多少天
	//3.直接把game当成date成员函数，不用传参，最快最好
	void game3()
	{
		input_date();
		print_calendar();
		print_day_of_year();
	}
};