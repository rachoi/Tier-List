//
//  Champion.cpp
//  TierList
//
//  Created by Raymond Choi on 9/14/19.
//  Copyright © 2019 Raymond Choi. All rights reserved.
//

#include <iostream>
#include "Champion.h"
#include "TierList.h"

using namespace std;

const Champion& Champion::operator=(const Champion &c)
{
    name = c.name;
    winRate = c.winRate;
    proPresence = c.proPresence;
    tier = c.tier;
    
    return c;
}

void Champion::calculateTier()
{
    //calculate tier of champ, then add to Tier List
    float wr = winRate;
    float pp = proPresence;
    int score = 0; //op score
    if(pp == 100.0)
    {
        score += 10;
    }
    else if(pp >= 75.0)
    {
        score += 8;
    }
    else if(pp >= 50.0 && pp < 75.0)
    {
        score+= 6;
    }
    else if(pp >= 25.0 && pp < 50.0)
    {
        score+= 4;
    }
    else if(pp >= 0.0 && pp < 25.0)
    {
        score += 2;
    }
    
    if(wr == 100.0)
    {
        score += 5;
    }
    else if(wr >= 75.0)
    {
        score += 4;
    }
    else if(wr >= 50.0 && wr < 75.0)
    {
        score+= 3;
    }
    else if(wr >= 25 && wr < 50)
    {
        score+= 2;
    }
    else if(wr >= 0 && wr < 25)
    {
        score += 1;
    }


    if(score >= 12)
    {
        setTier('S');
    }
    else if(score < 12 && score >= 8)
    {
        setTier('A');
    }
    else if(score < 8 && score >= 6)
    {
        setTier('B');
    }
    else if(score < 6 && score >= 3)
    {
        setTier('C');
        
    }
    else if(score < 3 && score >= 0)
    {
        setTier('D');
    }
}



