#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

Game::Game()
: player(1,1), enemy(5,3), playerTurn(true), running(true) {}

bool Game::checkCollision() {
    return player.getX() == enemy.getX() &&
           player.getY() == enemy.getY();
}

void Game::run() {
    while (running) {
        render();
        input();
        update();
    }
}

void Game::input() {
    if (!playerTurn) return;

    char c;
    std::cout << "> ";
    std::cin >> c;

    std::cin.ignore(1000, '\n');
    c = std::tolower(c);

    bool moved = player.handleInput(c, map);

    if (moved) {
        playerTurn = false;
    }
}


void Game::update() {

    if (checkCollision()) {
        render();
        std::cout << "GAME OVER\n";
        running = false;
        return;
    }

    if (map.isExit(player.getX(), player.getY())) {
        render();
        std::cout << "YOU WIN!\n";
        running = false;
        return;
    }

    if (!playerTurn) {
        enemy.update(player.getX(), player.getY(), map);

        if (checkCollision()) {
            render();
            std::cout << "GAME OVER\n";
            running = false;
            return;
        }

        playerTurn = true;
    }
}

void Game::render() {
    system("cls");
    map.draw(player, enemy);

    std::cout << "Turn: " << (playerTurn ? "Player" : "Enemy") << "\n";
    std::cout << "Control: W A S D\n";
    std::cout << "Goal: Reach O\n";
}
