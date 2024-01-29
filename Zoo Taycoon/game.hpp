/*Program Filename: Game.hpp
 * Author: Sarp Kocabagli
 * Date: 05/12/2019
 * Description: Class of Game
 * Input:none
 * Output:none
 */
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game{
private:
    int weeks;
    float money;
    float daily_food_cost;
    bool bankrupt;
    
    Monkey * total_monkeys;
    Meerkat * total_meerkats;
    Sea_otter * total_sea_otters;
    int num_monkeys;
    int num_meerkats;
    int num_sea_otters;
    
public:
    Game();
    ~Game();
    int &get_weeks();
    float &get_money();
    float get_daily_food_cost();
    bool get_bankrupt();
    void set_bankrupt(bool x);
    
    //Monkey functions
    Monkey &get_specific_monkey(int x);
    void add_monkey();
    void remove_monkey(int removed);
    void display_monkeys();
    int get_num_monkeys();
    
    //meerkat functions
    Meerkat &get_specific_meerkat(int x);
    void add_meerkat();
    void remove_meerkat(int removed);
    void display_meerkats();
    int get_num_meerkats();
    
    //Sea Otter Functions
    Sea_otter &get_specific_sea_otter(int x);
    void add_sea_otter();
    void remove_sea_otter(int removed);
    void display_sea_otters();
    int get_num_sea_otters();
    
    //Game functions
    void recieve_revenue(int bonus);
    void subtract_food_cost();
    void increment_week();
    
};
#endif
