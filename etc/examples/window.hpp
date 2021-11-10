#ifndef wind__mer
#define wind__mer
#include "SFML/Window.hpp"
#include "textures/textures.cpp"
#include "textures/Vertexs.cpp"
#define STB_IMAGE_IMPLEMENTATION
#include "libs/stb_image.h"
#include "iostream"
#include "SFML/OpenGL.hpp"

class wind
{
private:  
     sf::RenderWindow w1;
     sf::Clock clk;
public:   
     wind(){};
     ~wind(){};
     void start_(){};
     void run(){};
};
const char *vertexpath = "/home/bruno/Projects/appwind/textures/Svertexshader.vertexshader";
const char *fragmentpath = "/home/bruno/Projects/appwind/textures/Fragmentshader.fragmentshader";
const char *containerpath = "/home/bruno/Downloads/container.png";
#endif