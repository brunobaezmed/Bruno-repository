/*#ifndef load_shader_
#define load_shader_
#include "textures.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
class ShaderLoader{
public:
     GLuint ID;
     ShaderLoader(){

     }
     ~ShaderLoader(){};
     void LoadShaders(const char * vertex_file_path,const char *fragment_file_path){
        
     };
     void use();
     void setBool(const std::string &name,bool value)const;
     void setInt(const std::string  &name,int value) const;
     void setFloat(const std::string &name, float value) const;
     
};

#endif**/