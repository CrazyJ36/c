#include <gtk/gtk.h>
#include <glib-2.0/glibconfig.h>

void btn1_function(GtkWidget *btnWidget1, gpointer ptr1) {
  printf("Button 1 Clicked.\n");
}

void btn2_function(GtkWidget *btnWidget2) {
  printf("Button 2 Clicked\n");
}

void end_program(GtkWidget *widget1, gpointer ptr2) {
  gtk_main_quit();
}

int main(int argc, char *argv[]){
  gtk_init(&argc, &argv);
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win), 500, 300);
  gtk_window_set_title(GTK_WINDOW(win), "GTK App");

  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(win), box);

  GtkWidget *textView = gtk_text_view_new();
  GtkTextBuffer *textViewBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
  gtk_text_buffer_set_text(textViewBuffer, "editable text view", 18);
  gtk_container_add(GTK_CONTAINER(box), textView);

  GtkWidget *btn1 = gtk_button_new_with_label("btn1");
  GtkWidget *btn2 = gtk_button_new_with_label("btn2");
  g_signal_connect(btn1, "clicked", G_CALLBACK(btn1_function), NULL);
  g_signal_connect(btn2, "clicked", G_CALLBACK(btn2_function), NULL);
  gtk_container_add(GTK_CONTAINER(box), btn1);
  gtk_container_add(GTK_CONTAINER(box), btn2);

  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

  gtk_widget_show_all(win);
  gtk_main();
  printf("Done.\n");
  return 0;
}

