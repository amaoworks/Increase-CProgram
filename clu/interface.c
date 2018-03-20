#include "my_cal.h"

// 界面构建函数
void interface(){
	char title[] = "My Calculator";
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);   // 创建一个窗口
	gtk_window_set_title(GTK_WINDOW(window), title);// 为窗口添加标题
	vbox = gtk_vbox_new(FALSE, 0);                  // 创建垂直框
	gtk_container_add(GTK_CONTAINER(window), vbox); // 把垂直框添加到窗口中
	gtk_widget_show(vbox);                          // 显示垂直框
	entry1 = gtk_entry_new();                       // 创建一个文本框
	gtk_box_pack_start(GTK_BOX(vbox),entry1, TRUE, FALSE, 0);  // 把文本框添加到垂直框中
	gtk_widget_show(entry1);                        // 显示文本框
	label1 = gtk_label_new("    10' Calculate    ");   // 创建一个标签
	gtk_box_pack_start(GTK_BOX(vbox), label1, TRUE, FALSE, 0); // 把标签添加到垂直框中
	gtk_widget_show(label1);                        // 显示垂直框
	table1 = gtk_table_new(4, 9, FALSE);            // 创建一个表格
	gtk_box_pack_start(GTK_BOX(vbox), table1, TRUE, FALSE, 0); // 表格添加到垂直框中
	gtk_widget_show(table1);                        // 显示表格
//----------	
	button1 = gtk_button_new_with_label("Pi");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button1 , 0 , 1 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button1 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button1);                           //显示按钮
	
	button2 = gtk_button_new_with_label("Sin");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button2 , 0 , 1 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button2 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button2);                           //显示按钮

	button3 = gtk_button_new_with_label("Cos");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button3 , 0 , 1 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button3 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button3);                           //显示按钮

	button4 = gtk_button_new_with_label("Tan");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button4 , 0 , 1 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button4 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button4);                           //显示按钮
//-----------
	button5 = gtk_button_new_with_label("Exp");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button5 , 1 , 2 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button5 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button5);                           //显示按钮
	
	button6 = gtk_button_new_with_label("X^Y");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button6 , 1 , 2 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button6 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button6);                           //显示按钮

	button7 = gtk_button_new_with_label("X^3");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button7 , 1 , 2 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button7 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button7);                           //显示按钮

	button8 = gtk_button_new_with_label("X^2");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button8 , 1 , 2 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button8 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button8);                           //显示按钮
//-----------
	button9 = gtk_button_new_with_label("Ln");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button9 , 2 , 3 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button9 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button9);                           //显示按钮

	button10 = gtk_button_new_with_label("Log");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button10 , 2 , 3 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button10 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button10);                           //显示按钮

	button11 = gtk_button_new_with_label("N!");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button11 , 2 , 3 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button11 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button11);                           //显示按钮

	button12 = gtk_button_new_with_label("1/X");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button12 , 2 , 3 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button12 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button12);                           //显示按钮
//-----------
	button13 = gtk_button_new_with_label("7");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button13 , 3 , 4 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button13 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button13);                           //显示按钮

	button14 = gtk_button_new_with_label("4");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button14 , 3 , 4 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button14 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button14);                           //显示按钮
	
    button15 = gtk_button_new_with_label("1");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button15 , 3 , 4 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button15 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button15);                           //显示按钮
	
    button16 = gtk_button_new_with_label("0");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button16 , 3 , 4 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button16 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button16);                           //显示按钮
//-----------	
    button17 = gtk_button_new_with_label("8");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button17 , 4 , 5 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button17 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button17);                           //显示按钮
	
    button18 = gtk_button_new_with_label("5");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button18 , 4 , 5 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button18 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button18);                           //显示按钮
	
    button19 = gtk_button_new_with_label("2");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button19 , 4 , 5 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button19 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button19);                           //显示按钮
	
    button20 = gtk_button_new_with_label("+/-");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button20 , 4 , 5 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button20 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button20);                           //显示按钮
//-----------	
    button21 = gtk_button_new_with_label("9");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button21 , 5 , 6 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button21 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button21);                           //显示按钮
	
    button22 = gtk_button_new_with_label("6");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button22 , 5 , 6 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button22 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button22);                           //显示按钮
	
    button23 = gtk_button_new_with_label("3");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button23 , 5 , 6 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button23 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button23);                           //显示按钮
	
    button24 = gtk_button_new_with_label(".");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button24 , 5 , 6 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button24 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button24);                           //显示按钮
//-----------	
    button25 = gtk_button_new_with_label("/");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button25 , 6 , 7 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button25 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button25);                           //显示按钮
	
    button26 = gtk_button_new_with_label("*");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button26 , 6 , 7 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button26 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button26);                           //显示按钮
	
    button27 = gtk_button_new_with_label("-");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button27 , 6 , 7 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button27 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button27);                           //显示按钮
	
    button28 = gtk_button_new_with_label("+");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button28 , 6 , 7 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button28 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button28);                           //显示按钮
//-----------	
    button29 = gtk_button_new_with_label("=");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button29 , 7 , 8 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button29 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button29);                           //显示按钮
	
    button30 = gtk_button_new_with_label("And");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button30 , 7 , 8 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button30 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button30);                           //显示按钮
	
    button31 = gtk_button_new_with_label("Or");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button31 , 7 , 8 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button31 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button31);                           //显示按钮
	
    button32 = gtk_button_new_with_label("Mod");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button32 , 7 , 8 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button32 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button32);                           //显示按钮
//-----------	
    button33 = gtk_button_new_with_label("CR");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button33 , 8 , 9 , 0 , 1 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button33 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button33);                           //显示按钮
	
    button34 = gtk_button_new_with_label("Not");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button34 , 8 , 9 , 1 , 2 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button34 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button34);                           //显示按钮
	
    button35 = gtk_button_new_with_label("Xor");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button35 , 8 , 9 , 2 , 3 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button35 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button35);                           //显示按钮
	
    button36 = gtk_button_new_with_label("Int");          //创建按钮
	gtk_table_attach(GTK_TABLE(table1) , button36 , 8 , 9 , 3 , 4 , (GtkAttachOptions)(GTK_FILL) , (GtkAttachOptions)(0) , 0 , 0);
	gtk_widget_set_size_request(button36 , 70 , 35);     //设置按钮大小
	gtk_widget_show(button36);                           //显示按钮
}

// 添加事件函数
void addsignal(){
    /*下面的按钮实现数字的输入*/
    g_signal_connect(G_OBJECT(button1) , "clicked" , G_CALLBACK(input_pi) , NULL);
	g_signal_connect(G_OBJECT(button13) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button14) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button15) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button16) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button17) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button18) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button19) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button21) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button22) , "clicked" , G_CALLBACK(input) , NULL);
	g_signal_connect(G_OBJECT(button23) , "clicked" , G_CALLBACK(input) , NULL);
	
	/*实现小数点的输入*/
	g_signal_connect(G_OBJECT(button24) , "clicked" , G_CALLBACK(dot) , NULL);
	/*实现正负号的输入*/
	g_signal_connect(G_OBJECT(button20) , "clicked" , G_CALLBACK(Sign) , NULL);
	/*实现各种运算的输入*/
	g_signal_connect(G_OBJECT(button2) , "clicked" , G_CALLBACK(Sin), NULL);
	g_signal_connect(G_OBJECT(button3) , "clicked" , G_CALLBACK(Cos) , NULL);
	g_signal_connect(G_OBJECT(button4) , "clicked" , G_CALLBACK(Tan) , NULL);
	g_signal_connect(G_OBJECT(button5) , "clicked" , G_CALLBACK(Exp) , NULL);
	g_signal_connect(G_OBJECT(button6) , "clicked" , G_CALLBACK(Mathpowxy) , NULL);
	g_signal_connect(G_OBJECT(button7) , "clicked" , G_CALLBACK(Cube) , NULL);
	g_signal_connect(G_OBJECT(button8) , "clicked" , G_CALLBACK(Square) , NULL);
	g_signal_connect(G_OBJECT(button9) , "clicked" , G_CALLBACK(Log_e) , NULL);
	g_signal_connect(G_OBJECT(button10) , "clicked" , G_CALLBACK(Log_10) , NULL);
	g_signal_connect(G_OBJECT(button11) , "clicked" , G_CALLBACK(Factorial) , NULL);
	g_signal_connect(G_OBJECT(button12) , "clicked" , G_CALLBACK(Inverse) , NULL);
	g_signal_connect(G_OBJECT(button25) , "clicked" , G_CALLBACK(Division) , NULL);
	g_signal_connect(G_OBJECT(button26) , "clicked" , G_CALLBACK(Mul) , NULL);
	g_signal_connect(G_OBJECT(button27) , "clicked" , G_CALLBACK(Sub) , NULL);
	g_signal_connect(G_OBJECT(button28) , "clicked" , G_CALLBACK(Add) , NULL);
	g_signal_connect(G_OBJECT(button30) , "clicked" , G_CALLBACK(And) , NULL);
	g_signal_connect(G_OBJECT(button31) , "clicked" , G_CALLBACK(Or) , NULL);
	g_signal_connect(G_OBJECT(button32) , "clicked" , G_CALLBACK(Mod) , NULL);
	g_signal_connect(G_OBJECT(button34) , "clicked" , G_CALLBACK(Not) , NULL);
	g_signal_connect(G_OBJECT(button35) , "clicked" , G_CALLBACK(Xor) , NULL);
	g_signal_connect(G_OBJECT(button36) , "clicked" , G_CALLBACK(Floor) , NULL);
	/*实现复位功能*/
	g_signal_connect(G_OBJECT(button33) , "clicked" , G_CALLBACK(clear) , NULL);
	/*实现结果输出*/
	g_signal_connect(G_OBJECT(button29) , "clicked" , G_CALLBACK(output) , NULL);
	g_signal_connect(G_OBJECT(window) , "delete_envent" , gtk_main_quit , NULL);
}
