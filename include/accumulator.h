
class Accumulator
{
public:
    Accumulator &add(int num);
    int result();
private:
    int accum = 0;
};