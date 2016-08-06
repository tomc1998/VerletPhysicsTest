#ifndef ENTITY_H
#define ENTITY_H
#include "vector.h"
#include "state.h"

typedef struct State State;
typedef struct Entity Entity;

struct Entity {
  Vector2f pos;
  Vector2f vel;
  Vector2f acc; // accel
  float mass;
  float rad;
};

void entityUpdate(State* state, Entity* e, float dt);

#endif
