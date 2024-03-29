/*********************************************************************
 ** Program Filename: wumpus.h
 ** Author: Sarp Kocabagli
 ** Date: 05/28/2019
 ** Description: Wumpus class, derived from Event class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include "player.h"

class Wumpus : public Event
{
public:
    Wumpus();
    ~Wumpus();
    Wumpus(const Wumpus &);
    void operator=(const Wumpus &);
    char* get_percept();
    void set_percept();
    void set_name();
    char get_name();
    void act_on_player(Player *, int);
    
};

#endif

