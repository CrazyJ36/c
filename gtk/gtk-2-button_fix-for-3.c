#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv); // init gtk libs with usabl arguments
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL); // instantiate a window
  GtkWidget *btn = gtk_button_new_with_label("Button"); // instantiate a button
  gtk_container_add(GTK_CONTAINER(win), btn); // add button to window
  gtk_widget_show_all(win); // show main window and button within
  gtk_main(); // start gtk main loop after initializing widgets and containers above
  return 0;
}
