/*
compile:
gcc `pkg-config --cflags gtk+-3.0` -o gtk-example gtk-example.c `pkg-config --libs gtk+-3.0`
*/

#include <gtk-3.0/gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data) {
  GtkWidget *window;
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Window");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
  gtk_widget_show_all(window);
}
int main(int argc, char **argv) {
  GtkApplication *app;
  int status;
  app = gtk_application_new("com.crazyj36.gtkexample", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  return status;
}
