#include "textures.hpp"
#include "../etc/matrixl.hpp"
glm::mat4 matrixQ(double &prevrt,float &rotation)
{

     glm:: mat4 transform = glm::mat4(1.0f);
    //identity matrix
     glm::mat4 modelmat = glm::mat4(1.0f);
     glm::mat4 view = glm::mat4(1.0f);
     glm::mat4 proj = glm::mat4(1.0f);
     
     modelmat = glm::rotate(modelmat,glm::radians(rotation),glm::vec3(0.0f,1.0f,0.0f));
     view = glm::translate(view,glm::vec3(0.0f,-0.5f,-2.0f));
     proj = glm::perspective(glm::radians(45.0f)
                            ,4.0f/3.0f
                            ,0.1f
                            ,100.0f);

     
     transform = modelmat * view * proj;
     
     return transform;
    


};
void LoadShaders()
{

  
     //create shaders
   

     
     

}

void triangle()
{
}
