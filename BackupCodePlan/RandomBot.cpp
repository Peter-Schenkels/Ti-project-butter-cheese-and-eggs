#include <vector>
#include <iostream>
#include <stdio.h> // voor
#include <stdlib.h>//
#include <time.h>  //
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

int checkwin(vector<int> &checkedveld, int &speler){
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

int main(){
    int robot = 1;
    int user = 2;
    vector<int> speelveld = {0,0,0,
                             0,0,0,
                             0,0,0};

    vector<int> robotzetten = {0,0,0,
                               0,0,0,
                               0,0,0};
    vector<int> legeindex = {};
    int nextmoveindex = 0;

    //
    //robot shit
    //

    vector<int> checkedveld = checkspeelveld(speelveld, robotzetten);

    nextmoveindex = checkwin(checkedveld, robot);

    cout << "\n" << nextmoveindex << "\n";

    if(nextmoveindex == -1){
        nextmoveindex = checkwin(checkedveld, user);
    }
    cout << nextmoveindex << "\n";

    if(nextmoveindex == -1){
        legeindex = {};
        for(unsigned int i = 0; i < checkedveld.size(); i++){
            if(checkedveld[i] == 0){
                legeindex.push_back(i);
            }
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