#ifndef CHESSMEN_H
#define CHESSMEN_H

#include<QString>

class Chessmen
{
public:
    Chessmen();
    ~Chessmen();
    enum TYPE{JIANG, CHE, MA, XIANG, SHI, PAO, BING};

    int _id;
    int _row;
    int _col;
    TYPE _type;
    bool _dead;
    bool _red;

    void init(int id)
    {
        struct {
            int row, col;
            Chessmen::TYPE type;
        } pos[16] = {
        {0, 0, Chessmen::CHE},
        {0, 1, Chessmen::MA},
        {0, 2, Chessmen::XIANG},
        {0, 3, Chessmen::SHI},
        {0, 4, Chessmen::JIANG},
        {0, 5, Chessmen::SHI},
        {0, 6, Chessmen::XIANG},
        {0, 7, Chessmen::MA},
        {0, 8, Chessmen::CHE},

        {2, 1, Chessmen::PAO},
        {2, 7, Chessmen::PAO},
        {3, 0, Chessmen::BING},
        {3, 2, Chessmen::BING},
        {3, 4, Chessmen::BING},
        {3, 6, Chessmen::BING},
        {3, 8, Chessmen::BING},
        };
        _id = id;
        _dead = false;
        _red = id<16;
        if (id < 16)
        {
            _row = pos[id].row;
            _col = pos[id].col;
            _type = pos[id].type;
        }
        else
        {
            _row = 9 -pos[id-16].row;
            _col = 8 - pos[id-16].col;
            _type = pos[id-16].type;
        }
    }

    QString getText()
    {
        switch (this->_type) {
            case CHE:
                return "车";
            case MA:
                return "马";
            case PAO:
                return "炮";
            case BING:
                return "兵";
            case JIANG:
                return "将";
            case SHI:
                return "士";
            case XIANG:
                return "相";
           }
        return "错误";
    }
};

#endif // CHESSMEN_H
