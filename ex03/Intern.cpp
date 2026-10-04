#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "../Color.hpp"

// ----------------------------------------------
// * OCF
// ----------------------------------------------
Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

// ----------------------------------------------
// * METHOD
// ----------------------------------------------

// 各フォーム生成用のメンバ関数の実装
AForm* Intern::makeShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // 1. 対応するフォーム名の配列を準備
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // メンバ関数へのポインタの配列を定義
    AForm* (Intern::*formMakers[])(const std::string&) const = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    // 2. 配列をループで回し、一致する名前を探す
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            // 配列から対応する関数ポインタを呼び出して実行
            return (this->*formMakers[i])(target);
        }
    }

    // 4. フォーム名が存在しない場合はエラーメッセージを出力
    std::cout   << RED << "Error: " << RESET 
                <<"Intern cannot create form '"
                << formName 
                << "' because it does not exist." << "\n";
    
    return NULL;
}
