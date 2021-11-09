#include "SFML/Window.hpp"
#include "textures/textures.cpp"
#include "textures/Vertexs.cpp"
class wind
{
private:  
     sf::RenderWindow w1;
     sf::ContextSettings settings;


public:   
     wind()
     {    
          settings.antialiasingLevel = 8;
          w1.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "OpenGl",sf::Style::Default,settings);
          w1.setVerticalSyncEnabled(true);
          
     
     };
     ~wind() {}

     void start_()
     {
          
      
          sf::Event event;
          sf::CircleShape circ(36.5f);
          sf::RectangleShape rectangle(sf::Vector2f(5.0f,50.f));
          sf::Text t;
         
          sf::Font f ;
          f.loadFromFile("/usr/share/fonts/adobe-source-code-pro/SourceCodePro-Bold.otf");
          t.setFont(f);
          t.setString("23");
          t.setCharacterSize(24);

          
          rectangle.setFillColor(sf::Color::White);
          rectangle.setRotation(60.0f);
          rectangle.setPosition(850.0f,100.0f);
          circ.setFillColor(sf::Color::Green);
          circ.setPosition(840.0f,50.0f);
          t.setPosition(860.0f,65.5f);
          while (w1.isOpen())
          {

               while (w1.pollEvent(event))
               {
                    if (event.type == sf::Event::Closed)
                         w1.close();
                         
               }
               
              w1.clear();
              w1.draw(rectangle);
              w1.draw(circ);
              w1.draw(t);
              w1.display();
          }
     }
};
void run()
{
     wind w1;
     w1.start_();
}