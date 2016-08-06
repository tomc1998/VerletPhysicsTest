#include <stdio.h>
#include <GLFW/glfw3.h>
#include "renderer.h"
#include "state.h"

void initRenderer(State* state) {
  glClearColor(1, 0, 0, 1);

  glViewport(0, 0, state->SCREEN_WIDTH, state->SCREEN_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, state->SCREEN_WIDTH, state->SCREEN_HEIGHT, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void render(State* state) {
  glBegin(GL_TRIANGLES);
  int ii = 0;
  printf("Hey\n");
  for (; ii < state->numEntities; ++ii) {
    Entity* e = state->entityList[ii];
    if (e) {
      renderEntity(e);
    }
  }
  glEnd();
}
