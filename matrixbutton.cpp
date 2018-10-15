#include "matrixbutton.h"
matrixButton::matrixButton(const QString& text, QWidget* parent) : QPushButton(text,parent) {
    setMaximumSize(110,110);
    setFont(QFont("Helvetica",10));
}
