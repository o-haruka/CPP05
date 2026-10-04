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
    // 官僚の等級が、サインに必要な等級よりも数値が大きい（＝等級が低い）場合は例外を投げる
    if(bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}
//結論から言うと、throw GradeTooLowException(); のままで全く問題ありません（Form:: は省略可能です）！

//【解説：どの階層の例外が投げられているのか？】
//C++の仕様では、クラスのメンバ関数（今回は Form::beSigned）の内部にいるとき、コンパイラはまず自分自身のクラス（Form）のスコープから名前を探します。

//そのため、単に GradeTooLowException() と書くだけで、自動的に Form クラス内に定義した Form::GradeTooLowException が選ばれて投げられます。

//逆に Form:: と明記しなければならないのは、main.cpp のように Form クラスの外の世界 からこの例外を指定する場合（例えば catch (Form::GradeTooLowException& e) と書くとき）だけです。メンバ関数の中では省略するのが一般的でスマートな書き方です。

//---------------------------------------------------------

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
