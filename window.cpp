#include "window.hpp"
#include "libs/GLMS/glm/glm/ext.hpp"
#include "textures/ShaderLoader.cpp"
#include "textures/textures.cpp"
#include "camera/camera.cpp"
class wind1 : public wind
{
public:
     sf::RenderWindow w1;
     sf::ContextSettings settings;
     sf::Clock clk;
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
     sf::Image i;
     sf::Event event;
     shloader s;
     vertex_ vert;

     glm::mat4 proj = glm::mat4(1.0f);
     proj = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
     glm::mat4 view = glm::mat4(1.0f);

     vert.VAO2();
     s.LoadShaders(vertexpath, fragmentpath);

     s.use();
     //////////////////////
     glm::vec3 Camera_Position = glm::vec3(0.0f, 0.0f, 1.0f);
     glm::vec3 Camera_front = glm::vec3(0.0, 0.0f, -1.0f);
     glm::vec3 camera_up = glm::vec3(0.0, 1.0f, 0.0f);
     glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
     /////////////////////////////
     if (!i.loadFromFile(containerpath))
          std::cout << "failed to load " << containerpath;
     i.flipVertically();
     const unsigned char *data = i.getPixelsPtr();

     GLuint width = 0;
     GLuint height = 0;
     width = i.getSize().x;
     height = i.getSize().y;

     if (data == nullptr)
          std::cout << "error";
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

     int nframes = 0;

     float lastime = wind.clk.getElapsedTime().asSeconds();
     float currentime = 0;
     float deltatime = 0;
     float FoV = 45.0f;
     const float speed = 3.0f;
     glBindVertexArray(vert.vertexbuffer);
     while (wind.w1.isOpen())
     {
          currentime = wind.clk.getElapsedTime().asSeconds();

          deltatime = float(currentime - lastime);

           lastime = currentime;
          while (wind.w1.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    wind.w1.close();
               if (event.type == sf::Event::KeyPressed)
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

                    proj = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
                    view = glm::lookAt(
                        Camera_Position,
                        Camera_Position + Camera_front,
                        up);

               }
          }

          glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

          glActiveTexture(GL_TEXTURE0);
          glBindTexture(GL_TEXTURE_2D, 0); ////////

          //identity matrix

          // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

          // retrieve the matrix uniform locations // pass them to the shaders (3 different ways)

          glBindVertexArray(vert.vertexbuffer);
          for (unsigned int l = 0; l < 10; ++l)
          {
               //calculate the model matrix for each object and pass it to shader before drawing
               glm::mat4 modelmat = glm::mat4(1.0f);

               modelmat = glm::translate(modelmat, vert.cubePositions[l]);
               float angle = 20.0f * l;
               ////
               // modelmat = glm::rotate(modelmat,glm::radians(angle),glm::vec3(1.0f,0.3f,0.5f));

               glm::mat4 MVP = proj * view * modelmat;

               s.setMat4("MVP", MVP);
               glDrawArrays(GL_TRIANGLES, 0, 36);
          }

          wind.w1.display();
     }
}
