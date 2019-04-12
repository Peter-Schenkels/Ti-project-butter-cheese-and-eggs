#include "BrickPi3.cpp"
#include <stdio.h>      // for printf
#include <unistd.h>     // for usleep
#include <signal.h>     // for catching exit signals
#include <time.h> 

BrickPi3 BP;				
int colorValue = 0;

void exit_signal_handler(int signo);

void drawGrid(){
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Arm naar voren (3,5)
	BP.set_motor_position(PORT_B, 645);
	sleep(2);
	// Pen naar boven 
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	// Rijden naar links (1)
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Arm naar achteren (3)
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	// Pen naar boven
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	//----------------------------------
	// Rijden naar links (1)
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	// Arm naar voren (1)
	BP.set_motor_position(PORT_B, 430);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Rijden naar rechts (3)
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(3);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	// Pen naar boven
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	// Arm naar voren (1)
	BP.set_motor_position(PORT_B, 215);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Rijden naar links (3)
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(3);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(2);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	BP.set_motor_position(PORT_B, -180);
	sleep(5);
}

void streepjeInVak1(){
	// Streep tekenen in eerste vakje
	// Arm naar eerste vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 537.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, -25);
	BP.set_motor_dps(PORT_D, -25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, -75);
	BP.set_motor_dps(PORT_D, -75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak2(){
	// Streep tekenen in tweede vakje
	// Arm naar tweede vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 537.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, 25);
	BP.set_motor_dps(PORT_D, 25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, 75);
	BP.set_motor_dps(PORT_D, 75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak3(){
	// Streep tekenen in derde vakje
	// Arm naar derde vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 537.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, 25);
	BP.set_motor_dps(PORT_D, 25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, 75);
	BP.set_motor_dps(PORT_D, 75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(2);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak4(){
	// Streep tekenen in vierde vakje
	// Arm naar vierde vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 322.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, -25);
	BP.set_motor_dps(PORT_D, -25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, -75);
	BP.set_motor_dps(PORT_D, -75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak5(){
	// Streep tekenen in vijfde vakje
	// Arm naar vijde vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 322.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, 25);
	BP.set_motor_dps(PORT_D, 25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, 75);
	BP.set_motor_dps(PORT_D, 75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak6(){
	// Streep tekenen in zesde vakje
	// Arm naar zesde vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 322.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, 25);
	BP.set_motor_dps(PORT_D, 25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, 75);
	BP.set_motor_dps(PORT_D, 75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(2);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak7(){
	// Streep tekenen in zevende vakje
	// Arm naar zevende vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 107.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, -25);
	BP.set_motor_dps(PORT_D, -25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, -75);
	BP.set_motor_dps(PORT_D, -75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak8(){
	// Streep tekenen in achtste vakje
	// Arm naar achtste vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 107.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, 25);
	BP.set_motor_dps(PORT_D, 25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, 75);
	BP.set_motor_dps(PORT_D, 75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

void streepjeInVak9(){
	// Streep tekenen in negende vakje
	// Arm naar negende vakje
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	BP.set_motor_position(PORT_B, 107.5);
	sleep(2);
	// Rijden
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, 25);
	BP.set_motor_dps(PORT_D, 25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen naar beneden
	BP.set_motor_position(PORT_A, 0);
	sleep(2);
	// Streep tekenen door te rijden
	BP.set_motor_dps(PORT_C, 75);
	BP.set_motor_dps(PORT_D, 75);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Reset alles
	BP.set_motor_position(PORT_A, 150);
	sleep(2);
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(2);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm naar achteren bij beginpunt, zodat speler een zet kan maken
	BP.set_motor_position(PORT_B, -180);
}

bool scanVakje(int colorValue){
	// Kleur is zwart
	printf("KELEUR: %4d\n", colorValue);
	if (colorValue < 580){
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

void scannenPerVakje(sensor_color_t Color2){
	// Pen omhoog
	BP.set_motor_position(PORT_A, 150);
	sleep(2);			
	// Arm naar bovenste horizontale rij
	BP.set_motor_position(PORT_B, 800);
	sleep(2);
	// Rijden naar eerste vakje
	BP.set_motor_dps(PORT_C, -25);
	BP.set_motor_dps(PORT_D, -25);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 1\n");
	}
	sleep(2);	
	// Rijden naar tweede vakje
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 2\n");
	}
	sleep(2);
	// Rijden naar derde vakje
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 3\n");
	}
	sleep(2);
	// Arm naar middelste horizontale rij
	BP.set_motor_position(PORT_B, 575);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 6\n");
	}
	sleep(2);
	// Rijden naar vijfde vakje
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 5\n");
	}
	sleep(2);
	//Rijden naar vierde vakje
	BP.set_motor_dps(PORT_C, -100);
	BP.set_motor_dps(PORT_D, -100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 4\n");
	}
	sleep(2);
	// Arm naar onderste horizontale rij
	BP.set_motor_position(PORT_B, 375);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 7\n");
	}
	sleep(2);
	// Rijden naar achtste vakje
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 8\n");
	}
	sleep(2);
	//Rijden naar negende vakje
	BP.set_motor_dps(PORT_C, 100);
	BP.set_motor_dps(PORT_D, 100);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	// Check of vakje is ingevuld
	BP.get_sensor(PORT_2, &Color2);
	colorValue = (Color2.reflected_red + Color2.reflected_green + Color2.reflected_blue) / 3;
	if(scanVakje(colorValue)){
		return;
		printf("Streep in vak 9\n");
	}
	sleep(2);
	//Terug rijden naar beginpositie
	BP.set_motor_dps(PORT_C, -175);
	BP.set_motor_dps(PORT_D, -175);
	sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
	sleep(2);
	//Arm terug naar beginpositie
	BP.set_motor_position(PORT_B, 0);
	sleep(2);
}

int main(){
	signal(SIGINT, exit_signal_handler); // register the exit function for Ctrl+C

	BP.detect();
	
	// bool gridDrawn = 0;

	int error;
	BP.set_sensor_type(PORT_2, SENSOR_TYPE_NXT_COLOR_FULL);
	BP.set_sensor_type(PORT_3, SENSOR_TYPE_TOUCH);

	BP.offset_motor_encoder(PORT_A, BP.get_motor_encoder(PORT_A)); // Motor pen
	BP.offset_motor_encoder(PORT_B, BP.get_motor_encoder(PORT_B)); // Motor x-as/arm
	BP.offset_motor_encoder(PORT_C, BP.get_motor_encoder(PORT_C)); // Motor wielen
	BP.offset_motor_encoder(PORT_D, BP.get_motor_encoder(PORT_D)); // Motor wielen

	sensor_color_t      Color2;
	sensor_touch_t      Touch3;

	while(true){
		error = 0;

		if ((BP.get_sensor(PORT_3, &Touch3)) || (BP.get_sensor(PORT_2, &Color2))){
			error++;
		} else{			
			if(Touch3.pressed){
				//drawGrid();
				
				BP.set_motor_position(PORT_B, 0);
				sleep(2);
				//streepjeInVak1();
				//streepjeInVak2();
				//streepjeInVak3();
				//streepjeInVak4();
				//streepjeInVak5();
				//streepjeInVak6();
				//streepjeInVak7();
				//streepjeInVak8();
				//streepjeInVak9();

				scannenPerVakje(Color2);
								
				BP.reset_all();    // Reset everything so there are no run-away motors
				exit(-2);
			} else{
				
			}
		}
		
		if (error == 4){
			printf("Waiting for sensors to be configured");
		}
		
		usleep(20000);
	}
}

// Signal handler that will be called when Ctrl+C is pressed to stop the program
void exit_signal_handler(int signo){
	if(signo == SIGINT){
		BP.reset_all();    // Reset everything so there are no run-away motors
		exit(-2);
	}
}
