#ifndef wind__mer
#define wind__mer
#include "SFML/Window.hpp"
#include "textures/Vertexs.cpp"
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
     
};
const char *vertexpath = "/home/bruno/Projects/appwind/textures/Svertexshader.vertexshader";
const char *fragmentpath = "/home/bruno/Projects/appwind/textures/Fragmentshader.fragment";
const char *containerpath = "/home/bruno/Downloads/container.jpg";
#endif