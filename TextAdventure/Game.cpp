#include "Game.h"

Game::Game()
{
}

bool Game::StartEncounter(std::string encounterText)
{
    DrawString(1, 43, std::wstring(encounterText.begin(), encounterText.end()).c_str());
    return true;
}

bool Game::OnUserCreate()
{
    playerX = 2;
    playerY = 2;

    mapX = 76;
    mapY = 38;

    myMap = new Map(mapX, mapY);

    return true;
}

bool Game::OnUserUpdate(float fElapesedTime)
{
    text = "";
    
    // get user input
    if (m_keys[VK_LEFT].bPressed) {
        moveX(-1);
    }

    if (m_keys[VK_RIGHT].bPressed) {
        moveX(1);
    }

    if (m_keys[VK_UP].bPressed) {
        moveY(-1);
    }

    if (m_keys[VK_DOWN].bPressed) {
        moveY(1);
    }

	if (GetKey(L'A').bPressed) {
		text = "A";
	}


    // clear the screen
    Fill(0, 0, m_nScreenWidth, m_nScreenHeight, L' ', 0);

    Fill(1, 1, 79, 41, PIXEL_SOLID, FG_WHITE);

    // draw map
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            Fill(2 + j, 2 + i, 3 + j, 3 + i, myMap->GetRoom(j, i).ToShort(), myMap->GetRoom(j, i).GetColour());
        }
    }

    // draw the player on the map
    Fill(playerX, playerY, playerX + 1, playerY + 1, L'P', FG_WHITE);

    // draw text
    // TODO: set up a queue or stack to read out multiple lines of text
    text = myMap->GetRoom(playerX - 2, playerY - 2).GetDescription();
    DrawString(1, 42, std::wstring(text.begin(), text.end()).c_str());

    // draw the player options
    DrawString(1, 50, L"Options: Arrows to Move, A to Atack, R to Run, Q to Quit");
    
	// execute the room
	myMap->GetRoom(playerX - 2, playerY - 2).Execute(*this);

    return true;
}

void Game::moveX(int amount)
{
    if (playerX + amount >= 2 && playerX + amount < mapX + 2) {
        playerX += amount;
    }
}

void Game::moveY(int amount)
{
    if (playerY + amount >= 2 && playerY + amount < mapY + 2) {
        playerY += amount;
    }
}
