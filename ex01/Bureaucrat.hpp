#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../Color.hpp"
#include <string>
#include <ostream>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string name_; //!定数ってどう指定するんだっけ？ → constつける
        int grade_;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(Form& form);

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    };

// std::ostream& operator<<(const std::string &name, const int &grade);
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
