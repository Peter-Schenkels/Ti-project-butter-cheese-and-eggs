#include <iostream>
#include <Windows.H>
#include <vector>
#include "BrickPi3.cpp"
using namespace std;


//convert de positie naar afstand vergeleken met de vorige
vector<int> piano(const vector<int> & noots){
	
	vector<int> tweedeList = {};
	tweedeList.push_back(noots[0]);
	for(int i = 0; i < noots.size()-1; i++){
		tweedeList.push_back(noots[i+1]-noots[i]);
	}
	return tweedeList;
}

//convert noten om in posities op het keyboard
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
			cout << "Deze noot bestaat niet!";
		}
	}
	return piano(newList);
}

// geef de lijst mee van de posities en zorg dat robot alle toetsen indrukt
void move(vector<int> & stappen){
	for (unsigned int i = 0; i < stappen.size(); i++) {
		if (i < 0){
			BP.set_motor_dps(PORT_C, -50);
			BP.set_motor_dps(PORT_D, -50);
			sleep(i*-1);
			BP.set_motor_dps(PORT_C, 0);
			BP.set_motor_dps(PORT_D, 0);
			sleep(1);
			BP.set_motor_position(PORT_A, 0);
			sleep(0.5);
			BP.set_motor_position(PORT_A, 150);
			sleep(0.5);
		} else if (i > 0){
			BP.set_motor_dps(PORT_C, 50);
			BP.set_motor_dps(PORT_D, 50);
			sleep(i);
			BP.set_motor_dps(PORT_C, 0);
			BP.set_motor_dps(PORT_D, 0);
			sleep(1);
			BP.set_motor_position(PORT_A, 0);
			sleep(0.5);
			BP.set_motor_position(PORT_A, 150);
			sleep(0.5);
		}
		sleep(1);
		BP.set_motor_position(PORT_A, 0);
		sleep(0.5);
		BP.set_motor_position(PORT_A, 150);
		sleep(0.5);
	}
}

int main(){
	vector<string> noots {"f8", "c16", "e", "b", "e8", "c", "c16", "e"};
	move(transform(noots));
}
