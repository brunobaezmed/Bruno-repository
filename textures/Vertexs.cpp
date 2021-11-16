#include "textures.hpp"
#include "../libs/GLMS/glm/glm/ext.hpp"
#include "../libs/GLMS/glm/glm/vec3.hpp"
class vertex_ : public textures{
public:
GLuint vertexbuffer,vbo;
GLuint programid;
     vertex_(GLuint programid){
                  vertex_::programid = programid;

     };
     ~vertex_(){
     glDeleteVertexArrays(1, &vertexbuffer);
     glDeleteBuffers(1, &vbo);

     };


         // world space positions of our cubes
    glm::vec3 cubePositions[10] = {
        glm::vec3( 0.0f,  0.0f,  -5.0f),
        glm::vec3( 3.0f,  0.0f,  -5.0f),
        glm::vec3(-3.0f,  0.0f,  -5.0f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    

   


 GLuint  VAO_GL(){

     return vertexbuffer;
}
void  DrawTriangle(GLuint &vertexbuffer,float &time,GLuint &shaderProgram){
    

       static const GLfloat g_vertex_buffer_data[] = { 
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};
     glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT| GL_COLOR_ARRAY_BUFFER_BINDING);
     glEnableVertexAttribArray(0);
     glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

     float timeValue = time;
     float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
     int vertexColorLocation = glGetUniformLocation(shaderProgram, "color1");
     glUseProgram(shaderProgram);

     glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);



}
void VAO2(){
	
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


     }
void draw(shloader &s){



};
    
};
