#ifndef STATE_H
#define STATE_H
#include <GLFW/glfw3.h>
#include "entity.h"

typedef struct Entity Entity;
typedef struct State State;
struct State {
  int SCREEN_WIDTH, SCREEN_HEIGHT;
  int endflag;
  int numEntities;
  int maxNumEntities;
  Entity** entityList;
};

// Initialises some state
void initState(State* state, int screenWidth, int screenHeight);

void stateUpdate(State* state, float dt);

void addEntity(State* s, Entity* e);

#endif
