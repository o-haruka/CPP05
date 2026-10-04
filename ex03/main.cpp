#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "../Color.hpp"

int main() {
    //! 通常 main() で一度だけ呼び出します。理由は、srand() が RobotomyRequestForm専用の設定ではなく、プロセス全体の rand() の初期化だから
    std::srand(std::time(NULL));

    std::cout << CYAN << "=======================================" << RESET << "\n";
    std::cout << CYAN << "     TEST 1: Intern Creation    " << RESET << "\n";
    std::cout << CYAN << "=======================================" << RESET << "\n";
    
    Intern someRandomIntern;
    AForm* rrf;

    // 1. Robotomy Request Form (ドキュメントの例)
    std::cout << YELLOW << "[Test 1: robotomy request]" << RESET << "\n";
    rrf = someRandomIntern.makeForm("robotomy request", "Bender"); 
    if (rrf) {
        std::cout << *rrf << "\n";
        delete rrf; // メモリリークを防ぐためにdeleteが必要
    }
    std::cout << "\n";

    // 2. Shrubbery Creation Form
    std::cout << YELLOW << "[Test 2: shrubbery creation]" << RESET << "\n";
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf) {
        std::cout << *scf << "\n";
        delete scf;
    }
    std::cout << "\n";

    // 3. Presidential Pardon Form
    std::cout << YELLOW << "[Test 3: presidential pardon]" << RESET << "\n";
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (ppf) {
        std::cout << *ppf << "\n";
        delete ppf;
    }
    std::cout << "\n";

    // 4. 存在しないフォーム名のエラーテスト
    std::cout << YELLOW << "[Test 4: unknown form]" << RESET << "\n";
    AForm* unknown = someRandomIntern.makeForm("coffee making request", "Intern");
    if (unknown) {
        delete unknown;
    } else {
        std::cout << "-> Successfully handled unknown form (returned NULL)." << "\n";
    }
    std::cout << "\n";

    return 0;
}
