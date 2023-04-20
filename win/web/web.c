#include "hack.h"
// TODO graves: Find out how to properly include
// #include "emscripten.h"

// Interface Specification, see window.doc

// A.  Low-level routines:

void web_raw_print(const char *str){}

void web_raw_print_bold(const char *str){}

void web_curs(winid window, int x, int y){}

void web_putstr(winid window, int attr, const char *text){}

void web_putmixed(winid window, int attr, const char *text){}

void web_get_nh_event(){}

int web_nhgetch(){}

int web_nh_poskey(int *x, int *y, int *mod){}

// B.  High-level routines:

void web_print_glyph(winid window, XCHAR_P x, XCHAR_P y, int glyph, int bkglyph){}

char web_yn_function(const char *question, const char *choices, CHAR_P def){}

void web_getlin(const char *question, char *input){}

int web_get_ext_cmd(){}

void web_player_selection(){}

void web_display_file(const char *filename, BOOLEAN_P must_exist){}

void web_update_inventory(){}

int web_doprev_message(){}

// TODO check if necessary
// Optional, POSITIONBAR must be defined.
#ifdef POSITIONBAR
void web_update_positionbar(char *features){}
#endif

// C.  Window Utility Routines

void web_init_nhwindows(int *argcp, char **argv){}

void web_exit_nhwindows(const char *str){}

winid web_create_nhwindow(int type){}

void web_clear_nhwindow(winid window){}

void web_display_nhwindow(winid window, BOOLEAN_P blocking){}

void web_destroy_nhwindow(winid window){}

void web_start_menu(winid window){}

void web_add_menu(winid window,
                  int glyph,
                  const ANY_P * identifier,
                  CHAR_P accelerator,
                  CHAR_P groupaccelerator,
                  int attr,
                  const char *str,
                  BOOLEAN_P preselected){}

void web_end_menu(winid window, const char *prompt){}

int web_select_menu(winid window, int how, MENU_ITEM_P **selected){}

char web_message_menu(CHAR_P let, int how, const char *message){}

void web_status_init(){}

// TODO check if this method is needed
//void web_status_enablefield(int fieldindex, CHAR_P fieldname, CHAR_P fieldformat, BOOLEAN_P enable){
//TODO find out how to convert CHAR_P properly
//    genl_status_enablefield(fieldindex, fieldname, fieldformat, enable);
//}

// TODO find out what chg stands for
void web_status_update(int idx, genericptr_t ptr, int chg, int percent, int color, unsigned long *colormasks){}

void web_status_finish(){}

// E.  Misc. Routines

void web_nhbell(){}

void web_mark_synch(){}

void web_wait_synch(){}

void web_delay_output(){}

void web_askname(){}

void web_cliparound(int x, int y){}

void web_number_pad(int state){}

void web_suspend_nhwindows(const char *str){}

void web_resume_nhwindows(){}

// TODO check if this method is needed
void web_can_suspend(){
  genl_can_suspend_no();
}

void web_start_screen(){}

void web_end_screen(){}

void web_outrip(winid window, int how, time_t when) {
  genl_outrip(window, how, when);
}

void web_preference_update(const char *preference){}

char *web_getmsghistory(BOOLEAN_P init){}

void web_putmsghistory(const char *message, BOOLEAN_P restoring){}

// See winprocs.h and windows.c
struct window_procs web_procs = {
    "web",
    0L, /* window port capability options supported */
    0L, /* additional window port capability options */
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   /* color availability */
    web_init_nhwindows,
    web_player_selection,
    web_askname,
    web_get_nh_event,
    web_exit_nhwindows,
    web_suspend_nhwindows,
    web_resume_nhwindows,
    web_create_nhwindow,
    web_clear_nhwindow,
    web_display_nhwindow,
    web_destroy_nhwindow,
    web_curs,
    web_putstr,
    web_putmixed,
    web_display_file,
    web_start_menu,
    web_add_menu,
    web_end_menu,
    web_select_menu,
    web_message_menu,
    web_update_inventory,
    web_mark_synch,
    web_wait_synch,
#ifdef CLIPPING
    web_cliparound,
#endif
#ifdef POSITIONBAR
    web_update_positionbar,
#endif
    web_print_glyph,
    web_raw_print,
    web_raw_print_bold,
    web_nhgetch,
    web_nh_poskey,
    web_nhbell,
    web_doprev_message,
    web_yn_function,
    web_getlin,
    web_get_ext_cmd,
    web_number_pad,
    web_delay_output,
#ifdef CHANGE_COLOR
    web_change_color,
#ifdef MAC
    web_change_background,
    web_set_font_name,
#endif
    web_get_color_string,
#endif
    web_start_screen,
    web_end_screen,
    web_outrip,
    web_preference_update,
    web_getmsghistory,
    web_putmsghistory,
    web_status_init,
    web_status_finish,
    genl_status_enablefield, //TODO graves replace with web
    web_status_update,
    genl_can_suspend_no, //TODO graves replace with web
};