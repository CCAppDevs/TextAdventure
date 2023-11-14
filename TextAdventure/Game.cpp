#include "Game.h"

Game::Game()
{
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate(float fElapesedTime)
{

    // clear the screen
    Fill(0, 0, m_nScreenWidth, m_nScreenHeight, L' ', 0);

    Fill(1, 1, 27, 27, PIXEL_SOLID, FG_WHITE);
    
    return true;
}
