#pragma once
#include "model.h"
#include "mainwindow.h"
 

/**
 * @brief Класс предоставляющий пользовательский интерфейс и сохраняющий текущее состояние.
 */
class Controller 
{
    public:

    Controller(std::shared_ptr<Figure>& figure, std::shared_ptr<View>& view): _figure(figure), _view(view)
    {

    }
/**
 * @brief метод создания изображения.
 * @param figure - описание создаваемого изображения.
 */
    void create(std::string figure)
    {
        if (figure == "Line") 
        {   
            _figure.reset(new Line());
            _view->show(_figure->name);
        }
        else if (figure == "Triangle") 
        {   
            _figure.reset(new Triangle());
            _view->show(_figure->name);
        }
        else if (figure == "Square") 
        {
            _figure.reset(new Square());
            _view->show(_figure->name);
        }
        else 
        {
            _view->show(figure + " - it is not a figure");
            _figure = nullptr;
        }
    }
/**
 * @brief удаление созданного изображения.
 */
    void clean()
    {
        if(_figure)
        {
            _view->show(_figure->name + " - deleted");
            _figure = nullptr;
        }
        else
        {
            _view->show("You dont have a figure");
        }
            
    }
/**
 * @brief Метод открытия документа с изображением.
 * @param doc - указатель на открываемый документ.
 */
    void openDocument(Document* doc)
    {
        _view->show(doc->_name + " - document is open");
        _figure = doc->getFigure();
        _view->show(_figure->name);
    }
/**
 * @brief Метод сохранения изображения в документ.
 * @param doc - указатель на документ куда будет сохранено изображение.
 */
    void saveDocument(Document* doc)
    {
        doc->saveFigure(_figure);
        _view->show(doc->_name + " - saved");
    }

    private:
    std::shared_ptr<Figure> _figure;
    std::shared_ptr<View> _view;
};
