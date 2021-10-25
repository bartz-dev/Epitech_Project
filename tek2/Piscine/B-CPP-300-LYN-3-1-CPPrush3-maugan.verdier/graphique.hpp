/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** graphique.hpp
*/


#ifndef _GRAPHIQUE_HPP_
#define _GRAPHIQUE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

template<typename T>
std::string toString(const T &t) {
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template<typename T>
T fromString( const std::string& s ) {
    std::istringstream stream( s );
    T t;
    stream >> t;
    return t;
}

struct global
{
    sf::Texture BG_t;
    sf::Sprite BG_s;
    sf::Text date_time;
    sf::Text creator;
    sf::Font font;
    sf::Clock clock;
    sf::Time time;
    sf::RectangleShape rectangleNet;
    sf::Text TNet;
    sf::Text INet;
    sf::RectangleShape rectangleCPU;
    sf::Text TCPU;
    sf::Text ICPU;
    sf::RectangleShape rectangleRAM;
    sf::Text TRAM;
    sf::Text IRAM;
    sf::RectangleShape rectangleSys;
    sf::Text TSys;
    sf::Text ISys;
};

void setCreator(global *global);
void setDateTime(global *global);
void setFont(global *global);
void setBG(global *global);
void setRectangle(global *global);
void setText(global *global);
void settall(global *global);
void setString(global *global);

#endif