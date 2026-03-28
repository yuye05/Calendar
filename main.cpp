#include "calendar.h"

void menu()
{
	cout << "====== 日期处理程序 ======" << endl;
	cout << "==== 1.start | 0.exit ====" << endl;
}

//1.通过引用的方式直接操作date的成员
void game1(Date &date_ref)
{
	date_ref.input_date();
	date_ref.print_calendar();
	date_ref.print_day_of_year();	
}
//2.也可以通过指针传参来操作date成员，逻辑和引用一样
void game2(Date* date_ptr)
{
	date_ptr->input_date();
	date_ptr->print_calendar();
	date_ptr->print_day_of_year();
}

int main()
{
	Date date;
	int input = 0;
	menu();
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "程序开始 ->" << endl;
		break;
	case 0:
		cout << "退出程序！" << endl << endl;
		break;
	default:
		cout << "选择错误！请重新输入..." << endl << endl;
		break;
	}
	while (input == 1)
	{
		game1(date);
		//game2(&date);
		//date.game3();
	}
	return 0;
}




