#ifndef tree__
#define tree__
#include "SFML/Graphics.hpp"
#include <memory>
namespace trg{
constexpr float radius = 50.0f;
class treeG
{ 

public:
     sf::CircleShape circlesimple;
     sf::RectangleShape line;
     sf::Text t;
     sf::Font f;
     float x,y;  
     std::unique_ptr<sf::CircleShape> circle;
     std::unique_ptr<sf::RectangleShape> li;
    

     treeG()
     {    
         
     };
     ~treeG(){};
     virtual int DrawCircle(sf::CircleShape &circle);
     virtual int DrawLine(sf::RectangleShape);
     virtual float getcoordinates(float x, float y);
     virtual void setkey(long &key,char &value);
     };
}
#endif