#include "calendar.h"

void Date::input_date()
{
	while (1)
	{
		cout << "请按如下格式输入日期：年 月 日（输入0 0 0退出）" << endl;
		cin >> year >> month >> day;
		if (year == 0 && month == 0 && day == 0)
		{
			cout << "退出程序！" << endl << endl;
			exit(0);	//用于没有返回值函数直接结束程序
		}
		//合法性校验
		else if (year < 2000 || month < 1 || month>12 || day < 1 || day > day_of_month())
		{
			cout << "日期格式错误，请重新输入！\n\n";
			continue;
		}
		break;
	}
}

bool Date::is_leap_year()
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int Date::day_of_month()
{
	const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && is_leap_year())
		return 29;
	else
		return days[month - 1];
}

int Date::day_of_year()
{
	int total = 0;
	const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//循环加第i-1月前的月份总天数
	for (int i = 0; i < month-1; i++)
	{
		total = total + days[i];
	}
	total += day;
	return total;
}

void Date::print_day_of_year()
{
	const int ret = day_of_year();
	cout << year <<"年"<<month<<"月"<<day<<"号"<<"是这一年的第" << ret << "天\n\n\n";

}

void Date::print_calendar()
{
	cout << "====== " << year << "年" << month << "月日历 ======" << endl;
	cout << "日  一  二  三  四  五  六" << endl;
	//通过基姆拉尔森公式计算每个月一号是周几
	int y = year;
	int m = month;
	const int d = 1;
	if (m < 3)
	{
		m += 12;
		y--;
	}
	const int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
	for (int i = 0; i < w; i++)
	{
		cout << "    ";
	}
	const int day1 = day_of_month();
	for (int i = 1; i <= day1; i++)
	{
		//将目标日期输出为红色（
		if (i == day)
			cout << "\033[31m" << left << setw(4) << i << "\033[0m";
		else
			cout << left << setw(4) << i;
	
		if ((w + i) % 7 == 0)
			cout << endl;
	}
	cout << endl;
}
