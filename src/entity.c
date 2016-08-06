#include <stdio.h>
#include <GLFW/glfw3.h>
#include "entity.h"
#include "vector.h"
#include "math.h"
#include "state.h"

void entityUpdate(State* state, Entity* e, float dt) {
  e->pos.x += e->vel.x * dt;
  e->pos.y += e->vel.y * dt;
  e->vel.x += e->acc.x * dt + .5f * e->acc.x * dt*dt;
  e->vel.y += e->acc.y * dt + .5f * e->acc.y * dt*dt;

  // Check if this is hitting the edge of the screen
  // Just reverse the speed for the moment, don't bother applying any
  // forces or anything fancy
  if (e->pos.x - e->rad < 0) {
    e->vel.x = -e->vel.x;
  }
  if (e->pos.x + e->rad > state->SCREEN_WIDTH) {
    e->vel.x = -e->vel.x;
  }
  if (e->pos.y - e->rad < 0) {
    e->vel.y = -e->vel.y;
  }
  if (e->pos.y + e->rad > state->SCREEN_HEIGHT) {
    e->vel.y = -e->vel.y;
  }
}

void renderEntity(Entity* e) {
  // Only 1 type of entity. Just draw a circle.
  // Assume glBegin is set to GL_TRIANGLES.
  int i = 0;
  static const int circleSegments = 120;
  glColor3f(1, 1, 1);
  for (; i < circleSegments; ++i) {
    float angle1 = 2*M_PI*((float)i/(float)circleSegments);
    float angle2 = 2*M_PI*((float)(i+1)/(float)circleSegments);
    glVertex2f(e->pos.x, e->pos.y);
    glVertex2f(e->pos.x + e->rad*cos(angle1),
               e->pos.y + e->rad*sin(angle1));
    glVertex2f(e->pos.x + e->rad*cos(angle2),
               e->pos.y + e->rad*sin(angle2));
  }
}

