class Vertex
{
private:
    int x;
    int y;

    int getRandomNumberInRange(int min, int max)
    {
        return min + (rand() % (max - min + 1));
    }

public:
    Vertex()
    {
    }
    void fill_rand()
    {

        x = getRandomNumberInRange(-100, 100);
        y = getRandomNumberInRange(-100, 100);
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    ~Vertex()
    {
    }
};