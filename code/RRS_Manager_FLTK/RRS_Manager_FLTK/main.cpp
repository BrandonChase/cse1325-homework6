#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

int main()
{
	Fl_Window window(200, 200, "My window title");
	Fl_Box box(0, 50, 200, 20, "Hello");
	window.show();
	return Fl::run();
}