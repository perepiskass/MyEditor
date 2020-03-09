#pragma once

#include "controller.h"
/**
 * @brief Класс позоволяющий выводить на экран изменения сделанные пользователем.
 */
class View
{   public:
    void show(std::string figure)
    {
       std::cout << figure << std::endl;
    }
};