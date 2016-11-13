#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

#include <cstdlib>
#include <iostream>


#define HEIGHT 480
#define WIDTH 640

void Quit_CB(Fl_Widget *, void *) {
    exit(0);
}


void Change_CB(Fl_Widget *w, void *) {
    Fl_Window *window = (Fl_Window*)w;
    Fl_Group *bbb = (Fl_Group*)w;
    std::cout<<"hi";
    bbb->show();
    window->redraw();
    Fl_Menu_Bar *menu = (Fl_Menu_Bar*)w;
    Fl_Menu_Item *p;
    // Change submenu name
    p = (Fl_Menu_Item*)menu->find_item("Edit/Submenu");
    if ( p ) p->label("New Submenu Name");
    // Change item name
    p = (Fl_Menu_Item*)menu->find_item("Edit/New Submenu Name/Aaa");
    if ( p ) p->label("New Aaa Name");
}

int main(int argc, char *argv[]) {
    Fl_Window *win = new Fl_Window(WIDTH,HEIGHT,"Joe's fltk program");
    {
        Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,WIDTH,25);
        menu->add("File/Quit",   FL_CTRL+'q', Quit_CB);
        menu->add("Edit/Change", FL_CTRL+'c', Change_CB);
        menu->add("Edit/Submenu/Aaa");
        menu->add("Edit/Submenu/Bbb");

        Fl_Tabs *tabs = new Fl_Tabs(0,25,WIDTH,HEIGHT);
        {
            // Aaa tab
            Fl_Group *aaa = new Fl_Group(0,0,WIDTH,HEIGHT);
            {
                Fl_Button *b1 = new Fl_Button(50, 60,90,25,"Button A1"); b1->color(88+1);
                Fl_Button *b2 = new Fl_Button(50, 90,90,25,"Button A2"); b2->color(88+2);
                Fl_Button *b3 = new Fl_Button(50,120,90,25,"Button A3"); b3->color(88+3);
            }
            aaa->end();

            // Bbb tab
            Fl_Group *bbb = new Fl_Group(0,0,WIDTH,HEIGHT);
            {
                Fl_Button *b1 = new Fl_Button( 50,60,90,25,"Button B1"); b1->color(88+1);
                Fl_Button *b2 = new Fl_Button(150,60,90,25,"Button B2"); b2->color(88+3);
                Fl_Button *b3 = new Fl_Button(250,60,90,25,"Button B3"); b3->color(88+5);
                Fl_Button *b4 = new Fl_Button( 50,90,90,25,"Button B4"); b4->color(88+2);
                Fl_Button *b5 = new Fl_Button(150,90,90,25,"Button B5"); b5->color(88+4);
                Fl_Button *b6 = new Fl_Button(250,90,90,25,"Button B6"); b6->color(88+6);
            }
            bbb->end();
        }
        tabs->end();
    }
    win->end();
    win->show();
    return(Fl::run());
}