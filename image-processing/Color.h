#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
    // Color constructor where each compoonent is a float value between 0-1
    Color(float r, float g, float b, float a);

    // Gets red component
    float Red() const { return components[0]; }
    // Gets green component
    float Green() const { return components[1]; }
    // Gets blue component
    float Blue() const { return components[2]; }
    // Gets alpha component
    float Alpha() const { return components[3]; }

private:
    // Components are stored in an array on the stack
    float components[4];
};




// Methods outside of the class in the header must be specified as inline
inline Color::Color(float r, float g, float b, float a) {
    // Sets each component
    components[0] = r;
    components[1] = g;
    components[2] = b;
    components[3] = a; 
}

#endif