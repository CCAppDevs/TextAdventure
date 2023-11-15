#include "Game.h"

Game::Game()
{
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
    //text = "";
    // get user input
    if (m_keys[VK_LEFT].bPressed) {
        // moveX(-1);
        text = "Left";
    }

    if (m_keys[VK_RIGHT].bPressed) {
        // moveX(1);
        text = "Right";
    }

    if (m_keys[VK_UP].bPressed) {
        // moveY(-1);
        text = "Up";
    }

    if (m_keys[VK_DOWN].bPressed) {
        // moveY(1);
        text = "Down";
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

    // draw the player


    // draw text

    DrawString(1, 42, std::wstring(text.begin(), text.end()).c_str());
    
    return true;
}

void Game::moveX(int amount)
{
    playerX += amount;
}

void Game::moveY(int amount)
{
    if (playerY + amount >= 2 && playerY + amount < mapY + 2) {
        playerY += amount;
    }
}
