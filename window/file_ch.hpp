#ifndef file_ch
#define file_ch
#include "../libs/SFML/Graphics.hpp"
class File_ch{
public: 
     File_ch(){};
     ~File_ch(){};

     sf::Image i;
     GLuint imageid,programid;
     const unsigned char *data;
     const unsigned char *charge_image();



};
 #endif