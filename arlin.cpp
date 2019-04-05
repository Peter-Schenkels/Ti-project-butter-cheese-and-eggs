#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

int move(vector<int> speelveldt, vector<vector<int>> diepteMinMax, int diepte, int size, int pointer){
	vector<int> speelveld = speelveldt;
	bool beurt;
	
	
	if (diepte%2== 0){
		beurt = 1;
	}
	else{
		beurt = 0;
	}
	cout << "beurt: " << beurt << "\n";
	Sleep(2000);

	cout << size << "\n";
	//computer is 0 maar speelding is 1
	
	
	
	if (beurt == 0){
		
		for(unsigned int i =pointer; i < 9;  i++){
			if(speelveld[i] == 0){
				speelveld[i] = 1;
				for (int i = 0; i < 9; i++){
					if (i%3 == 0){
						
						cout << "\n";
					}
					cout << speelveld[i];
				}
				cout << "\n";
				if (speelveld[0] == 1 && speelveld[1] == 1 && speelveld[2] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n"; return 1;}
				if (speelveld[3] == 1 && speelveld[4] == 1 && speelveld[5] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n"; return 1;}
				if (speelveld[6] == 1 && speelveld[7] == 1 && speelveld[8] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n"; return 1;}
					
				if (speelveld[0] == 1 && speelveld[4] == 1 && speelveld[8] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 1;}
				if (speelveld[6] == 1 && speelveld[4] == 1 && speelveld[2] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 1;}

				if (speelveld[0] == 1 && speelveld[3] == 1 && speelveld[6] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 1;}
				if (speelveld[1] == 1 && speelveld[4] == 1 && speelveld[7] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 1;}
				if (speelveld[2] == 1 && speelveld[5] == 1 && speelveld[8] == 1){diepteMinMax[0].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 1;}
				move(speelveld, diepteMinMax, diepte+1, size-1, pointer+1);
				
				}
			}
		}
	//speler is 1 maar speelding is 2
	else if (beurt == 1){
		for(unsigned int i =pointer; i < 9;  i++){
			if(speelveld[i] == 0){
				speelveld[i] = 2;
				for (int i = 0; i < 9; i++){
					if (i%3 == 0){
						
						cout << "\n";
					}
					cout << speelveld[i];
				}
				cout << "\n";
				if (speelveld[0] == 2 && speelveld[1] == 2 && speelveld[2] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				if (speelveld[3] == 2 && speelveld[4] == 2 && speelveld[5] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				if (speelveld[6] == 2 && speelveld[7] == 2 && speelveld[8] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				
				if (speelveld[0] == 2 && speelveld[4] == 2 && speelveld[8] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				if (speelveld[6] == 2 && speelveld[4] == 2 && speelveld[2] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				
				if (speelveld[0] == 2 && speelveld[3] == 2 && speelveld[6] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				if (speelveld[1] == 2 && speelveld[4] == 2 && speelveld[7] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				if (speelveld[2] == 2 && speelveld[5] == 2 && speelveld[8] == 2){diepteMinMax[1].push_back(diepte); pointer++; cout << "diepte: " << diepte << "\n";return 0;}
				move(speelveld, diepteMinMax, diepte+1, size-1, pointer+1);
			}
		}
		if (size == 0){
		
		diepteMinMax[0].push_back(diepte);
		return 0;
		
		}
		
	}
	
}

int main(){
	
	int size = 0;
	
	vector<vector<int>> diepteMinMax = {{}, {}};
	vector<vector<int>> minLijst = {};
	
	vector<int> veld = {0,0,0,0,0,0,0,0,0};
	
	//calculate size
	for (unsigned int i = 0; i < veld.size(); i++){
		if (veld[i] == 0){
			size++;
		}
	}
	//calculate per vakje
	
	for (unsigned int i = 0; i < veld.size(); i++){
		if (veld[i] == 0){
			veld[i] = 1;
			diepteMinMax = {{}, {}};
			move(veld, diepteMinMax, 0, size-1, 0);
			//calculate eerste route win
			
			int maxMin = diepteMinMax[0][0];
			for (unsigned int j=1; j < diepteMinMax[0].size(); j++){
				if (maxMin > diepteMinMax[0][j]){
					maxMin = diepteMinMax[0][j];
				}
			}
			//calculate eerste route verlies
			
			int maxMax = diepteMinMax[1][0];
			for (unsigned int j=1; j < diepteMinMax[1].size(); j++){
				if (maxMax > diepteMinMax[1][j]){
					maxMax = diepteMinMax[1][j];
				}
			}
			cout << "\n" << i<< ' ' << maxMax - maxMax;
			minLijst.push_back({i, maxMax - maxMax});
		}
		
	}
	cout << minLijst[0][1];
}




