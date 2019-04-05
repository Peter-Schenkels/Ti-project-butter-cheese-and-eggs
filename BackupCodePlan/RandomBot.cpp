#include <vector>
#include <iostream>
#include <stdio.h> // voor
#include <stdlib.h>// random
#include <time.h>  // jes
using namespace std;

//Robot = 1
//User = 2

vector<int> checkspeelveld(vector<int> &speelveld, vector<int> &robotzetten){
    vector<int> tempveld = {0,0,0,
                            0,0,0,
                            0,0,0};

    for(unsigned int i = 0; i < speelveld.size(); i++){
        if(speelveld[i] == 2 && robotzetten[i] == 1){
            tempveld[i] = 1;
        }else{
            tempveld[i] = 2;
        }
    }
}

bool checkwin(vector<int> &checkedveld, int &speler){
    //horizontaal
    if(checkedveld[0] == speler && checkedveld[1] == speler && checkedveld[2] == speler){
        return true;
    }else if(checkedveld[3] == speler && checkedveld[4] == speler && checkedveld[5] == speler){
        return true;
    }else if(checkedveld[6] == speler && checkedveld[7] == speler && checkedveld[8] == speler){
        return true;
    }
    //verticaal
    if(checkedveld[0] == speler && checkedveld[3] == speler && checkedveld[6] == speler){
        return true;
    }else if(checkedveld[1] == speler && checkedveld[4] == speler && checkedveld[7] == speler){
        return true;
    }else if(checkedveld[2] == speler && checkedveld[5] == speler && checkedveld[8] == speler){
        return true;
    }
    //diagonaal
    if(checkedveld[0] == speler && checkedveld[4] == speler && checkedveld[8] == speler){
        return true;
    }else if(checkedveld[2] == speler && checkedveld[4] == speler && checkedveld[6] == speler) {
        return true;
    }else{
        return false;
    }
}

int checkwinchance(vector<int> &checkedveld, int &speler){
    //horizontaal
    //rij 1
    if(checkedveld[0] == speler && checkedveld[1] == speler){
        return 2;
    }

    else if(checkedveld[0] == speler && checkedveld[2] == speler){
        return 1;
    }

    else if(checkedveld[1] == speler && checkedveld[2] == speler){
        return 0;
    }
    //rij 2
    else if(checkedveld[3] == speler && checkedveld[4] == speler){
        return 5;
    }

    else if(checkedveld[3] == speler && checkedveld[5] == speler){
        return 4;
    }

    else if(checkedveld[4] == speler && checkedveld[5] == speler){
        return 3;
    }
    //rij 3
    else if(checkedveld[6] == speler && checkedveld[7] == speler){
        return 8;
    }

    else if(checkedveld[6] == speler && checkedveld[8] == speler){
        return 7;
    }

    else if(checkedveld[7] == speler && checkedveld[8] == speler){
        return 6;
    }

    //verticaal
    //rij 1
    else if(checkedveld[0] == speler && checkedveld[3] == speler){
        return 6;
    }

    else if(checkedveld[0] == speler && checkedveld[6] == speler){
        return 3;
    }

    else if(checkedveld[3] == speler && checkedveld[6] == speler){
        return 0;
    }
    //rij 2
    else if(checkedveld[1] == speler && checkedveld[4] == speler){
        return 7;
    }

    else if(checkedveld[1] == speler && checkedveld[7] == speler){
        return 4;
    }

    else if(checkedveld[4] == speler && checkedveld[7] == speler){
        return 1;
    }
    //rij 3
    else if(checkedveld[2] == speler && checkedveld[5] == speler){
        return 8;
    }

    else if(checkedveld[2] == speler && checkedveld[8] == speler){
        return 5;
    }

    else if(checkedveld[5] == speler && checkedveld[8] == speler){
        return 2;
    }

    //diagonaal
    //rij 1
    else if(checkedveld[0] == speler && checkedveld[4] == speler){
        return 8;
    }

    else if(checkedveld[0] == speler && checkedveld[8] == speler){
        return 4;
    }

    else if(checkedveld[4] == speler && checkedveld[8] == speler){
        return 0;
    }
    //rij 2
    else if(checkedveld[2] == speler && checkedveld[4] == speler){
        return 6;
    }

    else if(checkedveld[2] == speler && checkedveld[6] == speler){
        return 4;
    }

    else{
        return -1;
    }
}

int randomindex(int upper){
    int num = rand() % upper;
    return num;
}

//Arlin Oerlain

int main(){
    int robot = 1;
    int user = 2;
    int winner = 0;
    bool finished = false;

    vector<int> speelveld = {0,0,0,
                             0,0,0,
                             0,0,0};

    vector<int> robotzetten = {0,0,0,
                               0,0,0,
                               0,0,0};

    vector<int> legeindex = {};
    int nextmoveindex = 0;

    while(finished == false) {
        //
        //robot checked de vakjes
        //
        vector<int> checkedveld = checkspeelveld(speelveld, robotzetten);

        if (checkwin(checkedveld, robot) == true) {
            winner = robot;
            finished = true;
        }

        if (checkwin(checkedveld, user) == true) {
            winner = user;
            finished = true;
        }

        nextmoveindex = checkwinchance(checkedveld, robot);

        cout << "\n" << nextmoveindex << "\n";

        if (nextmoveindex == -1) {
            nextmoveindex = checkwinchance(checkedveld, user);
        }
        cout << nextmoveindex << "\n";

        if (nextmoveindex == -1) {
            legeindex = {};
            for (unsigned int i = 0; i < checkedveld.size(); i++) {
                if (checkedveld[i] == 0) {
                    legeindex.push_back(i);
                }
            }
            if (legeindex.size() == 0) {
                winner = 3;
                finished = true;
            }
            srand(time(0));
            int gekozenindex = randomindex(legeindex.size());
            nextmoveindex = legeindex[gekozenindex];
        }
        cout << nextmoveindex << "\n";
        string naam = "streepjeInVakje" + to_string(nextmoveindex + 1);
        cout << "Naam: " << naam << endl;
        //
        //beweeg robot naar index
        //
    }

    if(winner == robot){
        cout << "Wanneer ik gewonnen heb:\n" << "Hey!, ik heb gewonnen!";
    }else if(winner == user){
        cout << "Gefeliciteerd met uw EPIC VICTORY ROYALE!";
    }else{
        cout << "Gelijkspel? Wat jammer! ;)";
    }
}