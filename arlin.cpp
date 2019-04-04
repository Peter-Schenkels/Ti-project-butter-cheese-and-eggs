#include <iostream>
#include <vector>
using namespace std;

int move(bool beurt, int size, vector<int> & speelveldt, int diepte, vector<int> & diepteNul, vector<int> & diepteEen){
	vector<int> speelveld = speelveldt;
	//0 is beurt voor computer, 1 is beurt voor de speler
	if(beurt == 0){
//		cout << "\naan de beurt Computer\n";
		for(unsigned int i =0; i < 9; i++){
			if (speelveld[i] == 0){
				speelveld[i] = 2;
				
//				cout << "\nhuidige diepte: " << diepte << "\n";
//				for (unsigned int j=0; j < 9; j++){
//					if(j%3 == 0){
//						cout << "\n";
//					}
//					cout << speelveld[j];
//				}
				cout << "\n";
				if (speelveld[0] == 2 && speelveld[1] == 2 && speelveld[2] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[3] == 2 && speelveld[4] == 2 && speelveld[5] == 2){diepteEen.push_back(diepte); return 1;}
				if (speelveld[6] == 2 && speelveld[7] == 2 && speelveld[8] == 2){diepteEen.push_back(diepte); return 1;}
				
				if (speelveld[0] == 2 && speelveld[4] == 2 && speelveld[8] == 2){diepteEen.push_back(diepte);  return 1;}
				if (speelveld[6] == 2 && speelveld[4] == 2 && speelveld[2] == 2){diepteEen.push_back(diepte);  return 1;}
				
				if (speelveld[0] == 2 && speelveld[3] == 2 && speelveld[6] == 2){diepteEen.push_back(diepte);  return 1;}
				if (speelveld[1] == 2 && speelveld[4] == 2 && speelveld[7] == 2){diepteEen.push_back(diepte);  return 1;}
				if (speelveld[2] == 2 && speelveld[5] == 2 && speelveld[8] == 2){diepteEen.push_back(diepte);  return 1;}
				
				
				//Als speel veld vol is
				move(true, size-1, speelveld, diepte+1, diepteNul, diepteEen);
				}
		}
	}
	//speler
	if(beurt == 1){
//		cout << "\naan de beurt Speler\n";
		for(unsigned int i =0; i < 9; i++){
			if(speelveld[i] == 0){
				speelveld[i] = 1;
			
//			cout << "\nhuidige diepte: " << diepte << "\n";
//			for (unsigned int j=0; j < 9; j++){
//					if(j%3 == 0){
//						cout << "\n";
//					}
//					cout << speelveld[j];
//				}
			cout << "\n";
			if (speelveld[0] == 1 && speelveld[1] == 1 && speelveld[2] == 1){diepteNul.push_back(diepte);return 0;}
			if (speelveld[3] == 1 && speelveld[4] == 1 && speelveld[5] == 1){diepteNul.push_back(diepte);return 0;}
			if (speelveld[6] == 1 && speelveld[7] == 1 && speelveld[8] == 1){diepteNul.push_back(diepte);return 0;}
				
			if (speelveld[0] == 1 && speelveld[4] == 1 && speelveld[8] == 1){diepteNul.push_back(diepte);return 0;}
			if (speelveld[6] == 1 && speelveld[4] == 1 && speelveld[2] == 1){diepteNul.push_back(diepte);return 0;}

			if (speelveld[0] == 1 && speelveld[3] == 1 && speelveld[6] == 1){diepteNul.push_back(diepte); return 0;}
			if (speelveld[1] == 1 && speelveld[4] == 1 && speelveld[7] == 1){diepteNul.push_back(diepte); return 0;}
			if (speelveld[2] == 1 && speelveld[5] == 1 && speelveld[8] == 1){diepteNul.push_back(diepte); return 0;}
			move(false, size-1, speelveld, diepte+1, diepteNul, diepteEen);
			}
		}
	}
	if(size == 0){
		diepteEen.push_back(1000); return 1; 
	}
	
}


int main(){
	vector<int> diepteNul = {};
	vector<int> diepteEen = {};
	int aantalVrijePlekken = 0;
	int tijdelijkeGrootsteVerschil = 0;
	int indexTijdelijkeGrootsteVerschil = 0;
	int besteZet = -1;
	vector<int> speelveldje = {1,1,0,
							   0,0,2,
							   2,0,0};
	
	//berekent aantal vrije plekken
	for(unsigned int i = 0; i < speelveldje.size(); i++){
		if(speelveldje[i] == 0){
			aantalVrijePlekken++;
		}
	}
	
	for(unsigned int i = 0; i < speelveldje.size(); i++){
		
		if (speelveldje[i] == 0){
			diepteEen.clear();
			diepteNul.clear();
			
			cout << "\n";
			
			vector<int> tmp = speelveldje;
			
			tmp[i] = 2;

			move(true, aantalVrijePlekken, tmp, 0, diepteNul, diepteEen);
			
			
			//min van alle dieptes berekenen
			
			//print alle items uit de diepte lijsten
			
			//for (unsigned int i=0; i < diepteNul.size(); i++){
				//cout << diepteNul[i] << ": van 0\n";
			//}
			//cout << diepteNul.size() << " :size \n";
			
			//for (unsigned int i=0; i < diepteEen.size(); i++){
//				cout << diepteEen[i] << ": van 1\n";
//			}
//			cout << diepteEen.size() << " :size \n";
			
			//min diepte berkenene van nul
			int tmpDiepte = diepteNul[0];
			for (unsigned int i=1; i < diepteNul.size(); i++){
				//cout << "0: " << diepteNul[i] << "\n";
				if (diepteNul[i] == 0){
					diepteNul.erase(diepteNul.begin() + i);
					continue;
				}
				if (tmpDiepte > diepteNul[i]){
					
					tmpDiepte = diepteNul[i];
				}
			}
			cout << "Van nul: "<<tmpDiepte << "\n";
			
			//min diepte berekenen van een
			tmpDiepte = diepteEen[0];
			for (unsigned int i=1; i < diepteEen.size(); i++){
				//cout << "1:" << diepteEen[i] << "\n";
				if (tmpDiepte > diepteEen[i]){
					
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
