#include "engine.h"

void CreateWindow(int SizeX, int SizeY, string Title){
    InitWindow(SizeX, SizeY, Title.c_str());
	SetTargetFPS(144);
	rlImGuiSetup(true);
}

int main(int argc, char* argv[]){
    Init();
	while (!WindowShouldClose()){
        Update();
	}
	rlImGuiShutdown();
	CloseWindow();
    return 0;
}