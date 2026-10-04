#include "Bureaucrat.hpp"
#include "../Color.hpp"
#include <iostream>

int main(){
    std::cout << "high:0 <----- GRADE -----> low:150 \n";
    std::cout << BLUE << "------------------------------------------------" << RESET << "\n";
    std::cout << BLUE << "TEST 1: 正常な動作" << RESET << "\n";
    std::cout << BLUE << "------------------------------------------------" << RESET << "\n";
    try {
        Bureaucrat normal("chikawa", 50);
        std::cout << normal << "\n";

        normal.incrementGrade();
        std::cout << "Increment後: " << normal << "\n";

        normal.decrementGrade();
        std::cout << "Decrement後: " << normal << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << BLUE << "\n------------------------------------------------" << RESET << "\n";
    std::cout << BLUE << "TEST 2: コンストラクタでの高すぎる例外テスト" << RESET << "\n";
    std::cout << BLUE << "------------------------------------------------" << RESET << "\n";
    try {
        Bureaucrat tooHigh("usagi", 0);
        //ここより下は実行されない→catchへ
        std::cout << tooHigh << "\n";

        tooHigh.incrementGrade();
        std::cout << "Increment後: " << tooHigh << "\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << BLUE << "\n------------------------------------------------" << RESET << "\n";
    std::cout << BLUE << "TEST 3: コンストラクタでの低すぎる例外テスト" << RESET << "\n";
    std::cout << BLUE << "------------------------------------------------" << RESET << "\n";
    try {
        Bureaucrat tooLow("hachiware", 151);
        std::cout << tooLow << "\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << BLUE << "\n------------------------------------------------" << RESET << "\n";
    std::cout << BLUE << "TEST 4: インクリメントでの範囲外エラーテスト" << RESET << "\n";
    std::cout << BLUE << "------------------------------------------------" << RESET << "\n";
    try {
        Bureaucrat inc("inc", 1);
        std::cout << inc << "\n";
        inc.incrementGrade();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << BLUE << "\n------------------------------------------------" << RESET << "\n";
    std::cout << BLUE << "TEST 5: デクリメントでの範囲外エラーテスト" << RESET << "\n";
    std::cout << BLUE << "------------------------------------------------" << RESET << "\n";
    try {
        Bureaucrat dec("dec", 150);
        std::cout << dec << "\n";
        dec.decrementGrade();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}
