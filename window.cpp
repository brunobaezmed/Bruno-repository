#include "window.hpp"
#include "libs/GLMS/glm/glm/ext.hpp"
#include "textures/ShaderLoader.cpp"
#include "textures/textures.cpp"
#include "camera/controls.cpp"
#include "window/filech.cpp"

class wind1 : public wind
{
public:
     sf::RenderWindow w1;
     sf::ContextSettings settings;
     sf::Clock clk;
     sf::Event event;
     wind1()
     {

          wind1::settings.depthBits = 24;
          wind1::settings.antialiasingLevel = 8;
          wind1::settings.Default;
          wind1::settings.sRgbCapable;
          wind1::settings.minorVersion = 4.6;
          w1.create(sf::VideoMode(1920, 1080), "OpenGl", sf::Style::Default, wind1::settings);
          w1.setVerticalSyncEnabled(true);
     };
     ~wind1() {}
};

void start_()
{
     wind1 wind;
     wind.w1.setActive(true);

     //initialize api
     glewInit();
     glEnable(GL_DEPTH_TEST);
     shloader s;
     s.LoadShaders(vertexpath, fragmentpath);
     filech f(s.ID);
     vertex_ vert(s.ID);

     f.charge_image();
     vert.VAO2();
     s.use();
     glm::mat4 proj = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
     glm::mat4 view = glm::mat4(1.0f);

     glm::mat4 ProjMatrix = glm::mat4(1.0f);
     glm::mat4 ViewMatrix = glm::mat4(1.0f);

     //////////////////////
     float lastime, deltatime, currentime;
     const float FoV = 45.0f;
     const float speed = 15.0f;
     const float mousespeed = 0.005f;
     glm::vec3 Camera_Position = glm::vec3(0.0f, 0.0f, 3.0f);
     glm::vec3 Camera_front = glm::vec3(0.0, 0.0f, -1.0f);
     glm::vec3 camera_up = glm::vec3(0.0, 1.0f, 0.0f);
     /////////////////////////////

     while (wind.w1.isOpen())
     {

          currentime = wind.clk.getElapsedTime().asSeconds();

          deltatime = (currentime - lastime);

          lastime = currentime;

          while (wind.w1.pollEvent(wind.event))
          {

               if (wind.event.type == sf::Event::Closed)
                    wind.w1.close();

               ///////////////////////////////////////////////
               if (wind.event.type == sf::Event::KeyPressed)
               {

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                         Camera_Position += Camera_front * deltatime * speed;
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {

                         Camera_Position -= glm::normalize(glm::cross(Camera_front, camera_up)) * deltatime * speed;
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                         Camera_Position += glm::normalize(glm::cross(Camera_front, camera_up)) * deltatime * speed;
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                         Camera_Position -= Camera_front * deltatime * speed;
                    }

                    ViewMatrix = glm::lookAt(
                        Camera_Position,
                        Camera_Position + Camera_front,
                        camera_up);
                    view = ViewMatrix;

               } ////////////////
          }

          glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          ////////
          f.bindTexture();

          for (unsigned int l = 0; l < 10; ++l)
          {
               //calculate the model matrix for each object and pass it to shader before drawing
               glm::mat4 modelmat = glm::mat4(1.0f);

               modelmat = glm::translate(modelmat, vert.cubePositions[l]);
               float angle = 20.0f * l;
               ////
               modelmat = glm::rotate(modelmat, glm::radians(angle) + wind.clk.getElapsedTime().asSeconds(), glm::vec3(1.0f, 0.3f, 0.5f));

               glm::mat4 MVP = proj * view * modelmat;

               s.setMat4("MVP", MVP);
               glDrawArrays(GL_TRIANGLES, 0, 36);
          }

          wind.w1.display();
     }
}
