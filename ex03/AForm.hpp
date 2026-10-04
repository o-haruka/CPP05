#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class AForm{
    private:
        const std::string name_;
        bool isSigned_;
        const int gradeToSign_;
        const int gradeToExecute_;
    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        // Exception classes
        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NotSignedException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif
