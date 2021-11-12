#include "textures.hpp"
#include "iostream"
textures::textures(){
     textureID = 0;
};



GLuint textures:: loadTexTr(const char * image_path)
{    


     glGenTextures(1,&textureID);
     glBindTexture(GL_TEXTURE_2D,textureID);

  
     //filtrado trilinear
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_REPEAT);
     
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   
    
     return textureID;

     }

