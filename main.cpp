#include "AllPlayerClasses.h"
#include "selectFunctions.h"
#include "clear_screen.h"
#include <iostream>
#include <string>

int main(void)
{

    // STORES ALL ATTACK INORMATION
    int damage1, damage2, APCost1, APCost2;
    int* damage1p = &damage1;
    int* damage2p = &damage2;
    int* APCost1p = &APCost1;
    int* APCost2p = &APCost2;
    std::string status1 = "none";
    std::string status2 = "none";
    std::string* status1p = &status1; 
    std::string* status2p = &status2;

    clear_screen();

    // CHARACTER SELECTION
    #ifndef NOUI_H
        std::cout << "Player 1" << std::endl;
    #endif
    Player* Player1 = select_character();
    clear_screen();
    #ifndef NOUI_H
        std::cout << "Player 2" << std::endl;
    #endif
    Player* Player2 = select_character();
    clear_screen();

    while (Player1->get_health() != 0 && Player2->get_health() != 0) // SELECT ATTACK
    {
        // CALCULATING ATTACK ORDER
        if (Player1->get_speed() >= Player2->get_speed()) // PLAYER 1 GOES FIRST
        {
            select_attack(Player1, damage1p, APCost1p, status1p);
           
            Player1->change_abilityPoints(-APCost1);
            Player2->change_health(-damage1);
            Player1->change_abilityPoints(Player1->get_abilityPointsGain());

            if (Player2->get_health() != 0) // CHECKING HEALTH, SKIP IF WINNER IS FOUND
            {
                select_attack(Player2, damage2p, APCost2p, status2p);

                Player2->change_abilityPoints(-APCost2);
                Player1->change_health(-damage2);
                Player2->change_abilityPoints(Player2->get_abilityPointsGain());
            }
        }
        else // PLAYER 2 GOES FIRST
        {
            select_attack(Player2, damage2p, APCost2p, status2p);

            Player2->change_abilityPoints(-APCost2);
            Player1->change_health(-damage2);
            Player2->change_abilityPoints(Player2->get_abilityPointsGain());

            if (Player1->get_health() != 0) // CHECKING HEALTH, SKIP IF WINNER IS FOUND
            {
                select_attack(Player1, damage1p, APCost1p, status1p); 

                Player1->change_abilityPoints(-APCost1);
                Player2->change_health(-damage1);
                Player1->change_abilityPoints(Player1->get_abilityPointsGain());
            }    
        }
    }

    #ifndef NOUI_H // USER WIN MESSAGE
    if (Player1->get_health() > 0)
    {
        std::cout << Player1->get_name() << " Wins!" << std::endl;
    }
    else
    {
        std::cout << Player2->get_name() << " Wins!" << std::endl;
    }
    #else
    if (Player1->get_health() > 0)
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        std::cout << "2" << std::endl;
    }
    #endif

    // DELETING DYNAMIC MEMORY
    delete Player1;
    delete Player2;

    return 0;
}
