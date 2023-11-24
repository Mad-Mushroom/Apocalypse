#pragma once

#include "../engine.h"

class PhysicsClass {
public:
    float gravitationForce;

    void SetupPhysics(float gravitationForce);
    void CalculatePhysics();
    bool CheckIfObjectIsColliding(int ObjIndex);
    bool CheckObjectCollision(int Obj1Index, int Obj2Index);
    void AddForceToObject(int ObjIndex, float force, float duration, Directions direction);
};

extern PhysicsClass Physics;