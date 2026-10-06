#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "../Color.hpp"

// ----------------------------------------------
// * OCF
// ----------------------------------------------
Form::Form()
:   name_("Default Form name"),
    isSigned_(false),
    gradeToSign_(150),
    gradeToExecute_(150)
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
:   name_(name),
    isSigned_(false),
    gradeToSign_(gradeToSign),
    gradeToExecute_(gradeToExecute)
{
    if (gradeToSign_ < 1 || gradeToExecute_ < 1)
        throw GradeTooHighException();
    if (gradeToSign_ > 150 || gradeToExecute_ > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
:   name_(other.name_),
    isSigned_(other.isSigned_),
    gradeToSign_(other.gradeToSign_),
    gradeToExecute_(other.gradeToExecute_)
{}

Form& Form::operator=(const Form& other){
    if(this != &other){
        isSigned_ = other.isSigned_;
    }
    return (*this);
}

Form::~Form() {}

// ----------------------------------------------
// * METHOD
// ----------------------------------------------
// * GETTER
const std::string& Form::getName(void) const
{
    return name_;
}

bool Form::getIsSigned(void) const
{
    return isSigned_;
}

int Form::getGradeToSign(void) const
{
    return gradeToSign_;
}

int Form::getGradeToExecute(void) const
{
    return gradeToExecute_;
}

// * MEMBER FUNCTIONS
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

// * EXCEPTION
const char* Form::GradeTooHighException::what() const throw()
{
    return RED "Error: " RESET "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return RED "Error: " RESET "Form grade is too low!";
}


// ----------------------------------------------
// * クラス外関数
// ----------------------------------------------
std::ostream& operator<<(std::ostream &os, const Form &form)
{
    os  << "Form                      : " << form.getName()
        << "\nsigned                    : " << (form.getIsSigned() ? "yes" : "no")
        << "\ngrade required to sign    : " << form.getGradeToSign()
        << "\ngrade required to execute : " << form.getGradeToExecute();
    return os;
}
