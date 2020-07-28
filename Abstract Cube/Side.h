//
// Created by art on 7/25/20.
//

#ifndef RUBICKSCUBE_SIDE_H
#define RUBICKSCUBE_SIDE_H


class Side {
public:
    Side(int rows, int columns, short color);
    Side();
    int rows, columns;
    short **matrix;
};


#endif //RUBICKSCUBE_SIDE_H
