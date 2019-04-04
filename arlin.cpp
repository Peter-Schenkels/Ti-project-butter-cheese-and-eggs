#include <iostream>
#include <vector>
using namespace std;

int move(bool beurt, int size, vector<int> & speelveldt, int pointer){
	vector<int> speelveld = speelveldt;
	if(beurt == 0){
		
		for(int i =pointer; i < 8; i++){
			
			speelveld[i] = 1;
			move(1, size-1, speelveld, pointer+1);
			
		}
		
	}
	if(beurt == 1){
		for(unsigned int i =pointer; i < 9; i++){
			if (speelveld[i] == 0){
				speelveld[i] = 2;
				for (unsigned int i=0; i < 9; i++){
						if(i%3 == 0){
							cout << "\n";
						}
						cout << speelveld[i];
						
						
					}
				cout << "\n";
			
				if (speelveld[0] == 2 && speelveld[1] == 2 && speelveld[2] == 2){cout << "Gewonnen";return 1;}
				if (speelveld[3] == 2 && speelveld[4] == 2 && speelveld[5] == 2){cout << "Gewonnen";return 1;}
				if (speelveld[6] == 2 && speelveld[7] == 2 && speelveld[8] == 2){cout << "Gewonnen";return 1;}
				
				if (speelveld[0] == 2 && speelveld[4] == 2 && speelveld[8] == 2){cout << "Gewonnen";return 1;}
				if (speelveld[6] == 2 && speelveld[4] == 2 && speelveld[2] == 2){cout << "Gewonnen";return 1;}
				
				if (speelveld[0] == 2 && speelveld[3] == 2 && speelveld[6] == 2){cout << "Gewonnen";return 1;}
				if (speelveld[1] == 2 && speelveld[4] == 2 && speelveld[7] == 2){cout << "Gewonnen";return 1;}
				if (speelveld[2] == 2 && speelveld[5] == 2 && speelveld[8] == 2){cout << "Gewonnen";return 1;}
				
				//mensen
				if (speelveld[0] == 1 && speelveld[1] == 1 && speelveld[2] == 1){cout << "Verloren";return 0;}
				if (speelveld[3] == 1 && speelveld[4] == 1 && speelveld[5] == 1){cout << "Verloren";return 0;}
				if (speelveld[6] == 1 && speelveld[7] == 1 && speelveld[8] == 1){cout << "Verloren";return 0;}
				
				if (speelveld[0] == 1 && speelveld[4] == 1 && speelveld[8] == 1){cout << "Verloren";return 0;}
				if (speelveld[6] == 1 && speelveld[4] == 1 && speelveld[2] == 1){cout << "Verloren";return 0;}
				
				if (speelveld[0] == 1 && speelveld[3] == 1 && speelveld[6] == 1){cout << "Verloren";return 0;}
				if (speelveld[1] == 1 && speelveld[4] == 1 && speelveld[7] == 1){cout << "Verloren";return 0;}
				if (speelveld[2] == 1 && speelveld[5] == 1 && speelveld[8] == 1){cout << "Verloren";return 0;}
				
				//Als speel veld vol is
				
				if(size == 0){
					return 2;
				}
			
				if (move(0, size-1, speelveld, pointer+1)){
					
					speelveldt[i] = 2;
				}
			}
		else{continue;}
					
					
					
					
				
				
			}
		
		}
		
	
	
	
}


int main(){
	vector<int> lol = {0,1,2,2,1,1,1,2,2};
	for (unsigned int i=0; i < 9; i++){
		if(i%3 == 0){
			cout << "\n";
			}
		cout << lol[i];
	}
	cout << "onnaangepast\n";
	move(true, 8, lol, 0);
	for (unsigned int i=0; i < 9; i++){
		if(i%3 == 0){
			cout << "\n";
			}
		cout << lol[i];
	}
	cout << "nieuwe move\n";
	
	
}



