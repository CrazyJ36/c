#include <gtk/gtk.h>
#include <stdlib.h>

static void btn1_func(GtkWidget *widget, gpointer data) {
  g_print("Starting XClock");
  system("xclock");
}

static void activate(GtkApplication* app, gpointer user_data) {
  // item variables
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  // the window
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "XClock: from gtk-xclock-launcher");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

  // button container
  button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add(GTK_CONTAINER(window), button_box);

  // button
  button = gtk_button_new_with_label("XClock");
  g_signal_connect(button, "clicked", G_CALLBACK(btn1_func), NULL);
  // optionally destry the window after click
  //g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
  gtk_container_add(GTK_CONTAINER(button_box), button);

  // show the above items
  gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;
  app = gtk_application_new("com.crazyj36.xclocklauncher", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  return status;
}
