#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "raylib.h"
#include "raymath.h"

#include "../imgui/imgui.h"
#include "../imgui/rlImGui.h"

using namespace std;

void CreateWindow(int SizeX, int SizeY, string Title);

void Init();
void Update();