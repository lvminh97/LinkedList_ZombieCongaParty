#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "linkedlist_Truong.hpp"
#include "conga_Truong.h"
using namespace std;

const char COLOR[6] = {'R', 'Y', 'G', 'B', 'C', 'M'};       // Color of zombie
const char ACTION[8][20] = {
    "Engine!", "Caboose!", "Jump in the Line!", "Everyone Out!", "You Out!", "Brains!", "Rainbow Brains!", "Making new Friends!"
};      // Action title

typedef void (Conga::*Conga_Func) (Zombie);
// Use function pointer to take the action easily
Conga_Func CONGA_ACTION[8] = {
    &Conga::engine_action, &Conga::caboose_action, &Conga::jump_in_action, &Conga::everyone_out_action,
    &Conga::you_out_action, &Conga::brains_action, &Conga::rainbow_action, &Conga::friend_action
};

int main(int argc, char **argv) {
    // the seed for random generator
    if(argc == 3 && strcmp(argv[1], "-s") == 0) {
        int seed = atoi(argv[2]);
        srand(seed);
    }
    else {
        srand(time(0));
    }

    // Enter the number of rounds
    int nRound = 0;
    cout << "How many rounds do you want to run?: ";
    cin >> nRound;

    // initial data: 1 rainbow brains and 3 brains
    Conga conga;
    conga.rainbow_action(Zombie(COLOR[rand() % 6]));
    conga.brains_action(Zombie(COLOR[rand() % 6]));
    conga.brains_action(Zombie(COLOR[rand() % 6]));
    conga.brains_action(Zombie(COLOR[rand() % 6]));

    // main loop
    int round = 0;
    char opt;
    while(true){
        // loop through nRound rounds of party
        for(;round < nRound; round++) {
            int action = rand() % 8;                    // get random action index
            Zombie newZomb(COLOR[rand() % 6]);          // get random color of zombie
            Conga_Func func = CONGA_ACTION[action];     // load the action through function pointer

            if(round % 5 == 0) {                        // if round % 5 == 0: delete the first and last zombie
                conga.zombieList.RemoveFromFront();     // first zombie
                conga.zombieList.RemoveFromEnd();       // last zombie
            }
            try{
                // Print the information of round
                cout << "Round: " << round << endl;
                cout << "Size: " << conga.zombieList.Length() << " :: ";
                conga.zombieList.PrintList();
                cout << "New Zombie: " << newZomb << " -- " << "Action: [" << ACTION[action] << "]" << endl;
                // implement the action
                (conga.*func)(newZomb);
                cout << "The conga line is now:" << endl;
                cout << "Size: " << conga.zombieList.Length() << " :: ";
                conga.zombieList.PrintList();
                cout << "**************************************************" << endl << endl;
            }
            catch(runtime_error& err) {
                // 
            }
            catch(out_of_range& err) {
                // 
            }
        }
        // get user's option about continue or not?
        cout << "Do you want to continue the party? (y/n): ";
        cin >> opt;
        if(opt == 'N' || opt == 'n') {      // if no, the program is ended
            break;
        }
        else if(opt == 'Y' || opt == 'y'){  // if yes, enter the number of addition rounds 
            cout << "Enter the number of addition rounds? ";
            cin >> nRound;
            round = 0;                      // reset for next party
        }
    }

    return 0;
}