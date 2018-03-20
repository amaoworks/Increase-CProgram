#ifndef my_cal_h
#define my_cal_h

#include <gtk/gtk.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

double a, b;
int hasdot;
int method;

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

void Binary_Operator();
void Right_output();
float fun(int c);
void output();
void Add(GtkWidget *widget, gpointer data);
void Sub(GtkWidget *widget, gpointer data);
void Mul(GtkWidget *widget, gpointer data);
void Division(GtkWidget *widget, gpointer data);
void Mathpowxy(GtkWidget *widget, gpointer data);
void And(GtkWidget *widget, gpointer data);
void Or(GtkWidget *widget, gpointer data);
void Xor(GtkWidget *widget, gpointer data);
void Mod(GtkWidget *widget, gpointer data);
void Sin(GtkWidget *widget, gpointer data);
void Cos(GtkWidget *widget, gpointer data);
void Tan(GtkWidget *widget, gpointer data);
void Exp(GtkWidget *widget, gpointer data);
void Cube(GtkWidget *widget, gpointer data);
void Square(GtkWidget *widget, gpointer data);
void Log_e(GtkWidget *widget, gpointer data);
void Log_10(GtkWidget *widget, gpointer data);
void Factorial(GtkWidget *widget, gpointer data);
void Inverse(GtkWidget *widget, gpointer data);
void Not(GtkWidget *widget, gpointer data);
void Floor(GtkWidget *widget, gpointer data);
void dot(GtkWidget *widget, gpointer data);
void Sign();
void clear(GtkWidget *widget, gpointer data);
void input(GtkWidget *widget, gpointer data);
void input_pi(GtkWidget *widget, gpointer data);
void interface();
void addsignal();

#endif
