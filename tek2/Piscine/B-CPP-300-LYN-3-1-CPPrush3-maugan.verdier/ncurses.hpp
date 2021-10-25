/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-maugan.verdier
** File description:
** ncurses.hpp
*/

#ifndef _NCURSES_GKRELLM_H_
#define _NCURSES_GKRELLM_H_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "MyGKrellM.hpp"
#include <ncurses.h>
#include <string>

class module_ncurses : public IMonitorModule {
    public:
        module_ncurses();
        virtual ~module_ncurses();
        WINDOW *_win;
        int _y;
        int _x;
        int _offset_y;
        int _offset_x;
};

class display_ncurses : public IMonitorDisplay {
    public:
        display_ncurses(const GKrellm &infos);
        virtual ~display_ncurses();
        void loop();
        void update_modules(module_ncurses &m, const char type);
        void update_windows();
        void display_cpuinfo(module_ncurses &m) const;
        void display_meminfo(module_ncurses &m) const;
        void display_network(module_ncurses &m) const;
        void display_other(module_ncurses &m) const;

    private:
        GKrellm _infos;
        int _term_y;
        int _term_x;
        module_ncurses _cpu;
        module_ncurses _mem;
        module_ncurses _net;
        module_ncurses _oth;
};

#endif
