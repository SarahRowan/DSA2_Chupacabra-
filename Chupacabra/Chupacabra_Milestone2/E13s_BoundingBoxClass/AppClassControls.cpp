#include "AppClass.h"
void AppClass::ProcessKeyboard(void)
{
	bool bModifier = false;
	float fSpeed = 0.01f * scaledDT;

#pragma region ON PRESS/RELEASE DEFINITION
	static bool	bLastF1 = false, bLastF2 = false, bLastF3 = false, bLastF4 = false, bLastF5 = false,
				bLastF6 = false, bLastF7 = false, bLastF8 = false, bLastF9 = false, bLastF10 = false,
				bLastEscape = false, bLastF = false;
#define ON_KEY_PRESS_RELEASE(key, pressed_action, released_action){  \
			bool pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::key);			\
			if(pressed){											\
				if(!bLast##key) pressed_action;}/*Just pressed? */\
			else if(bLast##key) released_action;/*Just released?*/\
			bLast##key = pressed; } //remember the state
#pragma endregion

#pragma region Modifiers
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		bModifier = true;
#pragma endregion

#pragma region Camera Positioning
	if(true)
		/*fSpeed *= 100.0f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_pCameraMngr->MoveForward(fSpeed);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_pCameraMngr->MoveForward(-fSpeed);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if (m_pCameraMngr->GetPosition().x >= -5.0f + fSpeed){ m_pCameraMngr->MoveSideways(-fSpeed); }

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (m_pCameraMngr->GetPosition().x <= 5.0f - fSpeed){ m_pCameraMngr->MoveSideways(fSpeed); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		m_pCameraMngr->MoveVertical(-fSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		m_pCameraMngr->MoveVertical(fSpeed);*/
#pragma endregion

/*#pragma region Creeper Control
	if (bModifier)
		fSpeed *= 10.0f;
	// if canCollide, bounce off and move other object
	if (instance->canCollide)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_v3O1.x -= 0.1f;

			// if collision, push back
			if (instance->objects[0]->isColliding)
			{
				m_v3O1.x += 0.101f;
				m_v3O2.x -= 0.101f; // move other object
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_v3O1.x += 0.1f;

			// if collision, push back
			if (instance->objects[0]->isColliding)
			{
				m_v3O1.x -= 0.101f;
				m_v3O2.x += 0.101f; // move other object
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_v3O1.y -= 0.1f;

			// if collision, push back
			if (instance->objects[0]->isColliding)
			{
				m_v3O1.y += 0.101f;
				m_v3O2.y -= 0.101f; // move other object
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_v3O1.y += 0.1f;

			// if collision, push back
			if (instance->objects[0]->isColliding)
			{
				m_v3O1.y -= 0.101f;
				m_v3O2.y += 0.101f; // move other object
			}
		}
	}
	// normal movement
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_v3O1.x -= 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_v3O1.x += 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_v3O1.y -= 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_v3O1.y += 0.1f;
		}
	}
#pragma endregion*/

#pragma region Manager Control
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		instance->ToggleVisibility(); 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		instance->ToggleAABB(); 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		instance->ToggleResolution();*/
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && instance->objects.size() < 1)
		instance->objects[0]->ToggleVisible(); 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && instance->objects.size() < 2)
		instance->objects[1]->ToggleVisible();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && instance->objects.size() < 3)
		instance->objects[2]->ToggleVisible();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && instance->objects.size() < 4)
		instance->objects[3]->ToggleVisible();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && instance->objects.size() < 5)
		instance->objects[4]->ToggleVisible();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && instance->objects.size() < 6)
		instance->objects[5]->ToggleVisible();*/
#pragma endregion

#pragma region Other Actions
	ON_KEY_PRESS_RELEASE(Escape, NULL, PostMessage(m_pWindow->GetHandler(), WM_QUIT, NULL, NULL));
	ON_KEY_PRESS_RELEASE(F1, NULL, m_pCameraMngr->SetCameraMode(CAMPERSP));
	ON_KEY_PRESS_RELEASE(F2, NULL, m_pCameraMngr->SetCameraMode(CAMROTHOZ));
	ON_KEY_PRESS_RELEASE(F3, NULL, m_pCameraMngr->SetCameraMode(CAMROTHOY));
	ON_KEY_PRESS_RELEASE(F4, NULL, m_pCameraMngr->SetCameraMode(CAMROTHOX));
#pragma endregion
}
void AppClass::ProcessMouse(void)
{
	m_bArcBall = false;
	m_bFPC = false;
	
	/*if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
		m_bArcBall = true;*/
	
	/*if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		m_bFPC = true;*/

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		//sf::Vector2i coord = sf::Mouse::getPosition(); 
		//coord = m_pWindow->GetHandler().mapPixelToCoords(coord); 

		//m_m4Camera = m_pCameraMngr->GetCameraPlane(); //Space right in front of the camera forming a plane that covers the window

		//Calculate the position of the mouse in device space [(-1,-1);(1,1)]
		int nMouseX, nMouseY; // Coordinates for the mouse
		POINT pt;
		GetCursorPos(&pt);
		nMouseX = static_cast<int>(pt.x);
		nMouseY = static_cast<int>(pt.y);
		float posX = static_cast<float>(nMouseX - m_pSystem->GetWindowX());
		float posY = static_cast<float>(nMouseY - m_pSystem->GetWindowY());
		float width = static_cast<float>(m_pSystem->GetWindowWidth());
		float height = static_cast<float>(m_pSystem->GetWindowHeight());
		float x = (posX / width - 0.5f) * 2.0f; // [0,w] -> [-1,1]
		float y = (posY / height - 0.5f) * 2.0f; // [0,h] -> [-1,1]
		y *= -1;
		//Translate that to World Space
		vector4 v4NDC(x, y, -1.0f, 1.0f); //Normalized Device Coordinates
		glm::mat4 m4InverseVP = glm::inverse(m_pCameraMngr->GetVP()); //inverse of the view projection
		glm::vec4 v4World = m4InverseVP * v4NDC; //translate device space to world coordinates
		v4World /= v4World.w;//normalize
		vector3 m_v3ClickedOn = vector3(v4World);


		m_pMeshMngr->PrintLine(player->ProveClick(vector2(posX, posY)), REGREEN);
		m_pMeshMngr->PrintLine(player->ProveClick(vector2(m_v3ClickedOn.x, m_v3ClickedOn.y)), REGREEN);
		player->ThrowObject(vector2(x, y)); //just until I can map values correctly
	}

	//sf::Mouse::getPosition()
}
