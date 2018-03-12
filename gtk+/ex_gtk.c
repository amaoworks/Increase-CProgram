#include <gtk/gtk.h>

static void hello(GtkWidget *widget, gpointer data){
	g_printf("Hello World\n");     // 输出信息
}

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
	g_printf("delete event occurred\n");
	// 如果返回 FALSE， GTK+ 会发出一个“ destroy ”信号
	return TRUE;
}

static void destroy(GtkWidget *widget, gpointer data){
	// 输出构件名称
	g_printf("%s : exit!\n", gtk_widget_get_name(widget));
	// 退出主循环
	gtk_main_quit();
}

int main(int argc, char **argv){
	GtkWidget *window;
	GtkWidget *button;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// 注册回调函数
	g_signal_connect(window, "delete-event",G_CALLBACK(delete_event), NULL);
	g_signal_connect(window, "destroy",G_CALLBACK(destory), NULL);

	// 设置窗口边距
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	// 设置构件名称
	gtk_widget_set_name(GTK_WIDGET(windows), "main_window");
	// 创建一个按钮
	button = gtk_button_new_with_label("Hello world");

	// 注册单击按钮
}
