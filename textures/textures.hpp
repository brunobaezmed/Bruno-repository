#ifndef makew_render
#define makew_render
#include "../libs/GL/glew.h"
#include "../libs/GL/freeglut.h"
#include "SFML/Graphics.hpp"
#include "../window.hpp"
class textures{
public:
GLuint textureID;
const char* image_path;
     textures();

     ~textures(){};
     
      void VAO(){};
      void triangle(){};
      GLuint loadTexTr(const char *image_path);
      void DrawTriangle(GLuint &vertexbuffer,float &time,GLuint &shaderProgram);
      void VAO2();
};
#endif