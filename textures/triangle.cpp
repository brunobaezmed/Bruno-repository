#include "triangle.hpp"
#include <vector>

void LoadShaders(){
     //create shaders
     if (!sf::Shader::isAvailable())
{
    std::cout<<"shaders are not available...";
}
     sf::Shader shader;
     std::vector<sf::Shader> vertices;
     if(!shader.loadFromFile("/home/bruno/Documents/c c++/appwind/textures/Svertexshader.vertexshader",sf::Shader::Vertex)){     
     std::cout<<"failed to load vertex";}
     
     if(!shader.loadFromFile("/home/bruno/Documents/c c++/appwind/textures/Fragmentshader.fragmentshader",sf::Shader::Fragment))
     std::cout<<"failed to load fragment";    
     
     shader.setUniform("fragLoopDuration",5.0f);
     shader.setUniform("time",10.0f);



     shader.bind(&shader);

}
   





void triangle(){

     //init loader
     if(glewInit() != GLEW_OK){
            
          
     }
     
     //get vertex id
     GLuint VertexArrayID;
     //
     glGenVertexArrays(1,&VertexArrayID);
     //create the buffer
     glBindVertexArray(VertexArrayID);
     //create shader
     

     //Array of 3 vectors 3 vertices
     static const GLfloat g_vertex_buffer_data[] = {
          -1.0f , -1.0f , 0.0f,
           1.0f , -1.0f , 0.0f,
           0.0f ,  1.0f , 0.0f,
     };
     //other id integer
     GLuint vertexbuffer;
     //generate 1 vertex buffer
     glGenBuffers(1,&vertexbuffer);
     //send to vertex buffer
     glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
     //give to opengl
     glBufferData(GL_ARRAY_BUFFER,sizeof(g_vertex_buffer_data),g_vertex_buffer_data,GL_STREAM_DRAW);
     //atributte vertices

     //use shader   



     glEnableVertexAttribArray(0);
     glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
     glVertexAttribPointer(
      0,
      3,
      GL_FLOAT,
      GL_FALSE,
      0,
      (void*)0 
     );
     glDrawArrays(GL_TRIANGLES,0,3);
     glDisableVertexAttribArray(0);

}

