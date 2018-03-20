#include "my_cal.h"

char out[20] = "0";

// 主函数
int main(int argc , char **argv)
{
    a = 0;
	b = 0;
	hasdot = 0;
	gtk_set_locale();
	gtk_init(&argc , &argv);
	method = 0;
	interface();                  /*建立界面*/
	addsignal();                  /*添加事件*/
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
