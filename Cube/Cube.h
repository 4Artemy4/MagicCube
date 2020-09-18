//
// Created by art on 9/3/20.
//

#ifndef RUBICKSCUBE_CUBE_H
#define RUBICKSCUBE_CUBE_H


#include <ostream>
#include "Side.h"

///\brief N-cube
class Cube {
private:

    // rotate one vertical layer (clockwise)
    void rotateVertical(int layer);

    // rotate one vertical layer (anticlockwise)
    void rotateVerticalInverse(int layer);

    // rotate one horizontal layer (clockwise)
    void rotateHorizontal(int layer);

    // rotate one horizontal layer (anticlockwise)
    void rotateHorizontalInverse(int layer);

    // rotate one of front layers (clockwise)
    void rotateFront(int layer);

    // rotate one of front layers (anticlockwise)
    void rotateFrontInverse(int layer);

    // initializer for matrix
    short ** initMatrix(short **matrix, short side);

    // delete matrix
    void deleteMatrix(short **matrix) const;

    // add 'V' command to the list of the last commands
    void addVerticalRotationCommand(bool isInverse, int layerNum);

    // add 'H' command to the list of the last commands
    void addHorizontalRotationCommand(bool isInverse, int layerNum);

    // add 'F' command to the list of the last commands
    void addFrontRotationCommand(bool isInverse, int layerNum);

    // string to int converter
    static int stringToInt(const std::string &commands, int j);

protected:
    Side sides[6];          ///< Sides of the Cube
    int size;               ///< Cube dimensions
    static char colors[6];  ///< Array for translating colorCode to Color
    const short currentColor = 0, backwardColor = 1, upColor = 2, downColor = 3, leftColor = 4, rightColor = 5;
    std::string rotations;  ///< List of the last commands

    void rotateSide(short side, bool isInverse);

    ///\brief Convert color code to color char
    ///\param colorCode
    ///\details: \n
    /// 0 - White \n
    /// 1 - Yellow \n
    /// 2 - Red \n
    /// 3 - Orange \n
    /// 4 - Blue \n
    /// 5 - Green \n
    static char convertCodeToColor(short colorCode);

    ///\brief Rotate layer vertically
    ///\param isInverse If false - clockwise rotation, true - anticlockwise rotation
    void rotateLayerVertically(bool isInverse, int layer);

    ///\brief Rotate layer horizontally
    ///\param isInverse If false - clockwise rotation, true - anticlockwise rotation
    void rotateLayerHorizontally(bool isInverse, int layer);

    ///\brief Rotate Front layer
    ///\param isInverse If false - clockwise rotation, true - anticlockwise rotation
    void rotateFrontLayer(bool isInverse, int layer);

public:

    ///\brief Constructor
    Cube(int n);

    ///\brief Output stream operator
    ///\param os output stream
    ///\param cube
    ///\return Output stream
    friend std::ostream &operator<<(std::ostream &os, const Cube &cube);

    ///\brief Output stream operator
    ///\param os output stream
    ///\param cube
    ///\return Output stream
    friend std::istream &operator>>(std::istream &is, Cube &cube);

    ///\brief Command for cube
    ///\details Convert commands in the "Cube rotation language" into the program commands
    ///\param commands string with commands
    ///\return true - if all commands are correct
    virtual bool command(const std::string &commands);

    ///\brief Random commands
    ///\return string with commands in the "Cube rotation language"
    virtual std::string rand();

    ///\brief Is Cube compiled?
    ///\return true - is compiled
    bool check() const;

    ///\brief Load Cube from the file
    ///\details Load string in the "Cube rotation language" from the file
    ///\param filename
    void load(const std::string &filename);

    ///\brief Solve Cube
    ///\details Clearing rotation, recolor sides
    void solve();

    ///\brief Get Cube dimensions
    ///\return Dimensions
    int getSize() const;

    ///\brief Getter for last rotations list
    ///\return String in "Cube rotation language"
    const std::string &getRotations() const;

    ///\brief Getter for Cube elements color
    ///\param sideColor Source of information
    ///\param i row
    ///\param j column
    short getColor(short sideColor, int i, int j) const;

    ///\brief Equality operator
    bool operator==(const Cube &rhs) const;

    ///\brief Equality operator
    bool operator!=(const Cube &rhs) const;

    ///\test vertical rotation
    static bool testVerticalRotation();

    ///\test horizontal rotation
    static bool testHorizontalRotation();

    ///\test front rotation
    static bool testFrontRotation();

};


#endif //RUBICKSCUBE_CUBE_H
