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
		case 0:
			a = a + b;
			Right_output();
			break;    // +
		case 1:
			a = a - b;
			Right_output();
			break;    // -
		case 2:
			a = a * b;
			Right_output();
			break;    // *
		case 3:
			if(b == 0){
				a = 0;
				b = 0;
				method = 0;
				gtk_entry_set_text(GTK_ENTRY(entry1),"Remainder can't for 0!");
			} else {
				a = a / b;
				Right_output();      // /
			}
			break;
		case 4:
			a = pow(a, b);
			Right_output();
			break;    // pow 算 a 的 b 次幂 X^Y
		case 5:
			a = ((int )a) & ((int)b);
			Right_output();
			break;    // & and
		case 6:
			a = ((int )a) | ((int )b);
			Right_output();
			break;    // | or
		case 7:
			a = ((int )a) ^ ((int )b);
			Right_output();
			break;    // ^ 异或 xor
		case 8:
			if(b == 0){
				a = 0;
				b = 0;
				method = 0;
				gtk_entry_set_text(GTK_ENTRY(entry1),"Remainder can't for 0!");
			} else {
				a = ((int )a) % ((int )b);
				Right_output();
			}
			break;    // % 取模（取余） mod
		case 9:
			a = sin(b);
			Right_output();
			break;    // sin
		case 10:
			a = cos(b);
			Right_output();
			break;    // cos
		case 11:
			a = tan(b);
			Right_output();
			break;    // tan
		case 12:
			a = exp(b);
			Right_output();
			break;    // exp
		case 13:
			a = b * b * b;
			Right_output();
			break;    // X ^ 3
		case 14:
			a = b * b;
			Right_output();
			break;    //  X ^ 2
		case 15:
			if(b <= 0){
				a = 0;
				b = 0;
				method = 0;
				gtk_entry_set_text(GTK_ENTRY(entry1),"Logarithm must be positive!");
			} else {
				a = log(b);
				Right_output();   // log
			}
			break;
		case 16:
			if(b <= 0){
				a = 0;
				b = 0;method = 0;
				gtk_entry_set_text(GTK_ENTRY(entry1),"Logarithm must be positive!");
			} else {
				a = log10(b);
				Right_output();   // ln
			}
			break;
		case 17:
			if(b < 0){
				a = 0;
				b = 0;
				method = 0;
				gtk_entry_set_text(GTK_ENTRY(entry1),"Function input is invalid,must be>=0!");
			} else {
				a = fun((int)(b));
				Right_output();   // n!
			}
			break;
		case 18:
			if(b == 0){
				a = 0;
				b = 0;
				method = 0;
				gtk_entry_set_text(GTK_ENTRY(entry1),"Divisor can't for 0!");
			} else {
				a = 1 / b;
				Right_output();   // 1 / X
			}
			break;
		case 19:
			a = ~((int )b);
			Right_output();
			break;    // not 取反
		case 20:
			a = floor(b);
			Right_output();
			break;    // int 取整 floor 返回小于或等于指定表达式的最大整数
		default:
			break;
	}
}

// 加法运算
void Add(GtkWidget *widget, gpointer data){
	method = 0;
	Binary_Operator();
}

// 减法运算
void Sub(GtkWidget *widget, gpointer data){
	method = 1;
	Binary_Operator();
}

// 乘法运算
void Mul(GtkWidget *widget, gpointer data){
	method 2;
	Binary_Operator();
}

// 除法运算
void Division(GtkWidget *widget, gpointer data){
	method = 3;
	Binary_Operator();
}

// exp 幂运算
void Mathpowxy(GtkWidget *widget, gpointer data){
	method = 4;
	Binary_Operator();
}

// and 逻辑与
void And(GtkWidget *widget, gpointer data){
	method = 5;
	Binary_Operator();
}

// or 逻辑或
void Or(GtkWidget *widget, gpointer data){
	method = 7;
	Binary_Operator();
}

// Mod 模运算（取余）
void Mod(GtkWidget *widget, gpointer data){
	method = 8;
	Binary_Operator();
}

// Sin
void Sin(GtkWidget *widget, gpointer data){
	method = 9;
	output();
}

// Cos
void Cos(GtkWidget *widget, gpointer data){
	method = 10;
	output();
}

// Tan
void Tan(GtkWidget *widget, gpointer data){
	method = 12;
	output();
}

// X ^ 3 立方
void Cube(GtkWidget *widget, gpointer data){
	method = 13;
	output();
}

// X ^ 2 平方
void Square(GtkWidget *widget, gpointer data){
	method = 14:
	output();
}

// log_e
void Log_e(GtkWidget *widget, gpointer data){
	method = 15;
	output();
}

// Log_10
void Log_10(GtkWidget *widget, gpointer data){
	method = 16;
	output();
}

// N!
void Factorial(GtkWidget *widget, gpointer data){
	method = 17;
	output();
}

// 1 / X
void lnverse(GtkWidget *widget, gpointer data){
	method = 18;
	output();
}

// not 逻辑非
void Not(GtkWidget *widget, gpointer data){
	method = 19;
	output();
}

// int 取整
void Floor(GtkWidget *widget, gpointer data){
	method = 20;
	output();
}

// . 小数点
void dot(GtkWidget *widget, gpointer data){
	if(hasdot == 0){
		gtk_entry_append_text(GTK_ENTRY(entry1),gtk_button_get_label(widget));
		hasdot = 1;     // 表示有一个小数点
	}
}

// 正负选择
void Sign(){
	char num[20];
	float c;
	strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry1))); // 取得文本框的内容
	c = atof(num);      // 字符型转换成浮点型
	c = -c;
	gcvt(c, 32, num);   // 浮点型转换成字符型
	gtk_entry_set_text(GTK_ENTRY(entry1), num);         // 显示结果
}

// 清除函数CR
