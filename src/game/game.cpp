#include "game.h"

void Init(){
    CreateWindow(1280, 720, "Apocalypse");
}

void Update(){
    BeginDrawing();
    ClearBackground(BLUE);

	rlImGuiBegin();

	rlImGuiEnd();
	EndDrawing();
}