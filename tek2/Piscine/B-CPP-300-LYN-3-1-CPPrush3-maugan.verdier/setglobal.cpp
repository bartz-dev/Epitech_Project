/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** setglobal.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphique.hpp"
#include "MyGKrellM.hpp"

void setText(global *global)
{
    std::string string_N;
    std::string string_C;
    std::string string_R;
    std::string string_S;
    GKrellm info;
    info.update_info();
    struct sysinfo infoS = info.getMem();
    struct utsname osinfo = info.getOsInfo();

    global->TNet.setFont(global->font);
    global->TNet.setString("Network");
    global->TNet.setCharacterSize(30);
    global->TNet.setFillColor(sf::Color::Blue);
    global->TNet.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    global->TNet.setOutlineColor(sf::Color::Cyan);
    global->TNet.setOutlineThickness(2);
    global->TNet.setPosition(70, 33);

    info.getNetwork();
    string_N = "\t|Receive\t\t|Transmit\n";
    string_N = "\t|Bytes\tPackets\t|Bytes\tPackets\n";
    string_N += info.nameI[0];
    string_N += "\t|";
    string_N += info.bytes_R[0];
    string_N += "\t";
    string_N += info.packets_R[0];
    string_N += "\t";
    string_N += info.bytes_T[0];
    string_N += "\t|";
    string_N += info.packets_T[0];
    string_N += "\n";
    string_N += info.nameI[1];
    string_N += "\t|";
    string_N += info.bytes_R[1];
    string_N += "\t";
    string_N += info.packets_R[1];
    string_N += "\t";
    string_N += info.bytes_T[1];
    string_N += "\t|";
    string_N += info.packets_T[1];
    string_N += "\n";
    string_N += info.nameI[2];
    string_N += "\t|";
    string_N += info.bytes_R[2];
    string_N += "\t";
    string_N += info.packets_R[2];
    string_N += "\t";
    string_N += info.bytes_T[2];
    string_N += "\t|";
    string_N += info.packets_T[2];
    string_N += "\n";
    string_N += info.nameI[3];
    string_N += "\t|";
    string_N += info.bytes_R[3];
    string_N += "\t";
    string_N += info.packets_R[3];
    string_N += "\t";
    string_N += info.bytes_T[3];
    string_N += "\t|";
    string_N += info.packets_T[3];
    string_N += "\n";
    global->INet.setFont(global->font);
    global->INet.setString(string_N);
    global->INet.setCharacterSize(20);
    global->INet.setFillColor(sf::Color::Blue);
    global->INet.setStyle(sf::Text::Style::Bold);
    global->INet.setOutlineColor(sf::Color::Magenta);
    global->INet.setOutlineThickness(2);
    global->INet.setPosition(70, 73);

    global->TCPU.setFont(global->font);
    global->TCPU.setString("CPU");
    global->TCPU.setCharacterSize(30);
    global->TCPU.setFillColor(sf::Color::Blue);
    global->TCPU.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    global->TCPU.setOutlineColor(sf::Color::Cyan);
    global->TCPU.setOutlineThickness(2);
    global->TCPU.setPosition(630, 33);

    string_C = "Model name:\n";
    string_C += info.getNameCPU();
    string_C += "\nInformation:\n";
    string_C += info.getCPUinfo();
    string_C += "\nNomber of core:\n";
    string_C += info.getCPUcore();
    string_C += "\nThread:\n";
    string_C += toString(info.getCPUthread());
    string_C += "\nUsage:\n";
    string_C += toString(info.getAccurateCPU());
    string_C += "%";
    global->ICPU.setFont(global->font);
    global->ICPU.setString(string_C);
    global->ICPU.setCharacterSize(15);
    global->ICPU.setFillColor(sf::Color::Blue);
    global->ICPU.setStyle(sf::Text::Style::Bold);
    global->ICPU.setOutlineColor(sf::Color::Magenta);
    global->ICPU.setOutlineThickness(2);
    global->ICPU.setPosition(630, 73);

    global->TRAM.setFont(global->font);
    global->TRAM.setString("RAM");
    global->TRAM.setCharacterSize(30);
    global->TRAM.setFillColor(sf::Color::Blue);
    global->TRAM.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    global->TRAM.setOutlineColor(sf::Color::Cyan);
    global->TRAM.setOutlineThickness(2);
    global->TRAM.setPosition(70, 363);

    double divide = 1000000.0;
    double totalram = (double)infoS.totalram / divide;
    double usedram = (double)(infoS.totalram - infoS.freeram) / divide;
    double freeram = (double)infoS.freeram / divide;
    double swapram = (double)(infoS.totalswap - infoS.freeswap) / divide;
    string_R = "Total RAM:\n";
    string_R += toString(totalram);
    string_R += "MB\nUsed RAM:\n";
    string_R += toString(usedram);
    string_R += "MB\nFree RAM:\n";
    string_R += toString(freeram);
    string_R += "MB\nSwap RAM:\n";
    string_R += toString(swapram);
    global->IRAM.setFont(global->font);
    global->IRAM.setString(string_R);
    global->IRAM.setCharacterSize(20);
    global->IRAM.setFillColor(sf::Color::Blue);
    global->IRAM.setStyle(sf::Text::Style::Bold);
    global->IRAM.setOutlineColor(sf::Color::Magenta);
    global->IRAM.setOutlineThickness(2);
    global->IRAM.setPosition(70, 403);

    global->TSys.setFont(global->font);
    global->TSys.setString("System");
    global->TSys.setCharacterSize(33);
    global->TSys.setFillColor(sf::Color::Blue);
    global->TSys.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    global->TSys.setOutlineColor(sf::Color::Cyan);
    global->TSys.setOutlineThickness(2);
    global->TSys.setPosition(780, 363);

    string_S = "Host name:\n";
    string_S += info.getHostname();
    string_S += "\nUser name:\n";
    string_S += info.getUsername();
    string_S += "\nKernel:\n";
    string_S += osinfo.sysname;
    string_S += "\nRelease:\n";
    string_S += osinfo.release;
    string_S += "\nVersion:\n";
    string_S += osinfo.version;
    string_S += "\nMachine:\n";
    string_S += osinfo.machine;
    global->ISys.setFont(global->font);
    global->ISys.setString(string_S);
    global->ISys.setCharacterSize(15);
    global->ISys.setFillColor(sf::Color::Blue);
    global->ISys.setStyle(sf::Text::Style::Bold);
    global->ISys.setOutlineColor(sf::Color::Magenta);
    global->ISys.setOutlineThickness(2);
    global->ISys.setPosition(780, 403);
}

void setRectangle(global *global)
{
    global->rectangleNet.setSize(sf::Vector2f(530, 300));
    global->rectangleNet.setFillColor(sf::Color(255,255,255,128));
    global->rectangleNet.setPosition(60, 35);

    global->rectangleCPU.setSize(sf::Vector2f(530, 300));
    global->rectangleCPU.setFillColor(sf::Color(255,255,255,128));
    global->rectangleCPU.setPosition(620, 35);

    global->rectangleRAM.setSize(sf::Vector2f(260, 300));
    global->rectangleRAM.setFillColor(sf::Color(255,255,255,128));
    global->rectangleRAM.setPosition(60, 360);

    global->rectangleSys.setSize(sf::Vector2f(380, 300));
    global->rectangleSys.setFillColor(sf::Color(255,255,255,128));
    global->rectangleSys.setPosition(770, 360);
}

void setCreator(global *global)
{
    global->creator.setFont(global->font);
    global->creator.setString("Made by:\nCharles Gosseine");
    global->creator.setCharacterSize(30);
    global->creator.setFillColor(sf::Color::Blue);
    global->creator.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    global->creator.setOutlineColor(sf::Color::Cyan);
    global->creator.setOutlineThickness(3);
    global->creator.setPosition(430, 450);
}

void setDateTime(global *global)
{
    GKrellm info;

    info.update_datetime();
    global->date_time.setFont(global->font);
    global->date_time.setString(info.getTime());
    global->date_time.setCharacterSize(30);
    global->date_time.setFillColor(sf::Color::Blue);
    global->date_time.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    global->date_time.setOutlineColor(sf::Color::Cyan);
    global->date_time.setOutlineThickness(3);
    global->date_time.setPosition(365, 600);
}

void setFont(global *global)
{
    if (!global->font.loadFromFile("./PlayfairDisplay-Bold.ttf"))
    {
        std::cout << "Error loading file" << std::endl;
        
        system("pause");
    }
}

void setBG(global *global)
{
    if (!global->BG_t.loadFromFile("./bg1.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    global->BG_s.setTexture(global->BG_t);
    global->BG_s.setTextureRect(sf::IntRect(0, 0, 1200, 675));
}

void settall(global *global)
{
    setBG(global);
    setFont(global);
    setDateTime(global);
    setCreator(global);
    setRectangle(global);
    setText(global);
}

void setString(global *global)
{
    std::string string_N;
    std::string string_C;
    std::string string_R;
    std::string string_S;
    GKrellm info;
    struct sysinfo infoS;

    info.update_info();
    infoS = info.getMem();

    global->date_time.setString(info.getTime());

    info.getNetwork();
    string_N = "\t|Receive\t\t|Transmit\n";
    string_N = "\t|Bytes\tPackets\t|Bytes\tPackets\n";
    string_N += info.nameI[0];
    string_N += "\t|";
    string_N += info.bytes_R[0];
    string_N += "\t";
    string_N += info.packets_R[0];
    string_N += "\t|";
    string_N += info.bytes_T[0];
    string_N += "\t";
    string_N += info.packets_T[0];
    string_N += "\n";
    string_N += info.nameI[1];
    string_N += "\t|";
    string_N += info.bytes_R[1];
    string_N += "\t";
    string_N += info.packets_R[1];
    string_N += "\t|";
    string_N += info.bytes_T[1];
    string_N += "\t";
    string_N += info.packets_T[1];
    string_N += "\n";
    string_N += info.nameI[2];
    string_N += "\t|";
    string_N += info.bytes_R[2];
    string_N += "\t";
    string_N += info.packets_R[2];
    string_N += "\t|";
    string_N += info.bytes_T[2];
    string_N += "\t";
    string_N += info.packets_T[2];
    string_N += "\n";
    string_N += info.nameI[3];
    string_N += "\t|";
    string_N += info.bytes_R[3];
    string_N += "\t";
    string_N += info.packets_R[3];
    string_N += "\t|";
    string_N += info.bytes_T[3];
    string_N += "\t";
    string_N += info.packets_T[3];
    string_N += "\n";
    global->INet.setString(string_N);

    string_C = "Model name:\n";
    string_C += info.getNameCPU();
    string_C += "\nInformation:\n";
    string_C += info.getCPUinfo();
    string_C += "\nNomber of core:\n";
    string_C += info.getCPUcore();
    string_C += "\nThread:\n";
    string_C += toString(info.getCPUthread());
    string_C += "\nUsage:\n";
    string_C += toString(info.getAccurateCPU());
    string_C += "%";
    global->ICPU.setString(string_C);

    double divide = 1000000.0;
    double totalram = (double)infoS.totalram / divide;
    double usedram = (double)(infoS.totalram - infoS.freeram) / divide;
    double freeram = (double)infoS.freeram / divide;
    double swapram = (double)(infoS.totalswap - infoS.freeswap) / divide;
    string_R = "Total RAM:\n";
    string_R += toString(totalram);
    string_R += "MB\nUsed RAM:\n";
    string_R += toString(usedram);
    string_R += "MB\nFree RAM:\n";
    string_R += toString(freeram);
    string_R += "MB\nSwap RAM:\n";
    string_R += toString(swapram);
    string_R += "MB\n";
    global->IRAM.setString(string_R);
}