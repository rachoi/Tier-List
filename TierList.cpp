//
//  TierList.cpp
//  TierList
//
//  Created by Raymond Choi on 9/15/19.
//  Copyright © 2019 Raymond Choi. All rights reserved.
//

#include <iostream>
#include "TierList.h"

using namespace std;


bool TierList::add(Champion c)
{
    c.calculateTier();
    if(itemCount == capacity)
    {
        cout << "Tierlist is full. \n";
        return false;
    }
    else{
        tierList[itemCount] = c;
        int indexOfAdded = itemCount;
        itemCount++;
        if(itemCount == 1)
        {
            return true;
        }
        else{ //sort upon adding champion
            if(tierList[indexOfAdded].getTier() == 'S')
            {
                //S Tier Case
                while(tierList[indexOfAdded-1].getTier() != 'S')
                {
                    //ranks S tier as highest
                    swap(tierList[indexOfAdded], tierList[indexOfAdded-1]);
                    indexOfAdded--;
                    
                }
                //if tiers are the same, check proPresence
                while(tierList[indexOfAdded].getTier() == tierList[indexOfAdded-1].getTier())
                {
                    //if proPresence is the same, check winrate, else check proPresence
                    if(tierList[indexOfAdded].getProPresence() == tierList[indexOfAdded-1].getProPresence())
                    {
                        if(tierList[indexOfAdded].getWinRate() > tierList[indexOfAdded-1].getWinRate())
                        {
                            //if pro presence is the same
                            swap(tierList[indexOfAdded], tierList[indexOfAdded-1]);
                            indexOfAdded--;
                        }
                        else{
                            return true;
                        }
                        
                    }
                    if(tierList[indexOfAdded].getProPresence() > tierList[indexOfAdded-1].getProPresence())
                    {
                        swap(tierList[indexOfAdded], tierList[indexOfAdded-1]);
                        indexOfAdded--;
                    }//if proPresence is the same, check the winrate
                    else{
                        return true;
                    }
                }
            } //ex if situtation is B A, and A is cur. index, check if index before it is greater (ie is B C or D, which are greater values in ASCII)
            else{ //CASE for A B C D,  ---
                while(tierList[indexOfAdded].getTier() < tierList[indexOfAdded-1].getTier() /*&& tierList[indexOfAdded-1].getTier() != 'S'*/)
                {
                    swap(tierList[indexOfAdded], tierList[indexOfAdded-1]);
                    indexOfAdded--;
                }
                while(tierList[indexOfAdded].getTier() == tierList[indexOfAdded-1].getTier())
                {
                    //check if proPresence is the same, if not, compare the propresence over the winrate
                    //if proPresence is the same, check the winrate
                    if(tierList[indexOfAdded].getProPresence() == tierList[indexOfAdded-1].getProPresence())
                    {
                        if(tierList[indexOfAdded].getWinRate() > tierList[indexOfAdded-1].getWinRate())
                        {
                            //if pro presence is the same
                            swap(tierList[indexOfAdded], tierList[indexOfAdded-1]);
                            indexOfAdded--;
                        }
                        else{
                            return true;
                        }
                    }
                    else{
                        if(tierList[indexOfAdded].getProPresence() > tierList[indexOfAdded-1].getProPresence())
                        {
                            swap(tierList[indexOfAdded], tierList[indexOfAdded-1]);
                            indexOfAdded--;
                        }
                        else{
                            return true;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool TierList::remove(Champion c)
{
    bool found = false;
    int index = 0;
    for(int i = 0; i < itemCount-1; i++)
    {
        if(tierList[i].getName() == c.getName()) //assume names are distinct
        {
            
            found = true;
            index = i;
        }
        
    }
    if(found)
    {
        for(int i = index; i <= itemCount; i++)
        {
            tierList[i] = tierList[i+1];
        }
        itemCount--;
        return found;
    }
    else{
        cout << "Entry not found. \n";
        return false;
    }
}

bool TierList::isEmpty()
{
    if(itemCount == 0)
    {
        return true;
    }
    return false;
}

void TierList::swap(Champion &a, Champion &b)
{
    Champion temp = a;
    a = b;
    b = temp;
}

bool TierList::getStatsFor(Champion c){
    for(int i = 0; i < itemCount; i++)
    {
        if(tierList[i].getName() == c.getName())
        {
            cout << "Region \t Tier \t Name \t Win Rate \t Pro Presence \t  \n";
            cout << " " << getRegion() << "\t \t" << "[" << tierList[i].getTier() << "] \t" << tierList[i].getName() << " \t " << tierList[i].getWinRate() << "% \t \t ";
            printf("%.2f", tierList[i].getProPresence());
            cout << "% \n";
            return true;
        }
    }
    cout << c.getName() << " was not found in the Tier List. \n";
    return false;
}

void TierList::displayTierList()
{
    
    cout << "Region \t Tier \t Name \t Win Rate \t Pro Presence \n";
    for(int i = 0; i < itemCount; i++)
    {
        cout << " " << getRegion() << "\t \t" << "[" << tierList[i].getTier() << "] \t" << tierList[i].getName() << "\t " << tierList[i].getWinRate() << "% \t \t ";
        printf("%.2f", tierList[i].getProPresence());
        cout << "% \n";
    }
}
    

