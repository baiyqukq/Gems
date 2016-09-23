#ifndef GEMS_H
#define GEMS_H

/* The singleton class */

#include <string>
#include <vector>

#include "GameObjectInterface.h"

class Gem;

class Gems : public GameObjectInterface
{
public:
    static Gems *Instance();

    Gem *getGem(int row, int col);

    //! [interface functions]
    virtual void update();
    virtual void draw();
    virtual void clear();
    virtual void load(const LoaderParams *params);
    //! []

    bool isComplete() const;
    bool exists(int row, int col);
    bool remove(int i);
    bool remove(int row, int col);
    void remove(Gem *gem);
    void remove(std::vector<Gem *> gems);

    //! [select]
    std::vector<Gem *> *getGems();
    Gem *getSelected() const;
    void clearSelection();
    bool hasSelected() const;
    void select(Gem *gem);
    //! []

    static int getCols();
    static int getRows();
private:
    Gems();
private:
    static Gems *s_instance;
    std::vector<Gem *> m_gems;
    static uint8_t s_rows;
    static uint8_t s_cols;
};

typedef Gems TheGems;

#endif // GEMS_H
