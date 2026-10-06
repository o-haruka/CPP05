#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class Form{
    private:
        const std::string name_;
        bool isSigned_;
        const int gradeToSign_;
        const int gradeToExecute_;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form &operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureaucrat);

        // Exception classes
        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif
