#include <iostream>
#include <cmath>

int main()
{
    //global variable score
    double score = 0;

    //first scope for 1st question
    {
        //ask and accept a double answer
        double answer_01;
        std::cout << "Rate the chance (0 -- 1) of having a flat today : \n";
        std::cin >> answer_01;
                if(answer_01 < 0.5){
                    //increase score by answer value
            score += 0.5;
        }
                else if(answer_01 >= 0.5 && answer_01 < 0.7){
                    score += 0.25;
                }
                else
                    score += 0;
    }

    //second scope, identical as above except question
    {
        double answer_02;
        std::cout << "How likley (0 -- 1) is it that you'll exit, pursued by a bear? : \n";
        std::cin >> answer_02;
                if(answer_02 < 0.5){
            score += 0.5;
        }
                else if(answer_02 >= 0.5 && answer_02 < 0.7){
                    score += 0.25;
                }
                else
                    score += 0;
    }

    //third scope as above
    {
        double answer_03;
        std::cout << "What odds (0 -- 1) that the sky will fall on our heads? : \n";
        std::cin >> answer_03;
                if(answer_03 < 0.5){
            score += 0.5;
        }
                else if(answer_03 >= 0.5 && answer_03 < 0.7){
                    score += 0.25;
                }
                else
                    score += 0;
    }

    //output optimism score
    std::cout << "Your optimism score is : " << score/1.5
              << std::endl;

    //output lovely messages for three score classes
    if(score/1.5 < 0.3){
        std::cout << "You're not going to last the day...\n";
    }
    else if(score/1.5 >= 0.3 && score/1.5 < 0.7){
        std::cout << "You're a reasonably optimistic person...\n";
    }
    else {
        std::cout << "Go jump in a canal you inveterate optimist!\n";
    }

    return 0;
}
