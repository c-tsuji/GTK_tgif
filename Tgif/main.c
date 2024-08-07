#include <gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *label;  // Label widget
    GtkWidget *image;  // Image widget for the icon
    GtkWidget *vbox;   // A vertical box to stack the label and the image

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Create a vertical box to stack widgets
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Create a new label with the text "Hello woul"
    label = gtk_label_new("Hello world");

    // Create an image widget using the XBM file
    image = gtk_image_new_from_file("./xbm/a1.xbm");

    // Add the image and label to the vertical box
    gtk_box_pack_start(GTK_BOX(vbox), image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    // Add the vertical box to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Make all widgets visible
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // Create a new GTK application
    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}