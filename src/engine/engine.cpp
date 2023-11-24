#include "engine.h"

using namespace std;

ConsoleClass Console;
ObjectsClass Objects;
PhysicsClass Physics;

void CreateWindow(int SizeX, int SizeY, string Title){
	InitWindow(SizeX, SizeY, Title.c_str());
	SetTargetFPS(144);
}

int main(){
    Init();
	while (!WindowShouldClose()){
		Update();
	}
	CloseWindow();
    return 0;
}