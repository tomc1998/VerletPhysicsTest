#include <stdio.h>
#include "state.h"
#include "entity.h"
#include "renderer.h"
#include "input_handler.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

GLFWwindow* window = 0;

// Initialises GLFW and sets up a GL context given a screen width and
// height in the state pointer
void initGLFW(State* state) {
  glfwInit();
  window = glfwCreateWindow(state->SCREEN_WIDTH, state->SCREEN_HEIGHT,
                            "Verlet Physics Test", NULL, NULL);
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyCallback);
  glfwSetMouseButtonCallback(window, mouseButtonCallback);
  glfwSetCursorPosCallback(window, cursorPosCallback);
}

int main(int argc, char** argv) {
  State state;
  initState(&state, 800, 450);
  setInputHandlerStateRef(&state);
  initGLFW(&state);
  initRenderer(&state);

  Entity* e0 = (Entity*) malloc(sizeof(Entity));
  Entity* e1 = (Entity*) malloc(sizeof(Entity));
  e0->pos.x = 100;
  e0->pos.y = 400;
  e0->acc.y = 50;
  e0->rad = 16;
  e1->pos.x = 200;
  e1->pos.y = 200;
  e1->rad = 16;
  addEntity(&state, e0);
  addEntity(&state, e1);

  while(!state.endflag) {
    // Update
    stateUpdate(&state, 0.016f);

    // render
    glClear(GL_COLOR_BUFFER_BIT);
    render(&state);
    glfwSwapBuffers(window);
    
    // Poll input
    glfwPollEvents();

    if (glfwWindowShouldClose(window)) {
      state.endflag = 1;
    }
  }

  return 0;
}
