#include "Game.h"

Game::Game()
{
    myPlayer = Player("Arthur", 100, 1, 10);
}

bool Game::StartEncounter(std::string encounterText)
{
    QueueOutputText(encounterText);
    return true;
}

void Game::StartCombat(Enemy& theEnemy)
{
    // is it an ambush
        // enemy deals damage
    // ask player for action
    isEngaged = true;


    QueueOutputText("You have encountered an enemy. " + theEnemy.GetName() + " is preparing to attack!");
    QueueOutputText("Do you want to (A)ttack or (R)un?");
    

        // run
            // player takes a single hit from the enemy
            // check to see if run is successfull
                // end encounter, mark as incomplete
                // push player to adjacent spot
}

bool Game::OnUserCreate()
{
    playerX = 2;
    playerY = 2;

    mapX = 76;
    mapY = 38;

    isEngaged = false;

    OutputTimeThreshold = 10.0f;
    OutputTimeElapsed = 0.0f;

    myMap = new Map(mapX, mapY);

    return true;
}

bool Game::OnUserUpdate(float fElapesedTime)
{
    text = "";

    if (!isEngaged) {
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
    }
    
    
    if (isEngaged) {
        if (GetKey(L'A').bPressed) {
            AdvanceText();
            MakeAttack();
        }

        if (GetKey(L'R').bPressed) {
            AdvanceText();
            Run();
        }
    }
    

    if (GetKey(L'Q').bPressed) {
        return false;
    }

    if (m_keys[VK_SPACE].bPressed) {
        AdvanceText();
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
    text = GetCurrentRoom().GetDescription();
    DrawString(1, 42, std::wstring(text.begin(), text.end()).c_str());

    // check room for execution
    if (!isEngaged) {
        GetCurrentRoom().Execute(*this);
    }
    
    // draw output
    DrawTextOutput(fElapesedTime);

    // draw the player options
    std::string stats = "| " + myPlayer.GetName() + " | Health Remaining: " + to_string(myPlayer.GetHealth());
    std::wstring playerText = std::wstring(stats.begin(), stats.end());
    DrawString(1, 50, playerText.c_str());
    
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

AbstractRoom& Game::GetCurrentRoom()
{
    return myMap->GetRoom(playerX - 2, playerY - 2);
}

void Game::MakeAttack()
{
    // start attack
    
    // make an attack roll
    
    float damage = myPlayer.RollForDamage();

    // apply the damage to the enemy
    EncounterRoom& room = (EncounterRoom&)GetCurrentRoom();
    room.GetEnemy()->TakeDamage(damage);

    // output for success
    QueueOutputText("You hit the " + room.GetEnemy()->GetName() + " for " + to_string(damage) + " damage!");
    
    if (room.GetEnemy()->GetHealth() <= 0) {
        // enemy has died
        QueueOutputText("You have vanquished your foe!");
        isEngaged = false;
        room.SetHasBeenVisited(true);
    }
    else {
        float enemyDamage = room.GetEnemy()->RollForDamage();
        myPlayer.TakeDamage(enemyDamage);
        QueueOutputText("The enemy strikes you back for " + to_string(enemyDamage) + " damage!");

        if (myPlayer.GetHealth() <= 0) {
            QueueOutputText("You have died...");
        }
    }

    // if both combatants are alive, continue combat
    if (room.GetEnemy()->GetHealth() > 0 && myPlayer.GetHealth() <= 0) {
        QueueOutputText(room.GetEnemy()->GetName() + " is preparing to attack!");
        QueueOutputText("Do you want to (A)ttack or (R)un?");
    }
}

void Game::Run()
{
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

void Game::AdvanceText()
{
    if (Output.size() > 1) {
        // set text to expire immedietly
        OutputTimeElapsed = OutputTimeThreshold;
    }
}
