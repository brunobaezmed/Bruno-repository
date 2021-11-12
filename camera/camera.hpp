#ifndef CAMERA_INPUT_
#define CAMERA_INPUT_
#include "../libs/GLMS/glm/glm/ext.hpp"
#include "../libs/SFML/Window.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../libs/GLMS/glm/glm/glm.hpp"
class camera{
public:
	camera();
	~camera(){};
	
	glm::mat4 ViewMatrix;
	glm::mat4 ProjMatrix;
	glm::vec3 Camera_Position = glm::vec3(0.0f,0.0f,3.0f);
	glm::vec3 Camera_front = glm::vec3(0.0,0.0f,-1.0f);
	glm::vec3 camera_up = glm::vec3(0.0,1.0f,0.0f);
	float horizontaangle;
	float verticalangle;
	float initialFoV;
	sf::Time time;

	double xpos ,ypos;
	double lastime;
	const float speed = 3.0f;
	const float mousespeed = 0.005f;
	
	glm::mat4 getViewMatrix();
	glm::mat4 getProjection_Matrix();
	void Init_Camera();




};
#endif