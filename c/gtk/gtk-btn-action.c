/* ------gtk-btn-action.c-----
   Some observations:
   Something like 'GtkWidget()' (the capitals) seems like A whole class similar to java.
   gtk_init() and gtk_container_add() are like functions of A class.
   GtkWidget is usable as parent(before, inherits properties) of GTK_CONTAINER in the API heirarchy.
*/
#include <gtk/gtk.h>
// parameters for this function could be (GtkWidget *widget, gpointer ptr)
void my_function(GtkWidget *widget1, gpointer ptr1) {
  printf("This text would have shown after button click, calling my function...\n"); // c standard functions (at stdout) still usable even under GTK loop
                                                                                     // probably can not print from widgets. Test.
}
void end_program(GtkWidget *widget2, gpointer ptr2) {
  gtk_main_quit(); // Gtk function that ends gtk_main() loop.
  printf("Program, GTK Ended...\n");
}
int main(int argc, char *argv[]){
  printf("Initializing gtk...\n");
  gtk_init(&argc, &argv);
  printf("Instantiating new top level gtk window...\n");
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  printf("Instantiating new button...\n");
  GtkWidget *btn = gtk_button_new_with_label("Print to Shell");
  printf("Adding button to top level window...\n");
  gtk_container_add(GTK_CONTAINER(win), btn); // add-to win, referencing win as container, with btn variable.
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL); // delete_event is from window 'x'(close) click. This is connected to 'win' Whole window widget, not btn.
  printf("Connecting button 'clicked' event to my function...\n");
  g_signal_connect(btn, "clicked", G_CALLBACK(my_function), NULL);
  printf("Showing all previously defined containers and widgets...\n");
  gtk_widget_show_all(win);
  printf("Preparing to start GTK main functions loop..,\n");
  printf("Test printf() after showing GTK widgets. gtk_main() not run yet...\n");
  gtk_main();
  printf("This text must wait for gtk_main loop to finish(located right below in code)...\n");
  return 0;
}

