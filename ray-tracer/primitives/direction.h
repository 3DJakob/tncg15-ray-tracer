using namespace std;

class Direction {
    private:
        /* data */
    public:
        double inclination;
        double azimuth;

        Direction();
        Direction(double inclination, double azimuth);
        ~Direction();
};

// Direction::Direction(double inclination, double azimuth) {

// }

// Direction::~Direction() {

// }

// ostream& operator << (ostream &os, const Direction &s);
