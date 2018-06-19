#ifndef BOMBERMAN_AI_H
#define BOMBERMAN_AI_H


#include <string>


class AI {
    public:
        AI(int id, int *pos);
        void move(char *tab);
        void throwBomb();

    private:
        int id;
        int &position;
};


#endif //BOMBERMAN_AI_H
