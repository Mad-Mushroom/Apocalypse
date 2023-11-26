#include "game.h"

Object TestObj("Obj");
Object TestPlatform("Platform");
Object STestPlatform("2Platform");

void Init(){
    CreateWindow(1280, 720, "Apocalypse");

    Physics.SetupPhysics(9.81);

    TestObj.Texture = LoadTexture("res/game/placeholder.png");
    TestObj.Position = {0,0};
    TestObj.Size = {100,100};
    TestPlatform.Texture = LoadTexture("res/game/placeholder.png");
    TestPlatform.Position = {0, 700};
    TestPlatform.Size = {1280, 100};
    STestPlatform.Texture = LoadTexture("res/game/placeholder.png");
    STestPlatform.Position = {800, 600};
    STestPlatform.Size = {300, 100};

    Objects.AddObject(TestObj);
    Objects.AddObject(TestPlatform);
    Objects.AddObject(STestPlatform);

    Objects.Objects.at(0).Physics.Gravitation = true;
    Objects.Objects.at(0).Physics.Mass = 0.2;

    Physics.AddForceToObject(0, 1, 1, {1, 1});
}

void Update(){
    BeginDrawing();
    ClearBackground(BLUE);

    Physics.CalculatePhysics();

    Objects.DrawAllObjects();

    DrawText(to_string(Physics.CheckIfObjectIsCollidingVec(0).x).c_str(), 0, 0, 20, WHITE);
    DrawText(to_string(Physics.CheckIfObjectIsCollidingVec(0).y).c_str(), 0, 20, 20, WHITE);
    
    if(UserInput.KeyDown(KEY_A)) DrawText("Hello World", 0, 0, 20, WHITE);

	EndDrawing();
}