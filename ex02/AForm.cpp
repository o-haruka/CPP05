#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "../Color.hpp"

// ----------------------------------------------
// * OCF
// ----------------------------------------------
AForm::AForm()
:   name_("Default Form name"),
    isSigned_(false),
    gradeToSign_(150),
    gradeToExecute_(150)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
:   name_(name),
    isSigned_(false),
    gradeToSign_(gradeToSign),
    gradeToExecute_(gradeToExecute)
{
    if (gradeToSign_ < 1 || gradeToExecute_ < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign_ > 150 || gradeToExecute_ > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
:   name_(other.name_),
    isSigned_(other.isSigned_),
    gradeToSign_(other.gradeToSign_),
    gradeToExecute_(other.gradeToExecute_)
{}

AForm& AForm::operator=(const AForm& other){
    if(this != &other){
        isSigned_ = other.isSigned_;
    }
    return (*this);
}

AForm::~AForm() {}
// ----------------------------------------------
// * METHOD
// ----------------------------------------------
// * GETTER
const std::string& AForm::getName(void) const
{
    return name_;
}

bool AForm::getIsSigned(void) const
{
    return isSigned_;
}

int AForm::getGradeToSign(void) const
{
    return gradeToSign_;
}

int AForm::getGradeToExecute(void) const
{
    return gradeToExecute_;
}

// * MEMBER FUNCTIONS
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    // 官僚の等級が、サインに必要な等級よりも数値が大きい（＝等級が低い）場合は例外を投げる
    if(bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

// * EXCEPTION
const char* AForm::GradeTooHighException::what() const throw()
{
    return RED "Error: " RESET "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return RED "Error: " RESET "Form grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return RED "Error: " RESET "Form is not signed yet!";
}

// ----------------------------------------------
// * クラス外関数
// ----------------------------------------------
std::ostream& operator<<(std::ostream &os, const AForm &form)
{
    os  << "Form                      : " << form.getName()
        << "\nsigned                    : " << (form.getIsSigned() ? "yes" : "no")
        << "\ngrade required to sign    : " << form.getGradeToSign()
        << "\ngrade required to execute : " << form.getGradeToExecute();
    return os;
}
