#include <iostream>
#include <vector>
#include "BrickPi3.cpp"
#include <stdio.h>      // for printf
#include <unistd.h>     // for usleep
#include <signal.h>     // for catching exit signals
#include <time.h> 
using namespace std;

BrickPi3 BP;
void exit_signal_handler(int signo);

// Convert de positie naar afstand vergeleken met de vorige
vector<int> piano(const vector<int> & noots){
	
	vector<int> tweedeList = {};
	tweedeList.push_back(noots[0]-1);
	for(int i = 0; i < noots.size()-1; i++){
		tweedeList.push_back(noots[i+1]-noots[i]);
	}
	return tweedeList;
}

// Convert noten om in posities op het keyboard
vector<int> transform(vector<string> & noots){
	
	vector<int> newList = {};
	
	for(int i =0; i < noots.size(); i++){
		if (noots[i] == "c"){
			newList.push_back(1);
		} else if (noots[i] == "d"){
			newList.push_back(2);
		} else if (noots[i] == "e"){
			newList.push_back(3);
		} else if (noots[i] == "f"){
			newList.push_back(4);
		} else if (noots[i] == "g"){
			newList.push_back(5);
		} else if (noots[i] == "a"){
			newList.push_back(6);
		} else if (noots[i] == "b"){
			newList.push_back(7);
		} else if (noots[i] == "c8"){
			newList.push_back(8);
		} else if (noots[i] == "d8"){
			newList.push_back(9);
		} else if (noots[i] == "e8"){
			newList.push_back(10);
		} else if (noots[i] == "f8"){
			newList.push_back(11);
		} else if (noots[i] == "g8"){
			newList.push_back(12);
		} else if (noots[i] == "a8"){
			newList.push_back(13);
		} else if (noots[i] == "b8"){
			newList.push_back(14);
		} else if (noots[i] == "c16"){
			newList.push_back(15);
		} else {
			printf("Deze noot bestaat niet!");
		}
	}
	
	return piano(newList);
}

// Geef de lijst mee van de posities en zorg dat robot alle toetsen indrukt
void move(vector<int> & stappen){
	BP.set_motor_position(PORT_A, -200);
	sleep(1);
	BP.set_motor_position(PORT_A, 0);


	for (unsigned int i = 0; i < stappen.size(); i++) {
		if (stappen[i] < 0){
			printf("\n%4d\n", stappen[i]);
			BP.set_motor_dps(PORT_C, -52);
			BP.set_motor_dps(PORT_D, -52);
			sleep(stappen[i]*-1);
			BP.set_motor_dps(PORT_C, 0);
			BP.set_motor_dps(PORT_D, 0);
			sleep(1);
			BP.set_motor_position(PORT_A, -200);
			sleep(1);
			BP.set_motor_position(PORT_A, 0);
		} else if (stappen[i] >= 0){
			
			printf("\n%4d\n", stappen[i]);
			BP.set_motor_dps(PORT_C, 52);
			BP.set_motor_dps(PORT_D, 52);
			sleep(stappen[i]);
			BP.set_motor_dps(PORT_C, 0);
			BP.set_motor_dps(PORT_D, 0);
			sleep(1);
			BP.set_motor_position(PORT_A, -200);
			sleep(1);
			BP.set_motor_position(PORT_A, 0);
		}
	}
}

int main(){
	signal(SIGINT, exit_signal_handler); // register the exit function for Ctrl+C
	
	vector<string> noots {"f8", "c16", "e", "b", "e8", "c", "c16", "e"};
	//vector<string> noots {"c", "c16", "g8", "a8", "e8", "f8", "c8", "f8", "g8", "c16", "g8", "a8", "e8", "f8", "c8", "f8", "g8", "c16", "g8", "a8", "e8", "f8", "c8", "f8", "g8"};
	vector<int> temp = transform(noots);
	move(temp);
	
	//BP.set_motor_dps(PORT_C, 53.5);
	//BP.set_motor_dps(PORT_D, 53.5);
	//sleep(1);
	BP.set_motor_dps(PORT_C, 0);
	BP.set_motor_dps(PORT_D, 0);
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
