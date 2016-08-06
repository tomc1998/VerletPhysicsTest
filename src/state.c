#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "entity.h"
#include "state.h"

void initState(State* state, int screenWidth, int screenHeight) {
  state->SCREEN_WIDTH = screenWidth;
  state->SCREEN_HEIGHT = screenHeight;
  state->endflag = 0;
  
  state->numEntities = 0;
  state->maxNumEntities = 32;
  state->entityList =
    (Entity**)malloc(sizeof(Entity*)*state->maxNumEntities);

  int i;
  for (; i < state->maxNumEntities; ++i) {
    state->entityList[i] = NULL;
  }
}

void stateUpdate(State* state, float dt) {
  int i;
  for (; i < state->numEntities; ++i) {
    entityUpdate(state, state->entityList[i], dt);
  }
}

void addEntity(State* state, Entity* e) {
  if (state->numEntities < state->maxNumEntities) {
    state->entityList[state->numEntities] = e;
    ++ state->numEntities;
  }
  else {
    printf("NO MORE ENTITY SPACE, REMEMBER TO IMPLEMENT THE ALLOCATION %s",
           "MORE SPACE FUNCTIONS FOR THE LIST OF ENTITIES IN state.c\n");
  }
}
