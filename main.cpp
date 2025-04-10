#include <iostream>
#include <vector>
#include <cstdlib>

// float globalSum = 0.0;

std::vector<int> generatePlayerSet(int gamesNumber)
{
    std::vector<int> playerSet;

    int onesCount = static_cast<int>(gamesNumber * 0.25);
    int twosCount = static_cast<int>(gamesNumber * 0.5);
    int threesCount = gamesNumber - onesCount - twosCount;

    for (int i = 0; i < onesCount; i++)
    {
        playerSet.push_back(1);
    }
    for (int i = 0; i < twosCount; i++)
    {
        playerSet.push_back(2);
    }
    for (int i = 0; i < threesCount; i++)
    {
        playerSet.push_back(3);
    }

    return playerSet;
}

void runGamesSet(const int gamesNumber)
{
    std::vector<int> firstPlayerSet = generatePlayerSet(gamesNumber);
    std::vector<int> secondPlayerSet = generatePlayerSet(gamesNumber);

    int firstPlayerScore = 0;
    int secondPlayerScore = 0;

    for (int i = 0; i < gamesNumber; i++)
    {
        int firstIndex = rand() % firstPlayerSet.size();
        int secondIndex = rand() % secondPlayerSet.size();

        int firstChoice = firstPlayerSet[firstIndex];
        int secondChoice = secondPlayerSet[secondIndex];

        int sum = firstChoice + secondChoice;

        firstPlayerSet.erase(firstPlayerSet.begin() + firstIndex);
        secondPlayerSet.erase(secondPlayerSet.begin() + secondIndex);

        if (sum % 2 == 0)
        {
            firstPlayerScore += sum;
            secondPlayerScore -= sum;
        }
        else
        {
            firstPlayerScore -= sum;
            secondPlayerScore += sum;
        }

        std::cout << "Round " << i + 1 << ": "
                  << "P1 chose " << firstChoice << ", P2 chose " << secondChoice
                  << " | Sum = " << sum << " -> "
                  << "P1: " << firstPlayerScore << "   P2: " << secondPlayerScore << std::endl;
    }
    // globalSum += firstPlayerScore;
    std::cout << "Final Score:" << std::endl
              << "Player 1: " << firstPlayerScore << std::endl
              << "Player 2: " << secondPlayerScore << std::endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int gamesNumber;
    // int testsNumber;
    std::cout << "=== Numbers Game Simulator ===" << std::endl;
    std::cout << "Enter the number of games to simulate: " << std::endl;
    std::cin >> gamesNumber;
    // std::cout << "Enter the number of simulations: " << std::endl;
    // std::cin >> testsNumber;

    if (gamesNumber <= 0)
    {
        std::cerr << "Number of games must be greater than 0.\n";
        return 1;
    }

    // for (int i = 0; i < testsNumber; i++)
    // {
    runGamesSet(gamesNumber);
    //}

    // std::cout << "Average = " << averagesum / float(testsNumber) << std::endl;
    return 0;
}