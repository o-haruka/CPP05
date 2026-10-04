#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "../Color.hpp"

int main() {
    std::cout << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 1: 正常なFormの作成と出力    " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        Form formA("FormA", 50, 20);
        std::cout << GREEN << "成功: " << RESET << "Form作成" << "\n";
        std::cout << formA << "\n"; // << 演算子のテスト
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n" << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 2: 異常なFormの作成 (例外)   " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        std::cout << YELLOW << "-> サイン要求等級を 0 (高すぎる) にして作成してみる" << RESET << "\n";
        Form formB("FormB", 0, 50);
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << YELLOW << "\n-> サイン要求等級 151 (低すぎる) にして作成してみる" << RESET << "\n";
        Form formC("FormC", 151, 50);
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n" << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 3: サイン成功のテスト        " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        Bureaucrat chikawa("chikawa", 50);
        Form formD("FormD", 50, 50);

        std::cout << chikawa << "\n";
        std::cout << formD << "\n";

        std::cout << YELLOW << "\n-> chikawaがサインを試みる (成功するはず)" << RESET << "\n";
        chikawa.signForm(formD);
        
        std::cout << "\n-> サイン後のFormの状態確認" << "\n";
        std::cout << formD << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n" << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 4: サイン失敗のテスト        " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        Bureaucrat usagi("usagi", 100);
        Form formE("formE", 50, 50);

        std::cout << usagi << "\n";
        std::cout << formE << "\n";

        std::cout << YELLOW << "\n-> usagiがサインを試みる (100 > 50 なので失敗するはず)" << RESET << "\n";
        usagi.signForm(formE);
        
        std::cout << "\n-> サイン後のFormの状態確認" << "\n";
        std::cout << formE << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
