#pragma once
#include <string>
#include <memory>
/**
 * @brief Родительский класс с пустым изображением.
 */
class Figure 
{
    public:
    std::string name = "Nothing";
};
/**
 * @brief Дочерний класс рисующий линии.
 */
class Line: public Figure
{
    public:    
    Line()
    {
        name = "Line";
    }
};

/**
 * @brief Дочерний класс рисующий квадраты.
 */
class Square: public Figure
{
    public:
    Square()
    {
        name = "Square";
    }
};

/**
 * @brief Дочерний класс рисующий треугольники.
 */
class Triangle: public Figure
{
    public:
    Triangle()
    {
        name = "Triangle";
    }
};

/**
 * @brief Класс создающий документ с рисунком.
 */
class Document
{
    public:
    Document(std::string name):_name(name)
    {
        _figure.name = "Empty";
    }
/**
 * @brief Метод сохранения изображения в файл хранящимся в объекте controller.
 * @param figure - ссылка на указатель на указатель хранящий состояние текущей фигуры которую надо сохранить.
 */
    void saveFigure(std::shared_ptr<Figure>& figure)
    {
        _figure = *figure;
    }
/**
 * @brief Метод экспорта изображения в объект controller.
 * @return указатель на объект хранящийся в документе
 */
    std::shared_ptr<Figure> getFigure()
    {
        return std::make_shared<Figure>(_figure);
    }

    std::string _name;
    private:
    Figure _figure;
};