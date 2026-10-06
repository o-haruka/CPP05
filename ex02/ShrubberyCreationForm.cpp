#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

// ----------------------------------------------
// * OCF
// ----------------------------------------------
//AForm("form name", gradeToSign, gradeToExecute)
ShrubberyCreationForm::ShrubberyCreationForm()
:   AForm("ShrubberyCreationForm", 145, 137),
    target_("default target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:   AForm("ShrubberyCreationForm", 145, 137),
    target_(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
:   AForm(other),
    target_(other.target_)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// ----------------------------------------------
// * METHOD
// ----------------------------------------------
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // フォームがサインされているか
    if (!this->getIsSigned()) {
        throw AForm::NotSignedException();
    }

    // 実行者のグレードが足りているか
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // <target>_shrubbery ファイルの作成と書き込み
    std::string filename = target_ + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open()) {
        std::cout << "Error: Could not open file " << filename << "\n";
        return;
    }

    outfile << "       _-_" << "\n";
    outfile << "    /~~   ~~\\" << "\n";
    outfile << " /~~         ~~\\" << "\n";
    outfile << "{               }" << "\n";
    outfile << " \\  _-     -_  /" << "\n";
    outfile << "   ~  \\\\ //  ~" << "\n";
    outfile << "_- -   | | _- _" << "\n";
    outfile << "  _ -  | |   -_" << "\n";
    outfile << "      // \\\\" << "\n";
    
    outfile.close();
}
