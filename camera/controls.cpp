#include "controls.hpp"
camera::camera()
{
	ProjMatrix = glm::mat4(1.0f);
	ViewMatrix = glm::mat4(1.0f);
	
	Camera_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	Camera_front = glm::vec3(0.0, 0.0f, -1.0f);
	camera_up = glm::vec3(0.0, 1.0f, 0.0f);
	
};

glm::mat4 camera::getViewMatrix()
{
	return ViewMatrix;
};
glm::mat4 camera::getProjection_Matrix()
{
	return ProjMatrix;
};
//compute input mouse4 matrix
void camera::Init_Camera()
{

	///


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
}
