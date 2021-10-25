/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** test.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphique.hpp"
#include "MyGKrellM.hpp"

int graphique()
{
    sf::RenderWindow window(sf::VideoMode(1200, 675), "Rush3: MyGKrellm");
    window.setFramerateLimit(1);
    global global;
    GKrellm info1;
    
    
    settall(&global);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        global.time = global.clock.getElapsedTime();
        if (global.time >= sf::seconds(2)) { 
            if ("Made by:\nCharles Gosseine" == global.creator.getString()) {
                global.creator.setString("Made by:\nClement Fleur");
            } else if ("Made by:\nClement Fleur" == global.creator.getString()) {
                global.creator.setString("Made by:\nMaugan Verdier");
            } else if ("Made by:\nMaugan Verdier" == global.creator.getString()) {
                global.creator.setString("Made by:\nBastien Ollivier");
            } else {
                global.creator.setString("Made by:\nCharles Gosseine");
            }
            global.clock.restart();
        }
        setString(&global);
        window.clear();
        window.draw(global.BG_s);
        window.draw(global.date_time);
        window.draw(global.creator);
        window.draw(global.rectangleNet);
        window.draw(global.rectangleCPU);
        window.draw(global.rectangleRAM);
        window.draw(global.rectangleSys);
        window.draw(global.TCPU);
        window.draw(global.ICPU);
        window.draw(global.TNet);
        window.draw(global.INet);
        window.draw(global.TRAM);
        window.draw(global.IRAM);
        window.draw(global.TSys);
        window.draw(global.ISys);
        window.display();
    }
    return 0;
}