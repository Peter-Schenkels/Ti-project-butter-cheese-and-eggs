#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

int move(vector<int> speelveldt, int diepte, int size){
	vector<int> speelveld = speelveldt;
	bool beurt;
	int a = 0;
	
	if (diepte%2== 0){
		beurt = 1;
	}
	else{
		beurt = 0;
	}
	cout << "beurt: " << beurt << "\n";
	
	cout << diepte << "\n";
	//computer is 0 maar speelding is 1
	
	
	if (beurt == 0){
		
		for(unsigned int i =0; i < 9;  i++){
			if(speelveld[i] == 0){
				speelveld[i] = 1;
				for (int j = 0; j < 9; j++){
					if (j%3 == 0){
						
						cout << "\n";
					}
					cout << speelveld[j];
				}
				cout << "\n";
				if (speelveld[0] == 1 && speelveld[1] == 1 && speelveld[2] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000); return 10;}
				if (speelveld[3] == 1 && speelveld[4] == 1 && speelveld[5] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}
				if (speelveld[6] == 1 && speelveld[7] == 1 && speelveld[8] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}
					
				if (speelveld[0] == 1 && speelveld[4] == 1 && speelveld[8] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}
				if (speelveld[6] == 1 && speelveld[4] == 1 && speelveld[2] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}

				if (speelveld[0] == 1 && speelveld[3] == 1 && speelveld[6] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}
				if (speelveld[1] == 1 && speelveld[4] == 1 && speelveld[7] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}
				if (speelveld[2] == 1 && speelveld[5] == 1 && speelveld[8] == 1){ cout << "diepte: " << diepte << "\n"; Sleep(1000);return 10;}
				a = a + move(speelveld, diepte+1, size-1);
				
				
				}
				cout << "volgende gay";
			}
			return a;
		}
	//speler is 1 maar speelding is 2
	else if (beurt == 1){
		for(unsigned int i =0; i < 9;  i++){
			if(speelveld[i] == 0){
				speelveld[i] = 2;
				
				for (int j = 0; j < 9; j++){
					if (j%3 == 0){
						
						cout << "\n";
					}
					cout << speelveld[j];
				}
				cout << "\n";
				if (speelveld[0] == 2 && speelveld[1] == 2 && speelveld[2] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				if (speelveld[3] == 2 && speelveld[4] == 2 && speelveld[5] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				if (speelveld[6] == 2 && speelveld[7] == 2 && speelveld[8] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				
				if (speelveld[0] == 2 && speelveld[4] == 2 && speelveld[8] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				if (speelveld[6] == 2 && speelveld[4] == 2 && speelveld[2] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				
				if (speelveld[0] == 2 && speelveld[3] == 2 && speelveld[6] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				if (speelveld[1] == 2 && speelveld[4] == 2 && speelveld[7] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				if (speelveld[2] == 2 && speelveld[5] == 2 && speelveld[8] == 2){ Sleep(1000);cout << "diepte: " << diepte << "\n";return -10;}
				a = a + move(speelveld, diepte+1, size-1);
				
			}
			
		}
		return a;
		
	}
	return a;
}

int main(){
	
	int size = 0;
	
	vector<vector<int>> diepteMinMax = {{}, {}};
	vector<vector<int>> minLijst = {};
	
	vector<int> veld = {0,0,0,
						0,0,0,
	0,0,0};
	
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
			minLijst.push_back({i, move(veld, 0, size-1)});
			
			
		}
		
	}
	for(int i =0; i < minLijst.size(); i++){
		
		cout << minLijst[i][1] << " " << minLijst[i][0] << ": ";
		
	}

}




