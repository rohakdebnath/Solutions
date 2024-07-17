#include <iostream>

double getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height {};
    std::cin >> height;

    return height;
}

double heightFromGround(double height, int x_seconds)
{
    const double g {9.8};
    return height - g * x_seconds * x_seconds / 2;
}

void printAnswer(double height, int x_seconds)
{
    double heightOfBall = heightFromGround(height, x_seconds);
    if (heightOfBall < 0)
        std::cout << "At " << x_seconds << " seconds, the ball is on the ground.\n";
    else 
        std::cout << "At " << x_seconds << " seconds, the ball is at height: " << heightOfBall << " meters\n";

}

int main()
{
    double height = getHeight();
    printAnswer(height, 0);
    printAnswer(height, 1);
    printAnswer(height, 2);
    printAnswer(height, 3);
    printAnswer(height, 4);
    printAnswer(height, 5);
    
}




