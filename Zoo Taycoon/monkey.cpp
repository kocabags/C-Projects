/*Program Filename: monkey.cpp
 * Author: Sarp Kocabagli
 * Date: 05/12/2019
 * Description: method definition of Monkeys
 * Input:none
 * Output:none
 */

#include<iostream>
#include"animal.hpp"
#include"monkey.hpp"

using namespace std;

/*Function: Monkey
 * Description: Default constructor for class monkey
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */

Monkey::Monkey(){
    set_age(104);
    set_cost(15000);
    set_babies(0);
    set_food_cost(4);
    set_revenue(1500);
}

