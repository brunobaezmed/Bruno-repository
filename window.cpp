#include "window.hpp"
#include "textures/ShaderLoader.cpp"

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
          w1.create(sf::VideoMode(800, 600), "OpenGl",sf::Style::Default,wind1::settings);
          w1.setVerticalSyncEnabled(true);
     };
     ~wind1() {}
};

void start_()
{
     wind1 wind;
     wind.w1.setActive(true);

     sf::Shader s1;
     //initialize api
     glewInit();
     glEnable(GL_DEPTH_TEST);

     if (!s1.loadFromFile(vertexpath, fragmentpath))
          std::cout << "error loading shaders";
     glm::mat4 projection = glm::mat4(1.0f);
     s1.bind(&s1);

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
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };






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
     GLuint programid = s1.getNativeHandle();
     GLuint texture1, texture2;

     glGenTextures(1, &texture1);
     glBindTexture(GL_TEXTURE_2D, texture1);

     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     int width, height, channel;
     stbi_set_flip_vertically_on_load(true);
     unsigned char *data = stbi_load("/home/bruno/Downloads/container.jpg", &width, &height, &channel, 0);

     glTexImage2D(GL_TEXTURE_2D,
                  0,
                  GL_RGB,
                  width,
                  height,
                  0,
                  GL_RGB,
                  GL_UNSIGNED_BYTE,
                  data);
     glGenerateMipmap(GL_TEXTURE_2D);

     stbi_image_free(data);

     glGenTextures(1, &texture2);
     glBindTexture(GL_TEXTURE_2D, texture2);

     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     int width1, height1, channel1;

     data = stbi_load("/home/bruno/Downloads/awesomeface.png", &width1, &height1, &channel1, 0);

     glTexImage2D(GL_TEXTURE_2D,
                  0,
                  GL_RGB,
                  width1,
                  height1,
                  0,
                  GL_RGBA,
                  GL_UNSIGNED_BYTE,
                  data);

     glGenerateMipmap(GL_TEXTURE_2D);
     stbi_image_free(data);

     float prevt = wind.clk.getElapsedTime().asSeconds();
     glUseProgram(programid);
     glUniform1i(glGetUniformLocation(programid, "texture1"), 0);

     glUniform1i(glGetUniformLocation(programid, "texture2"), 1);

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
           
               
          }


          glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

          glActiveTexture(GL_TEXTURE0);
          glBindTexture(GL_TEXTURE_2D, texture1);
          glActiveTexture(GL_TEXTURE1);
          glBindTexture(GL_TEXTURE_2D, texture2);

          glUseProgram(programid);

          //identity matrix
          glm::mat4 view = glm::mat4(1.0f);

          prevt = wind.clk.getElapsedTime().asSeconds();

          view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

          // retrieve the matrix uniform locations // pass them to the shaders (3 different ways)

          

          glBindVertexArray(vertexbuffer);
          for(unsigned int l = 0 ; l < 10 ; ++l){
          //calculate the model matrix for each object and pass it to shader before drawing       
           glm::mat4 modelmat = glm::mat4(1.0f);

          modelmat = glm::translate(modelmat, cubePositions[l]);
          float angle = 20.0f * l;
          modelmat = glm::rotate(modelmat,glm::radians(angle)+prevt,glm::vec3(1.0f,0.3f,0.5f));

          glm::mat4 MVP = proj * view * modelmat;
          glUniformMatrix4fv(glGetUniformLocation(programid, "MVP"), 1, GL_FALSE, &MVP[0][0]);
        
          glDrawArrays(GL_TRIANGLES, 0, 36);

          }

          wind.w1.display();
     }
     glDeleteVertexArrays(1, &vertexbuffer);
     glDeleteBuffers(1, &vbo);
}

void run()
{

     start_();
}