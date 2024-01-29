/*Program Filename: meerkat.cpp
 * Author: Sarp Kocabagli
 * Date: 05/12/2019
 * Description: Method definition of meerkats
 * Input:none
 * Output:none
 */
#include<iostream>
#include"animal.hpp"
#include"meerkat.hpp"

using namespace std;

/*Function: Meerkat
 * Description: Default constructor for class sloth
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */

Meerkat::Meerkat(){
    set_age(104);
    set_cost(500);
    set_babies(0);
    set_food_cost(1);
    set_revenue(250);
}
