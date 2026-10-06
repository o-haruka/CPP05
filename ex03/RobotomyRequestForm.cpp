#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib> // rand, srand用
#include "../Color.hpp"

// ----------------------------------------------
// * OCF
// ----------------------------------------------
//AForm("form name", gradeToSign, gradeToExecute)
RobotomyRequestForm::RobotomyRequestForm()
:   AForm("RobotomyRequestForm", 72, 45),
    target_("default target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:   AForm("RobotomyRequestForm", 72, 45),
    target_(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
:   AForm(other),
    target_(other.target_)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other){
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// ----------------------------------------------
// * METHOD
// ----------------------------------------------

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    // 1. 権限チェック (AForm の例外をスロー)
    if (!this->getIsSigned()) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // 2. ドリル音の出力
    std::cout << "gagagagagaggagaaggagag... (Drilling noises)" << "\n";

    // 3. 50%の確率で成功か失敗かを判定
    if (std::rand() % 2 == 0) {
        std::cout   << GREEN
                    << target_
                    << " has been robotomized successfully!"
                    << RESET
                    << "\n";
    } else {
        std::cout   << RED
                    <<"Robotomy on "
                    << target_
                    << " failed."
                    << RESET
                    << "\n";
    }
}
