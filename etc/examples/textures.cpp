#include "textures.hpp"
#include "../etc/matrixl.hpp"
glm::mat4 matrixq( float &prevrt,GLuint programid)
{

     glm:: mat4 transform = glm::mat4(1.0f);
    //identity matrix
     glm::mat4 modelmat = glm::mat4(1.0f);
     glm::mat4 view = glm::mat4(1.0f);
     glm::mat4 proj = glm::mat4(1.0f);
     
     modelmat = glm::rotate(modelmat,45.0f,glm::vec3(0.5f,1.0f,0.0f));
     view = glm::translate(view,glm::vec3(0.0f,0.0f,-3.0f));
     proj = glm::perspective(glm::radians(45.0f)
                            ,800.0f/600.0f
                            ,0.1f
                            ,100.0f);

     
     transform =   proj;
        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(programid, "model");
        unsigned int viewLoc  = glGetUniformLocation(programid, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelmat));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
     
     return transform;
    


};

GLuint woodenbox()
{    GLuint texture1;

     glGenTextures(1,&texture1);
     glBindTexture(GL_TEXTURE_2D,texture1);

     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_REPEAT);
     
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
     sf::Image i;
     i.loadFromFile("/home/bruno/Downloads/container.jpg");
     i.flipVertically();
     const unsigned char *data = i.getPixelsPtr();
     int width,height,channel;
     width = i.getSize().x;
     height = i.getSize().y;
     if(data){

          glTexImage2D(GL_TEXTURE_2D,
                         0,
                          GL_RGB,
                          width,
                          height,
                          0,
                          GL_RGB,
                          GL_UNSIGNED_BYTE,
                          data);

     }else std::cout<<"failed to load image";
     
     return texture1;

}

