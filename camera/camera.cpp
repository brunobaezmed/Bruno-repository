#include "camera.hpp"
camera::camera(){
	lastime = time.asSeconds();

	ViewMatrix = glm:: mat4 (1.0f);
	ProjMatrix = glm:: mat4 (1.0f);
	xpos = 0.0;
	ypos = 0.0;
	initialFoV = 45.0f;
	verticalangle = 0.0f;
	horizontaangle = 3.14f;
};
glm::mat4 camera:: getViewMatrix(){
	return ViewMatrix;
};
glm::mat4 camera:: getProjection_Matrix(){
	return ProjMatrix;
};
	//compute input mouse4 matrix
void camera:: Init_Camera(){
	

	///
	////
	double currentime = time.asSeconds();
	
	float deltatime = float(currentime - lastime);

	
	xpos = sf::Mouse::getPosition().x;
	ypos = sf::Mouse::getPosition().y;
	sf::Mouse::setPosition(sf::Vector2i(xpos,ypos));

	horizontaangle += mousespeed * float(1920/2) - xpos;
	verticalangle  += mousespeed * float(1080/2) - ypos;

	glm::vec3 direction(
		0.0f,
		0.0f,
		-1.0f
	);

	glm::vec3 right = glm::vec3(
		sin(horizontaangle - 3.14f/2.0f),
		0,
		cos(horizontaangle - 3.14/2.0f)
	);

	glm::vec3 up = glm::vec3 (0.0f,1.0f,0.0f);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		Camera_Position += Camera_front * deltatime * speed;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
	
		Camera_Position -= glm::normalize(glm::cross(Camera_front,camera_up)) * deltatime * speed;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		Camera_Position += glm::normalize(glm::cross(Camera_front,camera_up)) * deltatime * speed;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		Camera_Position -= Camera_front * deltatime * speed;	

	}


	float FoV = initialFoV;

	ProjMatrix = glm::perspective(glm::radians(FoV),4.0f/3.0f,0.1f,100.0f);
	ViewMatrix = glm::lookAt(
			Camera_Position,
			Camera_Position+Camera_front,
			up
	);
	lastime = currentime;
	}
