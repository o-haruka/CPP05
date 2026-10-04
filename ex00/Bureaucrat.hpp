#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

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

        // Exception classes
        // throw() は「この関数自体は例外を投げない」というC++98の仕様
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
