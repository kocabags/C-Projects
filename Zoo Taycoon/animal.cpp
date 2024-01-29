/*Program Filename: animal.cpp
 * Author: Sarp Kocabagli
 * Date: 05/12/2019
 * Description: Method definition of class Animal
 * Input:none
 * Output:none
 */

#include<iostream>
#include "animal.hpp"

using namespace std;
/*Function: Animal
 * Description: Default constructor for class animal
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: None
 */
Animal::Animal(){
    
}


/*Function: get age
 * Description: returns age of animal
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: integer age of animal
 */
int Animal::get_age(){
    return age;
}
/*Function: get cost
 * Description: returns cost of animal
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: integer cost of animal
 */
int Animal::get_cost(){
    return cost;
}
/*Function: get babies
 * Description: returns babies of animal
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: integer babies of animal
 */
int Animal::get_babies(){
    return babies;
}
/*Function: get food cost
 * Description: returns good cost of animal (1x,2x,4x)
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: float food cost
 */
float Animal::get_food_cost(){
    return food_cost;
}
/*Function: get revenue
 * Description: returns revenue of animal
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: integer revenue
 */
int Animal::get_revenue(){
    return revenue;
}
/*Function: set age
 * Description: preset the age of an animal
 * Parameters: integer
 * Pre-conditions: integer for age
 * Post-conditions: age is set to argument
 */
void Animal::set_age(int x){
    age=x;
}
/*Function: set cost
 * Description: preset the cost of an animal
 * Parameters: integer
 * Pre-conditions: integer for cost
 * Post-conditions: cost is set to argument
 */
void Animal::set_cost(int x){
    cost=x;
}
/*Function: set babies
 * Description: preset the babies of an animal
 * Parameters: integer
 * Pre-conditions: integer for babies
 * Post-conditions: babies is set to argument
 */
void Animal::set_babies(int x){
    babies = x;
}
/*Function: set food cost
 * Description: preset the food cost of an animal
 * Parameters: integer
 * Pre-conditions: integer for food cost
 * Post-conditions: food cost is set to argument
 */
void Animal::set_food_cost(float x){
    food_cost=x;
}
/*Function: set revenue
 * Description: preset the revnue of an animal
 * Parameters: integer
 * Pre-conditions: integer for revenue
 * Post-conditions: revnue is set to argument
 */
void Animal::set_revenue(int x){
    revenue=x;
}
/*Function: set babies
 * Description: preset the babies of an animal
 * Parameters: integer of amount of babies
 * Pre-conditions: integer for babies
 * Post-conditions: babies is set to argument
 */
void Animal::add_babies(int x){
    babies = babies +x;
}
