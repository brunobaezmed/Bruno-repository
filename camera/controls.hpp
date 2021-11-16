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
private:

	sf::Time time;
	glm::mat4 ProjMatrix ;
	glm::mat4 ViewMatrix ;
	
	glm::vec3 Camera_Position ;
	glm::vec3 Camera_front ;
	glm::vec3 camera_up ;
	float initialFoV;
	float lastime,deltatime,currentime;
	const float FoV = 45.0f;
	const float speed = 3.0f;
	const float mousespeed = 0.005f;
public:	
	glm::mat4 getViewMatrix();
	glm::mat4 getProjection_Matrix();
	void Init_Camera();
	




};
#endif