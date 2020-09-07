//
// Created by art on 7/25/20.
//

#ifndef RUBICKSCUBE_SIDE_H
#define RUBICKSCUBE_SIDE_H


class Side {
public:
    ///\brief Constructor
    ///\details Make one of the cube side
    ///\param size side dimensions
    ///\param color color of te side
    Side(int size, short color);

    ///\brief Default constructor
    Side();

    int size;       ///< side dimensions
    short **matrix; ///< side matrix
};


#endif //RUBICKSCUBE_SIDE_H
