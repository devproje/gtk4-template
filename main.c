#include <gtk/gtk.h>

static void on_activate(GtkApplication *app)
{
	GtkWidget *view = gtk_application_window_new(app);
	GtkWidget *btn = gtk_button_new_with_label("Hello, World!");
	g_signal_connect_swapped(btn, "clicked", G_CALLBACK(gtk_window_close), view);
	gtk_window_set_child(GTK_WINDOW(view), btn);
	gtk_window_present(GTK_WINDOW(view));

	gtk_window_set_default_size(GTK_WINDOW(view), 600, 400);
}

int main(int argc, char **argv)
{
	GtkApplication *app = gtk_application_new("net.wh64.template.TemplateApp",
						  G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

	return g_application_run(G_APPLICATION(app), argc, argv);
}

