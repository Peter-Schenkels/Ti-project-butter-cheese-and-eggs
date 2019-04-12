#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//kijkt of er een mogelijkheid is om te winnen na 1 move
int whichToFillIn(const vector<vector<int>> &winningSets, const vector<int> &chanceVector, const vector<int> &playfield, int winMove) {
	for (unsigned int i=0; i<winningSets[winMove].size(); i++) {
		for (unsigned int j=0; j<chanceVector.size(); j++) {
			if (winningSets[winMove][i] == chanceVector[j]) {
				break;
			} else if (j+1 == chanceVector.size()) {
				if (playfield[winningSets[winMove][i]-1] == 0) {
					return winningSets[winMove][i];
				}
				return 0;
			}
		}
	}
}

//gaat het speelveld af om te kijken of er iemand heeft gewonnen of bijna (na 1 move) en baseerd daar zijn move op.
//NOTE: hierbij is -1 dat human heeft gewonnen, 0 als de robot heeft gewonnen en 1 t/m 9 index van het speelveld.
vector<int> checkMoves(const vector<vector<int>> & winningSets, const vector<int> & playfield) {
	vector<int> vectorRobot = {};
	vector<int> vectorHuman = {};
	int drawProtect = 0;
	
	for (unsigned int i=0; i<playfield.size(); i++) {
		if (playfield[i] == 1) {
			vectorRobot.push_back(i+1);
			drawProtect++;
		} else if (playfield[i] == 2) {
			vectorHuman.push_back(i+1);
			drawProtect++;
		}
	}
	
	if (drawProtect == 9) {
		return {-2, -2};
	}
	
	int indexWinRobot = -1;
	int indexWinHuman = -1;
	
	for (unsigned int i=0; i<winningSets.size(); i++) {
		int goodMovesRobot = 0;
		int goodMovesHuman = 0;
		
		for (unsigned int j=0; j<winningSets[i].size(); j++) {
			for (unsigned int q=0; q<vectorRobot.size(); q++) {
				if (vectorRobot[q] == winningSets[i][j]) {
					goodMovesRobot++;
				}
			}
			for (unsigned int q=0; q<vectorHuman.size(); q++) {
				if (vectorHuman[q] == winningSets[i][j]) {
					goodMovesHuman++;
				}
			}
		}
		if (goodMovesRobot == 2) {
			if (whichToFillIn(winningSets, vectorRobot, playfield, i) > 0) {
				indexWinRobot = whichToFillIn(winningSets, vectorRobot, playfield, i);
			} else {
				continue;
			}
		} else if (goodMovesHuman == 2) {
			if (whichToFillIn(winningSets, vectorHuman, playfield, i) > 0) {
				indexWinHuman = whichToFillIn(winningSets, vectorHuman, playfield, i);
			} else {
				continue;
			}
		} else if (goodMovesHuman >= 3 || goodMovesRobot >= 3) {
			if (goodMovesRobot >=3) {
				return {0, -1};
			}
			return {-1, 0};
		}
	}
	return {indexWinRobot, indexWinHuman};
}

//hoofdfunctie die de info van checkMoves inleest en uitvoer geeft aan de main op een leesbare manier
int move(const vector<vector<int>> & winningSets, const vector<int> & playfield) {
	vector<int> chanceMoves = checkMoves(winningSets, playfield);
	if (chanceMoves[0] > 0) {
		return chanceMoves[0];
	} else if (chanceMoves[1] > 0) {
		return chanceMoves[1];
	} else if (chanceMoves[0] == -1 && chanceMoves[1] == -1) {
		vector<int> emptyPlaces = {};
		for (unsigned int i=0; i<playfield.size(); i++) {
			if (playfield[i] == 0) {
				emptyPlaces.push_back(i+1);
			}
		}
		srand(time(NULL));
		int random_number = rand()%emptyPlaces.size();
		return emptyPlaces[random_number];
	} else if (chanceMoves[0] == 0) {
		return 0;
	} else if (chanceMoves[1] == 0) {
		return -1;
	}
	return -2;
}

int main(){
	// alle mogelijkheden om te winnen
	vector<vector<int>> winningSets = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{1, 4, 7},
		{2, 5, 8},
		{3, 6, 9},
		{1, 5, 9},
		{3, 5, 7}
	};
	
	// The grid
	// |1|2|3|
	// |4|5|6|
	// |7|8|9|
	// {Speler (0 = geen, 1 = robot, 2 = mens), Place (0 = geen gridplek, 1 t/m 9 = in de grid)}
	vector<int> playfield = {
		2,1,1,
		1,1,2,
		2,2,1
	};
	
	int bestMove = move(winningSets, playfield);
	if (bestMove > 0) {
		cout << "Gegeven move is: " << bestMove << '\n';
	} else if (bestMove == 0) {
		cout << "De robot heeft een jaimey royal op jouw gedaan.\n";
	} else if (bestMove == -1) {
		cout << "Jij hebt de robot ge-jaimey-royal'ed.\n";
	} else {
		cout << "Niemand heeft een EPIC jaimey royal gekregen.\n";
	}
}
