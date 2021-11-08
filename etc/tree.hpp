#ifndef tree__
#define tree__
#include "SFML/Graphics.hpp"
class tree
{

private:
     sf::CircleShape circlesimple;
     sf::RectangleShape line;
     
public:
     tree()
     {
          tree::line = sf::RectangleShape(sf::Vector2f(20.f, 5.f));
     };
     virtual int DrawCircle(sf::CircleShape &circle);
     virtual int DrawLine(sf::RectangleShape);
     virtual float getcoordinates(float x, float y);
     virtual void setkey(long &key,char &value);
};

#endif