//
//  TierList.h
//  TierList
//
//  Created by Raymond Choi on 9/14/19.
//  Copyright © 2019 Raymond Choi. All rights reserved.
//  Program that organizes Champions into tiers based off of win rate and propresence in League of Legends.
//

#ifndef TierList_h
#define TierList_h
#include <iostream>
#include "Champion.h"
using namespace std;

class TierList
{
    private:
    Champion* tierList;
    int itemCount; //amount of Champions in tierlist
    int capacity; //how many champions can fit into tierlist
    string region; //which region the statistics came from
    void swap(Champion &a, Champion &b);
    
    
    public:
    TierList(int capacity, string r)
    { itemCount = 0; this->capacity = capacity; tierList = new Champion[capacity]; region = r;}
    
    bool add(Champion c);
    bool remove(Champion c);
    bool getStatsFor(Champion c);
    bool isEmpty();
    void displayTierList();
    
    void calculateTier(Champion c);
    
    string getRegion()
    { return region; }
    void setRegion(string r)
    { region = r; }



    
};


#endif /* TierList_h */
