#include "window.hpp"
#include "libs/GLMS/glm/glm/ext.hpp"
#include "textures/ShaderLoader.cpp"
#include "textures/textures.cpp"
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
          wind1::settings.minorVersion=4.6;
          w1.create(sf::VideoMode(1920, 1080), "OpenGl",sf::Style::Default,wind1::settings);
          w1.setVerticalSyncEnabled(true);
     };
     ~wind1() {}
};

void start_()
{
     wind1 wind;
     float prevtime = wind.clk.getElapsedTime().asSeconds();


     wind.w1.setActive(true);
     sf::Shader s1;
       
     //initialize api
     glewInit();
     glEnable(GL_DEPTH_TEST);

     shloader s;
     s.LoadShaders(vertexpath,fragmentpath);
     
     glm::mat4 projection = glm::mat4(1.0f);
     
     GLuint programid ;
     s.use();
     std::cout<<programid<<" "<<s.ID;
     float vertices[] = {
         -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
         -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
         0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
         0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
         -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

         -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
         -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
         -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
         -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

         // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 1.0f,  0.0f,  0.0f),
        glm::vec3(-1.0f,  0.0f,  0.0f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };//std::vect<glm::vec3> cubes;
    //cubes.push_back(glm::vec3(x,y,z));






     GLuint vertexbuffer, vbo;
     glGenVertexArrays(1, &vertexbuffer);
     glGenBuffers(1, &vbo);
     glBindVertexArray(vertexbuffer);
     glBindBuffer(GL_ARRAY_BUFFER, vbo);

     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

     glVertexAttribPointer(
         0,
         3,
         GL_FLOAT,
         GL_FALSE,
         5 * sizeof(float),
         (void *)0

     );
     glEnableVertexAttribArray(0);

     glVertexAttribPointer(
         1,
         2,
         GL_FLOAT,
         GL_FALSE,
         5 * sizeof(float),
         (void *)(3 * sizeof(float)));

     glEnableVertexAttribArray(1);


    
    
     sf::Image i;
     if(!i.loadFromFile(containerpath))std::cout<<"failed to load "<<containerpath;
     const unsigned char * data = i.getPixelsPtr() ;
     
     GLuint width = 0;
     GLuint height = 0;
     width = i.getSize().x;
     height = i.getSize().y;
     if(data == nullptr)std::cout<<"error";
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

     sf::Event event;
     glm::mat4 proj = glm::mat4(1.0f);

     proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

     glBindVertexArray(vertexbuffer);
     while (wind.w1.isOpen())
     {

          while (wind.w1.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    wind.w1.close();
               if(event.type == sf::Event::Resized)
                    wind.w1
               
          }


          glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

          glActiveTexture(GL_TEXTURE0);
          glBindTexture(GL_TEXTURE_2D, 0);////////     
       
          s.use();

          //identity matrix
          glm::mat4 view = glm::mat4(1.0f);

          prevtime = wind.clk.getElapsedTime().asSeconds();

          view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

          // retrieve the matrix uniform locations // pass them to the shaders (3 different ways)

          

          glBindVertexArray(vertexbuffer);
          for(unsigned int l = 0 ; l < 10 ; ++l){
          //calculate the model matrix for each object and pass it to shader before drawing       
           glm::mat4 modelmat = glm::mat4(1.0f);

          modelmat = glm::translate(modelmat, cubePositions[l]);
          float angle = 1.0f * l;
          ////
          //modelmat = glm::rotate(modelmat,glm::radians(angle),glm::vec3(1.0f,0.3f,0.5f));

          glm::mat4 MVP = proj * view * modelmat;
     
          s.setMat4("MVP",MVP);        
          glDrawArrays(GL_TRIANGLES, 0, 36);

          }

          wind.w1.display();
     }
     glDeleteVertexArrays(1, &vertexbuffer);
     glDeleteBuffers(1, &vbo);
}

