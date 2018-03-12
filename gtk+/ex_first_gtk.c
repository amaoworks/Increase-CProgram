#include <gtk/gtk.h>

int main(int argc, char *argv[]){
	// 声明一个窗口构件
	GtkWidget *window;
	// 初始化 Gtk+
	gtk_init(&argc, &argv);
	// 创建主窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// 显示主窗口
	gtk_widget_show(window);
	// 进入 GTK+ 循环
	gtk_main();

	return 0;
}
// 运行结果是一个空白窗口
// 单击窗口关闭按钮将关闭窗口
// 但应用程序并未停止，原因是尚未处理 Gtk 的事件
