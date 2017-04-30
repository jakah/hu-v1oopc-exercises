#ifndef VECTOR_HPP
#define VECTOR_HPP

/// @file

/// \brief
/// vector ADT
/// \details
/// This is an ADT that implement vectors.
/// The x and y value are stored as two integers.
/// The appropriate constructors are provide.
///
/// The following operators are implemented: +, +=, *, *= and <<
class vector{
private:
    int x;
    int y;
public:
    /// \brief
    /// constructor from explicit values
    /// \details
    /// This constructor initializes vector from a x and y value
    /// The default values for x and y are 0 and 0
    vector(int x , int y):
        x(x), y(y)
    {}
    vector():
        x( 0 ), y( 0 )
    {}

    /// \brief
    /// add a vector to another vector
    /// \details
    /// This operator+ adds a vector to another vector.
    vector operator+( const vector& rhs ) const {
        return vector( x + rhs.x, y + rhs.y );
    }

    /// \brief
    /// monodic plus operator
    /// \details
    /// This operator returns a vector with x and y.
    vector operator+() const {
        return vector( x, y );
    }

    /// \brief
    /// add a vector to itself
    /// \details
    /// This operator+= adds a vector to itself.
    vector &operator+=( const vector & rhs ){
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    /// \brief
    /// multiply a vector with another vector
    /// \details
    /// This operator*  multiplies a vector by a vector.
    vector operator*(const vector & rhs) const {
        return vector(
            x * rhs.x,
            y * rhs.y
        );
    }

    /// \brief
    /// multiply a vector by an integer
    /// \details
    /// This operator multiplies a vector with an integer and will return a
    /// vector
    vector operator*(const int & rhs) const {
        return vector(
            x * rhs,
            y * rhs
        );
    }

    /// \brief
    /// multiply integer by a vector
    /// \details
    /// This operator multiplies an integer with a vector and returns a vector
    friend vector operator*(const int lhs, const  vector & rhs){
        return vector(lhs * rhs.x, lhs * rhs.y);
    }

    /// \brief
    /// multiply a vector by itself
    /// \details
    /// This operator*= multiplies a vector into a vector and stores it in
    /// itself.
    vector &operator*=( const vector & rhs ){
        x = x * rhs.x;
        y = y * rhs.y;
        return *this;
    }

    /// \brief
    /// multiply integer into vector
    /// \details
    /// This operator multiplies a integer into a vector.
    vector &operator*=( const int & rhs ){
        x = x * rhs;
        y = y * rhs;
        return *this;
    }
    /// \brief
    /// output operator for a vector
    /// \details
    /// This operator<< prints a constructor in the format (x,y) where both
    /// values are printed as integers.
    friend std::ostream & operator<<( std::ostream & lhs, vector pos ){
        lhs << "(" << pos.x << "," << pos.y << ")";
        return lhs;
    }
};

#endif
