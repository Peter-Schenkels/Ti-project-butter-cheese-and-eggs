#include <iostream>
#include <vector>
using namespace std;


void transform(vector<char> & noots){
	vector<int> newList = {};
	for(int i =1; i < noots.size(); i++){
		if noots[i] == c{
			newList.push_back(1);
		}
		if noots[i] == d{
			newList.push_back(2);
		}
		if noots[i] == e{
			newList.push_back(3);
		}
		if noots[i] == f{
			newList.push_back(4);
		}
		if noots[i] == g{
			newList.push_back(5);
		}
		if noots[i] == a{
			newList.push_back(6);
		}
		if noots[i] == b{
			newList.push_back(7);
		}
		if noots[i] == c8{
			newList.push_back(8);
		}
		if noots[i] == d8{
			newList.push_back(9);
		}
		if noots[i] == e8{
			newList.push_back(10);
		}
		if noots[i] == f8{
			newList.push_back(11);
		}
		if noots[i] == g8{
			newList.push_back(12);
		}
		if noots[i] == a8{
			newList.push_back(13);
		}
		if noots[i] == b8{
			newList.push_back(14);
		}
		if noots[i] == c16{
			newList.push_back(15);
		}
	}
	return
}
vector<int> piano(const vector<int> & noots){
	
	vector<int> tweedeList = {};
	
	for(int i =1; i < noots.size(); i++){
		tweedeList.push_back(noot[i+1]-noots[i]);
	}
	return tweedelist;
}
