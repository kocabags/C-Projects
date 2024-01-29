/*********************************************************************
 ** Program Filename: pit.h
 ** Author: Sarp Kocabagli
 ** Date: 05/28/2019
 ** Description: Pit class, derived from Event class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef PIT_H
#define PIT_H

#include "event.h"
#include "player.h"

class Pit : public Event
{
public:
    Pit();
    ~Pit();
    Pit(const Pit &);
    void operator=(const Pit &);
    char* get_percept();
    void set_percept();
    void set_name();
    char get_name();
    void act_on_player(Player *, int);
    
};

#endif
