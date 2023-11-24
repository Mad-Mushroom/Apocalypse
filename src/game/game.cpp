#include "game.h"

Object TestObj("Obj");
Object TestPlatform("Platform");
Object STestPlatform("2Platform");

void Init(){
    CreateWindow(1280, 720, "Apocalypse");

    Physics.SetupPhysics(9.81);

    TestObj.Texture = LoadTexture("placeholder.png");
    TestObj.Position = {0,0};
    TestObj.Size = {100,100};
    TestPlatform.Texture = LoadTexture("placeholder.png");
    TestPlatform.Position = {0, 700};
    TestPlatform.Size = {1280, 100};
    STestPlatform.Texture = LoadTexture("placeholder.png");
    STestPlatform.Position = {0, 200};
    STestPlatform.Size = {200, 100};

    Objects.AddObject(TestObj);
    Objects.AddObject(TestPlatform);
    Objects.AddObject(STestPlatform);

    Objects.Objects.at(0).Physics.Gravitation = true;
    Objects.Objects.at(0).Physics.Mass = 0.1;

    Physics.AddForceToObject(0, 100, 2, Directions::Right);
}

void Update(){
    BeginDrawing();
    ClearBackground(BLUE);

    Physics.CalculatePhysics();

    Objects.DrawAllObjects();

	EndDrawing();
}