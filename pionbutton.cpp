#include "pionbutton.h"
#include <QWidget>
#include <QPushButton>

PionButton::PionButton()
{

}

QPushButton* PionButton::getPionButton() {
    QPushButton *button = new QPushButton();
    button->setMinimumSize(50, 50);
    button->setFlat(true);
    button->setUpdatesEnabled(false);
    return button;
}


