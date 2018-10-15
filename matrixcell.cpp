#include "matrixcell.h"
MatrixCell::MatrixCell() {
    setFixedSize(30,30);
    QFont f("Helvetica", 10);
    setFont(f);
    setAlignment(Qt::AlignCenter);
}
