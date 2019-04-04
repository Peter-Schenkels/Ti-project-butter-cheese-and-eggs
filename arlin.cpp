#include <iostream>
#include <vector>
using namespace std;

int move(bool beurt, int size, vector<int> & speelveldt, int diepte, vector<int> & diepteNul, vector<int> & diepteEen){
	vector<int> speelveld = speelveldt;
	//0 is beurt voor computer, 1 is beurt voor de speler
	if(beurt == 0){
		cout << "\naan de beurt Computer\n";
		for(unsigned int i =0; i < 9; i++){
			if (speelveld[i] == 0){
				speelveld[i] = 2;
				
				cout << "\nhuidige diepte: " << diepte << "\n";
				for (unsigned int j=0; j < 9; j++){
					if(j%3 == 0){
						cout << "\n";
					}
					cout << speelveld[j];
				}
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
		cout << "\naan de beurt Speler\n";
		for(unsigned int i =0; i < 9; i++){
			if(speelveld[i] == 0){
				speelveld[i] = 1;
			
			cout << "\nhuidige diepte: " << diepte << "\n";
			for (unsigned int j=0; j < 9; j++){
					if(j%3 == 0){
						cout << "\n";
					}
					cout << speelveld[j];
				}
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
	int tmpVerschil = 0;
	vector<vector<int>> mogelijkheden = {};
	vector<int> diepteNul = {};
	vector<int> diepteEen = {};
	int aantalVrijePlekken = 0;
	int tijdelijkeGrootsteVerschil = 0;
	int indexTijdelijkeGrootsteVerschil = 0;
	int besteZet = -1;
	vector<int> speelveldje = {1,2,2,
							   0,0,2,
							   1,0,1};
	
	//berekent aantal vrije plekken
	for(unsigned int i = 0; i < speelveldje.size(); i++){
		if(speelveldje[i] == 0){
			aantalVrijePlekken++;
		}
	}
	
	for(unsigned int i = 0; i < speelveldje.size(); i++){
		cout << "\n"<< i << "\n";
		if (speelveldje[i] == 0){
			diepteEen.clear();
			diepteNul.clear();
			

			
			vector<int> tmp = speelveldje;
			
			tmp[i] = 2;

			move(true, aantalVrijePlekken, tmp, 0, diepteNul, diepteEen);

			
			
			//min diepte berekenen van een
			int tmpDiepte = diepteEen[0];
			for (unsigned int j=1; j < diepteEen.size(); j++){
			
				if (tmpDiepte > diepteEen[j]){
					
					tmpDiepte = diepteEen[j];
				}
			}
			cout << "van een: "<< tmpDiepte << "\n";
			tmpVerschil = tmpDiepte;
			tmpDiepte = diepteNul[0];
			
			for (unsigned int j=1; j < diepteNul.size(); j++){
				
				if (diepteNul[j] == 0){
					diepteNul.erase(diepteNul.begin() + j);
					continue;
				}
				if (tmpDiepte > diepteNul[j]){
					
					tmpDiepte = diepteNul[j];
				}
			}
			cout << "Van nul: "<< tmpDiepte << "\n";
			tmpVerschil -= tmpDiepte;
			
			if(tmpVerschil >= 0){
				
				mogelijkheden.push_back({i, tmpVerschil});
				
			}
			
			
			
			
			for (unsigned int i=0; i < 9; i++){
				if(i%3 == 0){
					cout << "\n";
				}
				cout << tmp[i];
			}
		}
		
	}
	int max = mogelijkheden[0][1];
	int maxIndex = mogelijkheden[0][0];
	for(unsigned int i = 1; i < mogelijkheden.size(); i++){
		
		if (max < mogelijkheden[i][1]){
			
			max = mogelijkheden[i][1];
			maxIndex = mogelijkheden[i][0];
			
		}
		
	}
	besteZet = maxIndex;
	cout << "\nDe index daarvan is: " << besteZet << "\n";
	
	
	
	
	
	
}


//Voor volgende keer
//Bereken hoe diep die zit in recursie.
