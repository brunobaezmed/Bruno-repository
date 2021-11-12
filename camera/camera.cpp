#include "camera.hpp"
camera::camera(){
	ViewMatrix = glm:: mat4 (1.0f);
	ProjMatrix = glm:: mat4 (1.0f);
	sf::Time time;

};
glm::mat4 camera:: getViewMatrix(){
	return ViewMatrix;
};
glm::mat4 camera:: getProjection_Matrix(){
	return ProjMatrix;
};
	//compute input mouse4 matrix
void Init_Camera(){
	glm::vec3 camera_pos = glm::vec3(0.0f , 0.0f , 3.0f);
	glm::vec3 camera_front = glm::vec3(0.0f , 0.0f , -1.0f);

	///
	static double lastime = time.getElapsedTime().asSeconds();
	////
	double currentime = time.getElapsedTime().asSeconds();

	float deltatime = float(currentime - lastime);

	double xpos ,ypos;
	sf::




}