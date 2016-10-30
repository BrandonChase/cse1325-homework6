// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "test.h"

Fl_Menu_Item menu_[] = {
 {"File", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"New", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {"Edit", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Double_Window* make_window() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(640, 480, "Robbie Robot Shop v0.15");
    w = o;
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 640, 25);
      o->menu(menu_);
    } // Fl_Menu_Bar* o
    o->size_range(640, 480, 640, 480);
    o->end();
  } // Fl_Double_Window* o
  return w;
}
