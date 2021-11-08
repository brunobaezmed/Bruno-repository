#include "SFML/Window.hpp"
#include "textures/triangle.cpp"
class wind
{
private:  
     sf::Window w1;
     sf::ContextSettings settings;


public:   
     wind()
     {    
          settings.antialiasingLevel = 8;
          w1.create(sf::VideoMode(900, 720), "OpenGl",sf::Style::Default,settings);
          w1.setVerticalSyncEnabled(true);
          
     
     };
     ~wind() {}

     void start_()
     {
          
          w1.setActive(true);
          sf::Event event;
          LoadShaders();      
          while (w1.isOpen())
          {

               while (w1.pollEvent(event))
               {
                    if (event.type == sf::Event::Closed)
                         w1.close();
               }
               
               triangle();
               
              w1.display();
          }
     }
};
void run()
{
     wind w1;
     w1.start_();
}