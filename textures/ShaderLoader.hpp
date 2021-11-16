#ifndef LOAD_SHADER_HPP
#define LOAD_SHADER_HPP
#include "textures.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include "../libs/GLMS/glm/glm/glm.hpp"

class shloader{
public:
  
     GLuint ID;
      shloader();
      ~shloader(){};
     shloader(GLuint ID);
      void LoadShaders(const char * vertexpath,const char * fragmentpath);
      void use();
      void setBool(const std::string &name,bool value);
      void setInt(const std::string  &name,int value);
      void setFloat(const std::string &name, float value);
      void setVec3(const std::string &name,float x,float y ,float z);
      void setVec3(const std::string &name,glm::vec3 &value);
      void setMat4(const std::string &name,glm::mat4 &value);
};

#endif