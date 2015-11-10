#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>

static int _XlibErrorHandler(Display *display, XErrorEvent *event) {
  printf("Something bad happened.", stderr);
  return True;
}

int main(int argc, char const *argv[]) {
  int i, mo_x, mo_y, num_scrn, r, w_x, w_y;
  unsigned int mr;
  Display *display;
  Window window, wr;

  display = XOpenDisplay(0);
  XSetErrorHandler(_XlibErrorHandler);
  num_scrn = XScreenCount(display);

  for (i = 0; i < num_scrn; i++) {
    window = XRootWindow(display, i);
    if ((r = XQueryPointer(display, window, &wr, &wr, &mo_x, &mo_y, &w_x, &w_y, &mr)) > 0) {
      break;
    }
  }

  if (r) {
    printf("MoPos:(%d,%d)\n",mo_x,mo_y);
  }
  else {
    fputs("ERROR\n",stdout);
  }

  return 0;
}
