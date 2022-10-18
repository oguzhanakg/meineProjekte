#include "player.h"
#include <iostream>

using namespace std;

void Player::addGameWon()
{
    m_gamesWon++;
}

void Player::addGameLost()
{
    m_gamesLost++;
}

Player::Player(const std::string &playerName) : m_playerName(playerName), m_gamesWon(0), m_gamesLost(0)
{
}

int Player::getGamesWon() const
{
    return m_gamesWon;
}

int Player::getGamesLost() const
{
    return m_gamesLost;
}

int Player::getGamesPlayed() const
{
    return m_gamesWon + m_gamesLost;
}

string Player::getName()
{
    return m_playerName;
}
