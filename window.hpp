#include "SFML/Window.hpp"
#include "textures/textures.cpp"
#include "textures/Vertexs.cpp"


class wind
{
private:  
     sf::RenderWindow w1;
     sf::ContextSettings settings;
     sf::Clock clk;
public:   
     wind()
     {    
 
          w1.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "OpenGl",sf::Style::Default,settings);
          w1.setVerticalSyncEnabled(true);
          
     
     };
     ~wind() {}

     void start_()
     {

        float prevt = clk.getElapsedTime().asSeconds()+10.0f;
        std::cout<<prevt;
     
        sf::Event event;
         

          while (w1.isOpen())
          {

               while (w1.pollEvent(event))
               {
                    if (event.type == sf::Event::Closed)
                         w1.close();
                         
               }
               
              prevt = clk.restart().asSeconds()*1000.0f;
              w1.clear();
                      std::cout<<prevt<<"\t";

              w1.draw(&varray(prevt)[0],varray(prevt).size(),sf::Triangles);
              w1.display();
          }
     }
};
void run()
{
     wind w1;
     w1.start_();
}