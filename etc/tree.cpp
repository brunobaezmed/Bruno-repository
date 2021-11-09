#include "treeG.hpp"
#include "/home/bruno/Documents/c c++/lib/Trees/RBT/RedBlackTreeL.h"
using namespace trg;
class treeb:public treeG{
public:
     treeb(){
                      
          f.loadFromFile("/usr/share/fonts/adobe-source-code-pro/SourceCodePro-Bold.otf");
          t.setFont(f);
          t.setCharacterSize(24);

          line = sf::RectangleShape(sf::Vector2f(20.f, 5.f));
          

     };
     ~treeb(){};

           

     virtual int DrawCircle(sf::CircleShape &circle);
     virtual int DrawLine(sf::RectangleShape);
     virtual float getcoordinates(float x, float y);
     virtual void setkey(long &key,string &value);

};




int main(int argc,char *argvv[]){
     RedBlackTree<int,string> t;


}