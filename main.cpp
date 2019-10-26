//
//  main.cpp
//  TierList
//
//  Created by Raymond Choi on 10/6/19.
//  Copyright © 2019 Raymond Choi. All rights reserved.
//  Program that organizes assigns a tier to a champion and organizes it into a list (from best to worst)

#include <iostream>
#include "TierList.h"
#include "Champion.h"

int main()
{
    
    Champion Xayah("Xayah", 53.8, 13, 7, 26); //53.8% w/r, 13 games picked, banned in 7 games, out of 26 games
    Champion Sivir("Sivir", 50.0, 10, 4, 26);
    Champion Kaisa("Kai'Sa", 55.6, 9, 3, 26);
    Champion Ezreal("Ezreal", 50.0, 6, 5, 26);
    Champion Varus("Varus", 20.0, 5, 2, 26);
    Champion Caitlyn("Caitlyn", 75.0, 4, 6, 26);
    Champion Draven("Draven", 0.0, 2, 2, 26);
    Champion Ashe("Ashe", 100.0, 1, 1, 26);
    Champion Sona("Sona", 100.0, 1, 1, 26);
    Champion Vayne("Vayne", 0.0, 1, 1, 26);
    TierList tierlist(10,"NA");
    //From LCS 2019 Summer Playoffs, 10 unique picks from Botlane, 26 games played in playoffs
    
    tierlist.add(Varus);
    tierlist.add(Caitlyn);
    tierlist.add(Draven);
    tierlist.add(Xayah);
    tierlist.add(Sivir);
    tierlist.add(Ashe);
    tierlist.add(Sona);
    tierlist.add(Vayne);
    tierlist.add(Kaisa);
    tierlist.add(Ezreal);
    tierlist.displayTierList();
    
    Champion Akali("Akali", 44.4, 9, 17, 26);
    
    tierlist.getStatsFor(Kaisa);
    tierlist.getStatsFor(Akali);
    
    
    
    
}
