//
//  Champion.h
//  TierList
//
//  Created by Raymond Choi on 9/14/19.
//  Copyright © 2019 Raymond Choi. All rights reserved.
//

#ifndef Champion_h
#define Champion_h
using namespace std;


class Champion
{
    private:
    string name;
    float winRate;
    int gamesPicked; //times champ is picked 
    int gamesBanned; //times champ is banned
    float proPresence; //number of timesed picked or banned out of all the games throughout the season
    char tier; //tier assignment
    int games; //number of games during season
    
    
    public:
    
    Champion()
    { name = "Unknown"; winRate = 0.0; gamesPicked = 0; gamesBanned = 0;}
    Champion(string n, float wr, int gp, int gb, int g)
    { name = n; winRate = wr; gamesPicked = gp; gamesBanned = gb; games = g; proPresence = ((gamesPicked + gamesBanned)*100.0)/games; }
    string getName()
    { return name; }
    float getWinRate()
    { return winRate; }
    int getGamesPicked()
    { return gamesPicked; }
    int getGamesBanned()
    { return gamesBanned; }
    int getTotalGames()
    { return games; }
    char getTier()
    { return tier; }
    float getProPresence()
    { return proPresence; }

    
    
    void setName(string n)
    { name = n ;}
    void setWinRate(float wr)
    { winRate = wr; }
    void setGamesPlayed(int gp)
    { gamesPicked = gp; }
    void setGamesBanned(int gb)
    { gamesBanned = gb; }
    void setTier(char t)
    { tier = t; }
    void setGames(int g)
    { games = g; }
    void setProPresence(float pp)
    { proPresence = pp; }
    
    void calculateTier();
    
    const Champion& operator=(const Champion& c);
    
};

#endif /* Champion_h */


