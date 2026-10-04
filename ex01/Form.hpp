#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <ostream>
// #include "Bureaucrat.hpp" // 外します

class Bureaucrat; // !循環参照を防ぐための前方宣言

class Form{
    private:
        const std::string name_;
        bool isSigned_;
        const int gradeToSign_;
        const int gradeToExecute_;
    public:
        Form();
        //!name_, gradeToSign_, gradeToExecute_ は const 指定されているため、後から代入演算子などで値を変更することができません。そのため、初期化リストを用いてこれらの値を設定するための引数付きコンストラクタ
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
