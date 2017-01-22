//
//  main.cpp
//  Petr and a calendar
//
//  Created by Alexandru Chiurtu on 22/01/2017.
//  Copyright © 2017 Alexandru Chiurtu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int month, weekday, col = 0;
    
    std::cin >> month >> weekday;

    
    int monthsDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int calendar[7][6] = {0};
    
    weekday -= 1;
    month -= 1;
    
    int day = 1;
    
    
    while(day != monthsDays[month])
    {
        
        calendar[weekday][col] = day;
        
        day++;
        weekday++;
        
        if(weekday >= 7)
        {
            weekday = 0;
            col += 1;
        }
        
        
    }
    
    
    std::cout <<  col + 1 << std::endl;
    
    return 0;
}
