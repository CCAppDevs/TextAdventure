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

    OutputTimeThreshold = 30.0f;
    OutputTimeElapsed = 0.0f;

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
        QueueOutputText("Attack 1.");
    }

    if (GetKey(L'R').bPressed) {
        QueueOutputText("Running");
        // do running things
    }

    if (GetKey(L'Q').bPressed) {
        return false;
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

    // draw output
    DrawTextOutput(fElapesedTime);

    // draw the player options
    DrawString(1, 50, L"Options: Arrows to Move, A to Atack, R to Run, Q to Quit");
    
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

void Game::QueueOutputText(std::string message)
{
    // add a line to the output buffer
    Output.push(message);
}

void Game::DrawTextOutput(float fElapsedTime)
{
    if (Output.empty()) {
        Fill(1, 43, m_nScreenWidth, 44, L' ', 0);
        return;
    }
    else {
        // draw the current buffer
        DrawString(1, 43, std::wstring(Output.front().begin(), Output.front().end()).c_str());

        if (OutputTimeElapsed > OutputTimeThreshold) {
            // remove a line, reset the timer
            Output.pop();
            OutputTimeElapsed = 0;
        }
        else {
            // add the elapsed time to the OutputTimeElapsed
            OutputTimeElapsed += fElapsedTime;
        }
    }
}
