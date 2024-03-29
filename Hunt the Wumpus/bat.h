/*********************************************************************
 ** Program Filename: bat.h
 ** Author: Sarp Kocabagli
 ** Date: 05/28/2019
 ** Description: Bat class, derived from Event class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef BAT_H
#define BAT_H

#include "event.h"
#include "player.h"

class Bat : public Event
{
public:
    Bat();
    ~Bat();
    Bat(const Bat &);
    void operator=(const Bat &);
    char* get_percept();
    void set_percept();
    void set_name();
    char get_name();
    void act_on_player(Player *, int);
    
};

#endif
