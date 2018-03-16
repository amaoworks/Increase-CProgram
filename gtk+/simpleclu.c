#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

char buf[50] = "";

void deal_num(GtkButton *button, gpointer data){
	const char *text = gtk_button_get_label(button);

	// 退格操作
	if (0 == strcmp(text, "c")){
		buf[strlen(buf) - 1] = 0;
	}
	else{
		int a = 0, b = 0;
		char c;
		strcat(buf, text);

		if (0 == strcmp("=", text)){
			printf("text==##%s##\n", text);
			sscanf(buf, "%d%c%d", &a, &c, &b);

			printf("--------001-------%c--\n", c);
			if ('+' == c) {
				sprintf(buf, "%d", a+b);
			}
			else if ('-' == c) {
				sprintf(buf, "%d", a-b);
			}
			else if ('*' == c) {
				sprintf(buf, "%d", a*b);
			}
			else if ('/' == c) {
				sprintf(buf, "%d", a/b);
			}

		}
	}

	gtk_entry_set_text(GTK_ENTRY(data), buf);

	return;
}

int main(int argc, char **argv){
	// gtk 环境初始化
	gtk_init(&argc, &argv);

	// 创建一个窗口
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	// 创建一个表格容器 5 行 4 列
	GtkWidget *table = gtk_table_new(5, 4, TRUE);
	// 将 table 加入到 window 中
	gtk_container_add(GTK_CONTAINER(window), table);

	// 创建一个行编辑
	GtkWidget *entry = gtk_entry_new();
	// 设置行编辑的内容
	gtk_entry_set_text(GTK_ENTRY(entry), "2+2=4");
	// 设置行编辑不允许编辑， 只能显示用
	gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);

	// 创建多个按钮
	GtkWidget *button0 = gtk_button_new_with_label("0"); // 数值键0
	GtkWidget *button1 = gtk_button_new_with_label("1"); // 数值键1
	GtkWidget *button2 = gtk_button_new_with_label("2"); // 数值键2
	GtkWidget *button3 = gtk_button_new_with_label("3"); // 数值键3
	GtkWidget *button4 = gtk_button_new_with_label("4"); // 数值键4
	GtkWidget *button5 = gtk_button_new_with_label("5"); // 数值键5
	GtkWidget *button6 = gtk_button_new_with_label("6"); // 数值键6
	GtkWidget *button7 = gtk_button_new_with_label("7"); // 数值键7
	GtkWidget *button8 = gtk_button_new_with_label("8"); // 数值键8
	GtkWidget *button9 = gtk_button_new_with_label("9"); // 数值键9

	GtkWidget *button_add = gtk_button_new_with_label("+");   // 加号
	GtkWidget *button_minus = gtk_button_new_with_label("-"); // 减号
	GtkWidget *button_mul= gtk_button_new_with_label("*");    // 乘号
	GtkWidget *button_div = gtk_button_new_with_label("/");   // 除号
	GtkWidget *button_equal = gtk_button_new_with_label("="); // 等号
	GtkWidget *button_delete = gtk_button_new_with_label("c");// 退格键

	// 布局将上面的按钮均放入 table 容器中
	gtk_table_attach_defaults(GTK_TABLE(table), entry, 0, 4, 0, 1);

	gtk_table_attach_defaults(GTK_TABLE(table), button0, 0, 1, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), button1, 0, 1, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button2, 1, 2, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button3, 2, 3, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button4, 0, 1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button5, 1, 2, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button6, 2, 3, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button7, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), button8, 1, 2, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), button9, 2, 3, 1, 2);

	gtk_table_attach_defaults(GTK_TABLE(table), button_add, 1, 2, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_minus, 2, 3, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_mul, 3, 4, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button_div, 3, 4, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button_equal, 3, 4, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_delete, 3, 4, 1, 2);

	// 注册信号函数，把 entry 传回调函数 deal_num()
	g_signal_connect(button0, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button1, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button2, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button3, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button4, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button5, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button6, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button7, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button8, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button9, "pressed", G_CALLBACK(deal_num), entry);

	g_signal_connect(button_add, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button_mul, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button_div, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button_minus, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button_equal, "pressed", G_CALLBACK(deal_num), entry);
	g_signal_connect(button_delete, "pressed", G_CALLBACK(deal_num), entry);

	// 显示所有控件
	gtk_widget_show_all(window);

	// 主事件循环
	gtk_main();

	return 0;
}
