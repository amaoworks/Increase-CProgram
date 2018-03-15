#include <gtk/gtk.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

double a, b;

int hasdot;
int method;
char out[20] = "0";
GtkWidget *window;
GtkWidget *vbox;
GtkWidget *entry1;
GtkWidget *label1;
GtkWidget *table1;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *button10;
GtkWidget *button11;
GtkWidget *button12;
GtkWidget *button13;
GtkWidget *button14;
GtkWidget *button15;
GtkWidget *button16;
GtkWidget *button17;
GtkWidget *button18;
GtkWidget *button19;
GtkWidget *button20;
GtkWidget *button21;
GtkWidget *button22;
GtkWidget *button23;
GtkWidget *button24;
GtkWidget *button25;
GtkWidget *button26;
GtkWidget *button27;
GtkWidget *button28;
GtkWidget *button29;
GtkWidget *button30;
GtkWidget *button31;
GtkWidget *button32;
GtkWidget *button33;
GtkWidget *button34;
GtkWidget *button35;
GtkWidget *button36;

// 双目运算函数
void Binary_Operator(){
	char num[20];
	strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry1)));
	if (a == 0){      // 如果没有第一个数，则储存为第一个数
		gtk_entry_set_text(GTK_ENTRY(entry1),"");
		a = atof(num);// 字符串转换成浮点型
	} else {
		b = atof(num);
	}
	hasdot = 0;       // 表示没有小数点
}

// 单目运算的结果输出
void Right_output(){
	char num[20];
	gcvt(a, 32, num); // 运算结果浮点型转化成字符串
	gtk_entry_set_text(GTK_ENTRY(entry1), num);  // 直接显示结果
	a = 0;
	b = 0;
	method = 0;
}

// 递归函数求阶乘
float fun(int c){
	float d;
	if(c == 0 || c == 1)
		d = 1;
	else
		d = fun(c - 1)*c;

	return d;
}

// 双目运算的结果输出
void output(){
	char num[20] = "0";
	strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry1))); // 取得文本框的内容
	b = atof(num);    // 字符型转换成浮点型
	switch(method){

	}
}
