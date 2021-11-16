#include "file_ch.hpp"
class filech : public File_ch
{
public:
     filech(GLuint programid)
     {
          filech::programid = programid;
          imageid = 0;
          data = charge_image();
     };
     ~filech(){};

     const unsigned char *charge_image()
     {

          //generate texture id
           glGenTextures(1,&imageid);
           glBindTexture(GL_TEXTURE_2D,imageid);

          if (!i.loadFromFile(containerpath))
               std::cout << "failed to load " << containerpath;
          i.flipVertically();
          const unsigned char *data = i.getPixelsPtr();

          GLuint width = 0;
          GLuint height = 0;
          width = i.getSize().x;
          height = i.getSize().y;

          if (data == nullptr)
               std::cout << "error reading file";
          glTexImage2D(
              GL_TEXTURE_2D,
              0,
              GL_RGB,
              width,
              height,
              0,
              GL_RGBA,
              GL_UNSIGNED_BYTE,
              data);
          glGenerateMipmap(GL_TEXTURE_2D);
  
          return data;
     }
     void bindTexture()
     {
          //filtrado trilinear 
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);

          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

          glActiveTexture(GL_TEXTURE0);
          glBindTexture(GL_TEXTURE_2D, imageid);
     }
};