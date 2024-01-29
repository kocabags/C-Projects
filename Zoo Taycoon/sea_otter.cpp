/*Program Filename: sea_otter.cpp
 * Author: Sarp Kocabagli
 * Date: 05/12/2019
 * Description: Methid definition of Sea Otters
 * Input:none
 * Output:none
 */

#include<iostream>
#include"animal.hpp"
#include"sea_otter.hpp"

using namespace std;

/*Function: Sea otter
 * Description: Default constructor for class sea otter
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */

Sea_otter::Sea_otter(){
    set_age(104);
    set_cost(5000);
    set_babies(0);
    set_food_cost(2);
    set_revenue(250);
}
