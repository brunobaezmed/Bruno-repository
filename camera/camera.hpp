#ifndef CAMERA_INPUT_
#define CAMERA_INPUT_
#include "libs/GLMS/glm/ext"
class camera{
public:
	camera();
	~camera();
	
	glm::mat4 ViewMatrix;
	glm::mat4 ProjMatrix;
	float horizontaangle;
	float verticalangle;
	float initialFoV;
	sf::Time ;
	const float speed = 3.0f;
	const float mousespeed = 0.005f;


	glm::mat4 getViewMatrix();
	glm::mat4 getProjection_Matrix();
	void Init_Camera();




};
#endif