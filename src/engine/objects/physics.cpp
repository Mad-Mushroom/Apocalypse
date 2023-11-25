#include "physics.h"

void PhysicsClass::SetupPhysics(float gForce){
    gravitationForce = gForce;
}

void PhysicsClass::CalculatePhysics(){
    for(int i=0; i<Objects.ObjectCount; i++){
        if(Objects.Objects.at(i).Physics.Gravitation == true && !CheckIfObjectIsColliding(i)) Objects.Objects.at(i).Position.y += Objects.Objects.at(i).Physics.Mass * gravitationForce;
    }
}

bool PhysicsClass::CheckIfObjectIsColliding(int ObjIndex){
    for(int i=0; i<Objects.ObjectCount; i++){
        if(Objects.Objects.at(i).Name == Objects.Objects.at(ObjIndex).Name) continue;
        if(!Objects.Objects.at(i).Physics.Collision || !Objects.Objects.at(ObjIndex).Physics.Collision) return false;
        if(Objects.Objects.at(ObjIndex).Position.y + Objects.Objects.at(ObjIndex).Size.y >= Objects.Objects.at(i).Position.y && Objects.Objects.at(ObjIndex).Position.y <= Objects.Objects.at(i).Position.y + Objects.Objects.at(i).Size.y){
            if(Objects.Objects.at(ObjIndex).Position.x + Objects.Objects.at(ObjIndex).Size.x >= Objects.Objects.at(i).Position.x && Objects.Objects.at(ObjIndex).Position.x <= Objects.Objects.at(i).Position.x + Objects.Objects.at(i).Size.x){
                return true;
            }
        }
    }
    return false;
}

void PhysicsClass::AddForceToObject(int ObjIndex, float force, float duration, Directions direction){
    
}