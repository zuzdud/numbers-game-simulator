# Numbers Game Simulator

## Overview
This project implements a simple two-player **Numbers Game** simulator in C++. It is based on a game introduced in an Artificial Intelligence course at Wrocław University of Science and Technology (PWr). The purpose of the simulation is to model interactions between players using a fixed strategy over multiple rounds and analyze the outcomes.

## Game Description
The Numbers Game is played between two players who simultaneously choose a number from the set {1, 2, 3}. The selected numbers are added together to compute the sum. If the sum is even, then Player 2 pays Player 1 the amount equal to the sum (in zlotys). If the sum is odd, then Player 1 pays Player 2 the amount equal to the sum.

## Strategy 
Both players use the same **optimal mixed strategy** derived using Game Theory:
- Choose 1 with probability 1/4
- Choose 2 with probability 1/2
- Choose 3 with probability 1/4.

## Implementation Details
### Game Setup
Each player is assigned a sequence of numbers based on fixed strategy. These numbers are stored in vectors and are selected randomly using `rand()` during the simulation.

### Game Loop
In each round:
- A number is randomly selected from each player's remaining set.
- The selected numbers are added together.
- If the sum is even, Player 2 pays Player 1 the sum.
- If the sum is odd, Player 1 pays Player 2 the sum.
- The chosen numbers are removed from the players’ sets to ensure no repetition.

### Optional Multi-Test Mode
The code includes commented-out sections to support running multiple simulations and computing the average score for Player 1:
- Uncomment lines related to `globalSum`, `testsNumber`, and loop logic in `main()` and `runGamesSet()` to enable.
- This allows for analyzing results over many trials for statistical significance.

## Project Structure
- `main.cpp`: Main source code for the project.
- `README.md`: Project documentation

## How to Run
Clone this repository:
```
git clone https://github.com/zuzdud/numbers-game-simulator.git
cd numbers-game-simulator
```
Compile the program:
```
g++ -o numbers main.cpp
```
Run the executable:
```
./numbers
```
