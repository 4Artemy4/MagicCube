//
// Created by art on 7/25/20.
//

#ifndef RUBICKSCUBE_SIDE_H
#define RUBICKSCUBE_SIDE_H


class Side {
public:
    Side(int size, short color);
    Side();
    int size;
    short **matrix;
};


#endif //RUBICKSCUBE_SIDE_H
