/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** ncurses.cpp
*/

#include "MyGKrellM.hpp"
#include "ncurses.hpp"
#include <ncurses.h>

display_ncurses::display_ncurses(const GKrellm &infos)
{
    this->_infos = infos;
    initscr();
    cbreak();
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    keypad(stdscr, TRUE);
    wbkgd(stdscr, COLOR_PAIR(1));
    this->_term_y = 0;
    this->_term_x = 0;
    this->_infos.update_info();
    this->loop();
}

static void remove(module_ncurses &m)
{
    wborder(m._win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(m._win);
	delwin(m._win);
}

void display_ncurses::update_modules(module_ncurses &m, const char type)
{
    wclear(m._win);
    wborder(m._win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

    switch (type) {
        case 'c':
            wbkgd(m._win, COLOR_PAIR(2));
            wprintw(m._win, "Cpu Usage");
            this->display_cpuinfo(m);
            break;
        case 'm':
            wbkgd(m._win, COLOR_PAIR(3));
            wprintw(m._win, "Memory Usage");
            this->display_meminfo(m);
            break;
        case 'o':
            wbkgd(m._win, COLOR_PAIR(4));
            wprintw(m._win, "Network Bandwidth");
            this->display_network(m);
            break;
        default:
            wbkgd(m._win, COLOR_PAIR(1));
            wprintw(m._win, "Other System Info");
            this->display_other(m);
    }
    wrefresh(m._win);
}


static void recreate(module_ncurses &m, const char type)
{
    m._win = newwin(m._y, m._x, m._offset_y, m._offset_x);
    wborder(m._win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

    switch (type) {
        case 'c':
            wbkgd(m._win, COLOR_PAIR(2));
            wprintw(m._win, "Cpu Usage");
            break;
        case 'm':
            wbkgd(m._win, COLOR_PAIR(3));
            wprintw(m._win, "Memory Usage");
            break;
        case 'o':
            wbkgd(m._win, COLOR_PAIR(4));
            wprintw(m._win, "Network Bandwidth");
            break;
        default:
            wbkgd(m._win, COLOR_PAIR(1));
            wprintw(m._win, "Other System Info");
    }
    wrefresh(m._win);
}

void display_ncurses::update_windows()
{
    remove(this->_cpu);
    remove(this->_mem);
    remove(this->_net);
    remove(this->_oth);
    this->_cpu._y = this->_term_y / 2 - 2;
    this->_cpu._x = this->_term_x / 2 - 2;
    this->_cpu._offset_y = 1;
    this->_cpu._offset_x = 1;
    this->_mem._y = this->_term_y / 2 - 2;
    this->_mem._x = this->_term_x / 2 - 2;
    this->_mem._offset_y = 1;
    this->_mem._offset_x = this->_term_x / 2 + 1;
    this->_net._y = this->_term_y / 2 - 2;
    this->_net._x = this->_term_x / 2 - 2;
    this->_net._offset_y = this->_term_y / 2 + 1;
    this->_net._offset_x = 1;
    this->_oth._y = this->_term_y / 2 - 2;
    this->_oth._x = this->_term_x / 2 - 2;
    this->_oth._offset_y = this->_term_y / 2 + 1;
    this->_oth._offset_x = this->_term_x / 2 + 1;
    recreate(this->_cpu, 'c');
    recreate(this->_mem, 'm');
    recreate(this->_net, 'n');
    recreate(this->_oth, 'o');
    keypad(stdscr, TRUE);
}

void display_ncurses::loop()
{
    int y;
    int x;

    refresh();
    getmaxyx(stdscr, this->_term_y, this->_term_x);
    this->update_windows();
    while (1) {
        this->_infos.update_info();
        this->update_modules(this->_cpu, 'c');
        this->update_modules(this->_mem, 'm');
        this->update_modules(this->_net, 'n');
        this->update_modules(this->_oth, 'o');
        x = this->_term_x;
        y = this->_term_y;
        getmaxyx(stdscr, this->_term_y, this->_term_x);
        if (x != this->_term_x || y != this->_term_y)
            this->update_windows();
        timeout(800);
        if (getch() == 4) 
            break;
        refresh();
    }
}

display_ncurses::~display_ncurses()
{
    remove(this->_cpu);
    remove(this->_mem);
    remove(this->_net);
    remove(this->_oth);
    endwin();
}

module_ncurses::module_ncurses()
{
    this->_y = 0;
    this->_x = 0;
    this->_offset_y = 0;
    this->_offset_x = 0;
    this->_win = newwin(this->_y, this->_x, this->_offset_y, this->_offset_x);
    box(this->_win, 0 , 0);
    wborder(this->_win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    wrefresh(this->_win);
}

module_ncurses::~module_ncurses()
{
}
