#include "BrickPi3.cpp"
#include <vector>
#include <iostream>
#include <stdio.h>      // for printf
#include <unistd.h>     // for usleep
#include <signal.h>     // for catching exit signals
#include <time.h>
#include <stdlib.h>     // Random
using namespace std;

//Robot = 1
//User = 2
//De robot tekent een grid en zet een streep op een random plek.
//Het algorithme werkt als volgt:
//De loop begint, en blijft doorgaan zolang er geen winnaar is.
//Er wordt pas iets uitgevoerdt wanneer de knop is ingedrukt.
//De robot checkt de vakjes voor een verandering (de user input).
//Wanneer het deze ziet begint het met checken.
//Eerst kijkt het of de robot heeft gewonnen. Als dit waar is stopt het.
//Daarna kijkt het of de user gewonnen heeft. Als dit waar is stopt het.
//Daarna kijkt het of de robot een winkans heeft. Als dit waar zet hij een streep op de plek.
//Als hij dit niet heeft kijkt het of de user een winkans heeft. Als dit waar zet hij een streep op de plek.
//Als hij dit niet heeft kiest hij een random lege plek.
//Daarna zet hij een streep.
//Daarna wacht hij op de zet van de user (wacht op input van de knop) en begint het weer opnieuw.

BrickPi3 BP;
int colorValue = 0;
int colorValue1 = 0;
int colorValue2 = 0;

void exit_signal_handler(int signo);

//Maakt het speelveld.
void drawGrid(){
    // Pen naar beneden
    BP.set_motor_position(PORT_A, 0);
    sleep(1);
    // Arm naar voren (3,5)
    BP.set_motor_position(PORT_B, 645);
    sleep(1);
    // Pen naar boven
    BP.set_motor_position(PORT_A, 150);
    sleep(1);
    // Rijden naar links (1)
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    // Pen naar beneden
    BP.set_motor_position(PORT_A, 0);
    sleep(1);
    // Arm naar achteren (3)
    BP.set_motor_position(PORT_B, 0);
    sleep(1);
    // Pen naar boven
    BP.set_motor_position(PORT_A, 150);
    sleep(1);
    //----------------------------------
    // Rijden naar links (1)
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    // Arm naar voren (1)
    BP.set_motor_position(PORT_B, 430);
    sleep(1);
    // Pen naar beneden
    BP.set_motor_position(PORT_A, 0);
    sleep(1);
    // Rijden naar rechts (3)
    BP.set_motor_dps(PORT_C, -100);
    BP.set_motor_dps(PORT_D, -100);
    sleep(3);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    // Pen naar boven
    BP.set_motor_position(PORT_A, 150);
    sleep(1);
    // Arm naar voren (1)
    BP.set_motor_position(PORT_B, 215);
    sleep(1);
    // Pen naar beneden
    BP.set_motor_position(PORT_A, 0);
    sleep(1);
    // Rijden naar links (3)
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(3);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Reset alles
    BP.set_motor_position(PORT_A, 150);
    sleep(1);
    BP.set_motor_position(PORT_B, 0);
    sleep(1);
    BP.set_motor_dps(PORT_C, -100);
    BP.set_motor_dps(PORT_D, -100);
    sleep(2);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    BP.set_motor_position(PORT_B, -180);
    sleep(1);
}

//Zet een streepje in een vakje.
void streepjeInVak(int vakje, vector<int> &speelveld) {
    speelveld[vakje-1] = 1;
    if(vakje == 1) {
        // Streep tekenen in eerste vakje
        // Arm naar eerste vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 537.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, -25);
        BP.set_motor_dps(PORT_D, -25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, -75);
        BP.set_motor_dps(PORT_D, -75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, 100);
        BP.set_motor_dps(PORT_D, 100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 2){
        // Streep tekenen in tweede vakje
        // Arm naar tweede vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 537.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, 25);
        BP.set_motor_dps(PORT_D, 25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, 75);
        BP.set_motor_dps(PORT_D, 75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, -100);
        BP.set_motor_dps(PORT_D, -100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 3){
        // Streep tekenen in derde vakje
        // Arm naar derde vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 537.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, 100);
        BP.set_motor_dps(PORT_D, 100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, 25);
        BP.set_motor_dps(PORT_D, 25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, 75);
        BP.set_motor_dps(PORT_D, 75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, -100);
        BP.set_motor_dps(PORT_D, -100);
        sleep(2);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 4){
        // Streep tekenen in vierde vakje
        // Arm naar vierde vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 322.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, -25);
        BP.set_motor_dps(PORT_D, -25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, -75);
        BP.set_motor_dps(PORT_D, -75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, 100);
        BP.set_motor_dps(PORT_D, 100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 5){
        // Streep tekenen in vijfde vakje
        // Arm naar vijde vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 322.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, 25);
        BP.set_motor_dps(PORT_D, 25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, 75);
        BP.set_motor_dps(PORT_D, 75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, -100);
        BP.set_motor_dps(PORT_D, -100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 6){
        // Streep tekenen in zesde vakje
        // Arm naar zesde vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 322.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, 100);
        BP.set_motor_dps(PORT_D, 100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, 25);
        BP.set_motor_dps(PORT_D, 25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, 75);
        BP.set_motor_dps(PORT_D, 75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, -100);
        BP.set_motor_dps(PORT_D, -100);
        sleep(2);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 7){
        // Streep tekenen in zevende vakje
        // Arm naar zevende vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 107.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, -25);
        BP.set_motor_dps(PORT_D, -25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, -75);
        BP.set_motor_dps(PORT_D, -75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, 100);
        BP.set_motor_dps(PORT_D, 100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 8){
        // Streep tekenen in achtste vakje
        // Arm naar achtste vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 107.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, 25);
        BP.set_motor_dps(PORT_D, 25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, 75);
        BP.set_motor_dps(PORT_D, 75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, -100);
        BP.set_motor_dps(PORT_D, -100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
    else if(vakje == 9){
        // Streep tekenen in negende vakje
        // Arm naar negende vakje
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 107.5);
        sleep(1);
        // Rijden
        BP.set_motor_dps(PORT_C, 100);
        BP.set_motor_dps(PORT_D, 100);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, 25);
        BP.set_motor_dps(PORT_D, 25);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen naar beneden
        BP.set_motor_position(PORT_A, 0);
        sleep(1);
        // Streep tekenen door te rijden
        BP.set_motor_dps(PORT_C, 75);
        BP.set_motor_dps(PORT_D, 75);
        sleep(1);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        // Pen omhoog
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        // Reset alles
        BP.set_motor_position(PORT_A, 150);
        sleep(1);
        BP.set_motor_position(PORT_B, 0);
        sleep(1);
        BP.set_motor_dps(PORT_C, -100);
        BP.set_motor_dps(PORT_D, -100);
        sleep(2);
        BP.set_motor_dps(PORT_C, 0);
        BP.set_motor_dps(PORT_D, 0);
        sleep(1);
        //Arm naar achteren bij beginpunt, zodat speler een zet kan maken
        BP.set_motor_position(PORT_B, -180);
    }
}

//Checkt of een vakje zwart of wit is.
bool scanVakje(int colorValue){
    printf("KLEUR: %4d\n", colorValue);
    // Kleur is zwart
    if (colorValue < 570){
        printf("ZWART\n");
        return 1;
    }

    // Kleur is wit
    if (colorValue > 590){
        printf("WIT\n");
        return 0;
    }

    return -1;
}

//Beweegt sensor langs alle vakjes.
void scannenPerVakje(sensor_color_t Color2, vector<int> &speelveld) {
    // Pen omhoog
    BP.set_motor_position(PORT_A, 150);
    sleep(1);
    // Arm naar bovenste horizontale rij
    BP.set_motor_position(PORT_B, 800);
    sleep(1);
    // Rijden naar eerste vakje
    BP.set_motor_dps(PORT_C, -25);
    BP.set_motor_dps(PORT_D, -25);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1); 
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[0] == 0)){
        speelveld[0] = 2;
        printf("Streep in vak 1\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, 25);
		BP.set_motor_dps(PORT_D, 25);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    // Rijden naar tweede vakje
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[1] == 0)){
        speelveld[1] = 2;
        printf("Streep in vak 2\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, -75);
		BP.set_motor_dps(PORT_D, -75);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    // Rijden naar derde vakje
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[2] == 0)){
        speelveld[2] = 2;
        printf("Streep in vak 3\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, -175);
		BP.set_motor_dps(PORT_D, -175);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    // Arm naar middelste horizontale rij, vak 6
    BP.set_motor_position(PORT_B, 575);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[5] == 0)){
        speelveld[5] = 2;
        printf("Streep in vak 6\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, -175);
		BP.set_motor_dps(PORT_D, -175);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    // Rijden naar vijfde vakje
    BP.set_motor_dps(PORT_C, -100);
    BP.set_motor_dps(PORT_D, -100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[4] == 0)){
        speelveld[4] = 2;
        printf("Streep in vak 5\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, -75);
		BP.set_motor_dps(PORT_D, -75);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    //Rijden naar vierde vakje
    BP.set_motor_dps(PORT_C, -100);
    BP.set_motor_dps(PORT_D, -100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[3] == 0)){
        speelveld[3] = 2;
        printf("Streep in vak 4\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, 25);
		BP.set_motor_dps(PORT_D, 25);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    // Arm naar onderste horizontale rij, vak 7
    BP.set_motor_position(PORT_B, 375);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[6] == 0)){
        speelveld[6] = 2;
        printf("Streep in vak 7\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, 25);
		BP.set_motor_dps(PORT_D, 25);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    // Rijden naar achtste vakje
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;   
    sleep(1);    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[7] == 0)){
		speelveld[7] = 2;
        printf("Streep in vak 8\n");
		sleep(1);
		//Terug rijden naar beginpositie
		BP.set_motor_dps(PORT_C, -75);
		BP.set_motor_dps(PORT_D, -75);
		sleep(1);
		BP.set_motor_dps(PORT_C, 0);
		BP.set_motor_dps(PORT_D, 0);
		sleep(1);
		//Arm terug naar beginpositie
		BP.set_motor_position(PORT_B, 0);
		sleep(1);
        return;
    }
    sleep(1);
    //Rijden naar negende vakje
    BP.set_motor_dps(PORT_C, 100);
    BP.set_motor_dps(PORT_D, 100);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    // Check of vakje is ingevuld
    BP.get_sensor(PORT_2, &Color2);
    colorValue1 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;    
    BP.get_sensor(PORT_2, &Color2);
    colorValue2 = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
    colorValue = (colorValue1 + colorValue2) / 2;
    if(scanVakje(colorValue) && (speelveld[8] == 0)){
        speelveld[8] = 2;
        printf("Streep in vak 9\n");
	}
    sleep(1);
    //Terug rijden naar beginpositie
    BP.set_motor_dps(PORT_C, -175);
    BP.set_motor_dps(PORT_D, -175);
    sleep(1);
    BP.set_motor_dps(PORT_C, 0);
    BP.set_motor_dps(PORT_D, 0);
    sleep(1);
    //Arm terug naar beginpositie
    BP.set_motor_position(PORT_B, 0);
    sleep(1);
}

//Checkt of een speler gewonnen heeft.
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

//Checkt of een speler een kans heeft om te winnen.
int checkwinchance(vector<int> &checkedveld, int &speler){
    //horizontaal
    //rij 1
    if(checkedveld[0] == speler && checkedveld[1] == speler && checkedveld[2] == 0){
        return 2;
    }

    else if(checkedveld[0] == speler && checkedveld[2] == speler && checkedveld[1] == 0){
        return 1;
    }

    else if(checkedveld[1] == speler && checkedveld[2] == speler && checkedveld[0] == 0){
        return 0;
    }
        //rij 2
    else if(checkedveld[3] == speler && checkedveld[4] == speler && checkedveld[5] == 0){
        return 5;
    }

    else if(checkedveld[3] == speler && checkedveld[5] == speler && checkedveld[4] == 0){
        return 4;
    }

    else if(checkedveld[4] == speler && checkedveld[5] == speler && checkedveld[3] == 0){
        return 3;
    }
        //rij 3
    else if(checkedveld[6] == speler && checkedveld[7] == speler && checkedveld[8] == 0){
        return 8;
    }

    else if(checkedveld[6] == speler && checkedveld[8] == speler && checkedveld[7] == 0){
        return 7;
    }

    else if(checkedveld[7] == speler && checkedveld[8] == speler && checkedveld[6] == 0){
        return 6;
    }

        //verticaal
        //rij 1
    else if(checkedveld[0] == speler && checkedveld[3] == speler && checkedveld[6] == 0){
        return 6;
    }

    else if(checkedveld[0] == speler && checkedveld[6] == speler && checkedveld[3] == 0){
        return 3;
    }

    else if(checkedveld[3] == speler && checkedveld[6] == speler && checkedveld[0] == 0){
        return 0;
    }
        //rij 2
    else if(checkedveld[1] == speler && checkedveld[4] == speler && checkedveld[7] == 0){
        return 7;
    }

    else if(checkedveld[1] == speler && checkedveld[7] == speler && checkedveld[4] == 0){
        return 4;
    }

    else if(checkedveld[4] == speler && checkedveld[7] == speler && checkedveld[1] == 0){
        return 1;
    }
        //rij 3
    else if(checkedveld[2] == speler && checkedveld[5] == speler && checkedveld[8] == 0){
        return 8;
    }

    else if(checkedveld[2] == speler && checkedveld[8] == speler && checkedveld[5] == 0){
        return 5;
    }

    else if(checkedveld[5] == speler && checkedveld[8] == speler && checkedveld[2] == 0){
        return 2;
    }

        //diagonaal
        //rij 1
    else if(checkedveld[0] == speler && checkedveld[4] == speler && checkedveld[8] == 0){
        return 8;
    }

    else if(checkedveld[0] == speler && checkedveld[8] == speler && checkedveld[4] == 0){
        return 4;
    }

    else if(checkedveld[4] == speler && checkedveld[8] == speler && checkedveld[0] == 0){
        return 0;
    }
        //rij 2
    else if(checkedveld[2] == speler && checkedveld[4] == speler && checkedveld[6] == 0){
        return 6;
    }

    else if(checkedveld[2] == speler && checkedveld[6] == speler && checkedveld[4] == 0){
        return 4;
    }
    
	else if(checkedveld[4] == speler && checkedveld[6] == speler && checkedveld[2] == 0){
        return 2;
    }

    else{
        return -1;
    }
}

//Geeft random index.
int randomindex(int upper){
    int num = rand() % upper;
    return num;
}

int main() {
    signal(SIGINT, exit_signal_handler); // register the exit function for Ctrl+C

    BP.detect();

    int error;
    BP.set_sensor_type(PORT_2, SENSOR_TYPE_NXT_COLOR_FULL);
    BP.set_sensor_type(PORT_3, SENSOR_TYPE_TOUCH);

    BP.offset_motor_encoder(PORT_A, BP.get_motor_encoder(PORT_A)); // Motor pen
    BP.offset_motor_encoder(PORT_B, BP.get_motor_encoder(PORT_B)); // Motor x-as/arm
    BP.offset_motor_encoder(PORT_C, BP.get_motor_encoder(PORT_C)); // Motor wielen
    BP.offset_motor_encoder(PORT_D, BP.get_motor_encoder(PORT_D)); // Motor wielen

    sensor_color_t Color2;
    sensor_touch_t Touch3;

    int robot = 1;
    int user = 2;
    int winner = 0;
    bool finished = false;

    vector<int> speelveld = {0, 0, 0,
                             0, 0, 0,
                             0, 0, 0};

    vector<int> legeindex = {};
    int nextmoveindex = 0;

    drawGrid();

    srand(time(0));
    streepjeInVak(randomindex(9), speelveld);

    while (finished == false) {
        error = 0;

        if ((BP.get_sensor(PORT_3, &Touch3)) || (BP.get_sensor(PORT_2, &Color2))) {
            error++;
        } else {
            if (Touch3.pressed) {

                scannenPerVakje(Color2, speelveld);

                if (checkwin(speelveld, robot) == true) {
                    winner = robot;
                    finished = true;
                    break;
                }

                if (checkwin(speelveld, user) == true) {
                    winner = user;
                    finished = true;
                    break;
                }

                nextmoveindex = checkwinchance(speelveld, robot);
                if (nextmoveindex != -1) {
                    winner = robot;
                    finished = true;
                    cout << "\n" << nextmoveindex << "\n";
                }

                if (nextmoveindex == -1) {
                    nextmoveindex = checkwinchance(speelveld, user);
                    cout << "\n" << nextmoveindex << "\n";
                }

                if (nextmoveindex == -1) {
                    legeindex = {};
                    for (unsigned int i = 0; i < speelveld.size(); i++) {
                        if (speelveld[i] == 0) {
                            legeindex.push_back(i);
                        }
                    }
                    if (legeindex.size() == 1 || legeindex.size() == 0) {
                        winner = 3;
                        finished = true;
                        break;
                    }
                    srand(time(0));
                    int gekozenindex = randomindex(legeindex.size());
                    nextmoveindex = legeindex[gekozenindex];
                    cout << "\n" << nextmoveindex << "\n";
                }

                BP.set_motor_position(PORT_B, 0);
                sleep(1);
                streepjeInVak(nextmoveindex + 1, speelveld);
                Touch3.pressed = false;
            }
        }

        if (error == 4) {
            printf("Waiting for sensors to be configured");
        }
        usleep(20000);
    }

    if (winner == robot) {
        cout << "Verloren! Loser...";
    } else if (winner == user) {
        cout << "Gefeliciteerd! U heeft gewonnen!\n";
    } else {
        cout << "Gelijkspel? Wat jammer!\n";
    }
    BP.reset_all();    // Reset everything so there are no run-away motors
    exit(-2);
}


// Signal handler that will be called when Ctrl+C is pressed to stop the program
void exit_signal_handler(int signo){
    if(signo == SIGINT){
        BP.reset_all();    // Reset everything so there are no run-away motors
        exit(-2);
    }
}
