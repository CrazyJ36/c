#include <gtk/gtk.h>

void my_function(GtkWidget *widget1, gpointer ptr1) {
  printf("This text would have shown after button click, calling my function...\n");
}

void end_program(GtkWidget *widget2, gpointer ptr2) {
  gtk_main_quit(); // Gtk function that ends gtk_main() loop.
  printf("Program, GTK Ended...\n");
}

int main(int argc, char *argv[]){
  gtk_init(&argc, &argv);
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Print to Shell");
  gtk_container_add(GTK_CONTAINER(win), btn);
  g_signal_connect(win, "delete_event", G_CALLBACK(gtk_main_quit()), NULL);
  g_signal_connect(btn, "clicked", G_CALLBACK(my_function), NULL);
  gtk_widget_show_all(win);
  gtk_main();
  printf("Done.\n");
  return 0;
}

