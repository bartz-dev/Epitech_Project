/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** MyUnitTest
*/

#include "Wrap.hpp"
#include "Box.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"

Object *MyUnitTest(Object **object)
{
    Teddy *ted = (Teddy*)object[0];
    Box *box =(Box*)object[1];
    (ted)->isTaken();
    std::cout << "opening open warp" << std::endl;
    (box)->OpenMe();
    std::cout << "adding to closed box"<< std::endl;
    (box)->CloseMe();
    //(box)->wrapMeThat(
    //std::cout << "msg a deffinir" << std::endl;

}