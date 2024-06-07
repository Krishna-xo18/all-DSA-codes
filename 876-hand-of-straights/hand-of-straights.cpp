class Solution
{
public:
    bool isNStraightHand(std::vector<int> &hand, int groupSize)
    {
        int length = hand.size();
    
        if (length % groupSize != 0)
            return false;
       
        map<int, int> cardCount;
        for (int card : hand)
            cardCount[card]++;
        while (!cardCount.empty())
        {
            
            int startCard = cardCount.begin()->first;
            
            for (int i = 0; i < groupSize; i++)
            {
                int currentCard = startCard + i;
                if (cardCount.find(currentCard) == cardCount.end())
                    return false;
              
                cardCount[currentCard]--;
                if (cardCount[currentCard] == 0)
                    cardCount.erase(currentCard);
            }
        }
   
        return true;
    }
};