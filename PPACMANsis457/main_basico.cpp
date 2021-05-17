#include <iostream>
#include "GameManager.h"
#include "GameObject.h"
#include "map"
#include "Misc.h"

#include<vector>

using namespace std;
vector<GameObject*> gGameObjectList;



int main(int argc, char* argv[]) {

	bool quit = false;

	GameManager theApp;
	//While application is running
	while (!quit)
	{
		// Remove all objects marked for deletion from gameobjects vector
		for (unsigned int i = 0; i < gGameObjectList.size(); i++) {
			if (gGameObjectList[i]->ToDelete()) {
				delete gGameObjectList[i];
				removeFromVector(gGameObjectList, *gGameObjectList[i]);
			}
		}

		return theApp.onExecute();
	}

}