#include "physics.h"

void PhysicsClass::SetupPhysics(float gForce){
    gravitationForce = gForce;
}

void PhysicsClass::CalculatePhysics(){
    for(int i=0; i<Objects.ObjectCount; i++){
        if(Objects.Objects.at(i).Physics.Gravitation == true && !CheckIfObjectIsColliding(i)) Objects.Objects.at(i).Position.y += Objects.Objects.at(i).Physics.Mass * gravitationForce;
        if(Objects.Objects.at(i).Physics.ForcesCount > 0){
            for(int j=0; j<Objects.Objects.at(i).Physics.ForcesCount; j++){
                Objects.Objects.at(i).Physics.Forces.at(j).force = Objects.Objects.at(i).Physics.Forces.at(j).force/10;
                if(Objects.Objects.at(i).Physics.Forces.at(j).duration > 0){
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Left) Objects.Objects.at(i).Position.x -= Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Right) Objects.Objects.at(i).Position.x += Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Top) Objects.Objects.at(i).Position.x -= Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Bottom) Objects.Objects.at(i).Position.x += Objects.Objects.at(i).Physics.Forces.at(j).force;
                    Objects.Objects.at(i).Physics.Forces.at(j).duration = ((Objects.Objects.at(i).Physics.Forces.at(j).duration * 144) - 1) / 144;
                }else if(Objects.Objects.at(i).Physics.Forces.at(j).duration <= 0){
                    if(Objects.Objects.at(i).Physics.Forces.at(j).force > 0) Objects.Objects.at(i).Physics.Forces.at(j).force -= 144/Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Left) Objects.Objects.at(i).Position.x += Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Right) Objects.Objects.at(i).Position.x -= Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Top) Objects.Objects.at(i).Position.x += Objects.Objects.at(i).Physics.Forces.at(j).force;
                    if(Objects.Objects.at(i).Physics.Forces.at(j).direction == Directions::Bottom) Objects.Objects.at(i).Position.x -= Objects.Objects.at(i).Physics.Forces.at(j).force;
                }
            }
        }
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
    Objects.Objects.at(ObjIndex).Physics.Forces.push_back({force, direction, duration});
    Objects.Objects.at(ObjIndex).Physics.ForcesCount++;
}