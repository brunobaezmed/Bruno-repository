#include "ShaderLoader.hpp"
 shloader::shloader(){
          shloader::ID = ID;
     };

  void shloader:: LoadShaders(const char * vertexpath,const char * fragmentpath)
{


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
      

          const char* vShadercode = vertexCode.c_str();
          const char* fShadercode = fragmentCode.c_str();

          //compile
          GLint vertex,fragment,success;

          vertex = glCreateShader(GL_VERTEX_SHADER);
          glShaderSource(vertex,1,&vShadercode,NULL);
          glCompileShader(vertex);

          glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
          if(!success)std::cout<<"error compiling a shader";
          fragment = glCreateShader(GL_FRAGMENT_SHADER);
          glShaderSource(fragment,1,&fShadercode,NULL);
          glCompileShader(fragment);

          glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
          if(!success)std::cout<<"error compiling a shader";
          
          ID = glCreateProgram();
          glAttachShader(ID,vertex);
          glAttachShader(ID,fragment);
          glLinkProgram(ID);
          glGetProgramiv(ID,GL_LINK_STATUS,&success);
          if(!success)std::cout<<"error linking a shader";

          glDeleteShader(vertex);
          glDeleteShader(fragment);

     }
     //use programy
  void  shloader:: use(){
          glUseProgram(ID);
     }
  void shloader:: setBool(const std::string &name,bool value){
          glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);

     };
  void shloader:: setInt(const std::string  &name,int value) {
          glUniform1i(glGetUniformLocation(ID,name.c_str()),value);  
     };
   void shloader::setFloat(const std::string &name, float value) {
          glUniform1f(glGetUniformLocation(ID,name.c_str()),value);  

     };
  void shloader:: setVec3(const std::string &name,float x,float y ,float z){
          glUniform3f(glGetUniformLocation(ID,name.c_str()),x,y,z);
  };
  void shloader:: setVec3(const std::string &name,glm::vec3 &value){
          glUniform3fv(glGetUniformLocation(ID,name.c_str()),1, &value[0]);
  };


  void shloader::setMat4(const std::string &name,glm::mat4 &value){
          glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);

  }
    

