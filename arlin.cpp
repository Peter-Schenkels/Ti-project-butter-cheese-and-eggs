#include <iostream>
#include <vector>
using namespace std;

int move(bool beurt, int size, vector<int> & speelveldt, int pointer, int diepte, vector<int> & diepteNul, vector<int> & diepteEen){
	vector<int> speelveld = speelveldt;
	if(beurt == 0){
		
		for(unsigned int i =pointer; i < 9; i++){
			
			speelveld[i] = 1;
			if (speelveld[0] == 1 && speelveld[1] == 1 && speelveld[2] == 1){diepteNul.push_back(diepte);  return 0;}
			if (speelveld[3] == 1 && speelveld[4] == 1 && speelveld[5] == 1){diepteNul.push_back(diepte); return 0;}
			if (speelveld[6] == 1 && speelveld[7] == 1 && speelveld[8] == 1){diepteNul.push_back(diepte); return 0;}
				
			if (speelveld[0] == 1 && speelveld[4] == 1 && speelveld[8] == 1){diepteNul.push_back(diepte); return 0;}
			if (speelveld[6] == 1 && speelveld[4] == 1 && speelveld[2] == 1){diepteNul.push_back(diepte); return 0;}

			if (speelveld[0] == 1 && speelveld[3] == 1 && speelveld[6] == 1){diepteNul.push_back(diepte); return 0;}
			if (speelveld[1] == 1 && speelveld[4] == 1 && speelveld[7] == 1){diepteNul.push_back(diepte); return 0;}
			if (speelveld[2] == 1 && speelveld[5] == 1 && speelveld[8] == 1){diepteNul.push_back(diepte); return 0;}
			move(1, size-1, speelveld, pointer+1, diepte+1, diepteNul, diepteEen);
			
		}
		
	}
	if(beurt == 1){
		for(unsigned int i =pointer; i < 9; i++){
			if (speelveld[i] == 0){
				
				speelveld[i] = 2;
				speelveld[i] = 2;
				
				if (speelveld[0] == 2 && speelveld[1] == 2 && speelveld[2] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[3] == 2 && speelveld[4] == 2 && speelveld[5] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[6] == 2 && speelveld[7] == 2 && speelveld[8] == 2){diepteEen.push_back(diepte); return 1;}
				
				if (speelveld[0] == 2 && speelveld[4] == 2 && speelveld[8] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[6] == 2 && speelveld[4] == 2 && speelveld[2] == 2){diepteEen.push_back(diepte); return 1;}
				
				if (speelveld[0] == 2 && speelveld[3] == 2 && speelveld[6] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[1] == 2 && speelveld[4] == 2 && speelveld[7] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[2] == 2 && speelveld[5] == 2 && speelveld[8] == 2){diepteEen.push_back(diepte); return 1;}
				
				//mensen
				
				
				//Als speel veld vol is
				move(0, size-1, speelveld, pointer+1, diepte+1, diepteNul, diepteEen);
					
				
				if(size == 0){
					
					return 1;
				}
				
			}
			
		else{continue;}
					
					
					
					
				
				
			}
		
		}
		
	
	
	
}


int main(){
	float nulletjes = 0;
	float eentjes = 0;
	vector<int> diepteNul;
	vector<int> diepteEen;
	int aantalVrijePlekken = 0;
	int tijdelijkeGrootsteVerschil = 0;
	int indexTijdelijkeGrootsteVerschil = 0;
	int besteZet = -1;
	vector<int> lol = {1,1,0,
					   0,0,2,
					   2,0,0};
	for (unsigned int i=0; i < 9; i++){
		if(i%3 == 0){
			cout << "\n";
			}
		cout << lol[i];
	}
	cout << "\nonnaangepast\n";
	
	for(int i = 0; i < lol.size(); i++){
		if(lol[i] == 0){
			aantalVrijePlekken++;
		}
	}
	
	for(int i = 0; i < lol.size(); i++){
		if (lol[i] == 0){
			diepteEen = {};
			diepteNul = {};
			cout << "\n";
			vector<int> tmp = lol;
			tmp[i] = 2;
			move(false, aantalVrijePlekken, tmp, 0, 0, diepteNul, diepteEen);
			//cout << eentjes << " :eentjes\n" << nulletjes << " :nulletjes\n";
			
			//max van alle dieptes berekenen
			int tmpDiepte = diepteNul[0];
			for (unsigned int i=1; i < diepteNul.size(); i++){
				
				if (tmpDiepte < diepteNul[i]){
					
					tmpDiepte = diepteNul[i];
				}
			}
			cout << "Van nul: "<<tmpDiepte << "\n";
			tmpDiepte = diepteEen[0];
			for (unsigned int i=1; i < diepteEen.size(); i++){
				
				if (tmpDiepte < diepteEen[i]){
					
					tmpDiepte = diepteEen[i];
				}
			}
			cout << "van een: "<< tmpDiepte << "\n";
			
			
			
			
			for (unsigned int i=0; i < 9; i++){
			if(i%3 == 0){
				cout << "\n";
			}
			cout << tmp[i];
			
			
		
		
			}
		}
		
	}
	cout << "Het grootste verschil tussen eentjes en nulletjes is: " << tijdelijkeGrootsteVerschil << "\n";
	cout << "De index daarvan is: " << besteZet << "\n";
	
	
	
	
	
	
}


//Voor volgende keer
//Bereken hoe diep die zit in recursie.
