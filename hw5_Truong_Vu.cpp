#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "linkedlist_Truong.hpp"
#include "conga_Truong.h"

using namespace std;

typedef void (Conga::*Conga_Func) (Zombie);

const char COLOR[6] = {'R', 'Y', 'G', 'B', 'C', 'M'};
const char ACTION[8][20] = {"Engine!", "Caboose!", "Jump In!", "Everyone Out!", "You Out!", "Brains!", "Rainbow!", "New Friends!"};


int main(int argc, char **argv) {
    // the seed for random generator
    if(argc == 3 && strcmp(argv[1], "-s") == 0) {
        int seed = atoi(argv[2]);
        srand(seed);
    }
    else {
        srand(time(0));
    }
    
    //
    int nRound = 0;
    cout << "Enter the number of rounds: ";
    cin >> nRound;

    // initial data
    Conga conga;
    conga.rainbow_action(Zombie(COLOR[rand() % 6]));
    conga.brains_action(Zombie(COLOR[rand() % 6]));
    conga.brains_action(Zombie(COLOR[rand() % 6]));
    conga.brains_action(Zombie(COLOR[rand() % 6]));

    while(true){
        // start
        for(int round = 0; round < nRound; round++) {
            Zombie newZomb(COLOR[rand() % 6]);
            int action = rand() % 8;
            //Conga_Func func = CONGA_ACTION[action];

            if(round % 5 == 0) {
                conga.zombieList.RemoveFromFront();
                conga.zombieList.RemoveFromEnd();
            }
            try{
                cout << "Round: " << round << endl;
                cout << "Size: " << conga.zombieList.Length() << " :: ";
                conga.zombieList.PrintList();
                cout << "New Zombie: " << newZomb << " -- " << "Action: " << ACTION[action] << endl;
                // implement the action
                switch(action) {
                    case 0: conga.engine_action(newZomb); break;
                    case 1: conga.caboose_action(newZomb); break;
                    case 2: conga.jump_in_action(newZomb); break;
                    case 3: conga.everyone_out_action(newZomb); break;
                    case 4: conga.you_out_action(newZomb); break;
                    case 5: conga.brains_action(newZomb); break;
                    case 6: conga.rainbow_action(newZomb); break;
                    case 7: conga.friend_action(newZomb); break;
                }
                cout << "The conga line is now:" << endl;
                cout << "Size: " << conga.zombieList.Length() << " :: ";
                conga.zombieList.PrintList();
                cout << "**************************************************" << endl << endl;
            }
            catch(runtime_error& err) {

            }
            catch(out_of_range& err) {
                
            }
        }
        char opt;
        cout << "Do you want to continue the party (Y/N)? ";
        cin >> opt;
        if(opt == 'N' || opt == 'n') {
            break;
        }
        else {
            cout << "Enter the addition round? ";
            cin >> nRound;
        }
    }

    return 0;
}