#include "textures.hpp"
sf::Vertex vertex(){

 sf::Vertex v;
 v.position = sf::Glsl::Vec3(20.0f,20.0f,1.0f);
 v.color = sf::Color::Green;
 v.texCoords = sf::Vector2f(100.f,100.f);
 return v;

}
std::vector<sf::Vertex> varray(float &x){
     std::vector<sf::Vertex> v1;
  
     v1.push_back(sf::Vertex(sf::Vector2f(20.f+x,100.f+x),sf::Color::Green,sf::Vector2f(100.f,100.f)));
     v1.push_back(sf::Vertex(sf::Vector2f(200.f+x,60.f+x),sf::Color::Red,sf::Vector2f(20.f,20.f)));
     v1.push_back(sf::Vertex(sf::Vector2f(20.f+x,400.f+x),sf::Color::Blue,sf::Vector2f(50.f,50.f)));

     
     
     return v1;
}