#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
    private:
        AForm* makeShrubbery(const std::string& target) const;
        AForm* makeRobotomy(const std::string& target) const;
        AForm* makePresidential(const std::string& target) const;
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
