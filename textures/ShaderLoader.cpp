#include "ShaderLoader.hpp"
#include "textures.hpp"
#include "iostream"
#include "sstream"
#include "fstream"
class Shaderloader: public ShaderLoader{
 public:    
     void Shader(const char *vertexpath,const char *fragmentpath){

          std::string vertexCode;
          std::string fragmentCode;
          std::ifstream vShaderFile;
          std::ifstream fShaderFile;
          vShaderFile.exceptions(std::ifstream::failbit  |std::ifstream::badbit);
          fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
       try{
            //open files
        vShaderFile.open(vertexpath);
        fShaderFile.open(fragmentpath);
        std::stringstream vShaderStream,fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();


       }catch(std::ifstream::failure e){
            std::cout<<"shader not loaded";
       }
       compileShader(vertexCode,fragmentCode);
     };
     void compileShader(std::string &vertexCode,std::string &fragmentCode){
          const char* vShadercode = vertexCode.c_str();
          const char* fShadercode = fragmentCode.c_str();

          //compile
          GLuint vertex,fragment;

          vertex = glCreateShader(GL_VERTEX_SHADER);
          glShaderSource(vertex,1,&vShadercode,NULL);
          glCompileShader(vertex);
    
          fragment = glCreateShader(GL_FRAGMENT_SHADER);
          glShaderSource(fragment,1,&fShadercode,NULL);
          glCompileShader(fragment);

          ID = glCreateProgram();
          glAttachShader(ID,vertex);
          glAttachShader(ID,fragment);

          glLinkProgram(ID);

          glDeleteShader(vertex);
          glDeleteShader(fragment);

     }
     void use(){
          glUseProgram(ID);
     }
     void setBool(const std::string &name,bool value)const{
          glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);

     };
     void setInt(const std::string  &name,int value) const{
          glUniform1i(glGetUniformLocation(ID,name.c_str()),value);  
     };
     void setFloat(const std::string &name, float value) const{
          glUniform1f(glGetUniformLocation(ID,name.c_str()),value);  

     };
    

};
GLuint Shloader(const char *vertexpath,const char *fragmentpath){
      sf::Shader s1;
        s1.loadFromFile(vertexpath,fragmentpath);
     glm::mat4 projection    = glm::mat4(1.0f);
        s1.bind(&s1);
        s1.getNativeHandle();
        s1.setUniformArray("projection",&projection[0][0],16);
        return s1.getNativeHandle();
        
}
const unsigned char* imageloader(const char* path){
     sf::Image i;
     i.loadFromFile(containerpath);
     
     return i.getPixelsPtr();
}