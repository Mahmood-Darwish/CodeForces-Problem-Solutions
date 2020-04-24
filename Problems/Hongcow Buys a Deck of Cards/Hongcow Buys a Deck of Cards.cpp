#include <iostream>
#include <string.h>

using namespace std;

struct cards{
    char C;
    int R, B;
}card[17];

int n, dp[(1 << 16)][2][(16 * 16) + 1], INF = (1 << 30), Blue, Red, basic_movement;

int DP(int mask, int blue, int how_much)
{
    how_much = min(n * n, how_much); // we don't need more than (n ^ 2) tokens even if we have more because in the beginning we made sure that all the cards have n or less tokens
    if(mask == (1 << n) - 1) // counting the bits that equals one in the binary represintation of mask (if it is equal to n then we are done)
        return 0;
    int &cur = dp[mask][blue][how_much];
    if(cur != -1)return cur;
    cur = INF;
    int how_much_blue = 0, how_much_red = 0, card_red = 0, card_blue = 0; // this line and the next 4 lines we count how much red tokens we have and how much blue tokens we have
    if(blue)
        how_much_blue = how_much;
    else
        how_much_red = how_much;
    for(int i = 0 ; i < 32 ; i++){ // here we see what cards we do have from each color
        if(mask & (1 << i)){
            if(card[i].C == 'R')
                card_red++;
            else
                card_blue++;
        }
    }
    for(int i = 0 ; i < n ; i++){ // here we try to take every card we did not take and then pick the best one
        if(!(mask & (1 << i))){ // making sure we haven't took this card
            int temp_red = card[i].R; // how much red tokens it needs
            int temp_blue = card[i].B; // how much blue tokens it needs
            temp_blue = max(0, temp_blue - (how_much_blue + card_blue)); // how much blue tokens we need to buy
            temp_red = max(0, temp_red - (how_much_red + card_red)); // how much red tokens we need to buy
            int need = max(temp_blue, temp_red); // how much tokens we will have to buy from the blue kind AND the red kind
            int red_to_have = how_much_red + need - max(0, card[i].R - card_red); // how much red tokens we will have after we buy this card
            int blue_to_have = how_much_blue + need - max(0, card[i].B - card_blue); // how much blue tokens we will have after we buy this card
            if(!blue_to_have){
                cur = min(cur, DP(mask | (1 << i), 0, red_to_have) + need);
            }
            if(!red_to_have){
                cur = min(cur, DP(mask | (1 << i), 1, blue_to_have) + need);
            }
        }
    }
    return cur;
}

int main()
{
    memset(dp,-1,sizeof(dp)); // filling array dp with -1 values
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> card[i].C >> card[i].R >> card[i].B;
        Blue += max(0, card[i].B - n);
        Red += max(0, card[i].R - n);
        card[i].R = min(card[i].R, n);
        card[i].B = min(card[i].B, n);
    }
    basic_movement = max(Blue, Red);
    if(Blue <= Red)
        cout << DP(0, 1, Red - Blue) + basic_movement + n << endl;
    else
        cout << DP(0, 0, Blue - Red) + basic_movement + n << endl;
    return 0;
}