#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// ----------------------------------------------
// * OCF
// ----------------------------------------------
//AForm("form name", gradeToSign, gradeToExecute)
PresidentialPardonForm::PresidentialPardonForm()
:   AForm("PresidentialPardonForm", 25, 5),
    target_("default target")
{}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:   AForm("PresidentialPardonForm", 25, 5),
    target_(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
:   AForm(other),
    target_(other.target_)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// ----------------------------------------------
// * METHOD
// ----------------------------------------------

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    // 1. 権限チェック
    if (!this->getIsSigned()) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // 2. 恩赦の通知
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << "\n";
}
