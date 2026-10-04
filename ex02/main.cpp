#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "../Color.hpp"

#include <iostream>
#include <cstdlib> // 追加: rand, srand用
#include <ctime>   // 追加: time用

int main() {
    std::srand(std::time(NULL));

    std::cout << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 1: ShrubberyCreationForm    " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        // ShrubberyCreationFormの要件: サイン145, 実行137
        Bureaucrat boss("BOSS", 1);       // 全てできる
        Bureaucrat mid("MID", 140);        // サインはできるが実行はできない
        Bureaucrat newbie("NEWBIE", 150); // 何もできない
        ShrubberyCreationForm form("home");

        std::cout << "--- 初期状態のフォーム ---\n";
        std::cout << form << "\n\n";

        std::cout << YELLOW << "[Test 1: 権限不足の NEWBIE (150) がサインを試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 失敗\n";
        newbie.signForm(form); 
        std::cout << "\n";

        std::cout << YELLOW << "[Test 2: 権限を満たす MID (140) がサインを試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 成功\n";
        mid.signForm(form);
        std::cout << "\n";
        std::cout << form << "\n\n";

        std::cout << YELLOW << "[Test 3: サイン済みだが実行権限が足りない MID (140) が実行を試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 失敗\n";
        mid.executeForm(form);
        std::cout << "\n";

        std::cout << YELLOW << "[Test 4: 全権限を持つ BOSS (1) が実行を試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 成功\n";
        boss.executeForm(form);
        std::cout << "\n";

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "\n" << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 2: RobotomyRequestForm   " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        // RobotomyRequestFormの要件: サイン72, 実行45
        Bureaucrat boss("BOSS", 1);       // 全てできる
        Bureaucrat mid("MID", 50);        // サインはできるが実行はできない
        Bureaucrat newbie("NEWBIE", 150); // 何もできない
        RobotomyRequestForm form("Bender");

        std::cout << "--- 初期状態のフォーム ---\n";
        std::cout << form << "\n\n";

        std::cout << YELLOW << "[Test 1: 権限不足の NEWBIE (150) がサインを試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 失敗\n";
        newbie.signForm(form); 
        std::cout << "\n";

        std::cout << YELLOW << "[Test 2: 権限を満たす MID (50) がサインを試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 成功\n";
        mid.signForm(form);
        std::cout << "\n";
        std::cout << form << "\n\n";

        std::cout << YELLOW << "[Test 3: サイン済みだが実行権限が足りない MID (50) が実行を試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 失敗\n";
        mid.executeForm(form);
        std::cout << "\n";

        std::cout << YELLOW << "[Test 4: 全権限を持つ BOSS (1) が複数回実行を試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: ドリル音の後、50%の確率で成功/失敗\n";
        for (int i = 0; i < 4; ++i) {
            std::cout << "--- 実行 " << (i + 1) << " 回目 ---\n";
            boss.executeForm(form);
        }
        std::cout << "\n";

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    
    std::cout << "\n" << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 3: PresidentialPardonForm        " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    try {
        Bureaucrat boss("BOSS", 1);       // 全てできる
        Bureaucrat mid("MID", 20);        // サイン(25)はできるが実行(5)はできない
        Bureaucrat newbie("NEWBIE", 150); // 何もできない
        PresidentialPardonForm form("Ford Prefect");

        std::cout << "--- 初期状態のフォーム ---\n";
        std::cout << form << "\n\n";

        std::cout << YELLOW << "[Test 1: 権限不足の NEWBIE (150) がサインを試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 失敗\n";
        newbie.signForm(form); 
        std::cout << "\n";

        std::cout << YELLOW << "[Test 2: 権限を満たす MID (20) がサインを試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 成功\n";
        mid.signForm(form);
        std::cout << "\n";
        std::cout << form << "\n\n";

        std::cout << YELLOW << "[Test 3: サイン済みだが実行権限が足りない MID (20) が実行を試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 失敗\n";
        mid.executeForm(form);
        std::cout << "\n";

        std::cout << YELLOW << "[Test 4: 全権限を持つ BOSS (1) が実行を試みる]" << RESET << "\n";
        std::cout << "-> 期待される結果: 恩赦のメッセージが出力される\n";
        boss.executeForm(form);
        std::cout << "\n";
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}
