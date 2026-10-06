#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "../Color.hpp"

// ----------------------------------------------
// * OCF
// ----------------------------------------------
Bureaucrat::Bureaucrat()
    :   name_("Default name"), 
        grade_(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :   name_(name),
        grade_(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    :   name_(other.name_),
        grade_(other.grade_)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        grade_ = other.grade_;
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

// ----------------------------------------------
// * METHOD
// ----------------------------------------------
const std::string& Bureaucrat::getName(void) const
{
    return name_;
}

int Bureaucrat::getGrade(void) const
{
    return grade_;
}

void Bureaucrat::incrementGrade()
{
    if(grade_ - 1 < 1)
        throw GradeTooHighException();
    --grade_;
}
void Bureaucrat::decrementGrade()
{
    if(grade_ + 1 > 150)
        throw GradeTooLowException();
    ++grade_;
}

void Bureaucrat::signForm(AForm& form)
{
    try{
        form.beSigned(*this);

        std::cout   << this->getName()
                    << " signed "
                    << form.getName()
                    << "\n";
    }
    catch(std::exception& e){
        std::cout   << this->getName()
                    << " couldn't sign "
                    << form.getName()
                    << " because "
                    << e.what()
                    << "\n";
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try{
        form.execute(*this);
        std::cout   << this->getName()
                    << " executed "
                    << form.getName()
                    << "\n";
    } catch (std::exception & e) {
        std::cout   << this->getName()
                    << " couldn't execute "
                    << form.getName()
                    << " because "
                    << e.what()
                    << "\n";
    }
}

//* Exception classes
const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return  RED "Error: " RESET "Grade is too high! (Highest possible grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return  RED "Error: " RESET "Grade is too low! (Lowest possible grade is 150)";
}

// ----------------------------------------------
// * クラス外関数
// ----------------------------------------------

// <name>, bureaucrat grade <grade>. のフォーマットで出力
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os  << CYAN << bureaucrat.getName() << RESET
        << ", bureaucrat grade "
        << CYAN << bureaucrat.getGrade() << RESET
        << ".";
    return os;
}
