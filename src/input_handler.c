#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "state.h"
#include "input_handler.h"

const int CONTROL_QUIT = GLFW_KEY_ESCAPE;

State* state = NULL;
int lmbDown = 0;
double mouseXPos, mouseYPos;

void keyCallback(GLFWwindow* window,
                 int key,
                 int scancode,
                 int action,
                 int mods) {
  if (key == CONTROL_QUIT) {
    state->endflag = 1;
  }
}

void mouseButtonCallback(GLFWwindow* window,
                           int button,
                           int action,
                           int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    lmbDown = 1;
  }
  else if (button == GLFW_MOUSE_BUTTON_LEFT &&
           action == GLFW_RELEASE) {
    lmbDown = 0;
  }
}

void cursorPosCallback(GLFWwindow* window,
                              double xpos,
                              double ypos) {
  mouseXPos = xpos;
  mouseYPos = ypos;
}

void setInputHandlerStateRef(State* _state) {
  state = _state;
}
